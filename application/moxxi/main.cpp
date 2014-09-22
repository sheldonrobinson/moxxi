#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QtQml>
#include <QQuickWindow>
#include <QScreen>
#include "shop.h"
#include "listingsmodel.h"
#include "listingsimageprovider.h"

QString API_KEY("uid9009-25612247-65");

int main(int argc, char *argv[])
{
    qmlRegisterType<Brand>("Moxxi",1,0,"Brand");
    qmlRegisterType<Category>("Moxxi",1,0,"Category");
    qmlRegisterType<Listing>("Moxxi",1,0,"Listing");
    qmlRegisterType<Shop>("Moxxi",1,0,"Shop");
    qmlRegisterType<QAbstractItemModel>();
    qmlRegisterType<QAbstractListModel>();
    qmlRegisterType<ListingsModel>("Moxxi",1,0,"ListingsModel");
    QGuiApplication app(argc, argv);
    ListingsModel* model = new ListingsModel();
    QObject::connect(model,&ListingsModel::queryChanged, model,&ListingsModel::fetchData);
    QQmlApplicationEngine engine;
    QScreen *screen = QGuiApplication::primaryScreen();
    engine.rootContext()->setContextProperty("theModel",model);
    engine.rootContext()->setContextProperty("screenheight",screen->availableSize().height());
    engine.rootContext()->setContextProperty("screenwidth",screen->availableSize().width());
    model->setApiKey("uid9009-25612247-65");
    model->setFts("dress");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    int retvalue = app.exec();
    return retvalue;
}
