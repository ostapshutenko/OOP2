using System;
//System.Array;
//System.Array;
/// <summary>
/// Summary description for Class1
/// </summary>

namespace lab5_oop
{

	public class Figure
	{
		protected int _n = 0;
		protected Point[] _ptr;
		public Figure() { _n = 0; _ptr = new Point[_n]; }
		//public ~Figure() {}
		public void add(double x, double y)
		{
			Point buf;
			buf.X = x;
			buf.Y = y;
			_n++;
			Array.Resize<Point>(ref _ptr, _n);
			_ptr[_n-1] = buf;
		}
		public void add(Point buf_add)
		{
			_n++;
			Array.Resize<Point>(ref _ptr, _n);
			_ptr[_n-1] = buf_add;
		}
		/*
		void insert(int n, double x, double y);
		void insert(int n, Point buf_add);
		*/
		public double getPerimetr()
		{
			double sum = 0;
			if (_n > 0)
			{
				if (_n > 0)
				{
					for (int i = 0; i < _n - 1; i++)
					{
						sum += Math.Sqrt((_ptr[i + 1].X - _ptr[i].X) * (_ptr[i + 1].X - _ptr[i].X) + (_ptr[i + 1].Y - _ptr[i].Y) * (_ptr[i + 1].Y - _ptr[i].Y));

					}
					sum += Math.Sqrt((_ptr[0].X - _ptr[_n - 1].X) * (_ptr[0].X - _ptr[_n - 1].X) + (_ptr[0].Y - _ptr[_n - 1].Y) * (_ptr[0].Y - _ptr[_n - 1].Y));
				}
			}
			return sum;
		}
		public double getArea()
		{
			double sum1 = 0, sum2 = 0;
			if (_n > 0)
			{
				sum1 += _ptr[_n - 1].X * _ptr[0].Y;
				sum2 += _ptr[_n - 1].Y * _ptr[0].X;

				for (int i = 0; i < _n - 1; i++)
				{
					sum1 += _ptr[i].X * _ptr[i + 1].Y;
					sum2 += _ptr[i].Y * _ptr[i + 1].X;
				}
				sum1 -= sum2;
				if (sum1 < 0)
					sum1 *= -1;
			}
			return sum1 / 2;
		}
		public bool del(int n)
		{
			if (n < 0)
				n += _n;
			if (n >= 0 && n < _n)
			{
				int i = n;
				for (i = n; i < _n - 1; i++)
				{
					_ptr[i] = _ptr[i + 1];
				}
				_n--;
				Array.Resize<Point>(ref _ptr, _n);
				return true;
			}
			return false;
		}
		public Point getCentrMass()
		{
			double sum1 = 0, sum2 = 0;

			Point f;
			for (int i = 0; i < _n; i++)
			{
				sum1 += _ptr[i].X;
				sum2 += _ptr[i].Y;
			}
			sum1 /= _n;
			sum2 /= _n;

			f.X = sum1;
			f.Y = sum2;

			return f;
		}
		public Point getPoint(int n)
		{
			if (n < 0)
			{
				n = _n + n;
			}

			if (n >= _n || n < 0)
			{
				while (n < 0)
					n += _n;
				while (n >= _n)
					n -= _n;
			}
			return _ptr[n];
		}
		public int len()
		{
			return _n;
		}
	}
}