/****************************************************************************
** Meta object code from reading C++ file 'socket_adapter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "Monitor/socket_adapter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'socket_adapter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SocketAdapter_t {
    QByteArrayData data[16];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SocketAdapter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SocketAdapter_t qt_meta_stringdata_SocketAdapter = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SocketAdapter"
QT_MOC_LITERAL(1, 14, 9), // "connected"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "disconnected"
QT_MOC_LITERAL(4, 38, 5), // "error"
QT_MOC_LITERAL(5, 44, 5), // "rxMsg"
QT_MOC_LITERAL(6, 50, 13), // "ProtosMessage"
QT_MOC_LITERAL(7, 64, 5), // "txMsg"
QT_MOC_LITERAL(8, 70, 7), // "timeout"
QT_MOC_LITERAL(9, 78, 22), // "on_Socket_bytesWritten"
QT_MOC_LITERAL(10, 101, 5), // "bytes"
QT_MOC_LITERAL(11, 107, 19), // "on_Socket_connected"
QT_MOC_LITERAL(12, 127, 15), // "on_Socket_error"
QT_MOC_LITERAL(13, 143, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(14, 172, 19), // "on_Socket_readyRead"
QT_MOC_LITERAL(15, 192, 23) // "on_TimeoutTimer_timeout"

    },
    "SocketAdapter\0connected\0\0disconnected\0"
    "error\0rxMsg\0ProtosMessage\0txMsg\0timeout\0"
    "on_Socket_bytesWritten\0bytes\0"
    "on_Socket_connected\0on_Socket_error\0"
    "QAbstractSocket::SocketError\0"
    "on_Socket_readyRead\0on_TimeoutTimer_timeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SocketAdapter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    1,   71,    2, 0x06 /* Public */,
       5,    1,   74,    2, 0x06 /* Public */,
       7,    1,   77,    2, 0x06 /* Public */,
       8,    1,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   83,    2, 0x08 /* Private */,
      11,    0,   86,    2, 0x08 /* Private */,
      12,    1,   87,    2, 0x08 /* Private */,
      14,    0,   90,    2, 0x08 /* Private */,
      15,    0,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SocketAdapter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SocketAdapter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->disconnected(); break;
        case 2: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->rxMsg((*reinterpret_cast< const ProtosMessage(*)>(_a[1]))); break;
        case 4: _t->txMsg((*reinterpret_cast< const ProtosMessage(*)>(_a[1]))); break;
        case 5: _t->timeout((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 6: _t->on_Socket_bytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 7: _t->on_Socket_connected(); break;
        case 8: _t->on_Socket_error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 9: _t->on_Socket_readyRead(); break;
        case 10: _t->on_TimeoutTimer_timeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ProtosMessage >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ProtosMessage >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SocketAdapter::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SocketAdapter::connected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SocketAdapter::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SocketAdapter::disconnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SocketAdapter::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SocketAdapter::error)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SocketAdapter::*)(const ProtosMessage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SocketAdapter::rxMsg)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SocketAdapter::*)(const ProtosMessage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SocketAdapter::txMsg)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SocketAdapter::*)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SocketAdapter::timeout)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SocketAdapter::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SocketAdapter.data,
    qt_meta_data_SocketAdapter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SocketAdapter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SocketAdapter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SocketAdapter.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SocketAdapter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void SocketAdapter::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SocketAdapter::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SocketAdapter::error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SocketAdapter::rxMsg(const ProtosMessage & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SocketAdapter::txMsg(const ProtosMessage & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SocketAdapter::timeout(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
