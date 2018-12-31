#include "statusinform.h"
#pragma execution_character_set("utf-8")
statusInform::statusInform(System* s,Flight*flight,bool flag,QWidget *parent)
	: QWidget(parent),ui(new Ui::statusInform),S(s)
{
	ui->setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose, 1);
	Flight* fp = nullptr;
	if (flag)ui->status->setText(u8"取消");
	else ui->status->setText(u8"延误");
	ui->flightid->setText(QString::fromLocal8Bit(flight->ID.c_str()));
	
	fp = S->FindLatest(flight->TakeOff, flight->ID,flight->FromCityID, flight->ToCityID);
	ui->tc1->setText(QString::fromLocal8Bit(S->FindCityFromID(flight->FromCityID).c_str()));
	ui->tc2->setText(QString::fromLocal8Bit(S->FindCityFromID(flight->ToCityID).c_str()));
	if (fp != nullptr) {
		ui->tf->setText(QString::fromLocal8Bit(fp->ID.c_str()));
	}
	else {
		ui->tf->setText(u8"无满足条件航班");
	}
	if (flight->FirstHalf != nullptr&&flight->SecondHalf != nullptr) {
		fp = S->FindLatest(flight->TakeOff, flight->ID, flight->FromCityID, flight->FirstHalf->ToCityID);
		ui->fc1->setText(QString::fromLocal8Bit(S->FindCityFromID(flight->FromCityID).c_str()));
		ui->fc2->setText(QString::fromLocal8Bit(S->FindCityFromID(flight->FirstHalf->ToCityID).c_str()));
		if (fp != nullptr) {
			ui->ff->setText(QString::fromLocal8Bit(fp->ID.c_str()));
		}
		else {
			ui->ff->setText(u8"无满足条件航班");
		}
		fp = S->FindLatest(flight->SecondHalf->TakeOff, flight->ID, flight->SecondHalf->FromCityID, flight->ToCityID);
		ui->sc1->setText(QString::fromLocal8Bit(S->FindCityFromID(flight->SecondHalf->FromCityID).c_str()));
		ui->sc2->setText(QString::fromLocal8Bit(S->FindCityFromID(flight->ToCityID).c_str()));
		if (fp != nullptr) {
			ui->sf->setText(QString::fromLocal8Bit(fp->ID.c_str()));
		}
		else {
			ui->sf->setText(u8"无满足条件航班");
		}
	}
}

statusInform::~statusInform(){
	delete ui;
}
void statusInform::on_back_clicked() {
	emit signal();
	this->close();
}