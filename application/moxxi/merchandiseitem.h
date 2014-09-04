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
    Q_PROPERTY(QString name MEMBER _name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY( QVariantMap attributes READ attributes WRITE setAttributes NOTIFY attributesChanged)
    //Q_PROPERTY(QUrl image MEMBER _image READ image WRITE setImage NOTIFY imageChanged)


public:
    explicit MerchandiseItem(QObject *parent = 0);

    QString name() const;
    void setName(const QString& name);

    QVariantMap attributes() const;
    void setAttributes(const QVariantMap& map);

    Q_INVOKABLE void setAttribute(const QString& key, const QVariant& value);


    //QUrl image() const;
    //void setImage(const QUrl& image);
signals:
    void nameChanged();
    void attributesChanged();
    //void imageChanged(const QUrl& newImage);

public slots:

private:
    QString _name;
    //QUrl _image;
    QJsonObject _attributes;

};

#endif // MERCHANDISEITEM_H
