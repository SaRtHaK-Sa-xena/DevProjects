using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C_Sharp_Project
{
    class MyClass
    {
        public int SimpleAdditionFunction(int num1, int num2)
        {
            return num1 + num2;
        }

        public int SubtractFunction(int num1, int num2)
        {
            return num1 - num2;
        }

        public int DivideFunction(int num1, int num2)
        {
            return num1 / num2;
        }

        public int MultiplyFunction(int num1, int num2)
        {
            return num1 * num2;
        }

        public void ArrayExample(int size)
        {
            int[] array = new int[size];
            //foreach (int item in array)
            //{
            //    Console.WriteLine(item);
            //}
            for(int index = 0; index < array.Length; index++)
            {
                Console.WriteLine(array[index]);
            }
        }

    }
}
