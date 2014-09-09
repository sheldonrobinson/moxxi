#include "imagedownloader.h"
#include <QNetworkReply>

ImageDownloader::ImageDownloader(QObject *parent) :
    QObject(parent)
{
}

// Init
//ImageDownloader* ImageDownloader::imageDownloader = NULL;

//ImageDownloader* ImageDownloader::getInstance ()
//{
//    if  (NULL == imageDownloader)
//    {
//        imageDownloader = new  ImageDownloader;
//    }
//    return  imageDownloader;
//}

void ImageDownloader::replyError(QNetworkReply::NetworkError err){
    qDebug()<<"ImageDownloader::QNetworkReply::NetworkError";
    qDebug()<<"Error: "<< err;

}

void  ImageDownloader::downloadImg (const QUrl& url)
{
    QNetworkAccessManager * nam;
    nam = new  QNetworkAccessManager ( this );
    connect (nam, SIGNAL (finished (QNetworkReply *)), this , SLOT (downloadImg_finished (QNetworkReply *)));

    QNetworkRequest request(url);

    QNetworkReply* reply = nam->get(request);
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(replyError(QNetworkReply::NetworkError)));
}
QImage ImageDownloader::getImg(const QUrl& url) const {
    if(_cache.contains(url)){
        return _cache[url];
    }
    return QImage();
 }
void  ImageDownloader::setImg (const QUrl& url, const QImage& img) {_cache.insert(url,img);}
void  ImageDownloader :: downloadImg_finished (QNetworkReply * reply)
{
    reply-> open (QIODevice :: ReadOnly);

    if (reply-> error() == QNetworkReply::NoError)
    {
        QByteArray b = reply-> readAll ();
        QImage imgTmp;
        imgTmp.loadFromData (b);
        _cache.insert(reply->url(),imgTmp);
        //ImageDownloader::getInstance()->setImg(imgTmp);
         emit downloaded(reply->url(),true);
    }
    else
    {
        qDebug () << reply-> errorString ();
        emit downloaded(reply->url(), false);
    }
}
