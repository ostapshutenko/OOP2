#pragma once

#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"

using namespace std;
class Operations
{
private:

	int _flag = 0;

public:

	// ����� ��������� ��������
	void Compare(Shape* p1, Shape* p2);

	// ����� �������� ����������� ��������
	void IsIntersect(Shape* p1, Shape* p2);

	// ����� �������� ��������� ����� ���� � �����
	void IsInclude(Shape* p1, Shape* p2);

	// ����� �������� ��������� �������������� � �����������
	bool rec_in_tre(Shape* p1, Shape* p2);

	// ����� �������� ��������� ������������ � �������������
	bool tre_in_rec(Point A, Point B, Point C, Point P);
};
