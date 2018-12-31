/********************************************************************************
** Form generated from reading UI file 'statusinform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATUSINFORM_H
#define UI_STATUSINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_statusInform
{
public:
    QTextEdit *passengers;
    QLineEdit *tf;
    QPushButton *back;
    QLabel *maininform;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *passengers2;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *flightid;
    QLineEdit *status;
    QLineEdit *tc1;
    QLineEdit *tc2;
    QLineEdit *fc1;
    QLineEdit *fc2;
    QLabel *label_7;
    QLineEdit *sc1;
    QLineEdit *sc2;
    QLabel *label_8;
    QLineEdit *ff;
    QLineEdit *sf;

    void setupUi(QWidget *statusInform)
    {
        if (statusInform->objectName().isEmpty())
            statusInform->setObjectName(QString::fromUtf8("statusInform"));
        statusInform->resize(577, 384);
        passengers = new QTextEdit(statusInform);
        passengers->setObjectName(QString::fromUtf8("passengers"));
        passengers->setGeometry(QRect(150, 120, 104, 131));
        tf = new QLineEdit(statusInform);
        tf->setObjectName(QString::fromUtf8("tf"));
        tf->setEnabled(false);
        tf->setGeometry(QRect(300, 260, 101, 21));
        back = new QPushButton(statusInform);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(430, 260, 81, 81));
        maininform = new QLabel(statusInform);
        maininform->setObjectName(QString::fromUtf8("maininform"));
        maininform->setGeometry(QRect(170, 20, 241, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\264\240\346\231\264\345\255\227\344\275\223"));
        maininform->setFont(font);
        label_2 = new QLabel(statusInform);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 110, 111, 31));
        label_3 = new QLabel(statusInform);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 260, 91, 21));
        label_4 = new QLabel(statusInform);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(260, 110, 111, 31));
        passengers2 = new QTextEdit(statusInform);
        passengers2->setObjectName(QString::fromUtf8("passengers2"));
        passengers2->setGeometry(QRect(380, 120, 104, 131));
        label = new QLabel(statusInform);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 260, 21, 21));
        label_5 = new QLabel(statusInform);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 70, 111, 21));
        label_6 = new QLabel(statusInform);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(290, 70, 111, 21));
        flightid = new QLineEdit(statusInform);
        flightid->setObjectName(QString::fromUtf8("flightid"));
        flightid->setEnabled(false);
        flightid->setGeometry(QRect(130, 70, 113, 21));
        status = new QLineEdit(statusInform);
        status->setObjectName(QString::fromUtf8("status"));
        status->setEnabled(false);
        status->setGeometry(QRect(370, 70, 113, 20));
        tc1 = new QLineEdit(statusInform);
        tc1->setObjectName(QString::fromUtf8("tc1"));
        tc1->setEnabled(false);
        tc1->setGeometry(QRect(120, 260, 71, 20));
        tc2 = new QLineEdit(statusInform);
        tc2->setObjectName(QString::fromUtf8("tc2"));
        tc2->setEnabled(false);
        tc2->setGeometry(QRect(220, 260, 71, 20));
        fc1 = new QLineEdit(statusInform);
        fc1->setObjectName(QString::fromUtf8("fc1"));
        fc1->setEnabled(false);
        fc1->setGeometry(QRect(120, 290, 71, 20));
        fc2 = new QLineEdit(statusInform);
        fc2->setObjectName(QString::fromUtf8("fc2"));
        fc2->setEnabled(false);
        fc2->setGeometry(QRect(220, 290, 71, 20));
        label_7 = new QLabel(statusInform);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(200, 290, 21, 21));
        sc1 = new QLineEdit(statusInform);
        sc1->setObjectName(QString::fromUtf8("sc1"));
        sc1->setEnabled(false);
        sc1->setGeometry(QRect(120, 320, 71, 20));
        sc2 = new QLineEdit(statusInform);
        sc2->setObjectName(QString::fromUtf8("sc2"));
        sc2->setEnabled(false);
        sc2->setGeometry(QRect(220, 320, 71, 20));
        label_8 = new QLabel(statusInform);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(200, 320, 21, 21));
        ff = new QLineEdit(statusInform);
        ff->setObjectName(QString::fromUtf8("ff"));
        ff->setEnabled(false);
        ff->setGeometry(QRect(300, 290, 101, 21));
        sf = new QLineEdit(statusInform);
        sf->setObjectName(QString::fromUtf8("sf"));
        sf->setEnabled(false);
        sf->setGeometry(QRect(300, 320, 101, 21));

        retranslateUi(statusInform);

        QMetaObject::connectSlotsByName(statusInform);
    } // setupUi

    void retranslateUi(QWidget *statusInform)
    {
        statusInform->setWindowTitle(QApplication::translate("statusInform", "statusInform", nullptr));
        back->setText(QApplication::translate("statusInform", "\347\241\256\345\256\232", nullptr));
        maininform->setText(QApplication::translate("statusInform", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\347\264\240\346\231\264\345\255\227\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:18pt; font-weight:600; color:#ff0000;\">\350\210\252\347\217\255\345\273\266\350\257\257/\345\217\226\346\266\210\351\200\232\347\237\245</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("statusInform", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\345\267\262\350\264\255\347\245\250\346\227\205\345\256\242\357\274\232</span></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("statusInform", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\346\216\250\350\215\220\350\210\252\347\217\255\357\274\232</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("statusInform", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\347\255\211\345\276\205\346\212\242\347\245\250\346\227\205\345\256\242\357\274\232</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("statusInform", "\345\210\260", nullptr));
        label_5->setText(QApplication::translate("statusInform", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\345\275\261\345\223\215\350\210\252\347\217\255\357\274\232</span></p></body></html>", nullptr));
        label_6->setText(QApplication::translate("statusInform", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\350\210\252\347\217\255\347\212\266\346\200\201\357\274\232</span></p></body></html>", nullptr));
        label_7->setText(QApplication::translate("statusInform", "\345\210\260", nullptr));
        label_8->setText(QApplication::translate("statusInform", "\345\210\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class statusInform: public Ui_statusInform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATUSINFORM_H
