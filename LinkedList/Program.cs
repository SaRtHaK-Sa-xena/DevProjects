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

    class LinkedList : Node
    {

        public void PushFront(int a_value)
        {
            Node node = new Node();


        }



        public void Print()
        {
            if (!Empty())
            {
                //. instead of * 
                Node* head = this->head;
                ofType(Node)
                head
                
                int i = 1;
                while (head != null)
                {
                    Console.WriteLine(i + ": " + head.GetNodeData() + "\n"); //writes out list in console
                    head = head.GetRight(); //iterate towards next
                    i++;
                }
            }
            else //list empty
            {
                Console.WriteLine("List is already Empty..." + "\n");
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

    class Node
    {
        //public void Node()

        public Node()
        {
            next = null;
            m_data = 0;
        }

        public Node(int a_data)
        {
            m_data = a_data;
        }

        //sets data
        public void SetNodeData(int a_data)
        {
            //set data
            m_data = a_data;
        }
        //Returns data
        public int GetNodeData()
        {
            return m_data;
        }

        //get next 
        public Node GetRight()
        {
            //returns next of current node
            return this.next;
        }

        //set next 
        public void SetRight(Node a_next)
        {
            this.next = a_next;
        }

        public int m_data;
        public Node next = new Node();

        //store value
        //store right and left
    }
}
