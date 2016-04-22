/****************************************************************************
** Meta object code from reading C++ file 'roomview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DevMashMafiaQt/views/roomview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roomview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RoomView_t {
    QByteArrayData data[12];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RoomView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RoomView_t qt_meta_stringdata_RoomView = {
    {
QT_MOC_LITERAL(0, 0, 8), // "RoomView"
QT_MOC_LITERAL(1, 9, 17), // "getWaitingPlayers"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 9), // "leaveRoom"
QT_MOC_LITERAL(4, 38, 9), // "startGame"
QT_MOC_LITERAL(5, 48, 7), // "players"
QT_MOC_LITERAL(6, 56, 10), // "playerJoin"
QT_MOC_LITERAL(7, 67, 6), // "player"
QT_MOC_LITERAL(8, 74, 10), // "playerLeft"
QT_MOC_LITERAL(9, 85, 9), // "player_id"
QT_MOC_LITERAL(10, 95, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(11, 117, 23) // "on_pushButton_2_clicked"

    },
    "RoomView\0getWaitingPlayers\0\0leaveRoom\0"
    "startGame\0players\0playerJoin\0player\0"
    "playerLeft\0player_id\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RoomView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   57,    2, 0x0a /* Public */,
       6,    1,   60,    2, 0x0a /* Public */,
       8,    1,   63,    2, 0x0a /* Public */,
      10,    0,   66,    2, 0x08 /* Private */,
      11,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QJsonArray,    5,
    QMetaType::Void, QMetaType::QJsonObject,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RoomView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RoomView *_t = static_cast<RoomView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getWaitingPlayers(); break;
        case 1: _t->leaveRoom(); break;
        case 2: _t->startGame(); break;
        case 3: _t->players((*reinterpret_cast< QJsonArray(*)>(_a[1]))); break;
        case 4: _t->playerJoin((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 5: _t->playerLeft((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RoomView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RoomView::getWaitingPlayers)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RoomView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RoomView::leaveRoom)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RoomView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RoomView::startGame)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject RoomView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RoomView.data,
      qt_meta_data_RoomView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RoomView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RoomView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RoomView.stringdata0))
        return static_cast<void*>(const_cast< RoomView*>(this));
    return QWidget::qt_metacast(_clname);
}

int RoomView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void RoomView::getWaitingPlayers()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void RoomView::leaveRoom()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void RoomView::startGame()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
