/****************************************************************************
** Meta object code from reading C++ file 'socketwrapper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DevMashMafiaQt/socketwrapper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'socketwrapper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SocketWrapper_t {
    QByteArrayData data[33];
    char stringdata0[344];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SocketWrapper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SocketWrapper_t qt_meta_stringdata_SocketWrapper = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SocketWrapper"
QT_MOC_LITERAL(1, 14, 11), // "socketClose"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 20), // "client::close_reason"
QT_MOC_LITERAL(4, 48, 6), // "reason"
QT_MOC_LITERAL(5, 55, 12), // "socketFailed"
QT_MOC_LITERAL(6, 68, 10), // "roomJoined"
QT_MOC_LITERAL(7, 79, 7), // "room_id"
QT_MOC_LITERAL(8, 87, 6), // "isHost"
QT_MOC_LITERAL(9, 94, 7), // "players"
QT_MOC_LITERAL(10, 102, 10), // "playerJoin"
QT_MOC_LITERAL(11, 113, 6), // "player"
QT_MOC_LITERAL(12, 120, 10), // "playerLeft"
QT_MOC_LITERAL(13, 131, 9), // "player_id"
QT_MOC_LITERAL(14, 141, 8), // "roomLeft"
QT_MOC_LITERAL(15, 150, 4), // "role"
QT_MOC_LITERAL(16, 155, 10), // "nightBegin"
QT_MOC_LITERAL(17, 166, 8), // "nightEnd"
QT_MOC_LITERAL(18, 175, 8), // "dayBegin"
QT_MOC_LITERAL(19, 184, 10), // "citizenEnd"
QT_MOC_LITERAL(20, 195, 10), // "mafiaBegin"
QT_MOC_LITERAL(21, 206, 5), // "error"
QT_MOC_LITERAL(22, 212, 4), // "mess"
QT_MOC_LITERAL(23, 217, 17), // "httpReplyFinished"
QT_MOC_LITERAL(24, 235, 14), // "QNetworkReply*"
QT_MOC_LITERAL(25, 250, 8), // "roomJoin"
QT_MOC_LITERAL(26, 259, 8), // "nickname"
QT_MOC_LITERAL(27, 268, 10), // "createRoom"
QT_MOC_LITERAL(28, 279, 13), // "players_count"
QT_MOC_LITERAL(29, 293, 17), // "getWaitingPlayers"
QT_MOC_LITERAL(30, 311, 9), // "leaveRoom"
QT_MOC_LITERAL(31, 321, 9), // "startGame"
QT_MOC_LITERAL(32, 331, 12) // "mafiaChoosen"

    },
    "SocketWrapper\0socketClose\0\0"
    "client::close_reason\0reason\0socketFailed\0"
    "roomJoined\0room_id\0isHost\0players\0"
    "playerJoin\0player\0playerLeft\0player_id\0"
    "roomLeft\0role\0nightBegin\0nightEnd\0"
    "dayBegin\0citizenEnd\0mafiaBegin\0error\0"
    "mess\0httpReplyFinished\0QNetworkReply*\0"
    "roomJoin\0nickname\0createRoom\0players_count\0"
    "getWaitingPlayers\0leaveRoom\0startGame\0"
    "mafiaChoosen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SocketWrapper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x06 /* Public */,
       5,    0,  122,    2, 0x06 /* Public */,
       6,    2,  123,    2, 0x06 /* Public */,
       9,    1,  128,    2, 0x06 /* Public */,
      10,    1,  131,    2, 0x06 /* Public */,
      12,    1,  134,    2, 0x06 /* Public */,
      14,    0,  137,    2, 0x06 /* Public */,
      15,    1,  138,    2, 0x06 /* Public */,
      16,    0,  141,    2, 0x06 /* Public */,
      17,    0,  142,    2, 0x06 /* Public */,
      18,    1,  143,    2, 0x06 /* Public */,
      19,    1,  146,    2, 0x06 /* Public */,
      20,    2,  149,    2, 0x06 /* Public */,
      21,    1,  154,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    1,  157,    2, 0x08 /* Private */,
      25,    3,  160,    2, 0x0a /* Public */,
      27,    2,  167,    2, 0x0a /* Public */,
      29,    0,  172,    2, 0x0a /* Public */,
      30,    0,  173,    2, 0x0a /* Public */,
      31,    0,  174,    2, 0x0a /* Public */,
      32,    2,  175,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    7,    8,
    QMetaType::Void, QMetaType::QJsonArray,    9,
    QMetaType::Void, QMetaType::QJsonObject,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, QMetaType::QJsonArray, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,   22,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 24,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Bool,   26,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   26,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

       0        // eod
};

void SocketWrapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SocketWrapper *_t = static_cast<SocketWrapper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->socketClose((*reinterpret_cast< const client::close_reason(*)>(_a[1]))); break;
        case 1: _t->socketFailed(); break;
        case 2: _t->roomJoined((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->players((*reinterpret_cast< QJsonArray(*)>(_a[1]))); break;
        case 4: _t->playerJoin((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 5: _t->playerLeft((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->roomLeft(); break;
        case 7: _t->role((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->nightBegin(); break;
        case 9: _t->nightEnd(); break;
        case 10: _t->dayBegin((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 11: _t->citizenEnd((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 12: _t->mafiaBegin((*reinterpret_cast< QJsonArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->httpReplyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 15: _t->roomJoin((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 16: _t->createRoom((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 17: _t->getWaitingPlayers(); break;
        case 18: _t->leaveRoom(); break;
        case 19: _t->startGame(); break;
        case 20: _t->mafiaChoosen((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SocketWrapper::*_t)(client::close_reason const & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketWrapper::socketClose)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SocketWrapper::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketWrapper::socketFailed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SocketWrapper::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketWrapper::roomJoined)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (SocketWrapper::*_t)(QJsonArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketWrapper::players)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (SocketWrapper::*_t)(QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketWrapper::playerJoin)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (SocketWrapper::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketWrapper::playerLeft)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (SocketWrapper::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketWrapper::roomLeft)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (SocketWrapper::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketWrapper::role)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (SocketWrapper::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketWrapper::nightBegin)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (SocketWrapper::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketWrapper::nightEnd)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (SocketWrapper::*_t)(QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketWrapper::dayBegin)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (SocketWrapper::*_t)(QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketWrapper::citizenEnd)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (SocketWrapper::*_t)(QJsonArray , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketWrapper::mafiaBegin)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (SocketWrapper::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketWrapper::error)) {
                *result = 13;
                return;
            }
        }
    }
}

const QMetaObject SocketWrapper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SocketWrapper.data,
      qt_meta_data_SocketWrapper,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SocketWrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SocketWrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SocketWrapper.stringdata0))
        return static_cast<void*>(const_cast< SocketWrapper*>(this));
    return QObject::qt_metacast(_clname);
}

int SocketWrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void SocketWrapper::socketClose(client::close_reason const & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SocketWrapper::socketFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void SocketWrapper::roomJoined(int _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SocketWrapper::players(QJsonArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SocketWrapper::playerJoin(QJsonObject _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SocketWrapper::playerLeft(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void SocketWrapper::roomLeft()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void SocketWrapper::role(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void SocketWrapper::nightBegin()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void SocketWrapper::nightEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void SocketWrapper::dayBegin(QJsonObject _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void SocketWrapper::citizenEnd(QJsonObject _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void SocketWrapper::mafiaBegin(QJsonArray _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void SocketWrapper::error(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}
QT_END_MOC_NAMESPACE
