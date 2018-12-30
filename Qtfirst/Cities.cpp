#include "stdafx.h"
#include "Cities.h"
#include"Flight.h"

City::City(string Name):Link(nullptr) { CityName = Name; }

City::City():Link(nullptr)
{
}

City::~City(){}

CityGraph::CityGraph()
{
	count = 0; heads = nullptr;
}

CityGraph::~CityGraph()
{
	for (int i = 0; i < count; i++) {
		FlightEdge* edge = heads[i].Link;
		FlightEdge* p = nullptr;
		while (edge != nullptr) { p = edge; edge = edge->next; delete p; }
	}
	delete[] heads;
}

int CityGraph::AddNewCity(string cityname)
{
	count++;
	City* New = new City[count];
	for (int i = 0; i < count - 1; i++) {
		New[i].CityID = i;
		New[i].CityName = heads[i].CityName;
		New[i].Link = heads[i].Link;
	}//复制原来数据
	New[count-1].CityID = count - 1;
	New[count-1].CityName = cityname;
	New[count-1].Link = nullptr;//完成添加
	if (heads != nullptr)
		delete[] heads;
	heads = New;
	return count - 1;
}

FNode * CityGraph::FindOtherFlights(Flight * f)
{
	if (f == nullptr)return nullptr;
	FNode* head = nullptr;
	FNode*temp = nullptr;
	FlightEdge* edge = nullptr;
	int from = f->FromCityID;
	int end = f->ToCityID;
	edge = heads[from].Link;
	while (edge != nullptr) {
		if (edge->fp->ToCityID == end) {
			temp = new FNode(edge->fp);
			if (head == nullptr)head = temp;
			else {
				head->pre = temp;
				temp->next = head;
				head = temp;
			}
		}
			edge = edge->next;
	}
	return head;
}

string CityGraph::GetCityName(int index){
	return heads[index].CityName;
}

int CityGraph::GetIDFromName(string cityname)
{
	int i = 0;
	for (i = 0; i < count; i++)
		if (heads[i].CityName == cityname)return i;
	return AddNewCity(cityname);
}

void CityGraph::AddFlight(Flight * flight)
{
	int i = flight->FromCityID;
	FlightEdge* edge = new FlightEdge();
	edge->fp = flight;
	edge->TargetID = flight->ToCityID;
	edge->next = heads[i].Link;
	heads[i].Link = edge;
	if(!flight->IsHalfFlight)//将两个经停班次也填入
		if(flight->FirstHalf!=nullptr&&flight->SecondHalf!=nullptr)
		{
			/*edge = new FlightEdge();
			edge->fp = flight;
			edge->TargetID = flight->FirstHalf->ToCityID;
			edge->next = heads[i].Link;
			heads[i].Link = edge;
			i = flight->SecondHalf->FromCityID;
			edge = new FlightEdge();
			edge->fp = flight;
			edge->TargetID = flight->SecondHalf->ToCityID;
			edge->next = heads[i].Link;
			heads[i].Link = edge;*/
			AddFlight(flight->FirstHalf);
			AddFlight(flight->SecondHalf);
		}
}

void CityGraph::DelFlight(Flight * flight){
	if (!flight->IsHalfFlight) {//防止误删半程而影响后续操作
		FlightEdge* p = nullptr;
		FlightEdge* p0 = nullptr;
		int num = flight->FromCityID;
		p = heads[num].Link;
		while (p != nullptr) {
			if (p->fp==flight||p->fp==flight->FirstHalf) {
				if (p0 == nullptr) {//第一个
					heads[num].Link = p->next;
					delete p;
					p = heads[num].Link;
				}
				else {
					p0->next = p->next;
					delete p;
					p = p0->next;
				}
			}
			else { p0 = p; p = p->next; }
		}
		p0 = nullptr;
		if (flight->SecondHalf != nullptr) {
			num = flight->SecondHalf->ToCityID;
			p = heads[num].Link;
			while (p != nullptr) {
				if (p->fp == flight->SecondHalf) {
					if (p0 == nullptr) {//第一个
						heads[num].Link = p->next;
						delete p;
						p = heads[num].Link;
					}
					else {
						p0->next = p->next;
						delete p;
						p = p0->next;
					}
				}
				else { p0 = p; p = p->next; }
			}
		}
	}
}


void CityGraph::FindRoute(string start, string end)
{
}

FlightEdge::FlightEdge()
{
	next = nullptr;
	fp = nullptr;
}

FlightEdge::~FlightEdge()
{
}
