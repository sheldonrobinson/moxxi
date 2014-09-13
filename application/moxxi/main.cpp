#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QtQml>
#include <QQuickWindow>
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
    //QUrl query("http://api.shopstyle.com/api/v2/products?pid=uid9009-25612247-65&fts=dress&offset=0&limit=100");
    QGuiApplication app(argc, argv);
    ListingsModel* model = new ListingsModel();
    QObject::connect(model,&ListingsModel::queryChanged, model,&ListingsModel::fetchData);
    model->setApiKey("uid9009-25612247-65");
    model->setFts("dress");
    //model->setQuery(query);
//    Listing test;
//    test.setImageUrl(QUrl("http://resources.shopstyle.com/sim/16/bd/16bd79acaa669c571def5fcf86633fd3_medium/wallis-red-zip-shoulder-ponte-dress.jpg"));
//    test.setName("Wallis Red Zip Shoulder Ponte Dress");
//    test.setLocale("en_US");
//    test.setPx(56.00);
//    test.setDescription("<br>This simple red dress is perfect modern staple for your wardrobe. This simple yet modern ponte dress features a drop waist, zip shoulder detailing and stud detail with pockets to add edge to a simple dress. Wear this chic dress with flats or heels, day or night.<br> 95% Polyester,5% Elastane. Machine washable.");
//    test.setListingId("458749740");
//    model->addListng(&test);

    //QThread tFetchData;

    //model->moveToThread(&tFetchData);
   // tFetchData.start();

    //model->fetchData();

//    while(!model->isReady()){
//        Sleep(1000);
//    }
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("theModel",model);
    //engine.addImageProvider("listings", new ListingsImageProvider);
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

    int retvalue = app.exec();
    return retvalue;
}
