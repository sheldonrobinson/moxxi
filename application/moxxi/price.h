#ifndef PRICE_H
#define PRICE_H

#include <QObject>
#include <QLocale>

class Price: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QLocale locale READ locale NOTIFY localeChanged)
    Q_PROPERTY(double px READ px NOTIFY pxChanged)
    Q_PROPERTY(QString currency READ currency NOTIFY localeChanged)
    Q_PROPERTY(QString symbol READ symbol NOTIFY localeChanged)
public:
    explicit Price(QObject *parent = 0);

    QLocale locale() const;
    void setLocale(const QLocale& locale);
    double px() const;
    void setPx(double px);
    QString currency() const;
    QString symbol() const;

signals:
    void localeChanged();
    void pxChanged();
public slots:
    QString formattedPx() const;

private:
    QLocale _locale;
    double _px;

};

#endif // PRICE_H
