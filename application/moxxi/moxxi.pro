TEMPLATE = app

QT += qml quick svg sql quickwidgets

SOURCES += main.cpp \
    merchandiseitem.cpp \
    listing.cpp \
    shop.cpp \
    price.cpp \
    category.cpp \
    brand.cpp

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
    brand.h

OTHER_FILES += \
    qml/ui/ButtonWithBadge.qml
