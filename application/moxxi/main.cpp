#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QtQml>
#include <QQuickWindow>
#include "shop.h"
#include "listingsmodel.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<Brand>("Moxxi",1,0,"Brand");
    qmlRegisterType<Category>("Moxxi",1,0,"Category");
    qmlRegisterType<Listing>("Moxxi",1,0,"Listing");
    qmlRegisterType<Shop>("Moxxi",1,0,"Shop");
    qmlRegisterType<QAbstractItemModel>();
    qmlRegisterType<ListingsModel>("Moxxi",1,0,"ListingsModel");

    ListingsModel model;
    QUrl query("http://api.shopstyle.com/api/v2/products?pid=uid9009-25612247-65&fts=red+dress&offset=0&limit=10");
    model.setQuery(query);
    model.fetchData();
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("theModel",&model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    //QQuickView viewer;
    //viewer.rootContext()->setContextProperty("listingsModel", &model);
    //viewer.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    //viewer.showFullScreen();
    // Create Component:
    //QQmlComponent *component = new QQmlComponent(&engine);
     //component->loadUrl(QUrl(QStringLiteral("qrc:/main.qml")));
     // Display Window:
     //QObject *topLevel = component->create();
     //QQuickWindow *window = qobject_cast<QQuickWindow*>(topLevel);
     //window->showFullScreen();

    return app.exec();
}
