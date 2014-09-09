/****************************************************************************
** Meta object code from reading C++ file 'brand.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../moxxi/brand.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'brand.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Brand_t {
    QByteArrayData data[13];
    char stringdata[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Brand_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Brand_t qt_meta_stringdata_Brand = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 11),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 10),
QT_MOC_LITERAL(4, 30, 15),
QT_MOC_LITERAL(5, 46, 14),
QT_MOC_LITERAL(6, 61, 13),
QT_MOC_LITERAL(7, 75, 7),
QT_MOC_LITERAL(8, 83, 10),
QT_MOC_LITERAL(9, 94, 4),
QT_MOC_LITERAL(10, 99, 8),
QT_MOC_LITERAL(11, 108, 3),
QT_MOC_LITERAL(12, 112, 7)
    },
    "Brand\0nameChanged\0\0urlChanged\0"
    "synonymsChanged\0brandIdChanged\0"
    "removeSynonym\0synonym\0addSynonym\0name\0"
    "synonyms\0url\0brandId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Brand[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       4,   54, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   48,    2, 0x0a /* Public */,
       8,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,    7,
    QMetaType::Bool, QMetaType::QString,    7,

 // properties: name, type, flags
       9, QMetaType::QString, 0x00495001,
      10, QMetaType::QStringList, 0x00495001,
      11, QMetaType::QUrl, 0x00495001,
      12, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,
       2,
       1,
       3,

       0        // eod
};

void Brand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Brand *_t = static_cast<Brand *>(_o);
        switch (_id) {
        case 0: _t->nameChanged(); break;
        case 1: _t->urlChanged(); break;
        case 2: _t->synonymsChanged(); break;
        case 3: _t->brandIdChanged(); break;
        case 4: { bool _r = _t->removeSynonym((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->addSynonym((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Brand::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Brand::nameChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (Brand::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Brand::urlChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (Brand::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Brand::synonymsChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (Brand::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Brand::brandIdChanged)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Brand::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Brand.data,
      qt_meta_data_Brand,  qt_static_metacall, 0, 0}
};


const QMetaObject *Brand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Brand::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Brand.stringdata))
        return static_cast<void*>(const_cast< Brand*>(this));
    return QObject::qt_metacast(_clname);
}

int Brand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = name(); break;
        case 1: *reinterpret_cast< QStringList*>(_v) = synonyms(); break;
        case 2: *reinterpret_cast< QUrl*>(_v) = url(); break;
        case 3: *reinterpret_cast< QString*>(_v) = brandId(); break;
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
void Brand::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Brand::urlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Brand::synonymsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Brand::brandIdChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
