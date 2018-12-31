/****************************************************************************
** Meta object code from reading C++ file 'passengerpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../passengerpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'passengerpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PassengerPage_t {
    QByteArrayData data[14];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PassengerPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PassengerPage_t qt_meta_stringdata_PassengerPage = {
    {
QT_MOC_LITERAL(0, 0, 13), // "PassengerPage"
QT_MOC_LITERAL(1, 14, 11), // "sendsignal2"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "on_back_clicked"
QT_MOC_LITERAL(4, 43, 16), // "on_total_clicked"
QT_MOC_LITERAL(5, 60, 16), // "on_half1_clicked"
QT_MOC_LITERAL(6, 77, 16), // "on_half2_clicked"
QT_MOC_LITERAL(7, 94, 14), // "on_buy_clicked"
QT_MOC_LITERAL(8, 109, 23), // "on_searchflight_clicked"
QT_MOC_LITERAL(9, 133, 17), // "on_search_clicked"
QT_MOC_LITERAL(10, 151, 17), // "on_refund_clicked"
QT_MOC_LITERAL(11, 169, 16), // "on_price_clicked"
QT_MOC_LITERAL(12, 186, 19), // "on_costtime_clicked"
QT_MOC_LITERAL(13, 206, 15) // "on_left_clicked"

    },
    "PassengerPage\0sendsignal2\0\0on_back_clicked\0"
    "on_total_clicked\0on_half1_clicked\0"
    "on_half2_clicked\0on_buy_clicked\0"
    "on_searchflight_clicked\0on_search_clicked\0"
    "on_refund_clicked\0on_price_clicked\0"
    "on_costtime_clicked\0on_left_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PassengerPage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

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

       0        // eod
};

void PassengerPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PassengerPage *_t = static_cast<PassengerPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendsignal2(); break;
        case 1: _t->on_back_clicked(); break;
        case 2: _t->on_total_clicked(); break;
        case 3: _t->on_half1_clicked(); break;
        case 4: _t->on_half2_clicked(); break;
        case 5: _t->on_buy_clicked(); break;
        case 6: _t->on_searchflight_clicked(); break;
        case 7: _t->on_search_clicked(); break;
        case 8: _t->on_refund_clicked(); break;
        case 9: _t->on_price_clicked(); break;
        case 10: _t->on_costtime_clicked(); break;
        case 11: _t->on_left_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PassengerPage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PassengerPage::sendsignal2)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject PassengerPage::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_PassengerPage.data,
    qt_meta_data_PassengerPage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PassengerPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PassengerPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PassengerPage.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PassengerPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void PassengerPage::sendsignal2()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
