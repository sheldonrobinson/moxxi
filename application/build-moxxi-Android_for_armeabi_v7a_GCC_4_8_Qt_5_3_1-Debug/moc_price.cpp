/****************************************************************************
** Meta object code from reading C++ file 'price.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../moxxi/price.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'price.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Price_t {
    QByteArrayData data[9];
    char stringdata[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Price_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Price_t qt_meta_stringdata_Price = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 13),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 9),
QT_MOC_LITERAL(4, 31, 11),
QT_MOC_LITERAL(5, 43, 6),
QT_MOC_LITERAL(6, 50, 2),
QT_MOC_LITERAL(7, 53, 8),
QT_MOC_LITERAL(8, 62, 6)
    },
    "Price\0localeChanged\0\0pxChanged\0"
    "formattedPx\0locale\0px\0currency\0symbol"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Price[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       4,   32, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   31,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::QString,

 // properties: name, type, flags
       5, QMetaType::QLocale, 0x00495001,
       6, QMetaType::Double, 0x00495001,
       7, QMetaType::QString, 0x00495001,
       8, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       0,
       0,

       0        // eod
};

void Price::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Price *_t = static_cast<Price *>(_o);
        switch (_id) {
        case 0: _t->localeChanged(); break;
        case 1: _t->pxChanged(); break;
        case 2: { QString _r = _t->formattedPx();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Price::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Price::localeChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (Price::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Price::pxChanged)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject Price::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Price.data,
      qt_meta_data_Price,  qt_static_metacall, 0, 0}
};


const QMetaObject *Price::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Price::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Price.stringdata))
        return static_cast<void*>(const_cast< Price*>(this));
    return QObject::qt_metacast(_clname);
}

int Price::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QLocale*>(_v) = locale(); break;
        case 1: *reinterpret_cast< double*>(_v) = px(); break;
        case 2: *reinterpret_cast< QString*>(_v) = currency(); break;
        case 3: *reinterpret_cast< QString*>(_v) = symbol(); break;
        default: break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Price::localeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Price::pxChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
