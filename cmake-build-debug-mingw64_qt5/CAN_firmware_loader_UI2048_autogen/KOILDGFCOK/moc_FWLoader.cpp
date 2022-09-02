/****************************************************************************
** Meta object code from reading C++ file 'FWLoader.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "FWLoader/FWLoader.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FWLoader.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FWLoader_t {
    QByteArrayData data[16];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FWLoader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FWLoader_t qt_meta_stringdata_FWLoader = {
    {
QT_MOC_LITERAL(0, 0, 8), // "FWLoader"
QT_MOC_LITERAL(1, 9, 17), // "signalAckReceived"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "signalNextBlock"
QT_MOC_LITERAL(4, 44, 5), // "delta"
QT_MOC_LITERAL(5, 50, 3), // "uid"
QT_MOC_LITERAL(6, 54, 4), // "addr"
QT_MOC_LITERAL(7, 59, 16), // "signalFinishedOK"
QT_MOC_LITERAL(8, 76, 5), // "msecs"
QT_MOC_LITERAL(9, 82, 14), // "signalBootData"
QT_MOC_LITERAL(10, 97, 3), // "UID"
QT_MOC_LITERAL(11, 101, 11), // "signalError"
QT_MOC_LITERAL(12, 113, 5), // "error"
QT_MOC_LITERAL(13, 119, 9), // "addDevice"
QT_MOC_LITERAL(14, 129, 8), // "fileName"
QT_MOC_LITERAL(15, 138, 4) // "uidT"

    },
    "FWLoader\0signalAckReceived\0\0signalNextBlock\0"
    "delta\0uid\0addr\0signalFinishedOK\0msecs\0"
    "signalBootData\0UID\0signalError\0error\0"
    "addDevice\0fileName\0uidT"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FWLoader[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    3,   45,    2, 0x06 /* Public */,
       7,    2,   52,    2, 0x06 /* Public */,
       9,    1,   57,    2, 0x06 /* Public */,
      11,    2,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    4,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    4,    5,    6,
    QMetaType::Void, QMetaType::UInt, QMetaType::Int,    5,    8,
    QMetaType::Void, QMetaType::UInt,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt,   12,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UChar, QMetaType::UInt, QMetaType::UChar,   14,    6,    5,   15,

       0        // eod
};

void FWLoader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FWLoader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalAckReceived(); break;
        case 1: _t->signalNextBlock((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 2: _t->signalFinishedOK((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->signalBootData((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 4: _t->signalError((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 5: _t->addDevice((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< uchar(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uchar(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FWLoader::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FWLoader::signalAckReceived)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FWLoader::*)(uint , uint , uint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FWLoader::signalNextBlock)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FWLoader::*)(uint , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FWLoader::signalFinishedOK)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FWLoader::*)(uint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FWLoader::signalBootData)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FWLoader::*)(const QString & , uint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FWLoader::signalError)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FWLoader::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FWLoader.data,
    qt_meta_data_FWLoader,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FWLoader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FWLoader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FWLoader.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FWLoader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}

// SIGNAL 0
void FWLoader::signalAckReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FWLoader::signalNextBlock(uint _t1, uint _t2, uint _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FWLoader::signalFinishedOK(uint _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FWLoader::signalBootData(uint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FWLoader::signalError(const QString & _t1, uint _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
