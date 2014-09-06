#include "brand.h"

Brand::Brand(QObject *parent) :
    QObject(parent)
{
}

QString Brand::brandId() const { return _brandId;}
void Brand::setBrandId(const QString& brandId) { _brandId = brandId; emit brandIdChanged();}

QUrl  Brand::url() const {return _url;}
void  Brand::setUrl(const QUrl& url){ _url = url; emit urlChanged();}

QString  Brand::name() const {return _name;}
void  Brand::setName(const QString& name){ _name = name; emit nameChanged();}

QStringList Brand::synonyms() const { return _synonyms;}
bool Brand::removeSynonym(const QString& synonym){
    if(_synonyms.contains(synonym)){
        _synonyms.removeAll(synonym);
        emit synonymsChanged();
        return true;
    }
    return false;
}

bool Brand::addSynonym(const QString& synonym){
    if(!_synonyms.contains(synonym)){
        _synonyms.append(synonym);
        emit synonymsChanged();
        return true;
    }
    return false;
}
