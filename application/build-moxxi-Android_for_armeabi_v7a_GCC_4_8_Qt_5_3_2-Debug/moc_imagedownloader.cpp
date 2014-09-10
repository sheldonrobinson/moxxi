/****************************************************************************
** Meta object code from reading C++ file 'imagedownloader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../moxxi/imagedownloader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagedownloader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImageDownloader_t {
    QByteArrayData data[12];
    char stringdata[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageDownloader_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageDownloader_t qt_meta_stringdata_ImageDownloader = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 10),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 3),
QT_MOC_LITERAL(4, 32, 7),
QT_MOC_LITERAL(5, 40, 11),
QT_MOC_LITERAL(6, 52, 20),
QT_MOC_LITERAL(7, 73, 14),
QT_MOC_LITERAL(8, 88, 5),
QT_MOC_LITERAL(9, 94, 10),
QT_MOC_LITERAL(10, 105, 27),
QT_MOC_LITERAL(11, 133, 3)
    },
    "ImageDownloader\0downloaded\0\0url\0success\0"
    "downloadImg\0downloadImg_finished\0"
    "QNetworkReply*\0reply\0replyError\0"
    "QNetworkReply::NetworkError\0err"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageDownloader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   39,    2, 0x0a /* Public */,
       6,    1,   42,    2, 0x0a /* Public */,
       9,    1,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QUrl, QMetaType::Bool,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QUrl,    3,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void ImageDownloader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageDownloader *_t = static_cast<ImageDownloader *>(_o);
        switch (_id) {
        case 0: _t->downloaded((*reinterpret_cast< const QUrl(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->downloadImg((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 2: _t->downloadImg_finished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->replyError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ImageDownloader::*_t)(const QUrl & , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageDownloader::downloaded)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ImageDownloader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ImageDownloader.data,
      qt_meta_data_ImageDownloader,  qt_static_metacall, 0, 0}
};


const QMetaObject *ImageDownloader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageDownloader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageDownloader.stringdata))
        return static_cast<void*>(const_cast< ImageDownloader*>(this));
    return QObject::qt_metacast(_clname);
}

int ImageDownloader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ImageDownloader::downloaded(const QUrl & _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
