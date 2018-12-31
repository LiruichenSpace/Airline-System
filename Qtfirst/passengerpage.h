#pragma once

#include <QWidget>
#include "ui_passengerpage.h"
#include"System.h"

class PassengerPage : public QWidget
{
	Q_OBJECT

public:
	PassengerPage(string passid,string flight,System* s,QWidget *parent = Q_NULLPTR);
	~PassengerPage();
signals:
	void sendsignal2();
private:
	string strpolish(string s, int len);
	bool println(Flight* fp);
	void clean();
	System* S;
	string passID;
	Ui::PassengerPage* ui;
private slots:
	void on_back_clicked();
	void on_total_clicked();
	void on_half1_clicked();
	void on_half2_clicked();
	void on_buy_clicked();
	void on_searchflight_clicked();
	void on_search_clicked();
};
