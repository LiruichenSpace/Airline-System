#pragma once
#include<string>
#include<stack>
#include<queue>
using namespace std;
#include"Flight.h"
#include"Passengers.h"
#include"Cities.h"
class chain {
public:
	chain();
	~chain();
	int id;
	chain* next;
};
class SortPack {
public:
	SortPack();
	~SortPack();
	int weight;//最终计算的权值
	SortPack* next;
	stack<Flight*> FlightS;//保存航班号//或者保存指针？（易于统计）
	stack<int> CityS;//保存城市路径
};
class GNode {
public:
	GNode(int n);
	GNode();
	~GNode();
	int num;
	GNode* adjacent;
};
class SubGraph {//城市图的简化版本
public:
	SubGraph(CityGraph* G);
	~SubGraph();
	GNode* heads;//头结点
	int count;
};
class System//主系统类
{
public:
	System();
	~System();
	void inchain(int num);
	void Delchain(int num);
	bool NeedInfo(int num);
	void Delay(string FlightID,Time delay);//通过manager处理
	void Cancel(string FlightID);//处理类似delay
	void AddNewFlight(Flight* flight);
	void GetRefund(Passenger* p);
	bool DelFlight(Flight* flight);
	bool BuyTickets(Flight * flight, int id);
	bool Reachable(int c1, int c2);
	bool DirReachable(int c1, int c2);
	int GetCityID(string city);
	string FindCityFromID(int index);
	Flight* FindFlight(string flightID);
	Flight* FindLatest(Time time,string ID, int c1, int c2);//实现可优化
	FNode* GetRecommend(int c1, int c2);//功能6，终局
	FNode* FindFlights(int id1,int id2);
	FNode* FindFlightsByAirline(string airline);
	Passenger* LoadPassenger();
	Passenger* FindPassenger(int id);
	SortPack* GetWay(int c1, int c2);//返回所有完成排序路径链表
private:
	chain* cancle;
	FlightManager flightmanager;
	CityGraph citygraph;
	PassengersManager pmanager;
	Flight* LoadFlights();
	SortPack* findway(int* visited, int currnode, int c2, stack<int>& CS, SortPack*& result, SubGraph* SG);//递归找到所有待比路径，第一步
	SortPack* deployFlights(SortPack* head);//将航班指针入栈并计算权值，第二步
	SortPack* getLowest(SortPack* head);//找出权值最小的一条路，第三步
	bool SaveFlights();
	bool SavePassengers();
	void LoadPassengers();
};
fstream& operator<<(fstream& os, Time& T);
ostream& operator<<(ostream&os, Time& T);
//如何组织和返回多条城市路径？//链表中包含queue（航班号），stack（用来查找图），并含有权值，初始赋为-1，找到路径后计算
//查找劣化版本：仅查找最短可及城市路径，考虑到扩展可能性
//是否可能在一个函数中一次遍历找到多条路径
//亦或者DFS中找到则记录路径？//难以得知当前路径是否已记录
//重新实现一个小型图结构，简化城市连接关系，重点放在可及上，回溯法//或许可以直接在原图上进行？
