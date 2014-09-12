#ifndef LISTINGSMODEL_H
#define LISTINGSMODEL_H

#include <QAbstractListModel>
#include "listing.h"
#include <QNetworkReply>
#include "imagedownloader.h"

class ListingsModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(bool isReady READ isReady NOTIFY isReadyChanged)
    Q_PROPERTY(QUrl query READ query WRITE setQuery NOTIFY queryChanged)
    Q_PROPERTY(QString fts READ fts WRITE setFts NOTIFY queryChanged)
    Q_PROPERTY(int count READ count)

    enum ListingsRoles {
        UrlRole = Qt::UserRole + 1,
        NameRole,
        BrandRole,
        PriceRole,
        DescriptionRole,
        CategoryRole,
        BuyerRole,
        ImageUrlRole,
        ImageFileNameRole,
        ImageUrlsRole,
        ImageFileNamesRole,
        TweetRole,
        ImageUrlStringRole,
        ImageUrlsStringsRole
    };


public:
    explicit ListingsModel(QObject *parent = 0);
    ~ListingsModel();

    bool isReady() const;
    void addListng(Listing *listing);
    QUrl query() const;
    void setQuery(const QUrl& query);
    int count() const;
    QString fts() const;
    void setFts(const QString& terms);

    virtual QHash<int, QByteArray> roleNames() const;

signals:
    void isReadyChanged();
    void queryChanged();

public slots:
    void fetchData();
    void setApiKey(const QString& key);
    //void clearFts();
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
        QUrl _imgUrl;
        QString apiKey;

};

#endif // LISTINGSMODEL_H
