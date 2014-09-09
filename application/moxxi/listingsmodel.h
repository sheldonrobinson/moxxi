#ifndef LISTINGSMODEL_H
#define LISTINGSMODEL_H

#include <QAbstractListModel>
#include "listing.h"
#include <QNetworkReply>
#include "imagedownloader.h"

class ListingsModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(bool isReady READ isReady)
    Q_PROPERTY(QUrl query READ query WRITE setQuery NOTIFY queryChanged)

    enum ListingsRoles {
        UrlRole = Qt::UserRole + 1,
        NameRole,
        BrandRole,
        PriceRole,
        DescriptionRole,
        CategoryRole,
        BuyerRole,
        ImageRole,
        ImagesRole,
        ImageUrlRole,
        ImageUrlsRole
    };


public:
    explicit ListingsModel(QObject *parent = 0);
    ~ListingsModel();

    bool isReady() const;
    void addListng(Listing *listing);
    QUrl query() const;
    void setQuery(const QUrl& query);

    virtual QHash<int, QByteArray> roleNames() const;

signals:
    void ready();
    void queryChanged();

public slots:
    void fetchData();
    void imageResult(const QUrl& url, bool success);
    void replyFinished(QNetworkReply* reply);
    void replyError(QNetworkReply::NetworkError err);

protected:
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;


private:


        QList<Listing*> m_modelData;            // Owned
        bool m_isReady;
        QUrl _query;
        QNetworkReply* _respones;
        QNetworkAccessManager* manager;
        ImageDownloader* _imgLoader;
        QUrl _imgUrl;

};

#endif // LISTINGSMODEL_H
