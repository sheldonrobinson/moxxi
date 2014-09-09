/****************************************************************************
** Meta object code from reading C++ file 'merchandiseitem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../moxxi/merchandiseitem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'merchandiseitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MerchandiseItem_t {
    QByteArrayData data[9];
    char stringdata[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MerchandiseItem_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MerchandiseItem_t qt_meta_stringdata_MerchandiseItem = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 16),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 17),
QT_MOC_LITERAL(4, 52, 12),
QT_MOC_LITERAL(5, 65, 3),
QT_MOC_LITERAL(6, 69, 5),
QT_MOC_LITERAL(7, 75, 9),
QT_MOC_LITERAL(8, 85, 10)
    },
    "MerchandiseItem\0referenceChanged\0\0"
    "attributesChanged\0setAttribute\0key\0"
    "value\0reference\0attributes"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MerchandiseItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       2,   36, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       4,    2,   31,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    5,    6,

 // properties: name, type, flags
       7, QMetaType::QString, 0x00495103,
       8, QMetaType::QVariantMap, 0x00495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void MerchandiseItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MerchandiseItem *_t = static_cast<MerchandiseItem *>(_o);
        switch (_id) {
        case 0: _t->referenceChanged(); break;
        case 1: _t->attributesChanged(); break;
        case 2: _t->setAttribute((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MerchandiseItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MerchandiseItem::referenceChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (MerchandiseItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MerchandiseItem::attributesChanged)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MerchandiseItem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MerchandiseItem.data,
      qt_meta_data_MerchandiseItem,  qt_static_metacall, 0, 0}
};


const QMetaObject *MerchandiseItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MerchandiseItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MerchandiseItem.stringdata))
        return static_cast<void*>(const_cast< MerchandiseItem*>(this));
    return QObject::qt_metacast(_clname);
}

int MerchandiseItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 0: *reinterpret_cast< QString*>(_v) = reference(); break;
        case 1: *reinterpret_cast< QVariantMap*>(_v) = attributes(); break;
        default: break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setReference(*reinterpret_cast< QString*>(_v)); break;
        case 1: setAttributes(*reinterpret_cast< QVariantMap*>(_v)); break;
        default: break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MerchandiseItem::referenceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MerchandiseItem::attributesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
