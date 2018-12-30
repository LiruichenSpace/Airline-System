#include "stdafx.h"
#include"Flight.h"
#include"Passengers.h"
#include"Time.h"

Flight::Flight() {
	OnBoard = nullptr;
	Waiting = nullptr;
	WaitingTail = nullptr;
	next = nullptr;
	pre = nullptr;
	FirstHalf = nullptr;
	SecondHalf = nullptr;
	IsHalfFlight = false;
	delayornot = false;
}

Flight::Flight(Flight & another)//�������˿�
{
	OnBoard = nullptr;
	Waiting = nullptr;
	WaitingTail = nullptr;
	ID = another.ID;
	Airline = another.Airline;
	IsHalfFlight = another.IsHalfFlight;
	FromCityID = another.FromCityID;
	ToCityID = another.ToCityID;
	Price = another.Price;
	TakeOff = another.TakeOff;
	CostTime = another.CostTime;
	Land = another.Land;
	LeftTickets = another.LeftTickets;
	next = nullptr;
	pre = nullptr;
	if (!IsHalfFlight)//������Ǿ�ͣ������ư��
	{
		if (another.FirstHalf != nullptr)
			FirstHalf = new Flight(*(another.FirstHalf));
		if (another.SecondHalf != nullptr)
			SecondHalf = new Flight(*(another.SecondHalf));
	}
}
/*
ʲô�ᵼ�º��౻ɾ����|�����Ƿ�ȫ��new�����ģ�|ɾ��ʱ�˿������ò��ÿ��ǣ�
*/
Flight::~Flight() {
	PNode* temp = OnBoard;
	PNode* p = nullptr;
	while (temp != nullptr) { p = temp; temp = temp->next; delete p; }
	temp = Waiting;
	while (temp != nullptr) { p = temp; temp = temp->next; delete p; }
	if (!IsHalfFlight) {
		if (FirstHalf != nullptr)delete FirstHalf;
		if (SecondHalf != nullptr)delete SecondHalf;
	}
}

void Flight::SetAirline(string NewAirline) { Airline = NewAirline; }

void Flight::SetTakeOff(Time takeoff){TakeOff = takeoff;}

void Flight::SetLand(Time land) { Land = land; }

PNode * Flight::GetPassengers()
{
	return OnBoard;
}

PNode * Flight::GetWaitings()
{
	return Waiting;
}

void Flight::AddWaiting(Passenger * p)
{
	PNode* node = new PNode();
	node->pp = p;
	if (WaitingTail != nullptr) {
		WaitingTail->next = node; node->pre = WaitingTail; WaitingTail = node;
	}
	else WaitingTail = node;
}

void Flight::AddOnBoard(Passenger * p){
	PNode* node = new PNode();
	node->pp = p;
	if (OnBoard != nullptr) {
		OnBoard->pre = node;
		node->next = OnBoard;
		OnBoard = node;
	}
	else OnBoard = node;
}

FlightManager::FlightManager()
{
	Head = nullptr;
}

FlightManager::~FlightManager()
{
}
void FlightManager::AddFlight(Flight* flight)
{
	flight->next = Head;
	Head->pre = flight;
	Head = flight;
}

void FlightManager::Destroyer(FNode * head){
	FNode* p = head;
	FNode*p0 = nullptr;
	while (p != nullptr) {
		p0 = p; p = p->next; delete p0;
	}
}

bool FlightManager::DelFlight(Flight* fp)//�˿Ͳ�����flight����������ʵ��
{
	if (fp == Head) { Head = fp->next; Head->pre = nullptr; }
	if (fp->next != nullptr) {
		fp->next->pre = fp->pre; 
	}
	if (fp->pre != nullptr) {
		fp->pre->next = fp->next;
	}
	delete fp;
	return true;
}

Flight* FlightManager::FindFlightByID(string flightid)
{
	Flight* p = Head;
	while (p != nullptr&& p->ID != flightid)//��ȥ���
		p = p->next;
	return p;
}

FNode* FlightManager::FindFlightsByAirline(string Airline) {
	Flight* p = Head;
	FNode* head=nullptr;
	FNode* temp = nullptr;
	while (p != nullptr)
	{
		if (p->Airline == Airline) {
			temp = new FNode();
			temp->fp = p;
			if (head == nullptr)head = temp;
			else { head->pre = temp; temp->next = head; head = temp; }
			temp = nullptr;
		}
		p = p->next;
	}
	return head;
}

FNode * FlightManager::SortByPrice(FNode * head)
{
	if (head == nullptr)return nullptr;
	FNode* p = head->next;
	FNode* p0 = nullptr;
	FNode* temp = nullptr;
	int key;
	while (p != nullptr) {
		p->pre->next = p->next;//��߲����
		if(p->next!=nullptr)p->next->pre = p->pre;//�ұ����ǿ�,���ժ��
		key = p->fp->Price;
		p0 = p->next;//��¼��һ��p��ֵ
		temp = p->pre;
		p->next = nullptr; p->pre = nullptr;
		while (temp != nullptr&&temp->fp->Price > key)temp = temp->pre;//��ǰ����
		if (temp == nullptr) { p->next = head; head->pre = p; head = p; }
		else {
			if (temp->next != nullptr)temp->next->pre = p;//��temp��ָ���
			p->next = temp->next;
			temp->next = p;
			p->pre = temp;
		}
		p = p0;
	}
	return head;
}

FNode * FlightManager::SortByTime(FNode * head)
{
	if (head == nullptr)return nullptr;
	FNode* p = head->next;
	FNode* p0 = nullptr;
	FNode* temp = nullptr;
	Time key;
	while (p != nullptr) {
		p->pre->next = p->next;//��߲����
		if (p->next != nullptr)p->next->pre = p->pre;//�ұ����ǿ�,���ժ��
		key = p->fp->CostTime;
		p0 = p->next;//��¼��һ��p��ֵ
		temp = p->pre;
		p->next = nullptr; p->pre = nullptr;
		while (temp != nullptr&&temp->fp->CostTime > key)temp = temp->pre;//��ǰ����
		if (temp == nullptr) { p->next = head; head->pre = p; head = p; }
		else {
			if (temp->next != nullptr)temp->next->pre = p;//��temp��ָ���
			p->next = temp->next;
			temp->next = p;
			p->pre = temp;
		}
		p = p0;
	}
	return head;
}

FNode * FlightManager::SortByTickets(FNode * head)
{
	if (head == nullptr)return nullptr;
	FNode* p = head->next;
	FNode* p0 = nullptr;
	FNode* temp = nullptr;
	int key;
	while (p != nullptr) {
		p->pre->next = p->next;//��߲����
		if (p->next != nullptr)p->next->pre = p->pre;//�ұ����ǿ�,���ժ��
		key = p->fp->LeftTickets;
		p0 = p->next;//��¼��һ��p��ֵ
		temp = p->pre;
		p->next = nullptr; p->pre = nullptr;
		while (temp != nullptr&&temp->fp->LeftTickets < key)temp = temp->pre;//��ǰ����
		if (temp == nullptr) { p->next = head; head->pre = p; head = p; }
		else {
			if (temp->next != nullptr)temp->next->pre = p;//��temp��ָ���
			p->next = temp->next;
			temp->next = p;
			p->pre = temp;
		}
		p = p0;
	}
	return head;
}

FNode::FNode():fp(nullptr),pre(nullptr),next(nullptr){}

FNode::FNode(Flight * p):fp(p),pre(nullptr),next(nullptr){}

FNode::FNode(FNode & another)
{
	fp = another.fp;
	next = nullptr;
	pre = nullptr;
}

FNode::~FNode()
{
	fp = nullptr; pre = nullptr; next = nullptr;
}
