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

        private int m_data;
        private Node next; //= new Node();

        //store value
        //store right and left
    }
}
