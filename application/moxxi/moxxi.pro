TEMPLATE = app

QT += qml quick svg sql quickwidgets

CONFIG += QML_IMPORT_TRACE=1

SOURCES += main.cpp \
    merchandiseitem.cpp \
    listing.cpp \
    shop.cpp \
    price.cpp \
    category.cpp \
    brand.cpp \
    listingsmodel.cpp \
    imagedownloader.cpp \
    brandsmodel.cpp \
    categorysmodel.cpp \
    listingsimageprovider.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    merchandiseitem.h \
    listing.h \
    shop.h \
    price.h \
    category.h \
    brand.h \
    listingsmodel.h \
    imagedownloader.h \
    brandsmodel.h \
    categorysmodel.h \
    listingsimageprovider.h

OTHER_FILES += \
    qml/ui/ButtonWithBadge.qml \
    qml/ui/CoverFlow.qml \
    qml/ui/CoverFlowDelegate.qml \
    qml/ui/ImageView.qml \
    qml/ui/SwipeArea.qml \
    qml/ui/RowGradient.qml
