#include "shop.h"
#include <QSet>

Shop::Shop(QObject *parent) :
    QObject(parent)
{

}

QString Shop::shopId() const {
    return _shopId;
}

void Shop::setShopId(const QString& shopId){
    _shopId = shopId;
    emit shopIdChanged();
}

QUrl  Shop::url() const {return _url;}
void  Shop::setUrl(const QUrl& url){ _url = url; emit urlChanged();}

QString  Shop::name() const {return _name;}
void  Shop::setName(const QString& name){ _name = name; emit nameChanged();}

QStringList Shop::aliases() const {
    return _aliases;
}
void Shop::addAlias(const QString& alias){

    _aliases.append(alias);
    emit aliasesChanged();
}

void Shop::removeAlias(const QString& alias){
    _aliases.removeAll(alias);
    emit aliasesChanged();
}

int Shop::countOfListings(QQmlListProperty<Listing> *list){
    Shop* obj = qobject_cast<Shop *>(list->object);
    return obj->_listings.count();
}

int Shop::countOfStyles(QQmlListProperty<QString> *list){
    Shop* obj = qobject_cast<Shop *>(list->object);
    return obj->_styles.count();
}
int Shop::countOfLocations(QQmlListProperty<QString> *list){
    Shop* obj = qobject_cast<Shop *>(list->object);
    return obj->_locations.count();
}
int Shop::countOfBrands(QQmlListProperty<QString> *list){
    Shop* obj = qobject_cast<Shop *>(list->object);
    return obj->_brands.count();
}
int Shop::countOfOccasions(QQmlListProperty<QString> *list){
    Shop* obj = qobject_cast<Shop *>(list->object);
    return obj->_occasions.count();
}

Listing* Shop::listingAt(QQmlListProperty<Listing> *list, int index){
    Shop* obj = qobject_cast<Shop *>(list->object);
    return obj->_listings.at(index);
}
QString* Shop::styleAt(QQmlListProperty<QString> *list, int index){
    Shop* obj = qobject_cast<Shop *>(list->object);
    return obj->_styles.at(index);
}

QString* Shop::locationAt(QQmlListProperty<QString> *list, int index){
    Shop* obj = qobject_cast<Shop *>(list->object);
    return obj->_locations.at(index);
}

QString* Shop::brandAt(QQmlListProperty<QString> *list, int index){
    Shop* obj = qobject_cast<Shop *>(list->object);
    return obj->_brands.at(index);
}

QString* Shop::occasionAt(QQmlListProperty<QString> *list, int index){
    Shop* obj = qobject_cast<Shop *>(list->object);
    return obj->_occasions.at(index);
}


void Shop::appendListing(QQmlListProperty<Listing> *list, Listing *value){
    Shop* obj = qobject_cast<Shop *>(list->object);
    if(! obj->_listings.contains(value)){
        obj->_listings.append(value);
        emit obj->listingsChanged();
    }
}

//void Shop::appendLocation(QQmlListProperty<QString> *list, QString *value);
//void Shop::appendBrand(QQmlListProperty<QString> *list, QString *value);
//void Shop::appendOccasion(QQmlListProperty<QString> *list, QString *value);
//void Shop::appendStyle(QQmlListProperty<QString> *list, QString *value);

void Shop::clearListings(QQmlListProperty<Listing> *list){
    Shop* obj = qobject_cast<Shop *>(list->object);
        obj->_listings.clear();
        emit  obj->listingsChanged();
}
//void Shop::clearLocations(QQmlListProperty<QString> *list);
//void Shop::clearBrands(QQmlListProperty<QString> *list);
//void Shop::clearOccasions(QQmlListProperty<QString> *list);
//void Shop::clearStyles(QQmlListProperty<QString> *list);

QQmlListProperty<Listing> Shop::listings() const{
    return QQmlListProperty<Listing>(const_cast<Shop*>(this),const_cast<QList<Listing*>*>(&_listings), &Shop::appendListing, &Shop::countOfListings, &Shop::listingAt,&Shop::clearListings);
}

QQmlListProperty<QString> Shop::styles() const{
    return QQmlListProperty<QString>(const_cast<Shop*>(this),const_cast<QList<QString*>*>(&_styles), &Shop::countOfStyles, &Shop::styleAt);
}

QQmlListProperty<QString> Shop::locations() const{
    return QQmlListProperty<QString>(const_cast<Shop*>(this),const_cast<QList<QString*>*>(&_locations), &Shop::countOfLocations, &Shop::locationAt);
}

QQmlListProperty<QString> Shop::brands() const{
    return QQmlListProperty<QString>(const_cast<Shop*>(this),const_cast<QList<QString*>*>(&_brands), &Shop::countOfBrands, &Shop::brandAt);
}

QQmlListProperty<QString> Shop::occasions() const{
    return QQmlListProperty<QString>(const_cast<Shop*>(this),const_cast<QList<QString*>*>(&_occasions), &Shop::countOfOccasions, &Shop::occasionAt);
}
