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
            LinkedList listToUse = new LinkedList();
            bool start = true;
            int input = 0;
            while (start)
            {
                Console.WriteLine("\n(q)PushFront---(w)PushBack---(e)Remove---(r)Sort---(t)Search---(p)Print");
                string value = Console.ReadLine();
                //int choice = Convert.ToInt32(value);

                char choice = Convert.ToChar(value);

                switch (choice)
                {
                    case 'q':
                        Console.Write("\tPushingFront...\n");
                        Console.WriteLine("Enter Which Number: ");
                        int.TryParse(Console.ReadLine(), out input);
                        listToUse.PushFront(input);
                        //pushFront function
                        break;
                    case 'w':
                        Console.Write("\t PushingBack... \n");
                        Console.WriteLine("Enter Which Number: ");
                        int.TryParse(Console.ReadLine(), out input);
                        listToUse.PushBack(input);
                        //push back function
                        break;
                    case 'e':
                        Console.Write("\t Remove...\n");
                        //remove function
                        break;
                    case 'r':
                        Console.Write("\t Sort...\n");
                        //Sort function
                        break;
                    case 't':
                        Console.Write("\t Searching...\n");
                        //Search function
                        break;
                    case 'p':
                        Console.Write("\t Printing...\n");
                        listToUse.Print();
                        break;
                    default:
                        Console.Write("\nEnter one of the given choices");
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
            node.SetNodeData(a_value);// = a_value;

            if (head == null)
            {
                head = node;
                tail = node;
                Console.WriteLine("Head Is Empty" + "\nStoring in Head" + "\n");
            }
            else
            {
                //set next of node to head and set head ot previous node
                node.SetRight(head); //= head;
                head = node;
            }

        }

        public void PushBack(int a_value)
        {
            Node node = new Node();
            node.SetNodeData(a_value);

            if (Empty())
            {
                //if nothing in list create head
                node.SetRight(head);
                head = node;
            }
            else
            {
                //tails right equals nodes
                tail.SetRight(node);
                //that node now equals tail
                tail = node;
            }
        }


        public void Remove(int a_value)
        {
            Node node = head;

            while (node.GetRight() != null)
            {
                node = node.GetRight();
            }

            Node temp = head;

            node = node.GetRight();
            if(node.GetNodeData() != a_value)
            {
                temp.SetRight(node);
                temp = node;
            }

        }


        public void Print()
        {
            if (!Empty())
            {
                //. instead of * 
                Node head = this.head;
                
                
                int i = 1;
                while (head != null)
                {
                    Console.WriteLine(i + ": " + head.GetNodeData()); //writes out list in console
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

    //class Node
    //{
    //    //public void Node()

    //    public Node()
    //    {
    //        next = null;
    //        m_data = 0;
    //    }

    //    public Node(int a_data)
    //    {
    //        m_data = a_data;
    //    }

    //    //sets data
    //    public void SetNodeData(int a_data)
    //    {
    //        //set data
    //        m_data = a_data;
    //    }
    //    //Returns data
    //    public int GetNodeData()
    //    {
    //        return m_data;
    //    }

    //    //get next 
    //    public Node GetRight()
    //    {
    //        //returns next of current node
    //        return this.next;
    //    }

    //    //set next 
    //    public void SetRight(Node a_next)
    //    {
    //        this.next = a_next;
    //    }

    //    public int m_data;
    //    public Node next = new Node();

    //    //store value
    //    //store right and left
    //}
}
