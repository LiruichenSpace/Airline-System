#include "stdafx.h"
#include "Passengers.h"
#include"Flight.h"
#include<fstream>
using namespace std;

Passenger::Passenger():FromCity(-1),ToCity(-1),HaveTicket(false)
{
	flight = nullptr;
	next = nullptr;
}


Passenger::~Passenger()
{
}

PassengersManager::PassengersManager()
{
	head = nullptr;
}

PassengersManager::~PassengersManager()
{
	Passenger* temp;
	while (head != nullptr) {
		temp = head; head = head->next;
		delete temp;
	}
}

Passenger * PassengersManager::GetPassenger(int ID)
{
	Passenger* p = head;
	while (p != nullptr&& p->ID != ID)
		p = p->next;
	return p;
}

void PassengersManager::GetRefund(Passenger * passenger)
{
	PNode* p = nullptr;
	PNode* m = nullptr;
	PNode* q = nullptr;
	PNode* t = nullptr;
	if (passenger->HaveTicket) {//若有票
		p = passenger->flight->OnBoard;
		m = passenger->flight->Waiting;
		passenger->HaveTicket = false;
		while (p != nullptr&&p->pp->ID != passenger->ID) {
			q = p; p = p->next;
		}
		if (p != nullptr)
			if (q == nullptr) {//首结点
				passenger->flight->OnBoard = p->next;
				if(passenger->flight->OnBoard!=nullptr)
				passenger->flight->OnBoard->pre = nullptr;
			}
			else {
				q->next = p->next;
				if (p->next != nullptr)
					p->next->pre = q;
			}//糟糕实现
		if (m == nullptr)
			passenger->flight->LeftTickets += 1;
		else {
			t = m;
			m = m->next;
			t->pp->HaveTicket = true;
			passenger->flight->Waiting = m;
			if(passenger->flight->Waiting!=nullptr)
			passenger->flight->Waiting->pre = nullptr;
			t->next = passenger->flight->OnBoard;
			if (passenger->flight->OnBoard != nullptr)
			passenger->flight->OnBoard->pre = t;
			passenger->flight->OnBoard = t;
		}
	}
	else {//若无票，也处理，从等待列表移除
		p = passenger->flight->Waiting;
		while (p != nullptr&&p->pp != passenger) {

			q = p; p = p->next;
		}
		if (p != nullptr)
			if (q == nullptr) {
				passenger->flight->Waiting = passenger->flight->Waiting->next;
				if (p == passenger->flight->WaitingTail)passenger->flight->WaitingTail = q;
				delete p;
			}
			else {
				q->next = p->next;
				if (p == passenger->flight->WaitingTail)passenger->flight->WaitingTail = q;
				delete p;
			}
	}
	/////////////////////////最后将其从总链表中删除
	Passenger* temp = head;//单链表
	Passenger* p0 = nullptr;
	while (temp != nullptr&&temp != passenger) {

		p0 = temp; temp = temp->next;
	}
	if (temp != nullptr)
		if (p0 == nullptr) {
			head = head->next;
			delete temp;
		}
		else {
			p0->next = temp->next;
			delete temp;
		}
}

void PassengersManager::NewPassenger(Passenger * passenger)
{
	passenger->next = head;
	head = passenger;
}

void PassengersManager::DelPassenger(int ID)
{
	GetRefund(GetPassenger(ID));
}

PNode::PNode(){pp = nullptr;pre = nullptr;next = nullptr;}


PNode::~PNode(){pp = nullptr;pre = nullptr;next = nullptr;}
bool PassengersManager::BuyTickets(Flight* flight, int id) {
	Passenger* passenger = new Passenger();
	passenger->flight = flight;
	passenger->ID = id;
	passenger->FromCity = flight->FromCityID;
	passenger->ToCity = flight->ToCityID;
	NewPassenger(passenger);
	if (flight->LeftTickets > 0) {
		passenger->HaveTicket = true;
		PNode* temp = new PNode();
		temp->pp = passenger;
		if(flight->OnBoard!=nullptr)
		flight->OnBoard->pre = temp;
		temp->next = flight->OnBoard;
		flight->OnBoard = temp;
		flight->LeftTickets--;
		return true;
	}
	else {
		passenger->HaveTicket = false;
		PNode* temp = new PNode();
		temp->pp = passenger;
		if (flight->WaitingTail == nullptr) {
			flight->Waiting = temp;
			flight->WaitingTail = temp;
		}
		else {
			flight->WaitingTail->next = temp;
			temp->pre = flight->WaitingTail;
			flight->WaitingTail = temp;
		}
		return false;
	}
}



void PassengersManager::AddPassenger(Passenger * p){
	NewPassenger(p);
	if (p->HaveTicket) {
		PNode* temp = new PNode();
		temp->pp = p;
		if (p->flight->OnBoard != nullptr)
			p->flight->OnBoard->pre = temp;
		temp->next = p->flight->OnBoard;
		p->flight->OnBoard = temp;
	}
	else {
		PNode* temp = new PNode();
		temp->pp = p;
		if (p->flight->WaitingTail == nullptr) {
			p->flight->Waiting = temp;
			p->flight->WaitingTail = temp;
		}
		else {
			p->flight->WaitingTail->next = temp;
			temp->pre = p->flight->WaitingTail;
			p->flight->WaitingTail = temp;
		}
	}
}

