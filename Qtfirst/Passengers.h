#pragma once
#include<string>
using namespace std;
class Flight;
class FNode;
class Passenger//�˿���
{
public:
	Passenger();
	~Passenger();
	bool HaveTicket;
	int ID;//�˿�ID
	int FromCity;//��ӦID
	int ToCity;//�����ж��Ƿ��Ǿ�ͣ�˿�
	Flight* flight;//�ȼ�������Ʊ����Ʊ���ڵȴ���Ʊ
	Passenger* next;//ά��manager�е���������
	Passenger* pre;
};

/*
˵����Ϊ�����ڲ��ı�ԭ���ǰ���»�ö��ִ��򣬶���
�µĽڵ�������Passenger����ָ�롣ͬһ�������ָ������ײ�ͬ�ġ��ǡ����ֱ�����
*/
class PNode {//���ڹ���˫������
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
	Passenger* GetPassenger(int ID);//��ȡ�˿�,����
	void GetRefund(Passenger* passenger);//ͨ��flightָ���ҵ���Ӧ���ಢ����
	void NewPassenger(Passenger* passenger);//��main�������������Ϣ����װ�˿Ͷ���
	void DelPassenger(int ID);//���˿͵�վʱɾ�����˺�����֤ɾ������

};

