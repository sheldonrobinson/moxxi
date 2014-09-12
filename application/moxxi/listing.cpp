#include "listing.h"
#include <QLocale>

Listing::Listing(QObject *parent) :
    QObject(parent)
{
//    initCurrency();
    _locale=QLocale::system();
}

void Listing::setLocale(const QString& locale){
    _locale = QLocale(locale);
}


QString Listing::name() const { return _name;}
void Listing::setName(const QString& name) { if(_name != name){_name =name; emit nameChanged();}}
QString Listing::listingId() const { return _listingId;}
void Listing::setListingId(const QString& listingId) { if(_listingId != listingId){ _listingId=listingId; emit listingIdChanged();}}
Listing::Status Listing::status() const { return _status;}
void Listing::setStatus( Listing::Status status) {if(_status != status){_status =status; emit statusChanged();}}
QString Listing::shopId() const { return _shopId;}
void Listing::setShopId(const QString& shopId) { _shopId = shopId; emit shopIdChanged();}
Category* Listing::category() const { return _category;}
void Listing::setCategory(Category* category) { if(_category != category){_category = category; emit categoryChanged();}}
Brand* Listing::brand() const { return _brand;}
void Listing::setBrand(Brand* brand) { if(_brand != brand){_brand = brand; emit brandChanged();}}
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

    if(_pricelist.contains(_currency)){
       return _pricelist[_currency];
    }else if(_pricelist.contains(_locale.currencySymbol(QLocale::CurrencyIsoCode))){
        return _pricelist[_locale.currencySymbol(QLocale::CurrencyIsoCode)];
    }else if(_pricelist.contains(QLocale::system().currencySymbol(QLocale::CurrencyIsoCode))){
        return _pricelist[QLocale::system().currencySymbol(QLocale::CurrencyIsoCode)];
    }
    return 0.0;
}

QString Listing::formattedPx() const{
   return _locale.toCurrencyString(px(), _locale.currencySymbol(QLocale::CurrencySymbol));
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
    if(_views != views){
    _views = views;
    emit viewsChanged();
    }
}

int Listing::faverors() const{
    return _faverors;
}
void Listing::setFaverors(int faverors){
    if(_faverors != faverors){
    _faverors = faverors;
    emit faverorsChanged();
    }
}


int Listing::year() const{
    return _brandyear;
}
void Listing::setYear(int year){
    if(_brandyear != year){
    _brandyear = year;
    emit yearChanged();
    }
}

 Listing::Buyer Listing::buyer() const{
    return _buyer;
}
void Listing::setBuyer( Listing::Buyer buyer){
    if(_buyer != buyer){
    _buyer = buyer;
    emit buyerChanged();
    }
}

QStringList Listing::occasions() const{
    return _occasions;
}
void Listing::removeOccasion(const QString& occasion){
    if(_occasions.contains(occasion)){
    _occasions.removeAll(occasion);
    emit occasionsChanged();
    }
}

void Listing::addOccasion(const QString& occasion){
    if(!_occasions.contains(occasion)){
    _occasions.append(occasion);
    emit occasionsChanged();
    }
}

QStringList Listing::styles() const{
    return _styles;
}
void Listing::removeStyle(const QString& style){
    if(_styles.contains(style)){
    _styles.removeAll(style);
    emit stylesChanged();
    }
}

void Listing::addStyle(const QString& style){
    if(!_styles.contains(style)){
    _styles.append(style);
    emit stylesChanged();
    }
}

QUrl Listing::url() const {return _url;}
void Listing::setUrl(const QUrl& url){ if(_url != url){_url = url; emit urlChanged();}}

QStringList Listing::aliases() const {
    return _aliases;
}
void Listing::addAlias(const QString& alias){
    if(!_aliases.contains(alias)){
    _aliases.append(alias);
    emit aliasesChanged();
    }
}

void Listing::removeAlias(const QString& alias){
    if(_aliases.contains(alias)){
    _aliases.removeAll(alias);
    emit aliasesChanged();
    }
}

int Listing::countOfImages(QQmlListProperty<QUrl> *list){
    Listing* obj = qobject_cast<Listing *>(list->object);
    return obj->_images.count();
}
QUrl* Listing::imageAt(QQmlListProperty<QUrl> *list, int index){
    Listing* obj = qobject_cast<Listing *>(list->object);
    return new QUrl(obj->_images.at(index));
}
void Listing::appendImage(QQmlListProperty<QUrl> *list, QUrl *value){
    Listing* obj = qobject_cast<Listing *>(list->object);
    if(! obj->_images.contains(value->url())){
        obj->_images.append(value->url());
        emit obj->imageUrlsChanged();
    }
}
void Listing::clearImages(QQmlListProperty<QUrl> *list){
    Listing* obj = qobject_cast<Listing *>(list->object);
        obj->_images.clear();
        emit  obj->imageUrlsChanged();
}

QUrl Listing::imageUrl() const{
    return _image;
}
void Listing::setImageUrl(const QUrl& image){
    _image = image;
    emit imageUrlChanged();
}

QQmlListProperty<QUrl> Listing::imageUrls() const{
    return QQmlListProperty<QUrl>(const_cast<Listing*>(this),const_cast<QList<QUrl>*>(&_images), &Listing::appendImage, &Listing::countOfImages, &Listing::imageAt,&Listing::clearImages);
}

QList<QUrl> Listing::getImages() const {
    return _images;
}

void Listing::addImage(const QUrl& url){
    _images.append(url);
}

