using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LinkedList
{
    class Program
    {
        static void Main(string[] args)
        {
            //get display running
            //with switch statement
            while (true)
            {
                Console.WriteLine("(a)dd---(r)emove---(s)ort---(c)Search");
                string value = Console.ReadLine();
                int choice = Convert.ToInt32(value);
                switch (choice)
                {
                    case 1:
                        Console.Write("\tAdd...");
                        break;
                    case 2:
                        Console.Write("\t Remove...");
                        break;
                    case 3:
                        Console.Write("\t Sort...");
                        break;
                    case 4:
                        Console.Write("\t Searching...");
                        break;
                    default:
                        Console.Write("Enter one of the given choices");
                        break;
                }
            }

        }
    }

    class
}
