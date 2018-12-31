#pragma once
#include<string>
using namespace std;
class Flight;
class FNode;

class FlightEdge//����ͼ�еĺ��߱�
{
public:
	FlightEdge();
	~FlightEdge();
	FlightEdge* next;
	Flight* fp;
	int TargetID;
};

class City//����������
{
public:
	City(string Name);
	City();
	~City();
	FlightEdge* Link;
	int CityID;
	string FlightID;//��¼����id���ڲ��ң�ͷ����ÿ�
	string CityName;
};

class CityGraph//����ͼ��
{
public:
	CityGraph();
	~CityGraph();
	FNode* FindFlightsBetween(int c1,int c2);//����ͬ����ֹ�ص���������࣬û�з��ؿ�
	City* heads;//ͷ���
	string GetCityName(int index);
	int GetIDFromName(string cityname);
	int  AddNewCity(string cityname);//���ͷ���,�����³��е�ID
	void AddFlight(Flight* flight);//ͨ������仯�޸�ͼ������,���Ǿ�ͣ���⣬�������1��3����
	void DelFlight(Flight* flight);
	void FindRoute(string start,string end);//��ʼ���к͵������
	int count;
};
