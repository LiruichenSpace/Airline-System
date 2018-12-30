#include "qtfirst.h"
#include<string>
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
	ui.airline->setText(QString::fromLocal8Bit(fp->Airline.c_str()));
	ui.takeoff->setText(QString::fromLocal8Bit(fp->TakeOff.tostring().c_str()));
	ui.fromcity->setText(QString::fromLocal8Bit(S.FindCityFromID(fp->FromCityID).c_str()));
	ui.tocity->setText(QString::fromLocal8Bit(S.FindCityFromID(fp->ToCityID).c_str()));
	ui.toland->setText(QString::fromLocal8Bit(fp->Land.tostring().c_str()));
	ui.totalleft->setText(QString::fromLocal8Bit(to_string(fp->LeftTickets).c_str()));
	ui.costtime->setText(QString::fromLocal8Bit(fp->CostTime.tostring().c_str()));
	ui.totalprice->setText(QString::fromLocal8Bit(to_string(fp->Price).c_str()));
	if (!fp->IsHalfFlight&&fp->FirstHalf != nullptr&&fp->SecondHalf != nullptr) {//гажазЊ
		ui.midcity->setText(QString::fromLocal8Bit(S.FindCityFromID(fp->FirstHalf->ToCityID).c_str()));
		ui.midland->setText(QString::fromLocal8Bit(fp->FirstHalf->Land.tostring().c_str()));
		ui.midtakeoff->setText(QString::fromLocal8Bit(fp->SecondHalf->TakeOff.tostring().c_str()));
		ui.firstleft->setText(QString::fromLocal8Bit(to_string(fp->FirstHalf->LeftTickets).c_str()));
		ui.secondleft->setText(QString::fromLocal8Bit(to_string(fp->SecondHalf->LeftTickets).c_str()));
		ui.firstprice->setText(QString::fromLocal8Bit(to_string(fp->FirstHalf->Price).c_str()));
		ui.secondprice->setText(QString::fromLocal8Bit(to_string(fp->SecondHalf->Price).c_str()));
	}
	else {
		ui.midcity->setText("NULL");
		ui.midland->setText("NULL");
		ui.midtakeoff->setText("NULL");
		ui.firstleft->setText("NULL");
		ui.secondleft->setText("NULL");
		ui.firstprice->setText("NULL");
		ui.secondprice->setText("NULL");
	}
}

void Qtfirst::on_managerlogin_clicked()
{
}
