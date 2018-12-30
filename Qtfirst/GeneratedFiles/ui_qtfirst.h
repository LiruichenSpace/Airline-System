/********************************************************************************
** Form generated from reading UI file 'qtfirst.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTFIRST_H
#define UI_QTFIRST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtfirstClass
{
public:
    QWidget *centralWidget;
    QPushButton *searchflight;
    QLabel *label;
    QLineEdit *flightID;
    QLabel *label_2;
    QLineEdit *userid;
    QLineEdit *managerpassword;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *managerlogin_2;
    QLabel *label_5;
    QLineEdit *flightstatus;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *userlogin;
    QLabel *label_15;
    QLineEdit *airline;
    QLineEdit *fromcity;
    QLineEdit *midcity;
    QLineEdit *tocity;
    QLineEdit *takeoff;
    QLineEdit *midland;
    QLineEdit *toland;
    QLineEdit *midtakeoff;
    QLineEdit *costtime;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLineEdit *firstleft;
    QLineEdit *secondleft;
    QLineEdit *totalleft;
    QLabel *label_19;
    QLineEdit *totalprice;
    QLabel *label_20;
    QLabel *label_21;
    QLineEdit *firstprice;
    QLineEdit *secondprice;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtfirstClass)
    {
        if (QtfirstClass->objectName().isEmpty())
            QtfirstClass->setObjectName(QString::fromUtf8("QtfirstClass"));
        QtfirstClass->resize(600, 432);
        centralWidget = new QWidget(QtfirstClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        searchflight = new QPushButton(centralWidget);
        searchflight->setObjectName(QString::fromUtf8("searchflight"));
        searchflight->setGeometry(QRect(400, 80, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 20, 181, 41));
        label->setTextFormat(Qt::AutoText);
        label->setWordWrap(false);
        flightID = new QLineEdit(centralWidget);
        flightID->setObjectName(QString::fromUtf8("flightID"));
        flightID->setGeometry(QRect(160, 80, 141, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 80, 91, 16));
        userid = new QLineEdit(centralWidget);
        userid->setObjectName(QString::fromUtf8("userid"));
        userid->setGeometry(QRect(70, 340, 113, 20));
        managerpassword = new QLineEdit(centralWidget);
        managerpassword->setObjectName(QString::fromUtf8("managerpassword"));
        managerpassword->setGeometry(QRect(390, 340, 113, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 340, 71, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(310, 340, 71, 16));
        managerlogin_2 = new QPushButton(centralWidget);
        managerlogin_2->setObjectName(QString::fromUtf8("managerlogin_2"));
        managerlogin_2->setGeometry(QRect(510, 340, 75, 23));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 120, 71, 21));
        flightstatus = new QLineEdit(centralWidget);
        flightstatus->setObjectName(QString::fromUtf8("flightstatus"));
        flightstatus->setGeometry(QRect(140, 120, 71, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(60, 150, 54, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(60, 180, 54, 16));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(63, 210, 51, 20));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(230, 150, 54, 16));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(230, 180, 54, 16));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(230, 210, 54, 16));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(390, 180, 54, 16));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(60, 250, 51, 20));
        userlogin = new QPushButton(centralWidget);
        userlogin->setObjectName(QString::fromUtf8("userlogin"));
        userlogin->setGeometry(QRect(190, 340, 75, 23));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(290, 120, 71, 21));
        airline = new QLineEdit(centralWidget);
        airline->setObjectName(QString::fromUtf8("airline"));
        airline->setGeometry(QRect(380, 120, 81, 20));
        fromcity = new QLineEdit(centralWidget);
        fromcity->setObjectName(QString::fromUtf8("fromcity"));
        fromcity->setGeometry(QRect(110, 150, 71, 20));
        midcity = new QLineEdit(centralWidget);
        midcity->setObjectName(QString::fromUtf8("midcity"));
        midcity->setGeometry(QRect(110, 180, 71, 20));
        tocity = new QLineEdit(centralWidget);
        tocity->setObjectName(QString::fromUtf8("tocity"));
        tocity->setGeometry(QRect(110, 210, 71, 20));
        takeoff = new QLineEdit(centralWidget);
        takeoff->setObjectName(QString::fromUtf8("takeoff"));
        takeoff->setGeometry(QRect(290, 150, 71, 20));
        midland = new QLineEdit(centralWidget);
        midland->setObjectName(QString::fromUtf8("midland"));
        midland->setGeometry(QRect(290, 180, 71, 20));
        toland = new QLineEdit(centralWidget);
        toland->setObjectName(QString::fromUtf8("toland"));
        toland->setGeometry(QRect(290, 210, 71, 20));
        midtakeoff = new QLineEdit(centralWidget);
        midtakeoff->setObjectName(QString::fromUtf8("midtakeoff"));
        midtakeoff->setGeometry(QRect(450, 180, 71, 20));
        costtime = new QLineEdit(centralWidget);
        costtime->setObjectName(QString::fromUtf8("costtime"));
        costtime->setGeometry(QRect(120, 250, 51, 20));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(180, 250, 51, 20));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(300, 250, 71, 20));
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(430, 250, 61, 20));
        firstleft = new QLineEdit(centralWidget);
        firstleft->setObjectName(QString::fromUtf8("firstleft"));
        firstleft->setGeometry(QRect(370, 250, 51, 20));
        secondleft = new QLineEdit(centralWidget);
        secondleft->setObjectName(QString::fromUtf8("secondleft"));
        secondleft->setGeometry(QRect(500, 250, 51, 20));
        totalleft = new QLineEdit(centralWidget);
        totalleft->setObjectName(QString::fromUtf8("totalleft"));
        totalleft->setGeometry(QRect(240, 250, 51, 20));
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(60, 300, 61, 20));
        totalprice = new QLineEdit(centralWidget);
        totalprice->setObjectName(QString::fromUtf8("totalprice"));
        totalprice->setGeometry(QRect(120, 300, 51, 20));
        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(230, 300, 61, 20));
        label_21 = new QLabel(centralWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(410, 300, 61, 20));
        firstprice = new QLineEdit(centralWidget);
        firstprice->setObjectName(QString::fromUtf8("firstprice"));
        firstprice->setGeometry(QRect(300, 300, 51, 20));
        secondprice = new QLineEdit(centralWidget);
        secondprice->setObjectName(QString::fromUtf8("secondprice"));
        secondprice->setGeometry(QRect(480, 300, 51, 20));
        QtfirstClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtfirstClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        QtfirstClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(QtfirstClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtfirstClass->setStatusBar(statusBar);

        retranslateUi(QtfirstClass);

        QMetaObject::connectSlotsByName(QtfirstClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtfirstClass)
    {
        QtfirstClass->setWindowTitle(QApplication::translate("QtfirstClass", "\350\210\252\347\217\255\347\256\241\347\220\206", nullptr));
        searchflight->setText(QApplication::translate("QtfirstClass", "\346\237\245\350\257\242\350\210\252\347\217\255", nullptr));
        label->setText(QApplication::translate("QtfirstClass", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#ff0000;\">\346\254\242\350\277\216\344\275\277\347\224\250\350\210\252\347\217\255\347\256\241\347\220\206\347\263\273\347\273\237</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("QtfirstClass", "\350\257\267\350\276\223\345\205\245\350\210\252\347\217\255\345\217\267\357\274\232", nullptr));
        label_3->setText(QApplication::translate("QtfirstClass", "\344\271\230\345\256\242\347\231\273\345\205\245\357\274\232", nullptr));
        label_4->setText(QApplication::translate("QtfirstClass", "\347\256\241\347\220\206\345\221\230\347\231\273\345\205\245\357\274\232", nullptr));
        managerlogin_2->setText(QApplication::translate("QtfirstClass", "\347\231\273\345\275\225", nullptr));
        label_5->setText(QApplication::translate("QtfirstClass", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600; color:#ff0000;\">\350\210\252\347\217\255\347\212\266\346\200\201\357\274\232</span></p></body></html>", nullptr));
        label_6->setText(QApplication::translate("QtfirstClass", "\350\265\267\351\243\236\347\253\231\357\274\232", nullptr));
        label_7->setText(QApplication::translate("QtfirstClass", "\347\273\217\345\201\234\347\253\231\357\274\232", nullptr));
        label_8->setText(QApplication::translate("QtfirstClass", "\347\273\210\347\202\271\347\253\231\357\274\232", nullptr));
        label_9->setText(QApplication::translate("QtfirstClass", "\350\265\267\351\243\236\346\227\266\351\227\264\357\274\232", nullptr));
        label_10->setText(QApplication::translate("QtfirstClass", "\351\231\215\350\220\275\346\227\266\351\227\264\357\274\232", nullptr));
        label_11->setText(QApplication::translate("QtfirstClass", "\351\231\215\350\220\275\346\227\266\351\227\264\357\274\232", nullptr));
        label_12->setText(QApplication::translate("QtfirstClass", "\350\265\267\351\243\236\346\227\266\351\227\264\357\274\232", nullptr));
        label_13->setText(QApplication::translate("QtfirstClass", "\345\205\250\347\250\213\350\200\227\346\227\266\357\274\232", nullptr));
        userlogin->setText(QApplication::translate("QtfirstClass", "\347\231\273\345\275\225", nullptr));
        label_15->setText(QApplication::translate("QtfirstClass", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600; color:#ff0000;\">\350\210\252\347\251\272\345\205\254\345\217\270\357\274\232</span></p></body></html>", nullptr));
        label_16->setText(QApplication::translate("QtfirstClass", "\345\205\250\347\250\213\344\275\231\347\245\250\357\274\232", nullptr));
        label_17->setText(QApplication::translate("QtfirstClass", "\345\215\212\347\250\213\344\275\231\347\245\2501\357\274\232", nullptr));
        label_18->setText(QApplication::translate("QtfirstClass", "\345\215\212\347\250\213\344\275\231\347\245\2502\357\274\232", nullptr));
        label_19->setText(QApplication::translate("QtfirstClass", "\345\205\250\347\250\213\347\245\250\344\273\267\357\274\232", nullptr));
        label_20->setText(QApplication::translate("QtfirstClass", "\345\215\212\347\250\213\347\245\250\344\273\2671\357\274\232", nullptr));
        label_21->setText(QApplication::translate("QtfirstClass", "\345\215\212\347\250\213\347\245\250\344\273\2672\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtfirstClass: public Ui_QtfirstClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTFIRST_H
