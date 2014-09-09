#ifndef IMAGEDOWNLOADER_H
#define IMAGEDOWNLOADER_H

# include <QObject>
# include <QImage>
# include <QtNetwork>
#include <QMap>

class  ImageDownloader: public  QObject
{
    Q_OBJECT
public:
    explicit ImageDownloader(QObject *parent);


signals:
    void  downloaded(const QUrl& url, bool success);

public :
    //static  ImageDownloader * getInstance ();

    QImage getImg(const QUrl& url) const;
    void  setImg (const QUrl& url, const QImage& i);

public  slots:
    void  downloadImg (const QUrl& url);
    void  downloadImg_finished (QNetworkReply * reply);
    void replyError(QNetworkReply::NetworkError err);
private :
//    static  ImageDownloader * imageDownloader;

    QMap<QUrl,QImage> _cache;

};

#endif // IMAGEDOWNLOADER_H
