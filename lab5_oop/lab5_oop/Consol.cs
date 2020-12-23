using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab5_oop
{
    class Consol
    {

        public void init()
        {
           
            int search=-1;
            while (search != 0) {
                Console.WriteLine("search: 1 - Figure 2 - Pentagon 3 - Rectangle\n");
                string buf = Console.ReadLine();
                search = int.Parse(buf);

                switch (search)
                {
                    case 1: viewFigure(); break;
                    case 2: viewPentagon(); break;
                    case 3: viewRectangle(); break;
                    default: break;
                }
        }
        }

        public int viewPentagon()
        {
            Pentagon Fig=new Pentagon();
            double x, y;
            int n = 5;
            string s;
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine( "enter vertex to enter:");
                x = double.Parse(Console.ReadLine());
                y = double.Parse(Console.ReadLine());
                Fig.add(x, y);
            }
            s = "Area=";
            s += Fig.getArea().ToString();
            s += ("\nPerimetr=");
            s += Fig.getPerimetr().ToString();
            s += (" \nCentrMass=");
            Console.Write(s);
            pprint(Fig.getCentrMass());
            Console.WriteLine("\nPrint figure\n");
            for (int i = 0; i < Fig.len(); i++)
                pprint(Fig.getPoint(i));
            Console.WriteLine( "\nenter vertex for delete\n");
            n = int.Parse(Console.ReadLine()); ;
            Fig.del(n);
            for (int i = 0; i < Fig.len(); i++)
                pprint(Fig.getPoint(i));
            return 0;
        }
        public int viewRectangle()
        {
            Rectangle Fig = new Rectangle();
            double x, y;
            int n = 4;
            string s;
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine( "enter vertex to enter:");
                x = double.Parse(Console.ReadLine());
                y = double.Parse(Console.ReadLine());
                Fig.add(x, y);
            }
            s = "Area=";
            s += Fig.getArea().ToString();
            s += ("\nPerimetr=");
            s += Fig.getPerimetr().ToString();
            s += (" \nCentrMass=");
            Console.Write(s);
            pprint(Fig.getCentrMass());
            Console.WriteLine( "\nPrint figure\n");
            for (int i = 0; i < Fig.len(); i++)
                pprint(Fig.getPoint(i));
            Console.WriteLine("\nenter vertex for delete\n");
            n = int.Parse(Console.ReadLine());
            Fig.del(n);
            for (int i = 0; i < Fig.len(); i++)
                pprint(Fig.getPoint(i));

            return 0;
        }
        public int viewFigure()
        {
            Figure Fig = new Figure();
            double x, y;
            int n;
            string s;
            Console.WriteLine("enter the number of vertexes:");
            n = int.Parse(Console.ReadLine());
            if (n > 0)
            {
                for (int i = 0; i < n; i++)
                {
                    Console.WriteLine( "enter vertex to enter:");
                    x = double.Parse(Console.ReadLine());
                    y = double.Parse(Console.ReadLine());
                    Fig.add(x, y);
                }
                s = "Area=";
                s += Fig.getArea().ToString();
                s += ("\nPerimetr=");
                s += Fig.getPerimetr().ToString();
                s += (" \nCentrMass=");
                Console.Write(s);
                pprint(Fig.getCentrMass());
                Console.WriteLine("\nPrint figure\n");
                for (int i = 0; i < Fig.len(); i++)
                    pprint(Fig.getPoint(i));
                Console.WriteLine("\nenter vertex for delete\n");
                n = int.Parse(Console.ReadLine());
                Fig.del(n);

                for (int i = 0; i < Fig.len(); i++)
                    pprint(Fig.getPoint(i));

            }
            else
                Console.WriteLine("there is no such figure");
            return 0;
        }

        public void pprint(Point buf)
        {
            string s = "";
            s += buf.X;
            s += " ";
            s += buf.Y;
            s += "\n";
            Console.Write(s); 
        }
    }
}