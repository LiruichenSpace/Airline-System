#pragma once
#include<iostream>
using namespace std;
class Time//��������أ���UI����
{
public:
	Time();
	Time(int a, int b);
	~Time();
	bool operator<(Time& another);
	bool operator>(Time& another);//�Ƚ�����
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
