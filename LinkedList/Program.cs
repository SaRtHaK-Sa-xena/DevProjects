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
                        Console.WriteLine("Enter Which Number To PushFront: ");
                        int.TryParse(Console.ReadLine(), out input);
                        listToUse.PushFront(input);
                        //pushFront function
                        break;
                    case 'w':
                        Console.Write("\t PushingBack... \n");
                        Console.WriteLine("Enter Which Number To PushBack: ");
                        int.TryParse(Console.ReadLine(), out input);
                        listToUse.PushBack(input);
                        //push back function
                        break;
                    case 'e':
                        Console.Write("\t Remove...\n");
                        Console.WriteLine("Enter Which Number To Delete: ");
                        int.TryParse(Console.ReadLine(), out input);
                        listToUse.Remove(input);
                        //remove function
                        break;
                    case 'r':
                        Console.Write("\t Sort...\n");
                        listToUse.Sort();
                        //Sort function
                        break;
                    case 't':
                        Console.Write("\t Searching...\n");
                        Console.WriteLine("Enter Which Number To Search: ");
                        int.TryParse(Console.ReadLine(), out input);
                        listToUse.Search(input);
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
            //Node node = head;

            //while (node.GetRight() != null)
            //{
            //    node = node.GetRight();
            //}

            //Node temp = head;

            //node = node.GetRight();
            //if(node.GetNodeData() != a_value)
            //{
            //    temp.SetRight(node);
            //    temp = node;
            //}

            //have a node at position
            //have another node before node
            Node node = new Node();
            node = head;
            Node temp = head;
            int extend = 0;
            while (node.GetNodeData() != a_value)
            {
                node = node.GetRight();
                extend++;
            }

            for (int i = 1; i < extend; i++)
            {
                //iterate that many over
                temp = temp.GetRight();
            }

            //temp is now behind NODE
            //NODE infront at node.a_value

            node = node.GetRight();

            if (node.GetNodeData() != a_value)
            {
                temp.SetRight(node);
                temp = node;
                while (node.GetNodeData() != a_value)
                {
                    node = node.GetRight();
                }

                temp.SetRight(node.GetRight());
            }
            else
            {
                while (node.GetNodeData() != a_value)
                {
                    node = node.GetRight();
                }

                temp.SetRight(node.GetRight());
                node = null;
            }
            //extend = 1, 2
            //HEAD      NODE
            //node node node node node
        }

        public void Sort()
        {
            Node node = head;
            Node nodeRight = node.GetRight();

            int temp1;
            int temp2;

            bool swap = false;

            while (node.GetRight() != null)
            {
                if (swap)
                {
                    node = head;
                    nodeRight = node.GetRight();
                }

                if (node.GetNodeData() > nodeRight.GetNodeData())
                {
                    temp1 = node.GetNodeData();
                    temp2 = nodeRight.GetNodeData();

                    //======SWAP=======
                    node.SetNodeData(temp2);
                    nodeRight.SetNodeData(temp1);
                    //======SWAP=======
                    swap = true;
                }
                else
                {
                    node = node.GetRight();
                    nodeRight = node.GetRight();
                    swap = false;
                }
            }
        }
        

        public void Search(int a_value)
        {
            Node node = head;
            int iterate = 0;
            while(node.GetRight() != null)
            {
                iterate++;
                if (node.GetNodeData() == a_value)
                {
                    Console.WriteLine(node.GetNodeData() + " Present at location " + iterate);
                    break;
                }
                else
                {
                    node = node.GetRight();
                }
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
