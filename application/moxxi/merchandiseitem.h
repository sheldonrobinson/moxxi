#ifndef MERCHANDISEITEM_H
#define MERCHANDISEITEM_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QUrl>
#include <QJsonObject>

class MerchandiseItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString reference MEMBER _reference READ reference WRITE setReference NOTIFY referenceChanged)
    Q_PROPERTY( QVariantMap attributes READ attributes WRITE setAttributes NOTIFY attributesChanged)
    //Q_PROPERTY(QUrl image MEMBER _image READ image WRITE setImage NOTIFY imageChanged)


public:
    explicit MerchandiseItem(QObject *parent = 0);

    QString reference() const;
    void setReference(const QString& reference);

    QVariantMap attributes() const;
    void setAttributes(const QVariantMap& map);

    Q_INVOKABLE void setAttribute(const QString& key, const QVariant& value);


    //QUrl image() const;
    //void setImage(const QUrl& image);
signals:
    void referenceChanged();
    void attributesChanged();
    //void imageChanged(const QUrl& newImage);

public slots:

private:
    QString _reference;
    //QUrl _image;
    QJsonObject _attributes;

};

#endif // MERCHANDISEITEM_H
