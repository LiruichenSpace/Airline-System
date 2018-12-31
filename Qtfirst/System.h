#pragma once
#include<string>
using namespace std;
#include"Flight.h"
#include"Passengers.h"
#include"Cities.h"
class System//��ϵͳ��
{
public:
	System();
	~System();
	void Delay(string FlightID,Time delay);//ͨ��manager����
	void Cancel(string FlightID);//��������delay
	void ShowFlights(FNode* node);
	void ShowFlight(Flight* flight);
	void AddNewFlight(Flight* flight);
	void GetRefund(Passenger* p);
	bool DelFlight(Flight* flight);
	int GetCityID(string city);
	string FindCityFromID(int index);
	Flight* FindFlight(string flightID);
	Flight* FindLatest(Time time,string ID, int c1, int c2);//ʵ�ֿ��Ż�
	Flight* BuildFlight();
	Flight* LoadFlights();
	FNode* FindFlights(int id1,int id2);
	FNode* FindFlightsByAirline(string airline);
	Passenger* LoadPassenger();
	Passenger* FindPassenger(string id);

private:
	FlightManager flightmanager;
	CityGraph citygraph;
	PassengersManager pmanager;
	bool SaveFlights();
	void ShowHint();
	void ShowDivider();
};
fstream& operator<<(fstream& os, Time& T);
ostream& operator<<(ostream&os, Time& T);
