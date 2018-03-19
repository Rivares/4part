/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[295];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "on_exit_clicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 16), // "on_clear_clicked"
QT_MOC_LITERAL(4, 45, 15), // "on_draw_clicked"
QT_MOC_LITERAL(5, 61, 15), // "on_save_clicked"
QT_MOC_LITERAL(6, 77, 14), // "on_LHM_clicked"
QT_MOC_LITERAL(7, 92, 14), // "on_NHM_clicked"
QT_MOC_LITERAL(8, 107, 16), // "on_Mexch_clicked"
QT_MOC_LITERAL(9, 124, 16), // "on_Hexch_clicked"
QT_MOC_LITERAL(10, 141, 30), // "on_CouiceZspinBox_valueChanged"
QT_MOC_LITERAL(11, 172, 4), // "arg1"
QT_MOC_LITERAL(12, 177, 27), // "on_lineEdit_editingFinished"
QT_MOC_LITERAL(13, 205, 29), // "on_lineEdit_2_editingFinished"
QT_MOC_LITERAL(14, 235, 29), // "on_lineEdit_3_editingFinished"
QT_MOC_LITERAL(15, 265, 29) // "on_lineEdit_4_editingFinished"

    },
    "MainWindow\0on_exit_clicked\0\0"
    "on_clear_clicked\0on_draw_clicked\0"
    "on_save_clicked\0on_LHM_clicked\0"
    "on_NHM_clicked\0on_Mexch_clicked\0"
    "on_Hexch_clicked\0on_CouiceZspinBox_valueChanged\0"
    "arg1\0on_lineEdit_editingFinished\0"
    "on_lineEdit_2_editingFinished\0"
    "on_lineEdit_3_editingFinished\0"
    "on_lineEdit_4_editingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    1,   87,    2, 0x08 /* Private */,
      12,    0,   90,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_exit_clicked(); break;
        case 1: _t->on_clear_clicked(); break;
        case 2: _t->on_draw_clicked(); break;
        case 3: _t->on_save_clicked(); break;
        case 4: _t->on_LHM_clicked(); break;
        case 5: _t->on_NHM_clicked(); break;
        case 6: _t->on_Mexch_clicked(); break;
        case 7: _t->on_Hexch_clicked(); break;
        case 8: _t->on_CouiceZspinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_lineEdit_editingFinished(); break;
        case 10: _t->on_lineEdit_2_editingFinished(); break;
        case 11: _t->on_lineEdit_3_editingFinished(); break;
        case 12: _t->on_lineEdit_4_editingFinished(); break;
        default: ;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
