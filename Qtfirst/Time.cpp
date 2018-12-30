#include "stdafx.h"
#include"Time.h"
using namespace std;

Time::Time():Hour(0), Min(0) {}

Time::Time(int a, int b) :Hour(a), Min(b) {}

Time::~Time() {}
void Time::SetHour(int hour) { Hour = hour; }

void Time::SetMin(int min) { Min = min; }

bool Time::operator<(Time& another) {
	if (Hour < another.Hour)return true;
	else if (Hour > another.Hour)return false;
	else if (Min < another.Min)return true;
	else return false;
}
bool Time::operator>(Time& another) {
	if (Hour > another.Hour)return true;
	else if (Hour < another.Hour)return false;
	else if (Min > another.Min)return true;
	else return false;
}
Time& Time::operator=(Time& another) {
	Hour = another.Hour;
	Min = another.Min;
	return (*this);
}

Time Time::operator+(Time& another) {
	Time T;
	int temp;
	temp = (Min + another.Min)/60;
	T.Min = (Min + another.Min) % 60;
	T.Hour = (Hour + another.Hour + temp) % 24;
	return T;
}

Time Time::operator-(Time& another) {//暂不考虑跨一整天
	Time T;
	int temp =0;
	if (Min < another.Min) {
		temp = -1;
		T.Min = Min + 60 - another.Min;
	}
	else
		T.Min = Min - another.Min;
	int hour = Hour + temp;
	if (hour<0) {
		hour += 24;
	}
	if (hour < another.Hour)
		T.Hour = hour + 24 - another.Hour;
	else T.Hour = hour - another.Hour;
	return T;
}

string Time::tostring()
{
	char time[6];
	time[5] = 0;
	if (Hour < 10) {
		time[0] = '0'; time[1] = Hour + '0';
	}
	else {
		time[0] = Hour / 10 + '0';
		time[1] = Hour % 10 + '0';
	}
	time[2] = ':';
	if (Min < 10) { time[3] = '0'; time[4] = Min + '0'; }
	else {
		time[3] = Min / 10 + '0';
		time[4] = Min % 10 + '0';
	}
	return string(time);
}

void Time::SetTime(string S)
{
	int i = 0;
	int temp=0;
	for (i = 0; S[i] != ':'; i++) {
		temp = 10 * temp + S[i]-'0';
	}
	Hour = temp;
	Min = (S[i + 1]-'0') * 10 + S[i + 2]-'0';
}

