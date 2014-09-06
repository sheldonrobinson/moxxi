#ifndef BRAND_H
#define BRAND_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QUrl>

class Brand : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(QStringList synonyms READ synonyms NOTIFY synonymsChanged)
    Q_PROPERTY(QUrl url READ url NOTIFY urlChanged)
    Q_PROPERTY(QString brandId READ brandId NOTIFY brandIdChanged)
public:
    explicit Brand(QObject *parent = 0);

    QString name() const;
    void setName(const QString& name);
    QString brandId() const;
    void setBrandId(const QString& brandId);
    QUrl url() const;
    void setUrl(const QUrl& url);
    QStringList synonyms() const;


signals:
    void nameChanged();
    void urlChanged();
    void synonymsChanged();
    void brandIdChanged();
public slots:
    bool removeSynonym(const QString& synonym);
    bool addSynonym(const QString& synonym);
private:
    QString _brandId;
    QUrl _url;
    QStringList _synonyms;
    QString _name;

};

#endif // BRAND_H
