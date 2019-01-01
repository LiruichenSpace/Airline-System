#include "passengerpage.h"
#include"qmessagebox.h"
#include<qdebug.h>
#pragma execution_character_set("utf-8")

PassengerPage::PassengerPage(int passid, string flight, System* s, QWidget *parent)
	: QWidget(parent),ui(new Ui::PassengerPage),passID(passid),S(s)
{
	ui->setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose, 1);
	Passenger* pp = S->FindPassenger(passid);
	qDebug() << passID<<endl;
	if (pp != nullptr) {//////////////�ѹ���״̬
		ui->buy->setEnabled(false);
		ui->refund->setEnabled(true);
		ui->total->setEnabled(false);
		ui->half1->setEnabled(false);
		ui->half2->setEnabled(false);
		ui->flightid->setText(QString::fromLocal8Bit(pp->flight->ID.c_str()));//���ó˿͵ĺ���
		ui->flightid->setEnabled(false);
		Flight*fp = S->FindFlight(pp->flight->ID);
		int flag;
		if (fp == pp->flight) {
			flag = 0; ui->total->setChecked(true);
		}
		else if (fp->FirstHalf == pp->flight) {
			flag = 1; ui->half1->setChecked(true);
		}
		else if (fp->SecondHalf == pp->flight) {
			flag = 2; ui->half2 ->setChecked(true);
		}
		if (pp->HaveTicket) {
			QMessageBox::information(NULL, u8"Notice", u8"���ѹ�Ʊ", QMessageBox::Yes , QMessageBox::Yes);

		}
		else {
			QMessageBox::information(NULL, u8"Notice", u8"����ԤԼ��Ʊ�У������ĵȴ�", QMessageBox::Yes , QMessageBox::Yes);
		}
	}
	else {
		QMessageBox message(QMessageBox::Information, u8"Notice", u8"�³˿ͣ��������빺Ʊ����", QMessageBox::Yes , NULL);
		bool flag = false;
		if (message.exec() == QMessageBox::Yes) {
			flag = true;
		}
		if (flag) {
			ui->buy->setEnabled(true);
			ui->refund->setEnabled(false);
			ui->searchflight->setEnabled(true);
			ui->total->setEnabled(true);
			ui->half1->setEnabled(true);
			ui->half2->setEnabled(true);
			if (!flight.empty()&&flight!=u8"�޴˺��࣬���������룡") {
				ui->flightid->setText(QString::fromLocal8Bit(flight.c_str()));
			}
		}
		
	}
}

PassengerPage::~PassengerPage(){
	delete ui;
}

string PassengerPage::strpolish(string s, int len)
{
	int num = len - s.length();
	for (num; num > 0; num--)s += " ";
	return s;
}
bool PassengerPage::println(Flight * fp){
	if (fp == nullptr)return false;
	string s;
	s += "    "+strpolish(fp->ID, 7)+u8"     ";
	if (fp->delayornot) {
		s += "delay          " ;
	}
	else {
		s += "ontime         ";
	} 
	s += strpolish(fp->TakeOff.tostring(),6)+"          "
		+strpolish(fp->CostTime.tostring(),6)+u8"       "
		+strpolish(to_string(fp->Price),6)+u8"      "
		+ strpolish(to_string(fp->LeftTickets),6);
	ui->textEdit->append(QString::fromLocal8Bit(s.c_str()));
	return true;
}
void PassengerPage::clean(){
	ui->textEdit->clear();
}
void PassengerPage::on_total_clicked() {
	ui->half1->setChecked(false);
	ui->half2->setChecked(false);
	/*string s((const char*)ui->flightid->text().toUtf8().data());
	Flight* fp = S->FindFlight(s);
	if (fp!=nullptr) {
		clean();
		println(fp);
	}*/
}
void PassengerPage::on_half1_clicked()
{
	ui->total->setChecked(false);
	ui->half2->setChecked(false);
}
void PassengerPage::on_half2_clicked()
{
	ui->total->setChecked(false);
	ui->half1->setChecked(false);
}
void PassengerPage::on_buy_clicked(){//ֻ�ڹ���ʱ�����³˿ͣ�
	if (ui->total->isChecked() || ui->half1->isChecked() || ui->half2->isChecked()) {
		string id((const char*)ui->flightid->text().toLocal8Bit().data());
		Flight* fp = S->FindFlight(id);
		if (ui->total->isChecked()) {
			
		}
		else if (ui->half1->isChecked()) {
			fp = fp->FirstHalf;
		}
		else if (ui->half2->isChecked()) {
			fp = fp->SecondHalf;
		}
		string info;
		if (fp->LeftTickets > 0) {
			info = "������ɹ�Ʊ���Ƿ�ȷ����";
		}
		else {
			info = "��Ʊ���㣬�Ƿ����ԤԼ��Ʊ��";
		}
		QMessageBox message(QMessageBox::Warning, "Warning",info.c_str(), QMessageBox::Yes | QMessageBox::No, NULL);
		bool flag = false;
		if (message.exec() == QMessageBox::Yes) {
			flag = true;
		}
		if (flag) {
			S->BuyTickets(fp, passID);
			/////////////////////��Ϊ�ѹ���״̬
			ui->buy->setEnabled(false);
			ui->refund->setEnabled(true);
			ui->searchflight->setEnabled(false);
			ui->total->setEnabled(false);
			ui->half1->setEnabled(false);
			ui->half2->setEnabled(false);
			ui->flightid->setEnabled(false);
			////////////////////////�����֪ͨ�Ƿ���Ʊ
		}
	}
	else {
		QMessageBox::critical(NULL, "Critical", u8"δѡ�񺽳̣�������ѡ��", QMessageBox::Yes, QMessageBox::Yes);
	}
}
void PassengerPage::on_searchflight_clicked(){
	string s(ui->flightid->text().toLocal8Bit().data());

	Flight* fp = S->FindFlight(s);
	if (fp != nullptr) {
		if (fp->FirstHalf != nullptr&&fp->SecondHalf != nullptr) {
			if (ui->half1->isChecked()) {
				clean();
				println(fp->FirstHalf);
				ui->fromcity->setText(QString::fromLocal8Bit(S->FindCityFromID(fp->FirstHalf->FromCityID).c_str()));
				ui->tocity->setText(QString::fromLocal8Bit(S->FindCityFromID(fp->FirstHalf->ToCityID).c_str()));
			}
			else if (ui->half2->isChecked()) {
				clean();
				println(fp->SecondHalf);
				ui->fromcity->setText(QString::fromLocal8Bit(S->FindCityFromID(fp->SecondHalf->FromCityID).c_str()));
				ui->tocity->setText(QString::fromLocal8Bit(S->FindCityFromID(fp->SecondHalf->ToCityID).c_str()));
			}
			else {
				clean();
				println(fp);
				ui->fromcity->setText(QString::fromLocal8Bit(S->FindCityFromID(fp->FromCityID).c_str()));
				ui->tocity->setText(QString::fromLocal8Bit(S->FindCityFromID(fp->ToCityID).c_str()));
			}
		}
		else {
			clean();
			ui->total->setChecked(true);
			ui->half1->setChecked(false);
			ui->half2->setChecked(false);
			println(fp);
			ui->fromcity->setText(QString::fromLocal8Bit(S->FindCityFromID(fp->FromCityID).c_str()));
			ui->tocity->setText(QString::fromLocal8Bit(S->FindCityFromID(fp->ToCityID).c_str()));
		}
	}
	else {
		ui->flightid->setText(u8"�޴˺��࣬����������");
	}

}
void PassengerPage::on_search_clicked(){
	clean();
	string c1((const char*)ui->fromcity->text().toLocal8Bit().data());
	string c2((const char*)ui->tocity->text().toLocal8Bit().data());
	if (!c1.empty() && !c2.empty()) {
		FNode* head = S->FindFlights(S->GetCityID(c1), S->GetCityID(c2));
		FNode* temp = head;
		while (temp != nullptr) {
			println(temp->fp);
			temp = temp->next;
		}
		FlightManager a; a.Destroyer(head);
	}
}
void PassengerPage::on_refund_clicked() {
	string s((const char*)ui->flightid->text().toLocal8Bit().data());
	Passenger* pp = S->FindPassenger(passID);
	QMessageBox message(QMessageBox::Warning, u8"Warning", u8"��ȷ��Ҫ��Ʊ��", QMessageBox::Yes | QMessageBox::No, NULL);
	bool flag = false;
	if (message.exec() == QMessageBox::Yes) {
		flag = true;
	}
	if (flag) {
		S->GetRefund(pp);
		////////////////////////////����Ϊ��Ʊ����
		ui->buy->setEnabled(true);
		ui->refund->setEnabled(false);
		ui->searchflight->setEnabled(true);
		ui->total->setEnabled(true);
		ui->half1->setEnabled(true);
		ui->half2->setEnabled(true);
		ui->flightid->clear();
		ui->flightid->setEnabled(true);
	}
}
void PassengerPage::on_price_clicked(){
	clean();
	string c1((const char*)ui->fromcity->text().toLocal8Bit().data());
	string c2((const char*)ui->tocity->text().toLocal8Bit().data());
	if (!c1.empty() && !c2.empty()) {
		FNode* head = S->FindFlights(S->GetCityID(c1), S->GetCityID(c2));
		head = FlightManager::SortByPrice(head);
		FNode* temp = head;
		while (temp != nullptr) {
			println(temp->fp);
			temp = temp->next;
		}
		FlightManager::Destroyer(head);
	}
}
void PassengerPage::on_costtime_clicked(){
	clean();
	string c1((const char*)ui->fromcity->text().toLocal8Bit().data());
	string c2((const char*)ui->tocity->text().toLocal8Bit().data());
	if (!c1.empty() && !c2.empty()) {
		FNode* head = S->FindFlights(S->GetCityID(c1), S->GetCityID(c2));
		head = FlightManager::SortByTime(head);
		FNode* temp = head;
		while (temp != nullptr) {
			println(temp->fp);
			temp = temp->next;
		}
		FlightManager::Destroyer(head);
	}
}
void PassengerPage::on_left_clicked(){
	clean();
	string c1((const char*)ui->fromcity->text().toLocal8Bit().data());
	string c2((const char*)ui->tocity->text().toLocal8Bit().data());
	if (!c1.empty() && !c2.empty()) {
		FNode* head = S->FindFlights(S->GetCityID(c1), S->GetCityID(c2));
		head = FlightManager::SortByTickets(head);
		FNode* temp = head;
		while (temp != nullptr) {
			println(temp->fp);
			temp = temp->next;
		}
		FlightManager::Destroyer(head);
	}
}
void PassengerPage::on_back_clicked() {
	emit sendsignal2();
	this->close();
}