#pragma once
#include<string>
#include"Time.h"
using namespace std;
class PNode;
class Passenger;
/*
˵���������ɾ��������ʹ��ȫ�̺��̣���Ҫ�ð�̺��̣�������ܵ�������Ԥ�ڵĺ��
*/
class Flight//������
{
public:
	Flight();
	Flight(Flight& another);//�������캯��,�������ӿǿ���ֱ�Ӹ��ƣ������Ƴ˿�����
	~Flight();//��վ��ֱ��ɾ�������Ҵ���ɾ�������еĳ˿�
	void SetAirline(string NewAirline);
	void SetTakeOff(Time takeoff);
	void SetLand(Time land);
	void AddWaiting(Passenger* p);
	void AddOnBoard(Passenger* p);
	PNode* GetPassengers();
	PNode* GetWaitings();

	PNode* OnBoard;//�Ѿ���Ʊ����
	PNode* Waiting;//�ȴ���Ʊ����
	PNode* WaitingTail;//�ȴ�����β
	string ID;//�����
	string Airline;//���չ�˾
	bool delayornot;
	bool IsHalfFlight;//�ж���Ϊ��ͣ�İ��·��
	int FromCityID;
	int ToCityID;
	int Price;//ȫ�̼۸�
	float weight;
	Time TakeOff;//���ʱ��
	Time Land;//����ʱ��
	Time CostTime;//ȫ��ʱ��
	int LeftTickets;//��Ʊ
	Flight* FirstHalf;//ǰ��ζ�Ӧ����
	Flight* SecondHalf;//���ζ�Ӧ����
	Flight* pre;
	Flight* next;//ά��manager�е���������
};
/*
	˵����Ϊ�����ڲ��ı�ԭ���ǰ���»�ö��ִ��򣬶���
	�µĽڵ�������Flight����ָ�롣ͬһ�������ָ������ײ�ͬ�ġ��ǡ����ֱ�����
*/
class FNode {//���ڹ���˫������ֻ��new��������ֱ��delete����
public:
	FNode();
	FNode(Flight* p);
	FNode(FNode& another);//������ǰ��ָ��
	~FNode();
	Flight* fp;
	FNode* pre;
	FNode* next;
};


class FlightManager {//���������
public:
	FlightManager();
	~FlightManager();
	Flight* Head;
	void AddFlight(Flight* flight);
	static void Destroyer(FNode* head);//�������ٹ�������FNode������Ϊ����FNode������new������
	bool DelFlight(Flight* fp);
	Flight* FindFlightByID(string flightid);//����
	FNode* FindFlightsByAirline(string Airline);
	static FNode* SortByPrice(FNode* head);//����
	static FNode* SortByTime(FNode* head);
	static FNode* SortByTickets(FNode* head);
	static FNode* SortByWeight(FNode* head);
 };

