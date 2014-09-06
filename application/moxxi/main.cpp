#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "shop.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<Brand>("Moxxi",1,0,"Brand");
    qmlRegisterType<Category>("Moxxi",1,0,"Category");
    qmlRegisterType<Listing>("Moxxi",1,0,"Listing");
    qmlRegisterType<Shop>("Moxxi",1,0,"Shop");
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
