#pragma once
#include<iostream>
using namespace std;
class Time//输出不重载，由UI负责
{
public:
	Time();
	Time(int a, int b);
	~Time();
	bool operator<(Time& another);
	bool operator>(Time& another);//比较重载
	Time& operator=(Time& another);
	Time operator+(Time& another);
	Time operator-(Time& another);
	string tostring();
	void SetTime(string S);
	void SetHour(int hour);
	void SetMin(int min);
	int Hour;
	int Min;
};
