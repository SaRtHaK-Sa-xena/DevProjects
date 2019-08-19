using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace C_Sharp_Project
{
    class Program
    {
        //static SpriteSheet spriteSheet = null;
        //static List<Character> characters = new List<Character> < Character > ();

        static void Main(string[] args)
        {

            Console.Write("(C)alculator Or (B)asic Or (A)rray");
            Console.WriteLine();
            string choice = Console.ReadLine();
            if(choice == "B")
            {
                Console.Write("What is Your Name? ");
                Console.WriteLine();
                string name = Console.ReadLine();
                if (name.Length < 6 && name.Length > 0)
                {
                    Console.Write("You Have a small Name:");
                    Console.WriteLine(name);
                }
                if (name.Length < 15 && name.Length > 6)
                {
                    Console.Write("You Have a large Name:");
                    Console.WriteLine(name);
                }
            }

            if (choice == "C")
            {
                Console.Write("Enter Number 1: and 2:");
                Console.WriteLine();

                int num1;
                int.TryParse(Console.ReadLine(), out num1);

                int num2;
                int.TryParse(Console.ReadLine(), out num2);

                Console.Write("(A)dd--(S)ubtract--(M)ultiply--(D)ivide");
                Console.WriteLine();

                choice = Console.ReadLine();
                MyClass myClass = new MyClass();

                if (choice == "A")
                {
                    int addition = myClass.SimpleAdditionFunction(num1, num2);
                    Console.WriteLine(addition);
                }
                if (choice == "S")
                {
                    int subtraction = myClass.SubtractFunction(num1, num2);
                    Console.WriteLine(subtraction);
                }
                if (choice == "M")
                {
                    int multiply = myClass.MultiplyFunction(num1, num2);
                    Console.WriteLine(multiply);
                }
                if (choice == "D")
                {
                    int divide = myClass.DivideFunction(num1, num2);
                    Console.WriteLine(divide);
                }

            }
            if (choice == "A")
            {
                Console.Write("Displaying Array");
                Console.WriteLine();

                MyClass use = new MyClass();
                use.ArrayExample(5);



                //int[][] myIntArray = new int[3][];
                //{
                //    new int[4] { 0, 0, 0, 0 },
                //    new int[7] { 0, 0, 0, 0, 0, 0, 0 },
                //    new int[2] { 0, 0 }
                //};
                //int[] myIntArray = new int[10]
                //{
                //    0,1,2,3,4,5,6,7,8,9
                //};

                //for (int i = 0; i < myIntArray.Length; i++)
                //{
                //    int array = myIntArray[i] *= 10;
                //    Console.WriteLine(array);
                //}
            }
        }
    }
}
