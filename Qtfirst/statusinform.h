#pragma once

#include <QWidget>
#include "ui_statusinform.h"
#include"System.h"

class statusInform : public QWidget
{
	Q_OBJECT

public:
	statusInform(System* s,Flight* flight,bool flag,QWidget *parent = Q_NULLPTR);//flag为true则为取消false为延误
	~statusInform();
signals:
	void signal();
private:
	Ui::statusInform* ui;
	System* S;
	void println(Passenger* pp);
	void printpassenger(Flight* fp);
private slots:
	void on_back_clicked();
};
