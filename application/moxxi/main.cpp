#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "shop.h"
#include "listingsmodel.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<Brand>("Moxxi",1,0,"Brand");
    qmlRegisterType<Category>("Moxxi",1,0,"Category");
    qmlRegisterType<Listing>("Moxxi",1,0,"Listing");
    qmlRegisterType<Shop>("Moxxi",1,0,"Shop");
    qmlRegisterType<QAbstractItemModel>();
    qmlRegisterType<ListingsModel>();

    ListingsModel model;
    QUrl query("http://api.shopstyle.com/api/v2/products?pid=uid9009-25612247-65&fts=red+dress&offset=0&limit=10");
    model.setQuery(query);
    model.fetchData();
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext *context = new QQmlContext(engine.rootContext());
    context->setContextProperty("listingsModel",&model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
