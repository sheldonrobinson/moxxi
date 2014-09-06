/****************************************************************************
** Meta object code from reading C++ file 'shop.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../moxxi/shop.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'shop.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Shop_t {
    QByteArrayData data[18];
    char stringdata[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Shop_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Shop_t qt_meta_stringdata_Shop = {
    {
QT_MOC_LITERAL(0, 0, 4),
QT_MOC_LITERAL(1, 5, 10),
QT_MOC_LITERAL(2, 16, 0),
QT_MOC_LITERAL(3, 17, 14),
QT_MOC_LITERAL(4, 32, 13),
QT_MOC_LITERAL(5, 46, 15),
QT_MOC_LITERAL(6, 62, 11),
QT_MOC_LITERAL(7, 74, 6),
QT_MOC_LITERAL(8, 81, 8),
QT_MOC_LITERAL(9, 90, 25),
QT_MOC_LITERAL(10, 116, 6),
QT_MOC_LITERAL(11, 123, 25),
QT_MOC_LITERAL(12, 149, 9),
QT_MOC_LITERAL(13, 159, 6),
QT_MOC_LITERAL(14, 166, 3),
QT_MOC_LITERAL(15, 170, 7),
QT_MOC_LITERAL(16, 178, 9),
QT_MOC_LITERAL(17, 188, 4)
    },
    "Shop\0urlChanged\0\0aliasesChanged\0"
    "shopIdChanged\0listingsChanged\0nameChanged\0"
    "shopId\0listings\0QQmlListProperty<Listing>\0"
    "styles\0QQmlListProperty<QString>\0"
    "locations\0brands\0url\0aliases\0occasions\0"
    "name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Shop[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       9,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,
       5,    0,   42,    2, 0x06 /* Public */,
       6,    0,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       7, QMetaType::QString, 0x00495001,
       8, 0x80000000 | 9, 0x00495009,
      10, 0x80000000 | 11, 0x00495009,
      12, 0x80000000 | 11, 0x00495009,
      13, 0x80000000 | 11, 0x00495009,
      14, QMetaType::QUrl, 0x00495001,
      15, QMetaType::QStringList, 0x00495001,
      16, 0x80000000 | 11, 0x00495009,
      17, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       2,
       3,
       3,
       3,
       3,
       0,
       3,
       3,
       4,

       0        // eod
};

void Shop::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Shop *_t = static_cast<Shop *>(_o);
        switch (_id) {
        case 0: _t->urlChanged(); break;
        case 1: _t->aliasesChanged(); break;
        case 2: _t->shopIdChanged(); break;
        case 3: _t->listingsChanged(); break;
        case 4: _t->nameChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Shop::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Shop::urlChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (Shop::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Shop::aliasesChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (Shop::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Shop::shopIdChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (Shop::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Shop::listingsChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (Shop::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Shop::nameChanged)) {
                *result = 4;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Shop::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Shop.data,
      qt_meta_data_Shop,  qt_static_metacall, 0, 0}
};


const QMetaObject *Shop::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Shop::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Shop.stringdata))
        return static_cast<void*>(const_cast< Shop*>(this));
    return QObject::qt_metacast(_clname);
}

int Shop::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = shopId(); break;
        case 1: *reinterpret_cast< QQmlListProperty<Listing>*>(_v) = listings(); break;
        case 2: *reinterpret_cast< QQmlListProperty<QString>*>(_v) = styles(); break;
        case 3: *reinterpret_cast< QQmlListProperty<QString>*>(_v) = locations(); break;
        case 4: *reinterpret_cast< QQmlListProperty<QString>*>(_v) = brands(); break;
        case 5: *reinterpret_cast< QUrl*>(_v) = url(); break;
        case 6: *reinterpret_cast< QStringList*>(_v) = aliases(); break;
        case 7: *reinterpret_cast< QQmlListProperty<QString>*>(_v) = occasions(); break;
        case 8: *reinterpret_cast< QString*>(_v) = name(); break;
        default: break;
        }
        _id -= 9;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 9;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Shop::urlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Shop::aliasesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Shop::shopIdChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Shop::listingsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Shop::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
