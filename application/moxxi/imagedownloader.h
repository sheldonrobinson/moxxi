#ifndef IMAGEDOWNLOADER_H
#define IMAGEDOWNLOADER_H

# include <QObject>
# include <QImage>
# include <QtNetwork>
#include <QMap>

class  ImageDownloader: public  QObject
{
    Q_OBJECT

public :
    static  ImageDownloader * getInstance ();

    QImage getImg(const QUrl& url) const;
    QImage getImg(const QString& fileName) const;
    void  setImg (const QUrl& url, const QImage& i);
    void  setImg (const QString& fileName, const QImage& img);

signals:
    void  downloaded(const QUrl& url, bool success);

public  slots:
    void  downloadImg (const QUrl& url);
    void  downloadImg_finished (QNetworkReply * reply);
    void replyError(QNetworkReply::NetworkError err);
private :
     explicit ImageDownloader(QObject *parent = 0);
     static  ImageDownloader * imageDownloader;
     QNetworkAccessManager * nam;
     QMap<QUrl,QImage> _cache;

};

#endif // IMAGEDOWNLOADER_H
