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
                Console.WriteLine("\n(q)PushFront---(w)PushBack---(e)Remove---(r)Sort---(t)Search---(a)PopFront---(s)PopBack---(d)Clear---(f)Count\n(g)InsertAfter--(p)Print");
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
                        if (listToUse.Count() > 0)
                        {
                            Console.WriteLine("Enter Which Number To Delete: ");
                            int.TryParse(Console.ReadLine(), out input);
                            listToUse.Remove(input);
                        }
                        else
                        {
                            Console.WriteLine("List is already Empty...");
                        }
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
                    case 'a':
                        Console.Write("\t PoppingFront...\n");
                        listToUse.PopFront();
                        //PopFront function
                        break;
                    case 's':
                        Console.Write("\t PoppingBack...\n");
                        listToUse.PopBack();
                        //PopBack function
                        break;
                    case 'd':
                        Console.Write("\t Clearing...\n");
                        listToUse.Clear();
                        //Clear function
                        break;
                    case 'f':
                        Console.Write("\t Counting...\n");
                        Console.WriteLine("Count: " + listToUse.Count());
                        //Clear function
                        break;
                    case 'g':
                        Console.Write("\t Inserting After...\n");
                        Console.WriteLine("Enter Which Number To InsertAfter: ");
                        int.TryParse(Console.ReadLine(), out input);
                        listToUse.Search(input);
                        //InsertAfter function
                        break;
                    case 'p':
                        Console.Write("\t Printing...\n");
                        listToUse.Print();
                        //Print Function
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
        class Iterator
        {
            //Iterator constructor
            public Iterator(Node a_node)
            {
                m_node = a_node;
            }

            //operator ++
            static public Iterator operator ++(Iterator Iter)
            {
                Iter.m_node = Iter.m_node.GetRight();
                return Iter;
            }

            //operator -
            static public Iterator operator -(Iterator Iter)
            {
                Iter.m_node = Iter.m_node.GetLeft();
                return Iter;
            }

            //operator --
            static public Iterator operator --(Iterator Iter)
            {
                Iter.m_node = Iter.m_node.GetLeft();
                return Iter;
            }

            public Node GetNode()
            {
                return m_node;
            }

            Node m_node = null;
        }

    
        public void UsingInsertAfter(LinkedList list)
        {
            if (!list.Empty())
            {
                string input;
                Console.WriteLine("Select starting point --> from (first) or from (last)");
                input = Console.ReadLine();

                if (input == "first")
                {
                    LinkedList.Iterator temp = new LinkedList.Iterator(list.First());// = list.First();
                    int size;
                    Console.WriteLine("Enter" + "\n How many places down from the beginning :");
                    int.TryParse(Console.ReadLine(), out size);
                    if (list.Count() > size)
                    {
                        for (int i = 0; i < size - 1; i++)
                        {
                            temp++;
                        }
                        int numberToEnter;
                        Console.WriteLine("What Number to place in that position: ");
                        int.TryParse(Console.ReadLine(), out numberToEnter);
                        list.InsertAfter(temp.GetNode(), numberToEnter);
                    }
                    else
                    {
                        Console.WriteLine("Number entered exceeds list size....");
                        Console.WriteLine("____________________________________");
                    }
                    
                }
                if (input == "last")
                {
                    LinkedList.Iterator temp = new LinkedList.Iterator(list.First());
                    int size;
                    Console.WriteLine("Enter" + "\n How many places up from the end: ");
                    int.TryParse(Console.ReadLine(), out size);

                    if (list.Count() > size)
                    {

                    }
                }
            }
        }


        public void InsertAfter(Node prev_Node, int a_value)
        {
            if (!Empty())
            {
                Node node = new Node();
                //next of previous node
                Node nodeAfterPrevNode = prev_Node.GetRight();

                if (nodeAfterPrevNode == null)
                {
                    prev_Node.SetRight(node);
                    node.SetLeft(prev_Node);
                    node.SetNodeData(a_value);
                }
                else
                {
                    prev_Node.SetRight(node);
                    node.SetLeft(prev_Node);
                    node.SetRight(nodeAfterPrevNode);
                    node.SetNodeData(a_value);
                }

            }
            else
            {
                Console.WriteLine("List is already Empty...");
            }
        }

        public Node First()
        {
            if (!Empty())
            {
                return head;
            }
            else
            {
                Console.WriteLine("List is already Empty...");
                Node Null = null;
                return Null;
            }
        }

        public Node Last()
        {
            if (!Empty())
            {
                return tail;
            }
            else
            {
                Console.WriteLine("List is already Empty");
                Node Null = null;
                return Null;
            }
        }

        public int Count()
        {
            if (!Empty())
            {
                int i = 0;
                //set node to head
                Node node = head;
                while (node.GetRight() != null)
                {
                    //iterate ->
                    node = node.GetRight();
                    i++;
                }
                i++;
                //return count
                return i;
            }
            else
            {
                Console.WriteLine("List is already Empty...");
                return 0;
            }
        }

        public void Clear()
        {
            if (!Empty())
            {
                head = null;
                tail = null;

                Console.WriteLine("List cleared");
            }
            else;
            {
                Console.WriteLine("List is already Empty...");
            }
                
        }

        public void PopBack()
        {
            if (head == null)
            {
                Console.WriteLine("List Is Empty...");
                return;
            }
            else
            {
                Node nullValue = null;
                Node node = tail;
                node.GetLeft().SetRight(nullValue);
                tail = tail.GetLeft();
                node = nullValue;
            }
        }


        public void PopFront()
        {
            if (head == null)
            {
                Console.WriteLine("List is empty");
                return;
            }
            else
            {
                Node nullValue = null;
                Node node = new Node();
                //head equal to next
                head = head.GetRight();
                //node equal to head's prev
                node = head.GetLeft();
                node = nullValue;
            }
        }


        public void PushFront(int a_value)
        {
            Node node = new Node();
            node.SetNodeData(a_value);// = a_value;
            

            if (head == null)
            {
                head = node;
                tail = node;
                Console.WriteLine("Head is Empty" + "\nStoring in Head");
            }
            else
            {
                node.SetRight(head);
                head.SetLeft(node);
                head = node;
                //tail = node.GetRight();
            }
            

            //Node node = new Node();
            //node.m_data = a_value;// = a_value;

            //if (head == null)
            //{
            //    head = node;
            //    tail = node;
            //    Console.WriteLine("Head Is Empty" + "\nStoring in Head" + "\n");
            //}
            //else
            //{
            //    //set next of node to head and set head ot previous node
            //    node.next = head; //= head;
            //    head = node;
            //}

        }

        public void PushBack(int a_value)
        {

            Node node = new Node();
            node.SetNodeData(a_value);// = a_value;

            if (Empty())
            {
                node.SetRight(head);// = head;
                head = node;
            }
            else
            {
                node.SetLeft(tail);// = tail;
                tail.SetRight(node);// = node;
                tail = node;
            }
            //Node node = new Node();
            //node.m_data = a_value;

            //if (Empty())
            //{
            //    if nothing in list create head
            //    node.next = head;
            //    head = node;
            //}
            //else
            //{
            //    tails right equals nodes
            //    tail.next = node;
            //    that node now equals tail
            //    tail = node;
            //}
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

            //===========================================================
            //Node node = new Node();
            //node = head;
            //Node temp = head;
            //int extend = 0;
            //while (node.m_data != a_value)
            //{
            //    node = node.next;
            //    extend++;
            //}

            //for (int i = 1; i < extend; i++)
            //{
            //    //iterate that many over
            //    temp = temp.next;
            //}

            ////temp is now behind NODE
            ////NODE infront at node.a_value

            //node = node.next;

            //if (node.m_data != a_value)
            //{
            //    temp.next = node;
            //    temp = node;
            //    while (node.m_data != a_value)
            //    {
            //        node = node.next;
            //    }

            //    temp.next = node.next;
            //}
            //else
            //{
            //    while (node.m_data != a_value)
            //    {
            //        node = node.next;
            //    }

            //    temp.next = node.next;
            //    node = null;
            //}
            //===========================================================
            //===========================================================SECOND ATTEMPT===========================================================
            //Node node = head;

            //while (node.GetNodeData() != a_value)
            //{
            //    node = node.GetRight();
            //}

            //Node temp = node.GetLeft();

            //node = node.GetRight();
            //if (node.GetNodeData() != a_value)
            //{
            //    temp.SetRight(node);// = node;
            //    temp = node;
            //    while (node.GetNodeData() != a_value)
            //    {
            //        node = node.GetRight();
            //    }

            //    temp.SetRight(node.GetRight());// = node.next;
            //    //node = null;
            //}

            //else
            //{
            //    while (node.GetNodeData() != a_value)
            //    {
            //        node = node.GetRight();
            //    }
            //    temp.SetRight(node.GetRight());// = node.next;
            //    //node = null;
            //}
            //===========================================================SECOND ATTEMPT===========================================================
           
            Node node = head;
            bool atEnd = false;
            bool reset = false;
            //helper
            Node nullValue = null;

            while (node.GetRight() != null)
            {
                if (node.GetNodeData() == a_value)
                {
                    //first out
                    head = node.GetRight();
                    head.SetLeft(nullValue);
                }
                while (node.GetNodeData() != a_value)
                {
                    if (node.GetRight() == null)//tail)
                    {
                        break;
                    }
                    //iterate ->
                    node = node.GetRight();

                    //if (node.GetRight() == tail)
                    //{
                    //    atEnd = true;
                    //}
                }

                if (atEnd == true)
                {
                    break;
                }


                Node temp = node.GetLeft();
                if (node == tail)
                {
                    //tail = temp;
                    //node = null;

                    tail = temp;
                    temp.SetRight(nullValue);

                    break;
                }
                while (node.GetRight().GetNodeData() == a_value)
                {
                    //iterate ->
                    node = node.GetRight();
                    if (node.GetRight() == tail)
                    {
                        //set it to tail
                        temp.SetRight(tail);
                    }

                }

                temp.SetRight(node.GetRight());
                temp = temp.GetRight();
                if (temp == tail)
                {
                    //then tail changes
                    if (temp.GetNodeData() == a_value)
                    {
                        //then tail changes
                        tail = temp.GetLeft();
                        break;
                    }
                    atEnd = true;
                    tail = temp;
                }
                while (atEnd == false && temp.GetRight().GetNodeData() != a_value)
                {
                    //iterate ->
                    temp = temp.GetRight();
                    if (temp == tail)
                    {
                        atEnd = true;
                        break;
                    }
                }
                if (atEnd == false)
                {
                    reset = true;
                }
                else
                {
                    break;
                }
                if (reset)
                {
                    node = head;
                    temp = head;
                    reset = false;
                }
            }
            //extend = 1, 2
            //HEAD      NODE
            //node node node node node
            
        }

        public void Sort()
        {
            ////================================================
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

                    //========SWAP==============
                    node.SetNodeData(temp2);// = temp2;
                    nodeRight.SetNodeData(temp1);// = temp1;
                    //========SWAP==============

                    swap = true;
                }

                else
                {
                    node = node.GetRight();
                    nodeRight = node.GetRight();
                    swap = false;
                }
            }
            //================================================
            //Node node = head;
            //Node nodeRight = node.next;

            //int temp1;
            //int temp2;

            //bool swap = false;

            //while (node.next != null)
            //{
            //    if (swap)
            //    {
            //        node = head;
            //        nodeRight = node.next;
            //    }

            //    if (node.m_data > nodeRight.m_data)
            //    {
            //        temp1 = node.m_data;
            //        temp2 = nodeRight.m_data;

            //        //======SWAP=======
            //        node.m_data = temp2;
            //        nodeRight.m_data = temp1;
            //        //======SWAP=======
            //        swap = true;
            //    }
            //    else
            //    {
            //        node = node.next;
            //        nodeRight = node.next;
            //        swap = false;
            //    }
            //}
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
                    Console.WriteLine(i + ": " + head.m_data); //writes out list in console
                    head = head.next; //iterate towards next
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
        private int m_size;
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
