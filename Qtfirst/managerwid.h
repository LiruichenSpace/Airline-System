#pragma once

#include <QWidget>
#include "ui_managerwid.h"
#include"System.h"
class managerWid : public QWidget
{
	Q_OBJECT

public:
	managerWid(System* s,QWidget *parent = Q_NULLPTR);
	~managerWid();

private:
	System* S;
	Ui::managerWid *ui;
	bool mode;
signals:
	void sendsignal();
private slots:
	void on_back_clicked();
	void on_searchflight_clicked();
	void on_confirm_clicked();//ÅÐ¶Ïdelay
	void on_cancel_clicked();
	void on_addflight_clicked();
};
