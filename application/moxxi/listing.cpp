#include "listing.h"
#include <QLocale>

Listing::Listing(QObject *parent) :
    QObject(parent)
{
    initCurrency();
}

void Listing::initCurrency(){
    QLocale _locale;
    _currency = _locale.currencySymbol(QLocale::CurrencyIsoCode);
    _currencySymbol = _locale.currencySymbol(QLocale::CurrencySymbol);
}

bool Listing::updateCurrency(const QString& ccy){
    if(_pricelist.contains(ccy)){
        setCurrency(ccy);
        return true;
    }
    return false;
}

QString Listing::name() const { return _name;}
void Listing::setName(const QString& name) { _name =name; emit nameChanged();}
QString Listing::listingId() const { return _listingId;}
void Listing::setListingId(const QString& listingId) { _listingId=listingId; emit listingIdChanged();}
Listing::Status Listing::status() const { return _status;}
void Listing::setStatus( Listing::Status status) {_status =status; emit statusChanged();}
QString Listing::shopId() const { return _shopId;}
void Listing::setShopId(const QString& shopId) { _shopId = shopId; emit shopIdChanged();}
Category* Listing::category() const { return _category;}
void Listing::setCategory(Category* category) { _category = category; emit categoryChanged();}
Brand* Listing::brand() const { return _brand;}
void Listing::setBrand(Brand* brand) { _brand = brand; emit brandChanged();}
QString Listing::description() const{
    return _description;
}
void Listing::setDescription(const QString& desc){
    _description = desc;
    emit descriptionChanged();
}

QString Listing::currency() const { return _currency;}
void Listing::setCurrency(const QString& currency){ if(_currency!=currency){ _currency =currency; emit pxChanged();}}
double Listing::px()const {
    return (_pricelist.contains(_currency)) ? _pricelist[_currency]: 0.0;
}
void Listing::setPx(double px) {
    _pricelist.insert(_currency,px);
    emit pxChanged();
}
double Listing::qty() const { return _qty;}
void Listing::setQty(double qty) { _qty=qty; emit qtyChanged();}
QVariantMap Listing::pricelist() const {
    QVariantMap _result;
    QMapIterator<QString, double> i(_pricelist);
    while (i.hasNext()) {
        i.next();
        _result.insert(i.key(),i.value());
    }
    return _result;
}

QStringList Listing::tags() const{
    return _tags;
}
void Listing::removeTag(const QString& tag){
    _tags.removeAll(tag);
    emit tagsChanged();
}

void Listing::addtag(const QString& tag){
    _tags.append(tag);
    emit tagsChanged();
}

QVariantMap Listing::materials() const{
    QVariantMap _result;
    QMapIterator<QString, double> i(_materials);
    while (i.hasNext()) {
        i.next();
        _result.insert(i.key(),i.value());
    }
    return _result;
}
int Listing::views() const{
    return _views;
}
void Listing::setViews(int views){
    _views = views;
    emit viewsChanged();
}

int Listing::faverors() const{
    return _faverors;
}
void Listing::setFaverors(int faverors){
    _faverors = faverors;
    emit faverorsChanged();
}

//QString Listing::brand() const{
//    return _brand;
//}
//void Listing::setBrand(const QString& brand){
//    _brand = brand;
//    emit brandChanged();
//}

int Listing::year() const{
    return _brandyear;
}
void Listing::setYear(int year){
    _brandyear = year;
    emit yearChanged();
}

 Listing::Buyer Listing::buyer() const{
    return _buyer;
}
void Listing::setBuyer( Listing::Buyer buyer){
    _buyer = buyer;
    emit buyerChanged();
}

QStringList Listing::occasions() const{
    return _occasions;
}
void Listing::removeOccasion(const QString& occasion){
    _occasions.removeAll(occasion);
    emit occasionsChanged();
}

void Listing::addOccasion(const QString& occasion){
    _occasions.append(occasion);
    emit occasionsChanged();
}

QStringList Listing::styles() const{
    return _styles;
}
void Listing::removeStyle(const QString& style){
    _styles.removeAll(style);
    emit stylesChanged();
}

void Listing::addStyle(const QString& style){
    _styles.append(style);
    emit stylesChanged();
}

QUrl Listing::url() const {return _url;}
void Listing::setUrl(const QUrl& url){ _url = url; emit urlChanged();}

QStringList Listing::aliases() const {
    return _aliases;
}
void Listing::addAlias(const QString& alias){

    _aliases.append(alias);
    emit aliasesChanged();
}

void Listing::removeAlias(const QString& alias){
    _aliases.removeAll(alias);
    emit aliasesChanged();
}
