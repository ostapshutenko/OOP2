#pragma once
#include <math.h>
#include "Shape.h"

class Square : public Shape
{
public:

	Square( )
	{	
		
	}
	~Square() { delete[] _point_arr; };
	std::string info() { return "��������� �� �������������"; };
	void Rotate() {};
	void Move() {};

};