using System;


namespace lab5_oop
{
	class Pentagon : Figure 
	{

		public Pentagon()
		{
			_n = 0;
			_ptr = new Point[_n];
		}

		public bool isExist()
		{
			if (_n == 5)
			{
				for (int i = 0; i < _n; i++)
					for (int j = i + 1; j < _n; j++)
						if (_ptr[j].X == _ptr[i].X && _ptr[j].Y == _ptr[i].Y)
							return false;
				return true;
			}
			return false;
		}

	}
}
