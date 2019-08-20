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
                Console.WriteLine("(1)Add---(2)Remove---(3)Sort---(4)Search");
                string value = Console.ReadLine();
                int choice = Convert.ToInt32(value);
                switch (choice)
                {
                    case 1:
                        Console.Write("\tAdd...");
                        
                        //add function
                        break;
                    case 2:
                        Console.Write("\t Remove...");
                        //remove function
                        break;
                    case 3:
                        Console.Write("\t Sort...");
                        //Sort function
                        break;
                    case 4:
                        Console.Write("\t Searching...");
                        //Search function
                        break;
                    default:
                        Console.Write("Enter one of the given choices");
                        break;
                }
            }

        }
    }

    class LinkedList
    {
        public void Print()
        {
            if(ref Empty == false)
            {

            }
        }







        //helper function
        public bool Empty()
        {
            if (head == null)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        private Node head, tail;
        int m_size;
    }
}
