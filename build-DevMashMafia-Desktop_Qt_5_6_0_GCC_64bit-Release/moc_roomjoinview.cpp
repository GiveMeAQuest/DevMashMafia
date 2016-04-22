/****************************************************************************
** Meta object code from reading C++ file 'roomjoinview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DevMashMafiaQt/views/roomjoinview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roomjoinview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RoomJoinView_t {
    QByteArrayData data[8];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RoomJoinView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RoomJoinView_t qt_meta_stringdata_RoomJoinView = {
    {
QT_MOC_LITERAL(0, 0, 12), // "RoomJoinView"
QT_MOC_LITERAL(1, 13, 8), // "roomJoin"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "createRoom"
QT_MOC_LITERAL(4, 34, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 56, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(6, 80, 11), // "socketError"
QT_MOC_LITERAL(7, 92, 4) // "mess"

    },
    "RoomJoinView\0roomJoin\0\0createRoom\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "socketError\0mess"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RoomJoinView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   39,    2, 0x06 /* Public */,
       3,    2,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Bool,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void RoomJoinView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RoomJoinView *_t = static_cast<RoomJoinView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->roomJoin((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->createRoom((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_pushButton_2_clicked(); break;
        case 4: _t->socketError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RoomJoinView::*_t)(QString , int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RoomJoinView::roomJoin)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RoomJoinView::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RoomJoinView::createRoom)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject RoomJoinView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RoomJoinView.data,
      qt_meta_data_RoomJoinView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RoomJoinView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RoomJoinView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RoomJoinView.stringdata0))
        return static_cast<void*>(const_cast< RoomJoinView*>(this));
    return QWidget::qt_metacast(_clname);
}

int RoomJoinView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void RoomJoinView::roomJoin(QString _t1, int _t2, bool _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RoomJoinView::createRoom(QString _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
