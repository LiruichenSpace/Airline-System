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
	bool DelFlight(Flight* flight);
	string FindCityFromID(int index);
	Flight* FindFlight(string flightID);
	Flight* BuildFlight();
	Flight* LoadFlights();
	FNode* FindOthers(Flight* f);
	FNode* FindFlightsByAirline(string airline);
	Passenger* LoadPassenger();

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
