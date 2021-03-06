#pragma once

#include <QWidget>
#include "ui_passengerpage.h"
#include"System.h"

class PassengerPage : public QWidget
{
	Q_OBJECT

public:
	PassengerPage(int passid,string flight,System* s,QWidget *parent = Q_NULLPTR);
	~PassengerPage();
signals:
	void sendsignal2();
private:
	string strpolish(string s, int len);
	bool println(Flight* fp);
	void clean();
	System* S;
	int passID;
	Ui::PassengerPage* ui;
private slots:
	void on_back_clicked();
	void on_total_clicked();
	void on_half1_clicked();
	void on_half2_clicked();
	void on_buy_clicked();
	void on_searchflight_clicked();
	void on_search_clicked();
	void on_refund_clicked();
	void on_price_clicked();
	void on_costtime_clicked();
	void on_left_clicked();
};
