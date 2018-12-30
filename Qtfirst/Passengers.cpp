#include "stdafx.h"
#include "Passengers.h"
#include"Flight.h"

Passenger::Passenger()
{
}


Passenger::~Passenger()
{
}

PassengersManager::PassengersManager()
{
}

PassengersManager::~PassengersManager()
{
}

Passenger * PassengersManager::GetPassenger(int ID)
{
	return nullptr;
}

void PassengersManager::GetRefund(Passenger * passenger)
{
}

void PassengersManager::NewPassenger(Passenger * passenger)
{
}

void PassengersManager::DelPassenger(int ID)
{
}

PNode::PNode(){pp = nullptr;pre = nullptr;next = nullptr;}


PNode::~PNode(){pp = nullptr;pre = nullptr;next = nullptr;}
