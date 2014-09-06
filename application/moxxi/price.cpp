#include "price.h"

Price::Price(QObject *parent) :
    QObject(parent)
{

}

QLocale Price::locale() const{return _locale;}

void Price::setLocale(const QLocale& locale){
    _locale = locale;
    emit localeChanged();
}

double Price::px() const{
    return _px;
}
void Price::setPx(double px){
    _px =px;
    emit pxChanged();
}

QString Price::currency() const{
    return _locale.currencySymbol( QLocale::CurrencySymbolFormat::CurrencyIsoCode);
}
QString Price::symbol() const{
    return _locale.currencySymbol( QLocale::CurrencySymbolFormat::CurrencySymbol);
}

QString Price::formattedPx() const{
    return currency() + " " + symbol() + QString("%L1").arg(_px, 0, 'f', 2);
}
