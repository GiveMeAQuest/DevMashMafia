/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DevMashMafiaQt/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[196];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "mafiaChoosen"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "socketClosed"
QT_MOC_LITERAL(4, 38, 20), // "client::close_reason"
QT_MOC_LITERAL(5, 59, 6), // "reason"
QT_MOC_LITERAL(6, 66, 12), // "socketFailed"
QT_MOC_LITERAL(7, 79, 10), // "roomJoined"
QT_MOC_LITERAL(8, 90, 7), // "room_id"
QT_MOC_LITERAL(9, 98, 6), // "isHost"
QT_MOC_LITERAL(10, 105, 8), // "roomLeft"
QT_MOC_LITERAL(11, 114, 11), // "roleChoosed"
QT_MOC_LITERAL(12, 126, 4), // "role"
QT_MOC_LITERAL(13, 131, 10), // "nightBegin"
QT_MOC_LITERAL(14, 142, 8), // "nightEnd"
QT_MOC_LITERAL(15, 151, 8), // "dayBegin"
QT_MOC_LITERAL(16, 160, 10), // "citizenEnd"
QT_MOC_LITERAL(17, 171, 10), // "mafiaBegin"
QT_MOC_LITERAL(18, 182, 13) // "optionChoosen"

    },
    "MainWindow\0mafiaChoosen\0\0socketClosed\0"
    "client::close_reason\0reason\0socketFailed\0"
    "roomJoined\0room_id\0isHost\0roomLeft\0"
    "roleChoosed\0role\0nightBegin\0nightEnd\0"
    "dayBegin\0citizenEnd\0mafiaBegin\0"
    "optionChoosen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   79,    2, 0x0a /* Public */,
       6,    0,   82,    2, 0x0a /* Public */,
       7,    2,   83,    2, 0x0a /* Public */,
      10,    0,   88,    2, 0x0a /* Public */,
      11,    1,   89,    2, 0x0a /* Public */,
      13,    0,   92,    2, 0x0a /* Public */,
      14,    0,   93,    2, 0x0a /* Public */,
      15,    1,   94,    2, 0x0a /* Public */,
      16,    1,   97,    2, 0x0a /* Public */,
      17,    2,  100,    2, 0x0a /* Public */,
      18,    1,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, QMetaType::QJsonArray, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mafiaChoosen((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->socketClosed((*reinterpret_cast< const client::close_reason(*)>(_a[1]))); break;
        case 2: _t->socketFailed(); break;
        case 3: _t->roomJoined((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->roomLeft(); break;
        case 5: _t->roleChoosed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->nightBegin(); break;
        case 7: _t->nightEnd(); break;
        case 8: _t->dayBegin((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 9: _t->citizenEnd((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 10: _t->mafiaBegin((*reinterpret_cast< QJsonArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->optionChoosen((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::mafiaChoosen)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::mafiaChoosen(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
