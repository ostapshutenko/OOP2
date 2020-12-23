#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"

Shape* Shape::createShape(char c, Point* pt)
{
	Shape* ptr = 0;

	// ����� ������
	switch (c)
	{
		// T - Triangle
	case 'T':
	{
		//Point* pt = new Point[3];
		//ptr = new Triangle(pt);
		ptr = new Triangle(pt);
		break;
	}

	// R - Rectangle
	case 'R':
	{
		//Point* pt = new Point[4];
		ptr = new Rectangle(pt);
		break;
	}

	// ������ ������ ��� ������ ��������� � ���, ��� "��������� ����� ������ �� �������������"
	default:
	{
		//Point* pt;
		ptr = new Square();
		break;
	}
	}
	return ptr;
}