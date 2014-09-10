#ifndef LISTINGSIMAGEPROVIDER_H
#define LISTINGSIMAGEPROVIDER_H

#include <QQuickImageProvider>

class ListingsImageProvider : public QQuickImageProvider
{
public:
    explicit ListingsImageProvider();

    virtual QImage requestImage(const QString & id, QSize * size, const QSize & requestedSize);

signals:

public slots:

};

#endif // LISTINGSIMAGEPROVIDER_H
