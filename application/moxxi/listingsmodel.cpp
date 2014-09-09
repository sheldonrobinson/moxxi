#include "listingsmodel.h"
#include <QLocale>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QLocale>
#include <QNetworkRequest>



ListingsModel::ListingsModel(QObject *parent) :
    QAbstractListModel(parent),m_isReady(false)
{
    _imgLoader = new ImageDownloader(this);
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
    connect(_imgLoader, SIGNAL(downloaded(const QUrl&, bool)),
            this, SLOT(imageResult(const QUrl&, bool)));

}

void ListingsModel::imageResult(const QUrl& url, bool success){
    qDebug()<<"ListingsModel::imageResult";
    qDebug()<<(!success?"Unable to load ":"Loaded ")<< url;
}

QHash<int, QByteArray> ListingsModel::roleNames() const {
    // QML uses role names when accessing properties from model
    QHash<int, QByteArray> roles;
    roles[UrlRole] = "url";
    roles[NameRole] = "name";
    roles[BrandRole] = "brand";
    roles[PriceRole] = "price";
    roles[DescriptionRole] = "description";
    roles[CategoryRole] = "category";
    roles[BuyerRole] = "buyer";
    roles[ImageRole] = "image";
    roles[ImagesRole] = "images";
    roles[ImageUrlRole]="imageUrl";
    roles[ImageUrlsRole]="imageUrls";

    return roles;
}

void ListingsModel::replyFinished(QNetworkReply* reply){
    if(reply-> error() == QNetworkReply::NoError)
    {
        QString strReply = (QString) reply->readAll();
        QJsonDocument jsonResponse  = QJsonDocument::fromJson(strReply.toUtf8());
        QJsonObject jsonObject = jsonResponse.object();

        QJsonArray jsonArray = jsonObject["products"].toArray();
        foreach (const QJsonValue & value, jsonArray)
        {

            QJsonObject obj = value.toObject();
            Listing listing(this);
            listing.setListingId(obj["id"].toString());
            listing.setName(obj["brandedName"].toString());
            listing.setDescription(obj["description"].toString());
            listing.setUrl(QUrl(obj["pageUrl"].toString()));
            QUrl url(obj["url"].toString());
            listing.setImageUrl(url);
            _imgLoader->downloadImg(url);
            QLocale _locale(obj["locale"].toString());
            listing.setCurrency(_locale.currencySymbol(QLocale::CurrencyIsoCode));
            QString  _px(obj["price"].toString());
            QString _sym(_locale.currencySymbol(QLocale::CurrencySymbol));
            bool result;
            listing.setPx(_locale.toDouble(_px.remove(_sym),&result));
            if(!result){
                qDebug()<<"Unable to convert price "<<_px;
            }
            QJsonArray imgs = obj["alternateImages"].toArray();
            foreach (const QJsonValue & altimg, jsonArray){
                QUrl _url(altimg.toObject()["sizes"].toObject()["IPhone"].toObject()["url"].toString());
                _imgLoader->downloadImg(_url);
                listing.addImage(_url);
            }
            listing.setShopId(obj["retailer"].toObject()["id"].toString());
        }
    }
    m_isReady =true;
}



ListingsModel::~ListingsModel(){
    qDeleteAll(m_modelData);
    delete manager;
}

void ListingsModel::replyError(QNetworkReply::NetworkError err){
    qDebug()<<"ListingsModel::QNetworkReply::NetworkError";
    qDebug()<<"Error from query "<< err;
    m_isReady = true;
    emit ready();
}

/*!
   Whether the model is done fetching media information.
*/
bool ListingsModel::isReady() const
{
    return m_isReady;
}

QUrl ListingsModel::query() const { return _query;}
void ListingsModel::setQuery(const QUrl& query) { if(_query != query){_query =query; emit queryChanged();}}

void ListingsModel::fetchData() {
    m_isReady = false;
    if(!_query.isEmpty()){
        QNetworkReply *reply = manager->get(QNetworkRequest(_query));
        connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
                this, SLOT(replyError(QNetworkReply::NetworkError)));
    }
}

QVariant ListingsModel::data( const QModelIndex& index, int role) const{
    if (!index.isValid() ||
            index.row() < 0 ||
            index.row() >= m_modelData.count()) {
        return QVariant();
    }
    Listing *listing = m_modelData.at(index.row());
    switch(role){
        case UrlRole:
        {
            return listing->url();
        }
        case NameRole:
        {
            return listing->name();
        }
        case BrandRole:
        {
            return listing->brand()->name();
        }
        case PriceRole:
        {
            return listing->formattedPx();
        }
        case DescriptionRole:
        {
            return listing->description();
        }
        case CategoryRole:
        {
            return listing->category()->name();
        }
        case BuyerRole:
        {
            return listing->buyer();
        }
        case ImageUrlRole:
        {
            return listing->imageUrl();
        }
        case ImageRole:
        {
            return _imgLoader->getImg(listing->imageUrl());
        }
        case ImagesRole:
        {
           QVariantList result;
           QList<QUrl> _imgs = listing->getImages();
           foreach (const QUrl& _image, _imgs) {
               result.append(_imgLoader->getImg(_image));
           }
           return result;
        }
        case ImageUrlsRole:
        {
            QVariantList result;
            QList<QUrl> _imgs = listing->getImages();
            foreach (const QUrl& _image, _imgs) {
                result.append(_image);
            }
            return result;
        }
    }
    return QVariant();
}

int ListingsModel::rowCount(const QModelIndex& index) const{
    Q_UNUSED(index);
    return m_modelData.count();
}
