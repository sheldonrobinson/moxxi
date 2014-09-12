#ifndef LISTING_H
#define LISTING_H

#include <QObject>
#include <QMap>
#include <QStringList>
#include <QVariantMap>
#include <QUrl>
#include <QQmlListProperty>
#include <QImage>
#include <QLocale>
#include "category.h"
#include "brand.h"

class Listing : public QObject
{
    Q_OBJECT
    Q_ENUMS(Status Buyer)
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(QString listingId READ listingId NOTIFY listingIdChanged)
    Q_PROPERTY(Status status READ status NOTIFY statusChanged)
    Q_PROPERTY(QString shopId READ shopId NOTIFY shopIdChanged)
    Q_PROPERTY(Category* category READ category NOTIFY categoryChanged)
    Q_PROPERTY(Brand* brand READ brand NOTIFY brandChanged)
    Q_PROPERTY(QString currency READ currency NOTIFY pxChanged)
    Q_PROPERTY(QString decription READ description NOTIFY descriptionChanged)
    Q_PROPERTY(double px READ px NOTIFY pxChanged)
    Q_PROPERTY(double qty READ qty WRITE setQty NOTIFY qtyChanged)
    Q_PROPERTY(QVariantMap pricelist READ pricelist NOTIFY pricelistChanged)
    Q_PROPERTY(QStringList tags READ tags NOTIFY tagsChanged)
    Q_PROPERTY(QVariantMap materials READ materials NOTIFY materialsChanged)
    Q_PROPERTY(int views READ views NOTIFY viewsChanged)
    Q_PROPERTY(int faverors READ faverors NOTIFY faverorsChanged)
    //Q_PROPERTY(QString brand READ brand NOTIFY brandChanged)
    Q_PROPERTY(int year READ year NOTIFY yearChanged)
    Q_PROPERTY(Buyer buyer READ buyer NOTIFY buyerChanged)
    Q_PROPERTY(QStringList occasions READ occasions NOTIFY occasionsChanged)
    Q_PROPERTY(QStringList styles READ styles NOTIFY stylesChanged)
    Q_PROPERTY(QUrl url READ url NOTIFY urlChanged)
    Q_PROPERTY(QStringList aliases READ aliases NOTIFY aliasesChanged)
    Q_PROPERTY(QUrl imageUrl READ imageUrl NOTIFY imageUrlChanged)
    Q_PROPERTY(QQmlListProperty<QUrl> imageUrls READ imageUrls NOTIFY imageUrlsChanged)

public:
    explicit Listing(QObject *parent = 0);

    enum Status { active, removed, soldout, expired, custom, unavailable};
    enum Buyer {men, women, unisex, adults, teenboy, teengirls, teens, preteenboys, preteegirls, children, boys, girls, babyboy, babygirl, babies};

    QString name() const;
    void setName(const QString& name);
    QString listingId() const;
    void setListingId(const QString& listingId);
    Status status() const;
    void setStatus(Status status);
    QString shopId() const;
    void setShopId(const QString& shopId);
    Brand* brand() const;
    void setBrand(Brand* brand);
    Category* category() const;
    void setCategory(Category* category);
    QString description() const;
    void setDescription(const QString& desc);
    QString currency() const;
    void setCurrency(const QString& currency);
    double px()const;
    void setPx(double px);
    double qty() const;
    void setQty(double qty);
    QVariantMap pricelist() const;
    QStringList tags() const;

    QVariantMap materials() const;
    int views() const;
    void setViews(int views);
    //QString brand() const;
    //void setBrand(const QString& brand);
    int year() const;
    void setYear(int year);
    Buyer buyer() const;
    void setBuyer(Buyer buyer);
    QStringList occasions() const;

    QStringList styles() const;

    int faverors() const;
    void setFaverors(int faverors);

    QUrl url() const;
    void setUrl(const QUrl& url);
    QStringList aliases() const;
    QUrl imageUrl() const;
    void setImageUrl(const QUrl& url);
    QQmlListProperty<QUrl> imageUrls() const;


signals:
    void nameChanged();
    void listingIdChanged();
    void statusChanged();
    void shopIdChanged();
    void categoryChanged();
    void descriptionChanged();
    void pxChanged();
    void qtyChanged();
    void pricelistChanged();
    void tagsChanged();
    void materialsChanged();
    void viewsChanged();
    void brandChanged();
    void yearChanged();
    void buyerChanged();
    void occasionsChanged();
    void stylesChanged();
    void urlChanged();
    void aliasesChanged();
    void faverorsChanged();
    void imageUrlChanged();
    void imageUrlsChanged();

public slots:

    //bool updateCurrency(const QString& ccy);
    void removeStyle(const QString& style);
    void addStyle(const QString& style);
    void addAlias(const QString& alias);
    void removeAlias(const QString& alias);
    void removeOccasion(const QString& occasion);
    void addOccasion(const QString& occasion);
    void removeTag(const QString& tag);
    void addtag(const QString& tag);
    QList<QUrl> getImages() const;
    void addImage(const QUrl& url);
    void setLocale(const QString& locale);
    QString formattedPx() const;

protected:
    static int countOfImages(QQmlListProperty<QUrl> *list);
    static QUrl* imageAt(QQmlListProperty<QUrl> *list, int index);
    static void appendImage(QQmlListProperty<QUrl> *list, QUrl *value);
    static void clearImages(QQmlListProperty<QUrl> *list);
private:
    //void initCurrency();
    QLocale _locale;

    QList<QUrl> _images;
    QUrl _image;
    QString _name;
    QString _listingId;
    Status _status;
    Brand * _brand;
    QString _shopId;
    Category* _category;
    QString _currency;
    QString _currencySymbol;
    QString _description;
    double _qty;
    QStringList _tags;
    QMap<QString,double> _materials;
    QMap<QString, double> _pricelist;
    int _views;
    int _faverors;
    //QString _brand;
    int _brandyear;
    Buyer _buyer;
    QStringList _occasions;
    QStringList _styles;
    QUrl _url;
    QStringList _aliases;

};

#endif // LISTING_H
