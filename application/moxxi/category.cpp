#include "category.h"

Category::Category(QObject *parent) :
    QObject(parent)
{
}

QString Category::name() const{ return _name;}
void Category::setName(const QString& name) { _name=name; emit nameChanged();}
QString Category::parentid() const{ return _parentid;}
void Category::setParentid(const QString& parentid){ _parentid= parentid; emit parentidChanged();}
QString Category::categoryId() const { return _categoryId;}
void Category::setCategoryId(const QString& categoryId) { _categoryId = categoryId; emit categoryIdChanged();}
QStringList Category::alternatives() const { return _alternatives;}
bool Category::removeAlternative(const QString& alternative){
    if(_alternatives.contains(alternative)){
        _alternatives.removeAll(alternative);
        emit alternativesChanged();
        return true;
    }
    return false;
}

bool Category::addAlternative(const QString& alternative){
    if(!_alternatives.contains(alternative)){
        _alternatives.append(alternative);
        emit alternativesChanged();
        return true;
    }
    return false;
}
