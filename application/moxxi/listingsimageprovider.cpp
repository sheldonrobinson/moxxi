#include "listingsimageprovider.h"
#include "imagedownloader.h"

ListingsImageProvider::ListingsImageProvider() :
    QQuickImageProvider (ImageType::Image)
{
}
QImage ListingsImageProvider::requestImage(const QString & id, QSize * size, const QSize & requestedSize){
    Q_UNUSED(requestedSize);
    QImage pic = ImageDownloader::getInstance()->getImg(QUrl(id));
    if(size){
        *size = pic.size();
    }
   return pic;
}
