#include "Console.h"

Point* Console::enter_Point(char c) {
	if (c == 'T')
	{
		Point* ptr = new Point[3];
		cout << "enter 1 vertex\n";
		cin >> ptr[0].X >> ptr[0].Y;
		cout << "enter 2 vertex\n";
		cin >> ptr[1].X >> ptr[1].Y;
		cout << "enter 3 vertex\n";
		cin >> ptr[2].X >> ptr[2].Y;
		return ptr;
	}
	else if (c == 'R')
	{
		Point* ptr = new Point[4];
		cout << "enter 1 vertex\n";
		cin >> ptr[0].X >> ptr[0].Y;
		cout << "enter 2 vertex\n";
		cin >> ptr[1].X >> ptr[1].Y;
		cout << "enter 3 vertex\n";
		cin >> ptr[2].X >> ptr[2].Y;
		cout << "enter 4 vertex\n";
		cin >> ptr[3].X >> ptr[3].Y;
		return ptr;
	}
	return nullptr;
}
int Console::init()
{
	

	// ������� �������� ������ � ������ Operations, symbol - ������ ������
	Shape* ptr1 = 0, * ptr2 = 0;
	Point* pt;
	Operations op;
	char symbol;

	// ���� ���� ������
	cout << "�������� ��� ������: ";
	cin >> symbol;
	// ����� ���������� � ������
	ptr1 = Shape::createShape(symbol, enter_Point(symbol));
	cout << ptr1->info();

	// ���� ���� ������
	cout << "\n�������� ��� ������: ";
	cin >> symbol;

	// ����� ���������� � ������
	ptr2 = Shape::createShape(symbol, enter_Point(symbol));
	cout << ptr2->info();

	// ����� �������� ���������, ��������� � ����������� ���� �����
	if ((ptr1->_Id_type == 'T' || ptr1->_Id_type == 'R') && (ptr2->_Id_type == 'T' || ptr2->_Id_type == 'R'))
	{
		op.Compare(ptr1, ptr2);
		op.IsIntersect(ptr1, ptr2);
		op.IsInclude(ptr1, ptr2);
	}
	double angle;
	cout << "\n������� 1 ���� ��������: ";
	cin >> angle;
	ptr1->Rotate(angle*M_PI/180);
	cout << ptr1->info();
	cout << "\n������� 2 ���� ��������: ";
	cin >> angle;
	ptr2->Rotate(angle * M_PI / 180);
	cout << ptr2->info();
	cout << "\n������� 1 ��������: ";
	double x, y;
	cin >> x >> y;
	ptr1->Move(x, y);
	cout << ptr1->info();
	cout << "\n������� 2 ��������: ";
	cin >> x >> y;
	ptr2->Move(x, y);
	cout << ptr2->info();
	// �������� ������
	delete ptr1;
	delete ptr2;
	return 0;
}