#include "Operations.h"

// ����� ��������� ��������
void Operations::Compare(Shape* p1, Shape* p2)
{
	// ��������� ������� ������ � ������ ������
	if (p1->getArea() > p2->getArea())
		cout << "������� ������ ������ ������ ������� ������ ������" << endl;
	else if (p1->getArea() < p2->getArea())
		cout << "������� ������ ������ ������ ������� ������ ������" << endl;
	else
		cout << "������� ����� �����" << endl;
}

// ����� �������� ����������� ��������
void Operations::IsIntersect(Shape* p1, Shape* p2)
{
	if ((p1->_Id_type == 'T' || p1->_Id_type == 'R') && (p2->_Id_type == 'T' || p2->_Id_type == 'R'))
		if (!rec_in_tre(p1, p2) && _flag == 1)
			cout << "������ ������������" << endl;

		else if ((!tre_in_rec(p2->_point_arr[0], p2->_point_arr[1], p2->_point_arr[2], p1->_point_arr[0]) || !tre_in_rec(p2->_point_arr[1], p2->_point_arr[2], p2->_point_arr[3], p1->_point_arr[0]) || !tre_in_rec(p2->_point_arr[2], p2->_point_arr[3], p2->_point_arr[0], p1->_point_arr[0])) && _flag == 1)
			if ((!tre_in_rec(p2->_point_arr[0], p2->_point_arr[1], p2->_point_arr[2], p1->_point_arr[1]) || !tre_in_rec(p2->_point_arr[1], p2->_point_arr[2], p2->_point_arr[3], p1->_point_arr[1]) || !tre_in_rec(p2->_point_arr[2], p2->_point_arr[3], p2->_point_arr[0], p1->_point_arr[1])) && _flag == 1)
				if ((!tre_in_rec(p2->_point_arr[0], p2->_point_arr[1], p2->_point_arr[2], p1->_point_arr[2]) || !tre_in_rec(p2->_point_arr[1], p2->_point_arr[2], p2->_point_arr[3], p1->_point_arr[2]) || !tre_in_rec(p2->_point_arr[2], p2->_point_arr[3], p2->_point_arr[0], p1->_point_arr[2])) && _flag == 1)
					cout << "������ ������������" << endl;

				else cout << "������ �� ������������" << endl;
			else cout << "������ �� ������������" << endl;

		else cout << "������ �� ������������" << endl;
	else cout << "��������� �� �������������" << endl;
	_flag = 0;
}

// ����� �������� ��������� ����� ���� � �����
void Operations::IsInclude(Shape* p1, Shape* p2)
{
	if ((p1->_Id_type == 'T' || p1->_Id_type == 'R') && (p2->_Id_type == 'T' || p2->_Id_type == 'R'))
	// ���� ������� ������������ ������ ������� ��������������
		if (p1->getArea() >= p2->getArea())
		{
			// ���� ������� rec_in_tre ������� 1, �� ������������� �������� � �����������, ����� ������ �� ���������
			if (rec_in_tre(p1, p2))
				cout << "������������� �������� � �����������" << endl;

			else cout << "������ �� ���������" << endl;
		}

		// ���� ������� ������������ ������ ������� ��������������
		else if (p1->getArea() < p2->getArea())
		{
			// ���� ������� tre_in_rec ������� �� ���� ��������� 1, �� ����������� �������� � �������������, ����� ������ �� ���������
			if (tre_in_rec(p2->_point_arr[0], p2->_point_arr[1], p2->_point_arr[2], p1->_point_arr[0]) || tre_in_rec(p2->_point_arr[1], p2->_point_arr[2], p2->_point_arr[3], p1->_point_arr[0]) || tre_in_rec(p2->_point_arr[2], p2->_point_arr[3], p2->_point_arr[0], p1->_point_arr[0]))
				if (tre_in_rec(p2->_point_arr[0], p2->_point_arr[1], p2->_point_arr[2], p1->_point_arr[1]) || tre_in_rec(p2->_point_arr[1], p2->_point_arr[2], p2->_point_arr[3], p1->_point_arr[1]) || tre_in_rec(p2->_point_arr[2], p2->_point_arr[3], p2->_point_arr[0], p1->_point_arr[1]))
					if (tre_in_rec(p2->_point_arr[0], p2->_point_arr[1], p2->_point_arr[2], p1->_point_arr[2]) || tre_in_rec(p2->_point_arr[1], p2->_point_arr[2], p2->_point_arr[3], p1->_point_arr[2]) || tre_in_rec(p2->_point_arr[2], p2->_point_arr[3], p2->_point_arr[0], p1->_point_arr[2]))
						cout << "����������� �������� � �������������" << endl;

					else cout << "������ �� ���������" << endl;
				else cout << "������ �� ���������" << endl;
			else cout << "������ �� ���������" << endl;
		}

		else
			cout << "������ �� ���������" << endl;
	else cout << "��������� �� �������������" << endl;

	_flag = 0;
}

// ����� �������� ��������� �������������� � �����������
bool Operations::rec_in_tre(Shape* p1, Shape* p2)
{
	double a, b, c;
	int fl = 1;

	// ���� �������� �� ������ ����� �������������� � ��������� � �� ������������� � �����������
	for (int i = 0; i < 4; i++)
	{
		a = (p1->_point_arr[0].X - p2->_point_arr[i].X) * (p1->_point_arr[1].Y - p1->_point_arr[0].Y) - (p1->_point_arr[1].X - p1->_point_arr[0].X) * (p1->_point_arr[0].Y - p2->_point_arr[i].Y);
		b = (p1->_point_arr[1].X - p2->_point_arr[i].X) * (p1->_point_arr[2].Y - p1->_point_arr[1].Y) - (p1->_point_arr[2].X - p1->_point_arr[1].X) * (p1->_point_arr[1].Y - p2->_point_arr[i].Y);
		c = (p1->_point_arr[2].X - p2->_point_arr[i].X) * (p1->_point_arr[0].Y - p1->_point_arr[2].Y) - (p1->_point_arr[0].X - p1->_point_arr[2].X) * (p1->_point_arr[2].Y - p2->_point_arr[i].Y);

		if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
			_flag = 1;
		else
			fl = 0;
	}

	if (_flag && fl)
		return 1;
	else
		return 0;
}

// ����� �������� ��������� ������������ � �������������
bool Operations::tre_in_rec(Point A, Point B, Point C, Point P)
{
	double a, b, c;
	int fl = 1;

	// ���� �������� �� ������ ����� ������������ � ��������� � �� ������������� � �������������
	for (int i = 0; i < 3; i++)
	{
		a = (A.X - P.X) * (B.Y - A.Y) - (B.X - A.X) * (A.Y - P.Y);
		b = (B.X - P.X) * (C.Y - B.Y) - (C.X - B.X) * (B.Y - P.Y);
		c = (C.X - P.X) * (A.Y - C.Y) - (A.X - C.X) * (C.Y - P.Y);

		if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
			_flag = 1;
		else
			fl = 0;
	}

	if (_flag && fl)
		return 1;
	else
		return 0;
}
