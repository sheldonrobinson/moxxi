#ifndef CATEGORY_H
#define CATEGORY_H

#include <QObject>
#include <QStringList>

class Category : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString categoryId READ categoryId NOTIFY categoryIdChanged)
    Q_PROPERTY(QString parentid READ parentid NOTIFY parentidChanged)
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(QStringList alternatives READ alternatives NOTIFY alternativesChanged )

public:
    explicit Category(QObject *parent = 0);
    QString name() const;
    void setName(const QString& name);
    QString parentid() const;
    void setParentid(const QString& parentid);
    QString categoryId() const;
    void setCategoryId(const QString& categoryId);
    QStringList alternatives() const;


signals:
    void categoryIdChanged();
    void parentidChanged();
    void nameChanged();
    void alternativesChanged();

public slots:
    bool removeAlternative(const QString& alternative);
    bool addAlternative(const QString& alternative);
private:
    QString _name;
    QStringList _alternatives;
    QString _parentid;
    QString _categoryId;

};

#endif // CATEGORY_H
