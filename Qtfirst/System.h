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
	int waight;//���ռ����Ȩֵ
	SortPack* next;
	queue<Flight*> FlightQ;//���溽���//���߱���ָ�룿������ͳ�ƣ�
	stack<int> CityS;//�������·��
};
class GNode {
public:
	GNode(int n);
	GNode();
	~GNode();
	int num;
	GNode* adjacent;
};
class SubGraph {//����ͼ�ļ򻯰汾
public:
	SubGraph(CityGraph* G);
	~SubGraph();
	GNode* heads;//ͷ���
	int count;
};
class System//��ϵͳ��
{
public:
	System();
	~System();
	void inchain(int num);
	void Delchain(int num);
	bool NeedInfo(int num);
	void Delay(string FlightID,Time delay);//ͨ��manager����
	void Cancel(string FlightID);//��������delay
	void AddNewFlight(Flight* flight);
	void GetRefund(Passenger* p);
	bool DelFlight(Flight* flight);
	bool BuyTickets(Flight * flight, int id);
	int GetCityID(string city);
	string FindCityFromID(int index);
	Flight* FindFlight(string flightID);
	Flight* FindLatest(Time time,string ID, int c1, int c2);//ʵ�ֿ��Ż�
	FNode* GetRecommend(int c1, int c2);//����6���վ�
	SortPack* GetWay(int c1,int c2);//���������������·������
	FNode* FindFlights(int id1,int id2);
	FNode* FindFlightsByAirline(string airline);
	Passenger* LoadPassenger();
	Passenger* FindPassenger(int id);

private:
	chain* cancle;
	FlightManager flightmanager;
	CityGraph citygraph;
	PassengersManager pmanager;
	Flight* LoadFlights();
	bool SaveFlights();
	bool SavePassengers();
	void LoadPassengers();
	void CountIndex();//������������ָ�����������㸴��Ȩֵ���ٶ����μ����ָ��Ӱ���С
};
fstream& operator<<(fstream& os, Time& T);
ostream& operator<<(ostream&os, Time& T);
//�����֯�ͷ��ض�������·����//�����а���queue������ţ���stack����������ͼ����������Ȩֵ����ʼ��Ϊ-1���ҵ�·�������
//�����ӻ��汾����������̿ɼ�����·�������ǵ���չ������
//�Ƿ������һ��������һ�α����ҵ�����·��
//�����DFS���ҵ����¼·����//���Ե�֪��ǰ·���Ƿ��Ѽ�¼
//����ʵ��һ��С��ͼ�ṹ���򻯳������ӹ�ϵ���ص���ڿɼ��ϣ����ݷ�//�������ֱ����ԭͼ�Ͻ��У�
