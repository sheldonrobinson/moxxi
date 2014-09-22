#include "listingsmodel.h"
#include <QLocale>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QLocale>
#include <QNetworkRequest>
#include <QUrlQuery>
#include <QModelIndex>



ListingsModel::ListingsModel(QObject *parent) :
    QAbstractListModel(parent),m_isReady(false)
{
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));

}

int ListingsModel::count() const { return m_modelData.size();}

void ListingsModel::imageResult(const QUrl& url, bool success){
    Q_UNUSED(url);
    Q_UNUSED(success);
}

QHash<int, QByteArray> ListingsModel::roleNames() const {
    // QML uses role names when accessing properties from model
    QHash<int, QByteArray> roles;
    roles[UrlRole] = "listingUrl";
    roles[NameRole] = "listingName";
    roles[BrandRole] = "listingBrand";
    roles[PriceRole] = "listingPrice";
    roles[DescriptionRole] = "listingDescription";
    roles[CategoryRole] = "listingCategory";
    roles[BuyerRole] = "listingBuyer";
    roles[ImageUrlRole]="listingImageUrl";
    roles[ImageFileNameRole] = "listingImageFileName";
    roles[ImageUrlsRole]="listingImageUrls";
    roles[ImageFileNamesRole] = "listingImageFileNames";
    roles[TweetRole] = "listingTweet";
    roles[ImageUrlStringRole]="listingImageUrlString";
    roles[ImageUrlsStringsRole]="listingImageUrlsStrings";


    return roles;
}

void ListingsModel::replyFinished(QNetworkReply* reply){
    if(reply-> error() == QNetworkReply::NoError)
    {
        //QModelIndex start = start();
        //QModelIndex end = end();
        beginResetModel();
        m_modelData.clear();
        QString strReply = (QString) reply->readAll();
        QJsonDocument jsonResponse  = QJsonDocument::fromJson(strReply.toUtf8());
        QJsonObject jsonObject = jsonResponse.object();

        QJsonArray jsonArray = jsonObject["products"].toArray();
        foreach (const QJsonValue & value, jsonArray)
        {

            QJsonObject obj = value.toObject();
            Listing* listing = new Listing(this);
            listing->setListingId(obj["id"].toString());
            listing->setName(obj["brandedName"].toString());
            listing->setDescription(obj["description"].toString());
            listing->setUrl(QUrl(obj["pageUrl"].toString()));
            QUrl url(obj["image"].toObject()["sizes"].toObject()["IPhone"].toObject()["url"].toString());
            listing->setImageUrl(url);
            QLocale _locale(obj["locale"].toString());
            listing->setCurrency(_locale.currencySymbol(QLocale::CurrencyIsoCode));
            QString  _px(obj["priceLabel"].toString());
            QString _sym(_locale.currencySymbol(QLocale::CurrencySymbol));
            bool result;
            listing->setPx(_locale.toDouble(_px.remove(_sym),&result));
            if(!result){
                qDebug()<<"Unable to convert price "<<_px;
            }
            QJsonArray imgs = obj["alternateImages"].toArray();
            foreach (const QJsonValue & altimg, imgs){
                QJsonObject objImg = altimg.toObject();
                QUrl _url(altimg.toObject()["sizes"].toObject()["IPhone"].toObject()["url"].toString());
                if(_url.isValid()){
                    listing->addImage(_url);
                }
            }
            listing->setShopId(obj["retailer"].toObject()["id"].toString());

            m_modelData.append(listing);
        }
        //QModelIndex start; QModelIndex end;
        endResetModel();
    }
    m_isReady =true;
    emit isReadyChanged();
}



ListingsModel::~ListingsModel(){
    qDeleteAll(m_modelData);
    delete manager;
}

void ListingsModel::replyError(QNetworkReply::NetworkError err){
    qDebug()<<"ListingsModel::QNetworkReply::NetworkError";
    qDebug()<<"Error from query "<< err;
    m_isReady = true;
    emit isReadyChanged();
}

/*!
   Whether the model is done fetching media information.
*/
bool ListingsModel::isReady() const
{
    return m_isReady;
}

QUrl ListingsModel::query() const { return _query;}
void ListingsModel::setQuery(const QUrl& query) {
    if(_query != query)
    {

        _query =query; emit queryChanged();
    }
}
QString ListingsModel::fts() const {
    if(_query.isValid() && _query.hasQuery()){
        QUrlQuery queryPart(_query);
        QStringList fts = queryPart.allQueryItemValues("fts",QUrl::FullyDecoded);
        QString result;
        foreach (QString part, fts) {
            result.append(part).append(" ");
        }
        return result.replace('+',' ').trimmed();
    }
        return QString();
}
void ListingsModel::setApiKey(const QString& key){
    apiKey = key;
}

void ListingsModel::setFts(const QString &terms){
    QUrlQuery queryPart;
    queryPart.addQueryItem("pid",apiKey);
    queryPart.addQueryItem("offset","0");
    queryPart.addQueryItem("limit","100");
    QString _temp(terms);
    queryPart.addQueryItem("fts",_temp.replace(' ','+').toUpper());
    QUrl _myurl("http://api.shopstyle.com/api/v2/products");
    _myurl.setQuery(queryPart);
    setQuery(_myurl);
}

void ListingsModel::fetchData() {
    m_isReady = false;
    if(_query.isValid()){

        QNetworkReply *reply = manager->get(QNetworkRequest(_query));
        connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
                this, SLOT(replyError(QNetworkReply::NetworkError)));
//        QEventLoop eventLoop;
//        connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
//        eventLoop.exec();
    }else{
        m_isReady=true;
        emit isReadyChanged();
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
        case ImageUrlStringRole:
        {
            return listing->imageUrl().url();
        }
        case ImageFileNameRole:
        {
            return listing->imageUrl().fileName();
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
        case ImageUrlsStringsRole:
        {
            QStringList result;
            QList<QUrl> _imgs = listing->getImages();
            foreach (const QUrl& _image, _imgs) {
                result.append(_image.url());
            }
            return result;
        }
        case ImageFileNamesRole:
        {
            QVariantList result;
            QList<QUrl> _imgs = listing->getImages();
            foreach (const QUrl& _image, _imgs) {
                result.append(_image.fileName());
            }
            return result;
        }
            case TweetRole:
            {
                //int len = listing->name().length();
                QString desc(listing->description().remove("<ul>").remove("</ul>").remove("<p>").remove("</p>").replace("</li>",".").replace("<li>","*").trimmed());
                //QString tweet("<h1><b>"+listing->name()+"</b></h1><p>"+desc);
                return desc;
            }
    }
    return QVariant();
}

int ListingsModel::rowCount(const QModelIndex& index) const{
    Q_UNUSED(index);
    return m_modelData.count();
}

void ListingsModel::addListng(Listing *listing){
    m_modelData.append(listing);
}
