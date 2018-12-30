#include "managerwid.h"
#include"qmessagebox.h"
using namespace std;
#pragma execution_character_set("utf-8")
managerWid::managerWid(System* s,QWidget *parent)
	: QWidget(parent),ui(new Ui::managerWid),S(s),mode(false)//falseΪ��ȡ����
{
	ui->setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose, 1);
}

managerWid::~managerWid(){
	delete ui;
}
void managerWid::on_searchflight_clicked(){
	string s((const char*) ui->flightID->text().toUtf8().data());
	Flight* fp = S->FindFlight(s);
	if (fp != nullptr) {
		if (fp->delayornot) {
			ui->flightstatus->setText(u8"����");
		}
		else ui->flightstatus->setText(u8"����");
		ui->airline->setText(QString::fromLocal8Bit(fp->Airline.c_str()));
		ui->takeoff->setText(QString::fromLocal8Bit(fp->TakeOff.tostring().c_str()));
		ui->fromcity->setText(QString::fromLocal8Bit(S->FindCityFromID(fp->FromCityID).c_str()));
		ui->tocity->setText(QString::fromLocal8Bit(S->FindCityFromID(fp->ToCityID).c_str()));
		ui->toland->setText(QString::fromLocal8Bit(fp->Land.tostring().c_str()));
		ui->totalleft->setText(QString::fromLocal8Bit(to_string(fp->LeftTickets).c_str()));
		ui->costtime->setText(QString::fromLocal8Bit(fp->CostTime.tostring().c_str()));
		ui->totalprice->setText(QString::fromLocal8Bit(to_string(fp->Price).c_str()));
		if (fp->FirstHalf != nullptr&&fp->SecondHalf != nullptr) {//����ת
			ui->midcity->setText(QString::fromLocal8Bit(S->FindCityFromID(fp->FirstHalf->ToCityID).c_str()));
			ui->midland->setText(QString::fromLocal8Bit(fp->FirstHalf->Land.tostring().c_str()));
			ui->midtakeoff->setText(QString::fromLocal8Bit(fp->SecondHalf->TakeOff.tostring().c_str()));
			ui->firstleft->setText(QString::fromLocal8Bit(to_string(fp->FirstHalf->LeftTickets).c_str()));
			ui->secondleft->setText(QString::fromLocal8Bit(to_string(fp->SecondHalf->LeftTickets).c_str()));
			ui->firstprice->setText(QString::fromLocal8Bit(to_string(fp->FirstHalf->Price).c_str()));
			ui->secondprice->setText(QString::fromLocal8Bit(to_string(fp->SecondHalf->Price).c_str()));
		}
		else {
			ui->midcity->setText(u8"NULL");
			ui->midland->setText(u8"NULL");
			ui->midtakeoff->setText(u8"NULL");
			ui->firstleft->setText(u8"NULL");
			ui->secondleft->setText(u8"NULL");
			ui->firstprice->setText(u8"NULL");
			ui->secondprice->setText(u8"NULL");
		}
	}
	else {
		ui->flightID->setText(u8"�޴˺��࣬���������룡");
	}
}
void managerWid::on_confirm_clicked(){//����delay
	if (mode == false) {
		string s = (const char*)ui->flightID->text().toUtf8().data();
		Flight* fp = S->FindFlight(s);
		if (fp != nullptr) {
			fp->Price = atoi(((string)ui->totalprice->text().toUtf8().data()).c_str());
			fp->LeftTickets = atoi(((string)ui->totalleft->text().toUtf8().data()).c_str());
			if (fp->FirstHalf != nullptr&&fp->SecondHalf != nullptr) {
				fp->FirstHalf->Price = atoi(((string)ui->firstprice->text().toUtf8().data()).c_str());
				fp->SecondHalf->Price = atoi(((string)ui->secondprice->text().toUtf8().data()).c_str());
				fp->FirstHalf->LeftTickets = atoi(((string)ui->firstleft->text().toUtf8().data()).c_str());
				fp->SecondHalf->LeftTickets = atoi(((string)ui->secondleft->text().toUtf8().data()).c_str());
			}
			Time time = fp->TakeOff;
			Time curr; curr.SetTime(((string)ui->takeoff->text().toUtf8().data()).c_str());
			if (curr > time) {//ʱ��ı�
				QMessageBox message(QMessageBox::Warning, "Warning", u8"����ʱ��ı䣬�������Ƿ�ȷ����", QMessageBox::Yes | QMessageBox::No, NULL);
				bool flag = false;
				if (message.exec() == QMessageBox::Yes) {
					flag = true;
				}
				if (flag) {

					//S->Delay((const char*)ui->flightID->text().toUtf8().data(), curr - time);
				}
			}
		}
	}
	else {//��ǰΪ����ģʽ
		//��װ�º���
		string id = ui->flightID->text().toLocal8Bit();
		string status = ui->flightstatus->text().toLocal8Bit();
		string com = ui->airline->text().toLocal8Bit();
		string from = ui->fromcity->text().toLocal8Bit();
		string to = ui->tocity->text().toLocal8Bit();
		string mid = ui->midcity->text().toLocal8Bit();
		string off1 = ui->takeoff->text().toLocal8Bit();
		string land1 = ui->midland->text().toLocal8Bit();
		string off2 = ui->midtakeoff->text().toLocal8Bit();
		string land2 = ui->toland->text().toLocal8Bit();
		string left1 = ui->totalleft->text().toLocal8Bit();
		string left2 = ui->firstleft->text().toLocal8Bit();
		string left3 = ui->secondleft->text().toLocal8Bit();
		string pri1 = ui->totalprice->text().toLocal8Bit();
		string pri2 = ui->firstprice->text().toLocal8Bit();
		string pri3 = ui->secondprice->text().toLocal8Bit();
		if (!(id.empty() || com.empty() || from.empty() || to.empty() || off1.empty() || land2.empty()
			|| left1.empty() || pri1.empty())&&S->FindFlight(id)==nullptr) {//��Щ�ַ���������Ϣ�����º���
			Flight* flight = new Flight();
			flight->Airline = com;
			flight->ID = id;
			if (status == "����")flight->delayornot = true;
			else flight->delayornot = false;
			flight->TakeOff.SetTime(off1);
			flight->Land.SetTime(land2);
			flight->FromCityID= S->GetCityID(from);
			flight->ToCityID = S->GetCityID(to);
			flight->CostTime = flight->Land - flight->TakeOff;
			flight->LeftTickets = atoi(left1.c_str());
			flight->Price = atoi(pri1.c_str());//�Ǿ�ͣ�������
			if (!(mid.empty() || land1.empty() || off2.empty() || left2.empty() 
				|| left3.empty() || pri2.empty() || pri3.empty())) {//�жϾ�ͣ��Ϣ�Ƿ���ȫ
				Flight* first = new Flight(); flight->ID = id; flight->Airline = com; flight->IsHalfFlight = true;
				Flight* second = new Flight(); second->ID = id; second->Airline = com; flight->IsHalfFlight = true;
				first->TakeOff = flight->TakeOff; first->Land.SetTime(land1); first->delayornot = flight->delayornot;
				second->TakeOff.SetTime(off2); second->Land = flight->Land; second->delayornot = flight->delayornot;
				first->CostTime = first->Land - first->TakeOff; first->FromCityID = flight->FromCityID;
				first->Price = atoi(pri2.c_str()); first->LeftTickets = atoi(left2.c_str());
				first->ToCityID= S->GetCityID(mid);
				second->CostTime = second->Land - second->TakeOff; second->FromCityID = S->GetCityID(mid);
				second->Price = atoi(pri3.c_str()); second->LeftTickets = atoi(left3.c_str());
				second->ToCityID = flight->ToCityID;
				flight->FirstHalf = first; flight->SecondHalf = second;
			}
			QMessageBox message(QMessageBox::Warning, "Warning", u8"���������Ӻ��࣬�Ƿ�ȷ����", QMessageBox::Yes | QMessageBox::No, NULL);
			bool flag = false;
			if (message.exec() == QMessageBox::Yes) {
				flag = true;
			}
			if (flag) {
				S->AddNewFlight(flight);
			}
			else delete flight;
		}
		else {
			QMessageBox::critical(NULL, "Critical", "������Ϣ����ȫ�����ʧ��", QMessageBox::Yes, QMessageBox::Yes);
		}
		////////////////////////////////////////////������Ϊֻ��
		ui->flightstatus->setEnabled(false);
		ui->flightstatus->clear();
		ui->airline->setEnabled(false);
		ui->airline->clear();
		ui->fromcity->setEnabled(false);
		ui->fromcity->clear();
		ui->midcity->setEnabled(false);
		ui->midcity->clear();
		ui->tocity->setEnabled(false);
		ui->tocity->clear();
		ui->midtakeoff->setEnabled(false);
		ui->midtakeoff->clear();
		ui->midland->setEnabled(false);
		ui->midland->clear();
		ui->toland->setEnabled(false);
		ui->toland->clear();
		ui->flightID->clear();
		ui->firstleft->clear();
		ui->totalleft->clear();
		ui->secondleft->clear();
		ui->totalprice->clear();
		ui->firstprice->clear();
		ui->takeoff->clear();
		ui->secondprice->clear();
		ui->costtime->clear();
		mode = false;
	}
}
void managerWid::on_cancel_clicked(){
	QMessageBox message(QMessageBox::Warning, "Warning", u8"����ȡ�����࣬�Ƿ�ȷ����", QMessageBox::Yes | QMessageBox::No, NULL);
	bool flag = false;
	if (message.exec() == QMessageBox::Yes){
		flag = true;
	}
	if (flag) {
		//string s = (const char*)ui->flightID->text().toUtf8().data();
		//S->Cancel(s);
	}
}
void managerWid::on_addflight_clicked(){
	QMessageBox message(QMessageBox::Warning, "Warning", u8"��������º��࣬�Ƿ�ȷ����", QMessageBox::Yes | QMessageBox::No, NULL);
	bool flag = false;
	if (message.exec() == QMessageBox::Yes) {
		flag = true;
	}
	if (flag) {
		mode = true;
		ui->flightstatus->setEnabled(true);
		ui->flightstatus->clear();
		ui->flightID->clear();
		ui->firstleft->clear();
		ui->totalleft->clear();
		ui->secondleft->clear();
		ui->totalprice->clear();
		ui->firstprice->clear();
		ui->takeoff->clear();
		ui->secondprice->clear();
		ui->costtime->clear();
		ui->airline->setEnabled(true);
		ui->airline->clear();
		ui->fromcity->setEnabled(true);
		ui->fromcity->clear();
		ui->midcity->setEnabled(true);
		ui->midcity->clear();
		ui->tocity->setEnabled(true);
		ui->tocity->clear();
		ui->midtakeoff->setEnabled(true);
		ui->midtakeoff->clear();
		ui->midland->setEnabled(true);
		ui->midland->clear();
		ui->toland->setEnabled(true);
		ui->toland->clear();
	}
}
void managerWid::on_back_clicked() {
	emit sendsignal();
	this->close();
}