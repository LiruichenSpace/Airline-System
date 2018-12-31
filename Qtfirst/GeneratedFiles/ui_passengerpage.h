/********************************************************************************
** Form generated from reading UI file 'passengerpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSENGERPAGE_H
#define UI_PASSENGERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PassengerPage
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *flightid;
    QLabel *label_3;
    QLineEdit *bestflight;
    QTextEdit *textEdit;
    QLineEdit *fromcity;
    QLineEdit *tocity;
    QPushButton *buy;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *search;
    QPushButton *back;
    QPushButton *refund;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QCheckBox *total;
    QCheckBox *half1;
    QCheckBox *half2;
    QPushButton *searchflight;

    void setupUi(QWidget *PassengerPage)
    {
        if (PassengerPage->objectName().isEmpty())
            PassengerPage->setObjectName(QString::fromUtf8("PassengerPage"));
        PassengerPage->resize(734, 460);
        label = new QLabel(PassengerPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(300, 30, 151, 31));
        label_2 = new QLabel(PassengerPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 80, 71, 21));
        flightid = new QLineEdit(PassengerPage);
        flightid->setObjectName(QString::fromUtf8("flightid"));
        flightid->setGeometry(QRect(90, 80, 113, 20));
        label_3 = new QLabel(PassengerPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 360, 71, 16));
        bestflight = new QLineEdit(PassengerPage);
        bestflight->setObjectName(QString::fromUtf8("bestflight"));
        bestflight->setEnabled(false);
        bestflight->setGeometry(QRect(100, 360, 113, 20));
        textEdit = new QTextEdit(PassengerPage);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setGeometry(QRect(60, 160, 641, 171));
        fromcity = new QLineEdit(PassengerPage);
        fromcity->setObjectName(QString::fromUtf8("fromcity"));
        fromcity->setGeometry(QRect(440, 80, 71, 20));
        tocity = new QLineEdit(PassengerPage);
        tocity->setObjectName(QString::fromUtf8("tocity"));
        tocity->setGeometry(QRect(570, 80, 71, 20));
        buy = new QPushButton(PassengerPage);
        buy->setObjectName(QString::fromUtf8("buy"));
        buy->setGeometry(QRect(210, 80, 41, 23));
        label_4 = new QLabel(PassengerPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(390, 80, 41, 21));
        label_5 = new QLabel(PassengerPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(520, 80, 54, 21));
        search = new QPushButton(PassengerPage);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(660, 80, 41, 23));
        back = new QPushButton(PassengerPage);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(590, 360, 75, 23));
        refund = new QPushButton(PassengerPage);
        refund->setObjectName(QString::fromUtf8("refund"));
        refund->setEnabled(true);
        refund->setGeometry(QRect(260, 80, 41, 23));
        label_6 = new QLabel(PassengerPage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(100, 132, 54, 20));
        label_7 = new QLabel(PassengerPage);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(200, 130, 54, 20));
        label_8 = new QLabel(PassengerPage);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(310, 130, 54, 20));
        label_9 = new QLabel(PassengerPage);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(450, 130, 54, 20));
        label_10 = new QLabel(PassengerPage);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(550, 130, 54, 21));
        label_11 = new QLabel(PassengerPage);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(630, 132, 54, 20));
        total = new QCheckBox(PassengerPage);
        total->setObjectName(QString::fromUtf8("total"));
        total->setGeometry(QRect(90, 110, 71, 16));
        half1 = new QCheckBox(PassengerPage);
        half1->setObjectName(QString::fromUtf8("half1"));
        half1->setGeometry(QRect(140, 110, 71, 16));
        half2 = new QCheckBox(PassengerPage);
        half2->setObjectName(QString::fromUtf8("half2"));
        half2->setGeometry(QRect(200, 110, 71, 16));
        half2->setMouseTracking(true);
        half2->setChecked(false);
        searchflight = new QPushButton(PassengerPage);
        searchflight->setObjectName(QString::fromUtf8("searchflight"));
        searchflight->setGeometry(QRect(310, 80, 41, 23));

        retranslateUi(PassengerPage);

        QMetaObject::connectSlotsByName(PassengerPage);
    } // setupUi

    void retranslateUi(QWidget *PassengerPage)
    {
        PassengerPage->setWindowTitle(QApplication::translate("PassengerPage", "\347\245\250\345\212\241\351\241\265\351\235\242", nullptr));
        label->setText(QApplication::translate("PassengerPage", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#ff0000;\">\344\271\230\345\256\242\347\245\250\345\212\241\347\256\241\347\220\206\351\241\265</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("PassengerPage", "\350\210\252\347\217\255\345\217\267\357\274\232", nullptr));
        label_3->setText(QApplication::translate("PassengerPage", "\346\234\200\344\274\230\350\210\252\347\217\255\357\274\232", nullptr));
        buy->setText(QApplication::translate("PassengerPage", "\350\264\255\347\245\250", nullptr));
        label_4->setText(QApplication::translate("PassengerPage", "\350\265\267\347\202\271\347\253\231\357\274\232", nullptr));
        label_5->setText(QApplication::translate("PassengerPage", "\347\233\256\346\240\207\347\253\231\357\274\232", nullptr));
        search->setText(QApplication::translate("PassengerPage", "\346\237\245\350\257\242", nullptr));
        back->setText(QApplication::translate("PassengerPage", "\350\277\224\345\233\236", nullptr));
        refund->setText(QApplication::translate("PassengerPage", "\351\200\200\347\245\250", nullptr));
        label_6->setText(QApplication::translate("PassengerPage", "\350\210\252\347\217\255\345\217\267", nullptr));
        label_7->setText(QApplication::translate("PassengerPage", "\347\212\266\346\200\201", nullptr));
        label_8->setText(QApplication::translate("PassengerPage", "\350\265\267\351\243\236\346\227\266\351\227\264", nullptr));
        label_9->setText(QApplication::translate("PassengerPage", "\350\200\227\346\227\266", nullptr));
        label_10->setText(QApplication::translate("PassengerPage", "\347\245\250\344\273\267", nullptr));
        label_11->setText(QApplication::translate("PassengerPage", "\344\275\231\347\245\250\346\225\260", nullptr));
        total->setText(QApplication::translate("PassengerPage", "\345\205\250\347\250\213", nullptr));
        half1->setText(QApplication::translate("PassengerPage", "\345\215\212\347\250\2131", nullptr));
        half2->setText(QApplication::translate("PassengerPage", "\345\215\212\347\250\2132", nullptr));
        searchflight->setText(QApplication::translate("PassengerPage", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PassengerPage: public Ui_PassengerPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSENGERPAGE_H
