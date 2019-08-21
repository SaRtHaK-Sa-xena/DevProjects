using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LinkedList
{
    class Node
    {
        //public void Node()

        public Node()
        {
            next = null;
            prev = null;
            m_data = 0;
        }

        public Node(int a_data)
        {
            m_data = a_data;
            next = null;
            prev = null;
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

        public Node GetLeft()
        {
            return this.prev;
        }

        //set next 
        public void SetRight(Node a_next)
        {
            this.next = a_next;
        }

        public void SetLeft(Node a_prev)
        {
            this.prev = a_prev;
        }

        public int m_data;
        public Node next; //= new Node();
        public Node prev;

        //store value
        //store right and left
    }
}
