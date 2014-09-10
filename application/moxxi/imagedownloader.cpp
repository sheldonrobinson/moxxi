#include "imagedownloader.h"
#include <QNetworkReply>

ImageDownloader::ImageDownloader(QObject *parent) :
    QObject(parent)
{
}

// Init
ImageDownloader* ImageDownloader::imageDownloader = NULL;

ImageDownloader* ImageDownloader::getInstance ()
{
    if  (NULL == imageDownloader)
    {
        imageDownloader = new  ImageDownloader;
        imageDownloader->nam = new  QNetworkAccessManager ( imageDownloader );
        connect (imageDownloader->nam, SIGNAL (finished (QNetworkReply *)), imageDownloader , SLOT (downloadImg_finished (QNetworkReply *)));
    }
    return  imageDownloader;
}

void ImageDownloader::replyError(QNetworkReply::NetworkError err){
    qDebug()<<"ImageDownloader::QNetworkReply::NetworkError";
    qDebug()<<"Error: "<< err;

}

void  ImageDownloader::downloadImg (const QUrl& url)
{
    QNetworkRequest request(url);
    QNetworkReply* reply = nam->get(request);
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(replyError(QNetworkReply::NetworkError)));
  //  QEventLoop eventLoop;
  //  connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
  //  eventLoop.exec();
}

QImage ImageDownloader::getImg(const QUrl& url) const {
    return getImg(url.fileName());
}

QImage ImageDownloader::getImg(const QString& fileName) const {
    if(_cache.contains(fileName)){
        return _cache[fileName];
    }
    return QImage();
}


void  ImageDownloader::setImg (const QUrl& url, const QImage& img) {setImg(url.fileName(),img);}
void  ImageDownloader::setImg (const QString& fileName, const QImage& img) {_cache.insert(fileName,img);}

void  ImageDownloader :: downloadImg_finished (QNetworkReply * reply)
{
    reply-> open (QIODevice :: ReadOnly);

    if (reply-> error() == QNetworkReply::NoError)
    {
        QByteArray b = reply-> readAll ();
        QImage imgTmp;
        imgTmp.loadFromData (b);
        _cache.insert(reply->url().fileName(),imgTmp);
        //ImageDownloader::getInstance()->setImg(imgTmp);
         emit downloaded(reply->url(),true);
    }
    else
    {
        qDebug () << reply-> errorString ();
        emit downloaded(reply->url(), false);
    }
}
