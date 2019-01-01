#include "stdafx.h"
#include "System.h"
#include<iostream>
#include<fstream>
#include<qdebug.h>

using namespace std;

System::System()
{
	LoadFlights();
	LoadPassengers();
}


System::~System(){
	SavePassengers();
	SaveFlights();
}

void System::Delay(string FlightID, Time delay){

		Flight* f = flightmanager.FindFlightByID(FlightID);
		if (f != nullptr) {
			f->delayornot = true;
			Time time = delay;
			f->TakeOff = f->TakeOff + time;
			f->Land = f->Land + time;
			if (!f->IsHalfFlight&&f->FirstHalf != nullptr&&f->SecondHalf != nullptr) {
				f->FirstHalf->TakeOff = f->FirstHalf->TakeOff + time;
				f->FirstHalf->Land = f->FirstHalf->Land + time;
				f->SecondHalf->TakeOff = f->SecondHalf->TakeOff + time;
				f->SecondHalf->Land = f->SecondHalf->Land + time;
			}
		}
}

void System::Cancel(string FlightID){
	Flight* f = flightmanager.FindFlightByID(FlightID);
	if (f != nullptr) {
		DelFlight(f); f = nullptr;//删除航班
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
		head = flight;
		flight = nullptr;
		first = nullptr;
		second = nullptr;
	}
	flightmanager.Head = head;
	fp.close();
	return head;
}

FNode * System::FindFlights(int id1,int id2){
	return citygraph.FindFlightsBetween(id1,id2);
}

FNode * System::FindFlightsByAirline(string airline){
	return flightmanager.FindFlightsByAirline(airline);
}

Flight * System::FindFlight(string flightID)
{
	return flightmanager.FindFlightByID(flightID);
}

Flight * System::FindLatest(Time time,string ID, int c1, int c2)
{
	FNode* head = FindFlights(c1, c2);
	FNode* temp=head;
	if (head != nullptr) {
		head = flightmanager.SortByPrice(head);
		Flight* result = nullptr;
		Time t = head->fp->TakeOff;
		t.Min += 1;
		while (temp != nullptr) {
			if (!temp->fp->delayornot&&temp->fp->ID!=ID) {
				result = temp->fp; break;
			}
			temp = temp->next;
		}
		flightmanager.Destroyer(head);
		return result;
	}
	else return nullptr;
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

void System::AddNewFlight(Flight * flight){
	flightmanager.AddFlight(flight);
	citygraph.AddFlight(flight);
}

void System::GetRefund(Passenger * p){
	pmanager.GetRefund(p);
}

bool System::DelFlight(Flight * flight){
	if (flight == nullptr)return false;
	Flight* fp = flight;
	PNode* temp=fp->OnBoard;
	while (temp != nullptr) {
		pmanager.DelPassenger(temp->pp->ID);
		temp = temp->next;
	}
	temp = fp->Waiting;
	while (temp != nullptr) {
		pmanager.DelPassenger(temp->pp->ID);
		temp = temp->next;
	}
	if (fp->FirstHalf != nullptr&&fp->SecondHalf != nullptr) {
		temp = fp->FirstHalf->OnBoard;
		while (temp != nullptr) {
			pmanager.DelPassenger(temp->pp->ID);
			temp = temp->next;
		}
		temp = fp->FirstHalf->Waiting;
		while (temp != nullptr) {
			pmanager.DelPassenger(temp->pp->ID);
			temp = temp->next;
		}
		temp = fp->SecondHalf->OnBoard;
		while (temp != nullptr) {
			pmanager.DelPassenger(temp->pp->ID);
			temp = temp->next;
		}
		temp = fp->SecondHalf->Waiting;
		while (temp != nullptr) {
			pmanager.DelPassenger(temp->pp->ID);
			temp = temp->next;
		}
	}
	citygraph.DelFlight(flight);
	flightmanager.DelFlight(flight);
	return true;
}

bool System::BuyTickets(Flight * flight, int id)
{
	return pmanager.BuyTickets(flight,id);
}

int System::GetCityID(string city)
{
	return citygraph.GetIDFromName(city);
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

void System::LoadPassengers(){
	ifstream fin("PassengerData.txt");
	Passenger* pass = nullptr;
	Flight* fp = nullptr;
	if (fin) {
		string s; char ch; int num;
		while (!fin.eof())
		{
			pass = new Passenger();
			fin >> s; num = atoi(s.c_str());
			if (num == -1) { delete pass; break; }
			pass->ID = num;
			fin >> s;
			pass->FromCity = citygraph.GetIDFromName(s);
			fin >> s;
			pass->ToCity = citygraph.GetIDFromName(s);
			fin >> ch;
			if (ch == 'Y')pass->HaveTicket = true;
			else pass->HaveTicket = false;
			fin >> s;
			fp = flightmanager.FindFlightByID(s);
			if (fp->FirstHalf != nullptr&&fp->FirstHalf->ToCityID == pass->ToCity)pass->flight = fp->FirstHalf;
			else if(fp->SecondHalf != nullptr&&fp->SecondHalf->FromCityID == pass->FromCity)pass->flight = fp->SecondHalf;
			else pass->flight = fp;
			pmanager.AddPassenger(pass);
		}
		fin.close();
	}
}

bool System::SavePassengers(){
	fstream fout;
	fout.open("PassengerData.txt", ios::out);
	if (fout) {
		Passenger* temp = pmanager.head;
		while (temp != nullptr) {
			fout << to_string(temp->ID) << "		";
			fout << citygraph.GetCityName(temp->FromCity) << "	";
			fout << citygraph.GetCityName(temp->ToCity) << "	";
			if (temp->HaveTicket)fout << "Y	";
			else fout << "N	";
			fout << temp->flight->ID<<"	"<<endl;
			temp = temp->next;
		}
		fout << -1;
		fout.close();
		return true;
	}
	return false;
}

Passenger * System::LoadPassenger()
{
	Passenger* passenger = new Passenger();
	return passenger;
}
Passenger * System::FindPassenger(int id)
{
	return pmanager.GetPassenger(id);
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