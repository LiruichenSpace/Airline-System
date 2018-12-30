#include "stdafx.h"
#include "System.h"
#include<iostream>
#include<fstream>

using namespace std;

System::System()
{
	LoadFlights();
	LoadPassenger();
}


System::~System(){
	SaveFlights();
}

void System::Delay(string FlightID, Time delay){

		Flight* f = flightmanager.FindFlightByID(FlightID);

		PNode* p = f->GetPassengers();

		cout << "ID为" << FlightID << "的航班将延迟至" << delay.Hour << "时" << delay.Min << "分" << "," << "以下是航班延迟乘客的ID:" << endl;

		while (p->next != NULL) {

			cout << p->pp->ID << " ";

			p = p->next;

		}

}

void System::Cancel(string FlightID){
	Flight* f = flightmanager.FindFlightByID(FlightID);

	PNode* p = f->GetPassengers();

	cout << "ID为" << FlightID << "的航班将取消" << "," << "以下是航班取消乘客的ID:" << endl;

	while (p->next != NULL) {

		cout << p->pp->ID << " ";

		p = p->next;

	}


}

Flight * System::LoadFlights()//直接读取全部航班信息
{
	Flight* flight = nullptr;
	Flight* first = nullptr;
	Flight* second = nullptr;
	Flight* head = nullptr;
	bool flag;
	Time time;
	ifstream fp("FlightData.txt");
	if (!fp) { cout << "file error" << endl; return nullptr; }
	string s;
	char ch;
	while (!fp.eof()) {
		flight = new Flight();
		fp >> s;
		if (s == "####")break;
		flight->Airline = s;
		fp >> flight->ID;
		fp >> ch;
		if (ch == 'Y')flight->delayornot=true;
		else flight->delayornot = false;
		fp >> s; flight->TakeOff.SetTime(s);
		fp >> ch;
		if (ch == 'Y') {
			first = new Flight(); first->Airline = flight->Airline; first->ID = flight->ID; first->TakeOff = flight->TakeOff;
			second = new Flight(); second->Airline = flight->Airline; second->ID = flight->ID;
			flag = true;
			first->IsHalfFlight = true;
			second->IsHalfFlight = true;
			first->delayornot = flight->delayornot;
			second->delayornot = flight->delayornot;
		}
		else flag = false;
		fp >> s;
		flight->FromCityID = citygraph.GetIDFromName(s);
		if (flag) {
			fp >> s;
			first->ToCityID = citygraph.GetIDFromName(s); first->FromCityID = flight->FromCityID;
			second->FromCityID = first->ToCityID;
		}
		fp >> s;
		flight->ToCityID = citygraph.GetIDFromName(s);
		fp >> flight->Price;
		if (flag) { fp >> first->Price; fp >> second->Price; second->ToCityID = flight->ToCityID; }
		fp >> s; flight->CostTime.SetTime(s);
		if(flag){ fp >> s; first->CostTime.SetTime(s); fp >> s; second->CostTime.SetTime(s);
		}
		fp >> s; flight->Land.SetTime(s);
		if (flag) {
			fp >> s; second->TakeOff.SetTime(s);
			fp >> s; first->Land.SetTime(s);
		}
		fp >> flight->LeftTickets;
		if (flag) {
			fp >> first->LeftTickets;
			fp >> second->LeftTickets;
			flight->FirstHalf = first;
			flight->SecondHalf = second;
		}
		if (head == nullptr)head = flight;
		else {
			head->pre = flight;
			flight->next = head;
		}
		citygraph.AddFlight(flight);
		//cout << flight->ID << endl;
		head = flight;
		flight = nullptr;
		first = nullptr;
		second = nullptr;
	}
	flightmanager.Head = head;
	fp.close();
	return head;
}

FNode * System::FindOthers(Flight * f){
	return citygraph.FindOtherFlights(f);
}

FNode * System::FindFlightsByAirline(string airline){
	return flightmanager.FindFlightsByAirline(airline);
}

void System::ShowFlights(FNode * node){
	ShowHint();
	node = flightmanager.SortByTickets(node);
	FNode* temp = node;
	Flight* flight = nullptr;
	while (temp != nullptr) {
		flight = temp->fp;
		cout << flight->ID << "   " << citygraph.GetCityName(flight->FromCityID) << "       " << flight->TakeOff << "    ";
		cout << citygraph.GetCityName(flight->ToCityID) << "     " << flight->Land << "     " << flight->Price << "      ";
		cout << flight->LeftTickets << "          ";
		if (flight->FirstHalf != nullptr)cout << "是" << endl;
		else cout << "否" << endl;
		temp = temp->next;
	}
	if (node == nullptr)cout << "未找到目标航班" << endl;
}

void System::ShowFlight(Flight * flight){
	if (flight != nullptr) {
		ShowHint();
		cout << flight->ID << "   " << citygraph.GetCityName(flight->FromCityID) << "       " << flight->TakeOff << "    ";
		cout << citygraph.GetCityName(flight->ToCityID) << "     " << flight->Land << "     " << flight->Price << "      ";
		cout << flight->LeftTickets << "          ";
		if (flight->FirstHalf != nullptr)cout << "是"<<endl;
		else cout << "否" << endl;
	}
	else cout << "无此航班";
}

Flight * System::FindFlight(string flightID)
{
	return flightmanager.FindFlightByID(flightID);
}

Flight * System::BuildFlight(){
	Flight* flight = new Flight();
	Flight* first=nullptr;
	Flight* second=nullptr;
	bool flag;
	string s;
	char ch;
	cin >> s;
	flight->Airline = s;
	cin >> flight->ID;
	cin >> ch;
	if (ch == 'Y')flight->delayornot = true;
	else flight->delayornot = false;
	cin >> s; flight->TakeOff.SetTime(s);
	cin >> ch;
	if (ch == 'Y') {
		first = new Flight(); first->Airline = flight->Airline; first->ID = flight->ID; first->TakeOff = flight->TakeOff;
		second = new Flight(); second->Airline = flight->Airline; second->ID = flight->ID;
		flag = true;
		first->IsHalfFlight = true;
		second->IsHalfFlight = true;
		first->delayornot = flight->delayornot;
		second->delayornot = flight->delayornot;
	}
	else flag = false;
	cin >> s;
	flight->FromCityID = citygraph.GetIDFromName(s);
	if (flag) {
		cin >> s;
		first->ToCityID = citygraph.GetIDFromName(s); first->FromCityID = flight->FromCityID;
		second->FromCityID = first->ToCityID;
	}
	cin >> s;
	flight->ToCityID = citygraph.GetIDFromName(s);
	cin >> flight->Price;
	if (flag) { cin >> first->Price; cin >> second->Price; second->ToCityID = flight->ToCityID; }
	cin >> s; flight->CostTime.SetTime(s);
	if (flag) {
		cin >> s; first->CostTime.SetTime(s); cin >> s; second->CostTime.SetTime(s);
	}
	cin >> s; flight->Land.SetTime(s);
	if (flag) {
		cin >> s; second->TakeOff.SetTime(s);
		cin >> s; first->Land.SetTime(s);
	}
	cin >> flight->LeftTickets;
	if (flag) {
		cin >> first->LeftTickets;
		cin >> second->LeftTickets;
		flight->FirstHalf = first;
		flight->SecondHalf = second;
	}
	return flight;
}

void System::ShowHint(){
	cout << "航班号  起飞地点  起飞时间  降落地点  降落时间  票价  余票数量  是否有经停站" << endl;
}

void System::ShowDivider(){
	cout << "************************************************************************" << endl;
}

void System::AddNewFlight(Flight * flight){
	flightmanager.AddFlight(flight);
	citygraph.AddFlight(flight);
}

bool System::DelFlight(Flight * flight){
	if (flight == nullptr)return false;
	citygraph.DelFlight(flight);
	flightmanager.DelFlight(flight);
	return true;
}

string System::FindCityFromID(int index)
{
	return citygraph.GetCityName(index);
}

bool System::SaveFlights(){

	Flight* p=flightmanager.Head;
	fstream fp;
	fp.open("FlightData.txt", ios::out);
	if (!fp)return false;
	bool flag = false;
	while (p != nullptr) {
		fp << p->Airline<<"	"; fp << p->ID<<"	";
		if (p->delayornot) { fp << "Y" << "	"; }
		else fp << "N" << "	";
		fp << p->TakeOff<<"	";
		if (p->FirstHalf != nullptr&&p->SecondHalf != nullptr)flag = true;
		else flag = false;
		if (flag)fp << 'Y';
		else fp << 'N';
		fp << "	";
		fp << citygraph.GetCityName(p->FromCityID) << "	";
		if (flag)fp << citygraph.GetCityName(p->FirstHalf->ToCityID) << "	";
		else fp << "	";
		fp << citygraph.GetCityName(p->ToCityID) << "	";
		fp << p->Price << "	";
		if (flag) {
			fp << p->FirstHalf->Price << "	"; fp << p->SecondHalf->Price << "	";
		}
		else {	
			fp << "	" << "	";
		}
		fp << p->CostTime<<"	";
		if (flag) {
			fp << p->FirstHalf->CostTime << "	"; fp << p->SecondHalf->CostTime << "	";
		}
		else {
			fp << "	" << "	  ";
		}
		fp << p->Land<<"	";
		if (flag) {
			fp << p->SecondHalf->TakeOff << "	"; fp << p->FirstHalf->Land << "	";
		}
		else {
			fp << "	" << "	 ";
		}
		fp << p->LeftTickets<<"	";
		if (flag) {
			fp << p->FirstHalf->LeftTickets << "	"; fp << p->SecondHalf->LeftTickets << "	";
		}
		else {
			fp << "	" << "	";
		}
		fp << endl;
		//cout << p->ID << endl;
		p = p->next;
	}
	fp << "####";
	fp.close();
	return true;
}

Passenger * System::LoadPassenger()
{
	Passenger* passenger = new Passenger();
	return passenger;
}
fstream& operator<<(fstream& os, Time& T) {
	os << T.Hour << ':' ;
	if (T.Min < 10)os << 0 << T.Min;
	else os << T.Min;
	return os;
}
ostream& operator<<(ostream&os, Time& T) {
	os << T.Hour << ':';
	if (T.Min < 10)os << 0 << T.Min;
	else os << T.Min;
	return os;
}