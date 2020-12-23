#include "Console.h"
int Console::init() {
	// ���������� ��� ���������� ����������
	bool error = false;

	FlightSchedule objFS;

	// ����� ������ � �������� � �������
	cout << "0 - ������ � �������� \n1 - ������ �� �������" << endl;
	cout << "�������� ����� ������: ";
	int answMode;
	cin >> answMode;

	// �������� �� ������������ ������ ����������
	if (answMode != 1 && answMode != 0)
	{
		cout << "��� ������ ������ ������!" << endl;
		return 0;
	}

	// �������� ����� ����������, � ������� ����� ��������
	objFS.choice(answMode);

	// �������� �������� ����� ����� throw-try-catch
	string namefile = "input.txt";
	try
	{
		readingfile(namefile, objFS);
	}
	catch (exception * e)
	{
		cout << e << endl;
		error = true;
	}
	if (error)
		return 0;

	// ���� ���� � ������ ����������
	string destonation;
	Date data;
	char c;
	cout << "������� ���� ����������� � ����� ���������� ����� ����� ������: ";
	cin >> data.Day >> c >> data.Month >> c >> data.Year;
	cin >> destonation;
	cout << objFS.printinfo(data, destonation);
}