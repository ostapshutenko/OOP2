#pragma once
#include <string>
#include "Date.h"
#include "Time.h"
struct Flight
{
	Date _departureDate;	// ���� �����������
	Time _departureTime;	// ����� �����������
	Time _arrivalTime;	// ����� ��������
	int _flightNumber;	// ����� �����
	std::string _destPoint;	// ����� ����������
	Flight(Date departureDate, Time departureTime, std::string destPoint, Time arrivalTime, int flightNumber) : _departureDate(departureDate), _departureTime(departureTime), _arrivalTime(arrivalTime), _flightNumber(flightNumber), _destPoint(destPoint) {}
};