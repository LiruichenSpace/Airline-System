#include "stdafx.h"
#include "System.h"
#include<iostream>
#include<fstream>
#include<qdebug.h>

using namespace std;

System::System():cancle(nullptr)
{
	LoadFlights();
	LoadPassengers();
	//if(FindFlights(GetCityID("长春"), 16)==nullptr)
		GetWay(GetCityID("长春"), GetCityID("新加坡"));
}


System::~System(){
	SavePassengers();
	SaveFlights();
	chain* temp = cancle;
	chain* p = nullptr;
	while (temp != nullptr) {
		p = temp; temp = temp->next;
		delete p;
	}
}
void System::inchain(int num) {
	chain* p = new chain();
	p->id = num;
	p->next = cancle;
	cancle = p;
}
void System::Delchain(int num) {
	chain* p = cancle;
	chain* p0 = nullptr;
	while (p != nullptr&&p->id != num) {
		p0 = p; p = p->next;
	}
	if (p != nullptr) {
		if (p0 == nullptr) {
			p0 = p; cancle = p->next; delete p0;
		}
		else {
			p0->next = p->next;
			delete p;
		}
	}
}
bool System::NeedInfo(int num) {
	chain* p = cancle;
	while (p != nullptr) {
		if (p->id == num)return true;
		p = p->next;
	}
	return false;
}
void System::Delay(string FlightID, Time delay){

		Flight* f = flightmanager.FindFlightByID(FlightID);
		if (f != nullptr) {
			f->delayornot = true;
			Time time = delay;
			f->TakeOff = f->TakeOff + time;
			f->Land = f->Land + time;
			if (!f->IsHalfFlight&&f->FirstHalf != nullptr&&f->SecondHalf != nullptr) {
				f->FirstHalf->TakeOff = f->FirstHalf->TakeOff + time;
				f->FirstHalf->Land = f->FirstHalf->Land + time;
				f->SecondHalf->TakeOff = f->SecondHalf->TakeOff + time;
				f->SecondHalf->Land = f->SecondHalf->Land + time;
			}
		}
}

void System::Cancel(string FlightID){
	Flight* f = flightmanager.FindFlightByID(FlightID);
	if (f != nullptr) {
		DelFlight(f); f = nullptr;//删除航班
	}
}

Flight * System::LoadFlights()//直接读取全部航班信息
{
	Flight* flight = nullptr;
	Flight* first = nullptr;
	Flight* second = nullptr;
	Flight* head = nullptr;
	bool flag;
	Time time;
	ifstream fp("FlightData.txt");
	if (!fp) { cout << "file error" << endl; return nullptr; }
	string s;
	char ch;
	while (!fp.eof()) {
		flight = new Flight();
		fp >> s;
		if (s == "####")break;
		flight->Airline = s;
		fp >> flight->ID;
		fp >> ch;
		if (ch == 'Y')flight->delayornot=true;
		else flight->delayornot = false;
		fp >> s; flight->TakeOff.SetTime(s);
		fp >> ch;
		if (ch == 'Y') {
			first = new Flight(); first->Airline = flight->Airline; first->ID = flight->ID; first->TakeOff = flight->TakeOff;
			second = new Flight(); second->Airline = flight->Airline; second->ID = flight->ID;
			flag = true;
			first->IsHalfFlight = true;
			second->IsHalfFlight = true;
			first->delayornot = flight->delayornot;
			second->delayornot = flight->delayornot;
		}
		else flag = false;
		fp >> s;
		flight->FromCityID = citygraph.GetIDFromName(s);
		if (flag) {
			fp >> s;
			first->ToCityID = citygraph.GetIDFromName(s); first->FromCityID = flight->FromCityID;
			second->FromCityID = first->ToCityID;
		}
		fp >> s;
		flight->ToCityID = citygraph.GetIDFromName(s);
		fp >> flight->Price;
		if (flag) { fp >> first->Price; fp >> second->Price; second->ToCityID = flight->ToCityID; }
		fp >> s; flight->CostTime.SetTime(s);
		if(flag){ fp >> s; first->CostTime.SetTime(s); fp >> s; second->CostTime.SetTime(s);
		}
		fp >> s; flight->Land.SetTime(s);
		if (flag) {
			fp >> s; second->TakeOff.SetTime(s);
			fp >> s; first->Land.SetTime(s);
		}
		fp >> flight->LeftTickets;
		if (flag) {
			fp >> first->LeftTickets;
			fp >> second->LeftTickets;
			flight->FirstHalf = first;
			flight->SecondHalf = second;
		}
		if (head == nullptr)head = flight;
		else {
			head->pre = flight;
			flight->next = head;
		}
		citygraph.AddFlight(flight);
		head = flight;
		flight = nullptr;
		first = nullptr;
		second = nullptr;
	}
	flightmanager.Head = head;
	fp.close();
	return head;
}

SortPack * System::GetWay(int c1, int c2)
{
	stack<int> S;
	stack<int> save;
	SortPack* result=nullptr;
	SortPack* addNode = nullptr;
	GNode* p = nullptr;
	bool flag;
	int temp;
	//////////////////////////图操作
	SubGraph SG(&citygraph);
	int* reached = new int[SG.count];
	for (int i = 0; i < SG.count; i++)reached[i] = 0;//访问数组
	S.push(c1);
	qDebug() << "try";
	while (!S.empty()) {
		flag = false;
		temp = S.top(); save.push(temp); reached[temp] = 1;
		S.pop(); 
		if (temp == c2) {//若找到路径
			addNode = new SortPack();
			addNode->CityS = save;
			if (result == nullptr)result = addNode;
			else addNode->next = result; result = addNode;
			while (!addNode->CityS.empty()) {
				qDebug() << QString::fromLocal8Bit(FindCityFromID(addNode->CityS.top()).c_str());
				addNode->CityS.pop();
			}
			qDebug() << "over";
			save.pop(); reached[temp] = 0;
			continue;
		}
		p = SG.heads[temp].adjacent;
		while (p != nullptr) {
			if (reached[p->num] == 0) {
				flag = true;
				S.push(p->num);
			}
			p = p->adjacent;
		}
		if (!flag) {//若是死路
			save.pop(); reached[temp] = 0;
		}
	}
	delete reached;
	//////////////////////////排序
	return result;
}

FNode * System::FindFlights(int id1,int id2){
	return citygraph.FindFlightsBetween(id1,id2);
}

FNode * System::FindFlightsByAirline(string airline){
	return flightmanager.FindFlightsByAirline(airline);
}

Flight * System::FindFlight(string flightID)
{
	return flightmanager.FindFlightByID(flightID);
}

Flight * System::FindLatest(Time time,string ID, int c1, int c2)
{
	FNode* head = FindFlights(c1, c2);
	FNode* temp=head;
	if (head != nullptr) {
		head = flightmanager.SortByPrice(head);
		Flight* result = nullptr;
		Time t = head->fp->TakeOff;
		t.Min += 1;
		while (temp != nullptr) {
			if (!temp->fp->delayornot&&temp->fp->ID!=ID) {
				result = temp->fp; break;
			}
			temp = temp->next;
		}
		flightmanager.Destroyer(head);
		return result;
	}
	else return nullptr;
}

void System::AddNewFlight(Flight * flight){
	flightmanager.AddFlight(flight);
	citygraph.AddFlight(flight);
}

void System::GetRefund(Passenger * p){
	pmanager.GetRefund(p);
}

bool System::DelFlight(Flight * flight){
	if (flight == nullptr)return false;
	Flight* fp = flight;
	PNode* temp=fp->OnBoard;
	while (temp != nullptr) {
		pmanager.DelPassenger(temp->pp->ID);
		temp = temp->next;
	}
	temp = fp->Waiting;
	while (temp != nullptr) {
		pmanager.DelPassenger(temp->pp->ID);
		temp = temp->next;
	}
	if (fp->FirstHalf != nullptr&&fp->SecondHalf != nullptr) {
		temp = fp->FirstHalf->OnBoard;
		while (temp != nullptr) {
			pmanager.DelPassenger(temp->pp->ID);
			temp = temp->next;
		}
		temp = fp->FirstHalf->Waiting;
		while (temp != nullptr) {
			pmanager.DelPassenger(temp->pp->ID);
			temp = temp->next;
		}
		temp = fp->SecondHalf->OnBoard;
		while (temp != nullptr) {
			pmanager.DelPassenger(temp->pp->ID);
			temp = temp->next;
		}
		temp = fp->SecondHalf->Waiting;
		while (temp != nullptr) {
			pmanager.DelPassenger(temp->pp->ID);
			temp = temp->next;
		}
	}
	citygraph.DelFlight(flight);
	flightmanager.DelFlight(flight);
	return true;
}

bool System::BuyTickets(Flight * flight, int id)
{
	return pmanager.BuyTickets(flight,id);
}

int System::GetCityID(string city)
{
	return citygraph.GetIDFromName(city);
}

string System::FindCityFromID(int index)
{
	return citygraph.GetCityName(index);
}

bool System::SaveFlights(){

	Flight* p=flightmanager.Head;
	fstream fp;
	fp.open("FlightData.txt", ios::out);
	if (!fp)return false;
	bool flag = false;
	while (p != nullptr) {
		fp << p->Airline<<"	"; fp << p->ID<<"	";
		if (p->delayornot) { fp << "Y" << "	"; }
		else fp << "N" << "	";
		fp << p->TakeOff<<"	";
		if (p->FirstHalf != nullptr&&p->SecondHalf != nullptr)flag = true;
		else flag = false;
		if (flag)fp << 'Y';
		else fp << 'N';
		fp << "	";
		fp << citygraph.GetCityName(p->FromCityID) << "	";
		if (flag)fp << citygraph.GetCityName(p->FirstHalf->ToCityID) << "	";
		else fp << "	";
		fp << citygraph.GetCityName(p->ToCityID) << "	";
		fp << p->Price << "	";
		if (flag) {
			fp << p->FirstHalf->Price << "	"; fp << p->SecondHalf->Price << "	";
		}
		else {	
			fp << "	" << "	";
		}
		fp << p->CostTime<<"	";
		if (flag) {
			fp << p->FirstHalf->CostTime << "	"; fp << p->SecondHalf->CostTime << "	";
		}
		else {
			fp << "	" << "	  ";
		}
		fp << p->Land<<"	";
		if (flag) {
			fp << p->SecondHalf->TakeOff << "	"; fp << p->FirstHalf->Land << "	";
		}
		else {
			fp << "	" << "	 ";
		}
		fp << p->LeftTickets<<"	";
		if (flag) {
			fp << p->FirstHalf->LeftTickets << "	"; fp << p->SecondHalf->LeftTickets << "	";
		}
		else {
			fp << "	" << "	";
		}
		fp << endl;
		//cout << p->ID << endl;
		p = p->next;
	}
	fp << "####";
	fp.close();
	return true;
}

void System::LoadPassengers(){
	ifstream fin("PassengerData.txt");
	Passenger* pass = nullptr;
	Flight* fp = nullptr;
	if (fin) {
		string s; char ch; int num;
		while (!fin.eof())
		{
			pass = new Passenger();
			fin >> s; num = atoi(s.c_str());
			if (num == -1) { delete pass; break; }
			pass->ID = num;
			fin >> s;
			if (s == "#") {
				inchain(pass->ID);
				delete pass;
				continue;
			}
			pass->FromCity = citygraph.GetIDFromName(s);
			fin >> s;
			pass->ToCity = citygraph.GetIDFromName(s);
			fin >> ch;
			if (ch == 'Y')pass->HaveTicket = true;
			else pass->HaveTicket = false;
			fin >> s;
			fp = flightmanager.FindFlightByID(s);
			if (fp->FirstHalf != nullptr&&fp->FirstHalf->ToCityID == pass->ToCity)pass->flight = fp->FirstHalf;
			else if(fp->SecondHalf != nullptr&&fp->SecondHalf->FromCityID == pass->FromCity)pass->flight = fp->SecondHalf;
			else pass->flight = fp;
			pmanager.AddPassenger(pass);
		}
		fin.close();
	}
}

bool System::SavePassengers(){
	fstream fout;
	fout.open("PassengerData.txt", ios::out);
	if (fout) {
		Passenger* temp = pmanager.head;
		while (temp != nullptr) {
			fout << to_string(temp->ID) << "	";
			fout << citygraph.GetCityName(temp->FromCity) << "	";
			fout << citygraph.GetCityName(temp->ToCity) << "	";
			if (temp->HaveTicket)fout << "Y	";
			else fout << "N	";
			fout << temp->flight->ID << "	" << endl;
			temp = temp->next;
		}
		chain* c = cancle;
		while (c != nullptr) {
			fout << to_string(c->id) << "   #" << endl;
			c = c->next;
		}
		fout << -1;
		fout.close();
		return true;
	}
	return false;
}

Passenger * System::LoadPassenger()
{
	Passenger* passenger = new Passenger();
	return passenger;
}
Passenger * System::FindPassenger(int id)
{
	return pmanager.GetPassenger(id);
}
fstream& operator<<(fstream& os, Time& T) {
	os << T.Hour << ':' ;
	if (T.Min < 10)os << 0 << T.Min;
	else os << T.Min;
	return os;
}
ostream& operator<<(ostream&os, Time& T) {
	os << T.Hour << ':';
	if (T.Min < 10)os << 0 << T.Min;
	else os << T.Min;
	return os;
}

chain::chain():next(nullptr),id(-1){}
chain::~chain(){}
SortPack::SortPack():waight(-1),next(nullptr){}
SortPack::~SortPack(){}
GNode::GNode(int n):num(n),adjacent(nullptr){}
GNode::GNode():num(-1),adjacent(nullptr){}
GNode::~GNode(){}

SubGraph::SubGraph(CityGraph * G):count(G->count){
	int size = G->count;
	int** mat = new int*[size];
	for (int i = 0; i < size; i++) {
		mat[i] = new int[size];
	}//完成矩阵创建
	for(int i=0;i<size;i++)
		for (int j = 0; j < size; j++)
			mat[i][j] = 0;
	FlightEdge* p = nullptr;
	for (int i = 0; i < size; i++) {
		p = G->heads[i].Link;
		while (p != nullptr) {
			mat[i][p->TargetID] = 1;
			p = p->next;
		}
	}//转化为可及矩阵
	for (int i = 0; i < size; i++)mat[i][i] = 0;
	heads = new GNode[size];
	GNode* temp = nullptr;
	for (int i = 0; i < size; i++)
	{
		heads[i].num = i;
		for (int j = 0; j < size; j++)
		{
			if (mat[i][j] == 1) {
				temp = new GNode(j);
				temp->adjacent = heads[i].adjacent;
				heads[i].adjacent = temp;
				temp = nullptr;//添加边
			}
		}
	}
	for (int i = 0; i < size; i++)
		delete[] mat[i];
	delete[] mat;
}

SubGraph::~SubGraph()
{
	GNode* p = nullptr;
	GNode* p0 = nullptr;
	for (int i = 0; i < count; i++) {
		p = heads[i].adjacent;
		while (p != nullptr) {
			p0 = p; p = p->adjacent; delete p0;
		}
	}
	delete[] heads;
}
/*void path(int st, int en)
{
	int *visit, *stack, top, v, head = 1, i;
	struct edgenode *p;
	visit = (int *)malloc(n * sizeof(int));
	stack = (int *)malloc((n + 1) * sizeof(int));
	for (i = 0; i < n; i++) visit[i] = 0;
	v = st; visit[st] = 1; top = 1; stack[top] = v;
	do {
		if (head == 1) {
			p = g[v].first;
			head = 0;
		}
		else p = p->next;
		if (p)
		{
			if (visit[p->no] == 0)
			{
				visit[p->no] = 1;
				top++;
				stack[top] = p->no;
				if (p->no == en)
				{
					for (i = 1; i <= top; i++)
						printf("%d ", stack[i]);
					printf("\n");
					visit[en] = 0;
					top--;
					v = stack[top];
					head = 0;
				}
				else {
					v = stack[top];
					head = 1;
				}
			} //
		}
		else {
			visit[stack[top--]] = 0; //
			if (top)
			{
				p = g[stack[top]].first;
				while (p->no != v) p = p->next;
				v = stack[top];
				head = 0;
			}
		}
	} while (top);
}*/