/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BingoCasaLinuxGui/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[338];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "handle90BallsButton"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 19), // "handle75BallsButton"
QT_MOC_LITERAL(4, 52, 25), // "handleGenerateCardsButton"
QT_MOC_LITERAL(5, 78, 20), // "handleNoThanksButton"
QT_MOC_LITERAL(6, 99, 30), // "handleNoThanksStartBingoButton"
QT_MOC_LITERAL(7, 130, 23), // "handlePickBallButton_75"
QT_MOC_LITERAL(8, 154, 23), // "handlePickBallButton_90"
QT_MOC_LITERAL(9, 178, 24), // "handleEnterPlayersButton"
QT_MOC_LITERAL(10, 203, 22), // "handleEnter75BallsGoOn"
QT_MOC_LITERAL(11, 226, 22), // "handleEnter90BallsGoOn"
QT_MOC_LITERAL(12, 249, 12), // "handleSeeYou"
QT_MOC_LITERAL(13, 262, 16), // "handleFinished75"
QT_MOC_LITERAL(14, 279, 16), // "handleFinished90"
QT_MOC_LITERAL(15, 296, 12), // "FillUp75Card"
QT_MOC_LITERAL(16, 309, 15), // "NumberOfPlayers"
QT_MOC_LITERAL(17, 325, 12) // "FillUp90Card"

    },
    "MainWindow\0handle90BallsButton\0\0"
    "handle75BallsButton\0handleGenerateCardsButton\0"
    "handleNoThanksButton\0"
    "handleNoThanksStartBingoButton\0"
    "handlePickBallButton_75\0handlePickBallButton_90\0"
    "handleEnterPlayersButton\0"
    "handleEnter75BallsGoOn\0handleEnter90BallsGoOn\0"
    "handleSeeYou\0handleFinished75\0"
    "handleFinished90\0FillUp75Card\0"
    "NumberOfPlayers\0FillUp90Card"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    1,  102,    2, 0x08 /* Private */,
      17,    1,  105,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handle90BallsButton(); break;
        case 1: _t->handle75BallsButton(); break;
        case 2: _t->handleGenerateCardsButton(); break;
        case 3: _t->handleNoThanksButton(); break;
        case 4: _t->handleNoThanksStartBingoButton(); break;
        case 5: _t->handlePickBallButton_75(); break;
        case 6: _t->handlePickBallButton_90(); break;
        case 7: _t->handleEnterPlayersButton(); break;
        case 8: _t->handleEnter75BallsGoOn(); break;
        case 9: _t->handleEnter90BallsGoOn(); break;
        case 10: _t->handleSeeYou(); break;
        case 11: _t->handleFinished75(); break;
        case 12: _t->handleFinished90(); break;
        case 13: _t->FillUp75Card((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->FillUp90Card((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
