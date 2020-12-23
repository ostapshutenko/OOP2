#include "FlightScgedule.h"

using namespace std;

	void FlightSchedule::choice(int nmode)
	{
		_mode = nmode;
	}

	int FlightSchedule::mode()const
	{
		return _mode;
	};

	/*void readingfile(string& namefile)		// exception
	{
		// �������� ���� �� �������������
		ifstream fin(namefile);
		if (!fin.is_open())
			throw new exception("������ �������� �����"); //exception

		// ��������� ������ ��� ���������� ����� �� �����
		Date depDate;
		Time depTime;
		string dstPoint;
		Time arrTime;
		int flightNo;
		char c;

		// ���� �� ����� �����, �� ����� ��������� ������
		while (!fin.eof())
		{
			// ��������� ������
			fin >> depDate.Day >> c >> depDate.Month >> c >> depDate.Year;
			fin >> depTime.Second >> c >> depTime.Minute >> c >> depTime.Hour;
			fin >> dstPoint;
			fin >> arrTime.Second >> c >> arrTime.Minute >> c >> arrTime.Hour;
			fin >> flightNo;
			Flight buf(depDate, depTime, dstPoint, arrTime, flightNo);

			//cout << depDate << depTime << dstPoint << arrTime << flightNo;
			// ���� ��� ������ ������, �� ������� � ������ ������
			if (mode == WORK_MODE_VECTOR)
				vector.push_back(buf);

			// ���� ��� ������ �������, �� ��������� � ������� ���� � ���� ������ (����) � ��������� (��� ������ �����)
			else if (mode == WORK_MODE_MAP)
			{
				mmap.insert(pair<string, Flight>(buf._destPoint, buf));
			}
		}

		// �������� �����
		fin.close();
	}*/
	void FlightSchedule::set(Flight buf) {
		if (_mode == WORK_MODE_VECTOR)
			_vector.push_back(buf);
		else if (_mode == WORK_MODE_MAP)
		{
			_mmap.insert(pair<string, Flight>(buf._destPoint, buf));
		}
	};
	
	string FlightSchedule::printinfo(Date& depDate, string& dstPoint)
	{
		string s = "";// ���� ������� ������
		if (_mode == WORK_MODE_VECTOR)
		{
			// ������� �������� �� ������ �������
			auto it = _vector.begin();

			// ���� �� ��������� �������
			while (it != _vector.end())
			{
				// ���� ��������� �� ������ �� ����� ��������� ����� �� ���� � �����
				it = find_if(it, _vector.end(), SearchData(depDate, dstPoint));
				// ���� �������� �� ����� �� ���� ��� �� ����� �� ������� �� ����� ������ ����
				if (it != _vector.end())
				{
					//cout << it->flightNo << " " << it->departureTime << " " << it->arrivalTime << endl;
					s += to_string(it->_departureDate.Day); s += ".";
					s += to_string(it->_departureDate.Month); s += ".";
					s += to_string(it->_departureDate.Year); s += " ";
					s += to_string(it->_departureTime.Hour); s += ":";
					s += to_string(it->_departureTime.Minute); s += ":";
					s += to_string(it->_departureTime.Second); s += " ";
					s += it->_destPoint; s += " ";
					s += to_string(it->_arrivalTime.Hour); s += ":";
					s += to_string(it->_arrivalTime.Minute); s += ":";
					s += to_string(it->_arrivalTime.Second); s += " ";
					s += to_string(it->_flightNumber); s += "\n";
					it++;
				}
			}
		}

		// ���� ��� ������ ������
		else if (_mode == WORK_MODE_MAP)
		{
			// ������� �������� �� ������
			auto it = _mmap.begin();
			// � ������� = ���������� ��������� ��� � ����
			int counter = _mmap.count(dstPoint);
			// � �������� ������� ������� � ������ ����
			it = _mmap.find(dstPoint);

			// ���� �� 0 �� ���������� ���
			for (int i = 0; i < counter; ++i, ++it)
			{
				// ���� ��������� ���� ����� �������� ����� ���������� �� ������� �� ����� ���� � �����
				if (it->second._departureDate == depDate)
				{
					//cout << it->second.departureDate << " " << it->second.departureTime << " " << it->second.destinationPoint<< " " << it->second.arrivalTime << " " << it->second.flightNumber << endl;
					s += to_string(it->second._departureDate.Day); s += ".";
					s += to_string(it->second._departureDate.Month); s += ".";
					s += to_string(it->second._departureDate.Year); s += " ";
					s += to_string(it->second._departureTime.Hour); s += ":";
					s += to_string(it->second._departureTime.Minute); s += ":";
					s += to_string(it->second._departureTime.Second); s += " ";
					s += it->second._destPoint; s += " ";
					s += to_string(it->second._arrivalTime.Hour); s += ":";
					s += to_string(it->second._arrivalTime.Minute); s += ":";
					s += to_string(it->second._arrivalTime.Second); s += " ";
					s += to_string(it->second._flightNumber); s += "\n";
				}
			}
		}
		return s;
	}

