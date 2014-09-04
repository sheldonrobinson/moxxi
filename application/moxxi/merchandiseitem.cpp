#include "merchandiseitem.h"
#include <QJsonValue>

MerchandiseItem::MerchandiseItem(QObject *parent) :
    QObject(parent)
{
}

QString MerchandiseItem::reference() const{
    return _reference;
}

void MerchandiseItem::setReference(const QString& reference){
    if(_reference != reference)
        _reference = reference;
    emit referenceChanged();
}

QVariantMap MerchandiseItem::attributes() const {
    return _attributes.toVariantMap();
}

void MerchandiseItem::setAttributes(const QVariantMap& map){
    _attributes.fromVariantMap(map);
    emit attributesChanged();
}

void MerchandiseItem::setAttribute(const QString& key, const QVariant& value){
    _attributes.insert(key,QJsonValue::fromVariant(value));
    emit attributesChanged();
}



/*QUrl MerchandiseItem::image() const {
    return _image;
}
void MerchandiseItem::setImage(const QUrl& image){
    _image = image;
}*/
