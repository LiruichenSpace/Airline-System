#pragma once
#include<string>
using namespace std;
class Flight;
class FNode;

class FlightEdge//城市图中的航线边
{
public:
	FlightEdge();
	~FlightEdge();
	FlightEdge* next;
	Flight* fp;
	int TargetID;
};

class City//单个城市类
{
public:
	City(string Name);
	City();
	~City();
	FlightEdge* Link;
	int CityID;
	string FlightID;//记录航班id用于查找，头结点置空
	string CityName;
};

class CityGraph//城市图类
{
public:
	CityGraph();
	~CityGraph();
	FNode* FindFlightsBetween(int c1,int c2);//查找同样起止地点的其他航班，没有返回空
	City* heads;//头结点
	string GetCityName(int index);
	int GetIDFromName(string cityname);
	int  AddNewCity(string cityname);//添加头结点,返回新城市的ID
	void AddFlight(Flight* flight);//通过航班变化修改图中内容,考虑经停问题，视情况加1或3条边
	void DelFlight(Flight* flight);
	void FindRoute(string start,string end);//开始城市和到达城市
	int count;
};
