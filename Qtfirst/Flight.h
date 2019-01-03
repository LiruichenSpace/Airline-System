#pragma once
#include<string>
#include"Time.h"
using namespace std;
class PNode;
class Passenger;
/*
说明：航班的删除操作请使用全程航程，不要用半程航程，否则可能导致难以预期的后果
*/
class Flight//航线类
{
public:
	Flight();
	Flight(Flight& another);//拷贝构造函数,若放弃加壳可以直接复制，不复制乘客内容
	~Flight();//到站后直接删除自身并且处理删除链表中的乘客
	void SetAirline(string NewAirline);
	void SetTakeOff(Time takeoff);
	void SetLand(Time land);
	void AddWaiting(Passenger* p);
	void AddOnBoard(Passenger* p);
	PNode* GetPassengers();
	PNode* GetWaitings();

	PNode* OnBoard;//已经购票链表
	PNode* Waiting;//等待抢票链表
	PNode* WaitingTail;//等待链表尾
	string ID;//航班号
	string Airline;//航空公司
	bool delayornot;
	bool IsHalfFlight;//判断因为经停的半程路线
	int FromCityID;
	int ToCityID;
	int Price;//全程价格
	float weight;
	Time TakeOff;//起飞时间
	Time Land;//降落时间
	Time CostTime;//全程时间
	int LeftTickets;//余票
	Flight* FirstHalf;//前半段对应航程
	Flight* SecondHalf;//后半段对应航程
	Flight* pre;
	Flight* next;//维持manager中的完整链表
};
/*
	说明：为了能在不改变原表的前提下获得多种次序，定义
	新的节点来保存Flight对象指针。同一个对象的指针可以套不同的“壳”来分别排序
*/
class FNode {//用于构建双向链表，只用new来创建，直接delete自身
public:
	FNode();
	FNode(Flight* p);
	FNode(FNode& another);//不复制前后指针
	~FNode();
	Flight* fp;
	FNode* pre;
	FNode* next;
};


class FlightManager {//航班管理类
public:
	FlightManager();
	~FlightManager();
	Flight* Head;
	void AddFlight(Flight* flight);
	static void Destroyer(FNode* head);//用来销毁构建出的FNode链表，因为所有FNode链表都是new出来的
	bool DelFlight(Flight* fp);
	Flight* FindFlightByID(string flightid);//查找
	FNode* FindFlightsByAirline(string Airline);
	static FNode* SortByPrice(FNode* head);//排序
	static FNode* SortByTime(FNode* head);
	static FNode* SortByTickets(FNode* head);
	static FNode* SortByWeight(FNode* head);
 };

