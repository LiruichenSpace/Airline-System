#pragma once
#include<string>
using namespace std;
#include"Flight.h"
#include"Passengers.h"
#include"Cities.h"
class System//主系统类
{
public:
	System();
	~System();
	void Delay(string FlightID,Time delay);//通过manager处理
	void Cancel(string FlightID);//处理类似delay
	void ShowFlights(FNode* node);
	void ShowFlight(Flight* flight);
	void AddNewFlight(Flight* flight);
	void GetRefund(Passenger* p);
	bool DelFlight(Flight* flight);
	bool BuyTickets(Flight * flight, int id);
	int GetCityID(string city);
	string FindCityFromID(int index);
	Flight* FindFlight(string flightID);
	Flight* FindLatest(Time time,string ID, int c1, int c2);//实现可优化
	Flight* BuildFlight();

	FNode* FindFlights(int id1,int id2);
	FNode* FindFlightsByAirline(string airline);
	Passenger* LoadPassenger();
	Passenger* FindPassenger(int id);

private:
	FlightManager flightmanager;
	CityGraph citygraph;
	PassengersManager pmanager;
	Flight* LoadFlights();
	bool SaveFlights();
	bool SavePassengers();
	void LoadPassengers();
};
fstream& operator<<(fstream& os, Time& T);
ostream& operator<<(ostream&os, Time& T);
