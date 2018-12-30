#include "qtfirst.h"
#include<string>
#include"managerwid.h"
using namespace std;
#pragma execution_character_set("utf-8")
Qtfirst::Qtfirst(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}
void Qtfirst::on_searchflight_clicked() {
	string s((const char*)ui.flightID->text().toUtf8().data());
	Flight* fp=S.FindFlight(s);
	if (fp != nullptr) {
		if (fp->delayornot) {
			ui.flightstatus->setText(u8"延误");
		}
		else ui.flightstatus->setText(u8"正点");
		ui.airline->setText(QString::fromLocal8Bit(fp->Airline.c_str()));
		ui.takeoff->setText(QString::fromLocal8Bit(fp->TakeOff.tostring().c_str()));
		ui.fromcity->setText(QString::fromLocal8Bit(S.FindCityFromID(fp->FromCityID).c_str()));
		ui.tocity->setText(QString::fromLocal8Bit(S.FindCityFromID(fp->ToCityID).c_str()));
		ui.toland->setText(QString::fromLocal8Bit(fp->Land.tostring().c_str()));
		ui.totalleft->setText(QString::fromLocal8Bit(to_string(fp->LeftTickets).c_str()));
		ui.costtime->setText(QString::fromLocal8Bit(fp->CostTime.tostring().c_str()));
		ui.totalprice->setText(QString::fromLocal8Bit(to_string(fp->Price).c_str()));
		if (!fp->IsHalfFlight&&fp->FirstHalf != nullptr&&fp->SecondHalf != nullptr) {//有中转
			ui.midcity->setText(QString::fromLocal8Bit(S.FindCityFromID(fp->FirstHalf->ToCityID).c_str()));
			ui.midland->setText(QString::fromLocal8Bit(fp->FirstHalf->Land.tostring().c_str()));
			ui.midtakeoff->setText(QString::fromLocal8Bit(fp->SecondHalf->TakeOff.tostring().c_str()));
			ui.firstleft->setText(QString::fromLocal8Bit(to_string(fp->FirstHalf->LeftTickets).c_str()));
			ui.secondleft->setText(QString::fromLocal8Bit(to_string(fp->SecondHalf->LeftTickets).c_str()));
			ui.firstprice->setText(QString::fromLocal8Bit(to_string(fp->FirstHalf->Price).c_str()));
			ui.secondprice->setText(QString::fromLocal8Bit(to_string(fp->SecondHalf->Price).c_str()));
		}
		else {
			ui.midcity->setText(u8"NULL");
			ui.midland->setText(u8"NULL");
			ui.midtakeoff->setText(u8"NULL");
			ui.firstleft->setText(u8"NULL");
			ui.secondleft->setText(u8"NULL");
			ui.firstprice->setText(u8"NULL");
			ui.secondprice->setText(u8"NULL");
		}
	}
	else {
		ui.flightID->setText(u8"无此航班，请重新输入！");
	}
}

void Qtfirst::on_managerlogin_clicked(){
	string s((const char*)ui.managerpassword->text().toUtf8().data());
	if (s=="123456") {
		this->hide();    
		managerWid * managewid = new managerWid(&S);
		connect(managewid,SIGNAL(sendsignal()),this,SLOT(reshow()));
		managewid->show();//子界面出现}
	}
}

void Qtfirst::reshow()
{
	this->show();
}
