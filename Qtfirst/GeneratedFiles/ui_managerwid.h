/********************************************************************************
** Form generated from reading UI file 'managerwid.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERWID_H
#define UI_MANAGERWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_managerWid
{
public:
    QLabel *label_9;
    QLineEdit *takeoff;
    QLabel *label_10;
    QLabel *label_20;
    QLabel *label_6;
    QLineEdit *midtakeoff;
    QLabel *label_11;
    QLabel *label_13;
    QLineEdit *airline;
    QLabel *label_5;
    QPushButton *searchflight;
    QLineEdit *firstprice;
    QLabel *label_18;
    QLineEdit *midland;
    QLineEdit *totalleft;
    QLabel *label;
    QLineEdit *totalprice;
    QLineEdit *secondleft;
    QLineEdit *firstleft;
    QLabel *label_16;
    QLineEdit *flightstatus;
    QLabel *label_7;
    QLabel *label_17;
    QLabel *label_8;
    QLineEdit *tocity;
    QLabel *label_19;
    QLabel *label_2;
    QLineEdit *secondprice;
    QLineEdit *fromcity;
    QLabel *label_21;
    QLabel *label_12;
    QLineEdit *midcity;
    QLineEdit *costtime;
    QLineEdit *flightID;
    QLineEdit *toland;
    QLabel *label_15;
    QPushButton *confirm;
    QPushButton *back;
    QPushButton *cancel;
    QPushButton *addflight;

    void setupUi(QWidget *managerWid)
    {
        if (managerWid->objectName().isEmpty())
            managerWid->setObjectName(QString::fromUtf8("managerWid"));
        managerWid->resize(598, 426);
        label_9 = new QLabel(managerWid);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(230, 160, 54, 16));
        takeoff = new QLineEdit(managerWid);
        takeoff->setObjectName(QString::fromUtf8("takeoff"));
        takeoff->setGeometry(QRect(290, 160, 71, 20));
        label_10 = new QLabel(managerWid);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(230, 190, 54, 16));
        label_20 = new QLabel(managerWid);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(230, 310, 61, 20));
        label_6 = new QLabel(managerWid);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(60, 160, 54, 16));
        midtakeoff = new QLineEdit(managerWid);
        midtakeoff->setObjectName(QString::fromUtf8("midtakeoff"));
        midtakeoff->setEnabled(false);
        midtakeoff->setGeometry(QRect(450, 190, 71, 20));
        label_11 = new QLabel(managerWid);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(230, 220, 54, 16));
        label_13 = new QLabel(managerWid);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(60, 260, 51, 20));
        airline = new QLineEdit(managerWid);
        airline->setObjectName(QString::fromUtf8("airline"));
        airline->setEnabled(false);
        airline->setGeometry(QRect(380, 130, 81, 20));
        label_5 = new QLabel(managerWid);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 130, 71, 21));
        searchflight = new QPushButton(managerWid);
        searchflight->setObjectName(QString::fromUtf8("searchflight"));
        searchflight->setGeometry(QRect(400, 90, 75, 23));
        firstprice = new QLineEdit(managerWid);
        firstprice->setObjectName(QString::fromUtf8("firstprice"));
        firstprice->setGeometry(QRect(300, 310, 51, 20));
        label_18 = new QLabel(managerWid);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(430, 260, 61, 20));
        midland = new QLineEdit(managerWid);
        midland->setObjectName(QString::fromUtf8("midland"));
        midland->setEnabled(false);
        midland->setGeometry(QRect(290, 190, 71, 20));
        totalleft = new QLineEdit(managerWid);
        totalleft->setObjectName(QString::fromUtf8("totalleft"));
        totalleft->setGeometry(QRect(240, 260, 51, 20));
        label = new QLabel(managerWid);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 30, 181, 41));
        label->setTextFormat(Qt::AutoText);
        label->setWordWrap(false);
        totalprice = new QLineEdit(managerWid);
        totalprice->setObjectName(QString::fromUtf8("totalprice"));
        totalprice->setGeometry(QRect(120, 310, 51, 20));
        secondleft = new QLineEdit(managerWid);
        secondleft->setObjectName(QString::fromUtf8("secondleft"));
        secondleft->setGeometry(QRect(500, 260, 51, 20));
        firstleft = new QLineEdit(managerWid);
        firstleft->setObjectName(QString::fromUtf8("firstleft"));
        firstleft->setGeometry(QRect(370, 260, 51, 20));
        label_16 = new QLabel(managerWid);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(180, 260, 51, 20));
        flightstatus = new QLineEdit(managerWid);
        flightstatus->setObjectName(QString::fromUtf8("flightstatus"));
        flightstatus->setEnabled(false);
        flightstatus->setGeometry(QRect(140, 130, 71, 20));
        label_7 = new QLabel(managerWid);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(60, 190, 54, 16));
        label_17 = new QLabel(managerWid);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(300, 260, 71, 20));
        label_8 = new QLabel(managerWid);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(63, 220, 51, 20));
        tocity = new QLineEdit(managerWid);
        tocity->setObjectName(QString::fromUtf8("tocity"));
        tocity->setEnabled(false);
        tocity->setGeometry(QRect(110, 220, 71, 20));
        label_19 = new QLabel(managerWid);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(60, 310, 61, 20));
        label_2 = new QLabel(managerWid);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 90, 91, 16));
        secondprice = new QLineEdit(managerWid);
        secondprice->setObjectName(QString::fromUtf8("secondprice"));
        secondprice->setGeometry(QRect(480, 310, 51, 20));
        fromcity = new QLineEdit(managerWid);
        fromcity->setObjectName(QString::fromUtf8("fromcity"));
        fromcity->setEnabled(false);
        fromcity->setGeometry(QRect(110, 160, 71, 20));
        label_21 = new QLabel(managerWid);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(410, 310, 61, 20));
        label_12 = new QLabel(managerWid);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(390, 190, 54, 16));
        midcity = new QLineEdit(managerWid);
        midcity->setObjectName(QString::fromUtf8("midcity"));
        midcity->setEnabled(false);
        midcity->setGeometry(QRect(110, 190, 71, 20));
        costtime = new QLineEdit(managerWid);
        costtime->setObjectName(QString::fromUtf8("costtime"));
        costtime->setEnabled(false);
        costtime->setGeometry(QRect(120, 260, 51, 20));
        flightID = new QLineEdit(managerWid);
        flightID->setObjectName(QString::fromUtf8("flightID"));
        flightID->setGeometry(QRect(160, 90, 141, 21));
        toland = new QLineEdit(managerWid);
        toland->setObjectName(QString::fromUtf8("toland"));
        toland->setEnabled(false);
        toland->setGeometry(QRect(290, 220, 71, 20));
        label_15 = new QLabel(managerWid);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(290, 130, 71, 21));
        confirm = new QPushButton(managerWid);
        confirm->setObjectName(QString::fromUtf8("confirm"));
        confirm->setGeometry(QRect(110, 350, 121, 31));
        back = new QPushButton(managerWid);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(370, 350, 111, 31));
        cancel = new QPushButton(managerWid);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(480, 90, 75, 23));
        addflight = new QPushButton(managerWid);
        addflight->setObjectName(QString::fromUtf8("addflight"));
        addflight->setGeometry(QRect(320, 90, 75, 23));

        retranslateUi(managerWid);
        QObject::connect(back, SIGNAL(clicked()), managerWid, SLOT(backtomain()));

        QMetaObject::connectSlotsByName(managerWid);
    } // setupUi

    void retranslateUi(QWidget *managerWid)
    {
        managerWid->setWindowTitle(QApplication::translate("managerWid", "managerWid", nullptr));
        label_9->setText(QApplication::translate("managerWid", "\350\265\267\351\243\236\346\227\266\351\227\264\357\274\232", nullptr));
        label_10->setText(QApplication::translate("managerWid", "\351\231\215\350\220\275\346\227\266\351\227\264\357\274\232", nullptr));
        label_20->setText(QApplication::translate("managerWid", "\345\215\212\347\250\213\347\245\250\344\273\2671\357\274\232", nullptr));
        label_6->setText(QApplication::translate("managerWid", "\350\265\267\351\243\236\347\253\231\357\274\232", nullptr));
        label_11->setText(QApplication::translate("managerWid", "\351\231\215\350\220\275\346\227\266\351\227\264\357\274\232", nullptr));
        label_13->setText(QApplication::translate("managerWid", "\345\205\250\347\250\213\350\200\227\346\227\266\357\274\232", nullptr));
        label_5->setText(QApplication::translate("managerWid", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600; color:#ff0000;\">\350\210\252\347\217\255\347\212\266\346\200\201\357\274\232</span></p></body></html>", nullptr));
        searchflight->setText(QApplication::translate("managerWid", "\346\237\245\350\257\242\350\210\252\347\217\255", nullptr));
        label_18->setText(QApplication::translate("managerWid", "\345\215\212\347\250\213\344\275\231\347\245\2502\357\274\232", nullptr));
        label->setText(QApplication::translate("managerWid", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#ff0000;\">\346\254\242\350\277\216\344\275\277\347\224\250\350\210\252\347\217\255\347\256\241\347\220\206\347\263\273\347\273\237</span></p></body></html>", nullptr));
        label_16->setText(QApplication::translate("managerWid", "\345\205\250\347\250\213\344\275\231\347\245\250\357\274\232", nullptr));
        label_7->setText(QApplication::translate("managerWid", "\347\273\217\345\201\234\347\253\231\357\274\232", nullptr));
        label_17->setText(QApplication::translate("managerWid", "\345\215\212\347\250\213\344\275\231\347\245\2501\357\274\232", nullptr));
        label_8->setText(QApplication::translate("managerWid", "\347\273\210\347\202\271\347\253\231\357\274\232", nullptr));
        label_19->setText(QApplication::translate("managerWid", "\345\205\250\347\250\213\347\245\250\344\273\267\357\274\232", nullptr));
        label_2->setText(QApplication::translate("managerWid", "\350\257\267\350\276\223\345\205\245\350\210\252\347\217\255\345\217\267\357\274\232", nullptr));
        label_21->setText(QApplication::translate("managerWid", "\345\215\212\347\250\213\347\245\250\344\273\2672\357\274\232", nullptr));
        label_12->setText(QApplication::translate("managerWid", "\350\265\267\351\243\236\346\227\266\351\227\264\357\274\232", nullptr));
        label_15->setText(QApplication::translate("managerWid", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600; color:#ff0000;\">\350\210\252\347\251\272\345\205\254\345\217\270\357\274\232</span></p></body></html>", nullptr));
        confirm->setText(QApplication::translate("managerWid", "\347\241\256\345\256\232", nullptr));
        back->setText(QApplication::translate("managerWid", "\350\277\224\345\233\236", nullptr));
        cancel->setText(QApplication::translate("managerWid", "\345\217\226\346\266\210\350\257\245\350\210\252\347\217\255", nullptr));
        addflight->setText(QApplication::translate("managerWid", "\346\267\273\345\212\240\350\210\252\347\217\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class managerWid: public Ui_managerWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERWID_H
