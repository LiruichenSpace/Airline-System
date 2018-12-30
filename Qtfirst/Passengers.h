#pragma once
#include<string>
using namespace std;
class Flight;
class FNode;
class Passenger//乘客类
{
public:
	Passenger();
	~Passenger();
	bool HaveTicket;
	int ID;//乘客ID
	int FromCity;//对应ID
	int ToCity;//用于判断是否是经停乘客
	Flight* flight;//先检验有无票，无票则在等待抢票
	Passenger* next;//维持manager中的完整链表
	Passenger* pre;
};

/*
说明：为了能在不改变原表的前提下获得多种次序，定义
新的节点来保存Passenger对象指针。同一个对象的指针可以套不同的“壳”来分别排序
*/
class PNode {//用于构建双向链表
public:
	PNode();
	~PNode();
	Passenger* pp;
	PNode* pre;
	PNode* next;
};

class PassengersManager {
public:
	PassengersManager();
	~PassengersManager();
	Passenger* head;
	Passenger* GetPassenger(int ID);//获取乘客,遍历
	void GetRefund(Passenger* passenger);//通过flight指针找到对应航班并处理
	void NewPassenger(Passenger* passenger);//由main函数负责读入信息和组装乘客对象
	void DelPassenger(int ID);//当乘客到站时删除，此函数保证删除即可

};

