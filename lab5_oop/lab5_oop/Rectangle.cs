using System;

namespace lab5_oop
{
	class Rectangle : Figure 
	{	
		public Rectangle()
		{
			_n = 0;
			_ptr = new Point[_n];
		}
		public bool isExist()
		{
			if (_n == 4)
			{
				if (_ptr[0].X == _ptr[1].X && _ptr[0].Y == _ptr[3].Y && _ptr[2].Y == _ptr[1].Y && _ptr[2].X == _ptr[3].X)
					return true;
			}
			return false;
		}
	}
}
