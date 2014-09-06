#ifndef SHOP_H
#define SHOP_H

#include <QObject>
#include "listing.h"
#include <QImage>
#include <QQmlListProperty>
#include <QSet>

class Shop : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString shopId READ shopId NOTIFY shopIdChanged)
    Q_PROPERTY(QQmlListProperty<Listing> listings READ listings NOTIFY listingsChanged)
    //Q_PROPERTY(QQmlListProperty<Listing::Buyer> buyers READ buyers NOTIFY listingsChanged)
    Q_PROPERTY(QQmlListProperty<QString> styles READ styles NOTIFY listingsChanged)
    Q_PROPERTY(QQmlListProperty<QString> locations READ locations NOTIFY listingsChanged)
    Q_PROPERTY(QQmlListProperty<QString> brands READ brands NOTIFY listingsChanged)
    Q_PROPERTY(QUrl url READ url NOTIFY urlChanged)
    Q_PROPERTY(QStringList aliases READ aliases NOTIFY listingsChanged)
    Q_PROPERTY(QQmlListProperty<QString> occasions READ occasions NOTIFY listingsChanged)
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
public:
    explicit Shop(QObject *parent = 0);
    QString shopId() const;
    void setShopId(const QString& shopId);
    QUrl url() const;
    void setUrl(const QUrl& url);
    QStringList aliases() const;
    void addAlias(const QString& alias);
    void removeAlias(const QString& alias);
    QString name() const;
    void setName(const QString& name);
    QQmlListProperty<QString> occasions() const;
    QQmlListProperty<QString> brands() const;
    //QQmlListProperty<Listing::Buyer> buyers() const;
    QQmlListProperty<QString> locations() const;
    QQmlListProperty<QString> styles() const;
    QQmlListProperty<Listing> listings() const;



signals:
    void urlChanged();
    void aliasesChanged();
    void shopIdChanged();
    void listingsChanged();
    //void buyersChanged();
    //void stylesChanged();
    //void locationsChanged();
    //void brandsChanged();
    //void occasionsChanged();
    void nameChanged();

public slots:

private:
    QString _shopId;
    QUrl _url;
    QStringList _aliases;
    QString _name;
    QList<Listing*> _listings;
    QList<QString*> _styles;
    QList<QString*> _occasions;
    QList<QString*> _brands;
    QList<QString*> _locations;

    static int countOfListings(QQmlListProperty<Listing> *list);
    //int countOfBuyers(QQmlListProperty<Listing::Buyer> *list);
    static int countOfStyles(QQmlListProperty<QString> *list);
    static int countOfLocations(QQmlListProperty<QString> *list);
    static int countOfBrands(QQmlListProperty<QString> *list);
    static int countOfOccasions(QQmlListProperty<QString> *list);

    static Listing* listingAt(QQmlListProperty<Listing> *list, int index);
    //Listing::Buyer* buyerAt(QQmlListProperty<Listing::Buyer> *list, int index);
    static QString* styleAt(QQmlListProperty<QString> *list, int index);
    static QString* locationAt(QQmlListProperty<QString> *list, int index);
    static QString* brandAt(QQmlListProperty<QString> *list, int index);
    static QString* occasionAt(QQmlListProperty<QString> *list, int index);

    static void appendListing(QQmlListProperty<Listing> *list, Listing *value);
    //void appendLocation(QQmlListProperty<QString> *list, QString *value);
    //void appendBrand(QQmlListProperty<QString> *list, QString *value);
    //void appendOccasion(QQmlListProperty<QString> *list, QString *value);
    //void appendStyle(QQmlListProperty<QString> *list, QString *value);

    static void clearListings(QQmlListProperty<Listing> *list);
    //void clearLocations(QQmlListProperty<QString> *list);
    //void clearBrands(QQmlListProperty<QString> *list);
    //void clearOccasions(QQmlListProperty<QString> *list);
    //void clearStyles(QQmlListProperty<QString> *list);

};

#endif // SHOP_H
