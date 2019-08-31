using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinaryTree
{
    class Program
    {


        static void Main(string[] args)
        {
            BinaryTreeClass m_binaryTree = new BinaryTreeClass();
            TreeNode m_selectedNode = null;
            bool start = true;
            int input = 0;

            while (start)
            {
                Console.WriteLine("Updated Binary Tree...");
                m_binaryTree.print(m_binaryTree.returnRoot());
                Console.WriteLine("\n(BINARY TREE APPLICATION), PRESS 'I' TO INSERT" + "\n PRESS 'R' TO REMOVE" + "\n PRESS 'S' TO SEARCH");
                string value = Console.ReadLine();

                Char choice = Convert.ToChar(value);
                switch (choice)
                {
                    case 'i':
                        Console.WriteLine("Enter Which Number To Insert: ");
                        int.TryParse(Console.ReadLine(), out input);
                        m_binaryTree.insert(input);
                        //pushFront function
                        break;
                    case 'r':
                        Console.WriteLine("Enter Which Number To delete: ");
                        int.TryParse(Console.ReadLine(), out input);
                        m_binaryTree.remove(input);
                        break;
                    case 's':
                        Console.WriteLine("Enter Which Number To Search: ");
                        int.TryParse(Console.ReadLine(), out input);
                        Console.WriteLine("=================================");
                        m_binaryTree.remove(input);
                        Console.WriteLine("=================================");
                        break;
                    default:
                        Console.Write("Choose one of the given options...");
                        break;
                }
            }
        }

        public class BinaryTreeClass : TreeNode
        {
            //============Private member variables============
            private TreeNode m_pRoot;
            //============Private member variables============


            //============Private function============
            private bool FindNode(int a_nSearchValue, ref TreeNode ppOutNode, ref TreeNode ppOutParent)
            {
                TreeNode current = new TreeNode(a_nSearchValue);
                TreeNode previous = null;

                current = m_pRoot;
                while (current != null)
                {
                    if (a_nSearchValue == current.getData())
                    {
                        ppOutNode = current;
                        ppOutParent = previous;
                        if (ppOutParent == null)
                        { Console.WriteLine("Parent: NULL" + "\n" + "Current: " + ppOutNode.getData()); }
                        else if (ppOutParent != null && ppOutNode != null)
                        { Console.WriteLine("Parent: " + ppOutParent.getData() + "\n" + "Current: " + ppOutNode.getData()); }
                        return true;
                    }
                    else
                    {
                        if (a_nSearchValue < current.getData())
                        {
                            previous = current;
                            current = previous.getLeft();
                        }
                        else
                        {
                            previous = current;
                            current = previous.getRight();
                        }
                    }
                }
                Console.WriteLine("Binary Tree Does Not Contain That Element...");
                return false;
            }

            private void draw(TreeNode pNode, int x, int y, int horizontalSpacing, TreeNode selected = null)
            {
                horizontalSpacing /= 2;

                if (pNode != null)
                {
                    if (pNode.hasLeft())
                    {
                        Console.WriteLine("hasLeft" + "\n pNode GetLeft:" + pNode.getLeft().getData() + "\n Selected: " + selected.getData());
                    }
                    if (pNode.hasRIght())
                    {
                        Console.WriteLine("hasRight" + "\n pNode GetRight:" + pNode.getRight().getData() + "\n Selected: " + selected.getData());

                    }
                }
            }
            //============Private function============


            //============Public functions============
            public BinaryTreeClass() { m_pRoot = null; }

            public void print(TreeNode root)
            {
                if (root == null)
                {
                    Console.Write("_");
                    return;
                }
                Console.Write(root.getData());
                //check if null
                if(root.getLeft() == null && root.getRight() == null)
                {
                    return;
                }
                Console.Write("[");
                
                //recursive
                print(root.getLeft());
                Console.Write(",");
                print(root.getRight());
                Console.Write("]");

                //int iterator = 0;
                //TreeNode current = m_pRoot;
                //TreeNode parent = m_pRoot;
                //bool reset = true;
                //if (parent != null)
                //{
                //    while (reset)
                //    {
                //        //at top
                //        while (parent.hasLeft() || parent.hasRIght())
                //        {
                //            Console.WriteLine(iterator + ":Current: " + current.getData());
                //            if (parent.hasLeft())
                //            {
                //                //Derived Left
                //                current = parent.getLeft();
                //                Console.WriteLine(iterator + ": Left: " + current.getData());
                //            }
                //            if (parent.hasRIght())
                //            {
                //                //Derived Right
                //                current = parent.getRight();
                //                Console.WriteLine(iterator + ": Right: " + current.getData());
                //            }

                //            //To move the parent
                //            if (parent.hasLeft())
                //            {
                //                parent = parent.getLeft();
                //                if(parent.getLeft() == null && parent.getRight() == null)
                //                {
                //                    reset = true;
                //                }
                //            }
                //            if (parent.hasRIght())
                //            {
                //                parent = parent.getRight();
                //                if (parent.getLeft() == null && parent.getRight() == null)
                //                {
                //                    reset = true;
                //                }
                //            }
                //        }
                //    }

                //}
            }

            public TreeNode returnRoot()
            {
                return m_pRoot;
            }

            public bool isEmpty()
            {
                if (m_pRoot == null)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }

            public void insert(int a_nValue)
            {
                if (m_pRoot == null)
                {
                    m_pRoot = new TreeNode(a_nValue);
                }
                else
                {
                    TreeNode current = null;
                    current = m_pRoot; //current will equal root

                    while (current != null)
                    {
                        if (a_nValue < current.getData()) //if less moves to the left
                        {
                            if (current.getLeft() == null)
                            {
                                current.setLeft(new TreeNode(a_nValue));
                                break;
                            }
                            current = current.getLeft(); //moves down left
                        }


                        if (a_nValue > current.getData()) // if value greater, it'll make it right child
                        {
                            if (current.getRight() == null)
                            {
                                current.setRight(new TreeNode(a_nValue));
                                break;
                            }

                            current = current.getRight();
                        }

                        if (a_nValue == current.getData())
                        {
                            return;
                        }
                    }
                }

            }

            public void remove(int a_nValue)
            {
                TreeNode current = null;
                TreeNode parent = null;

                TreeNode nullValue = null;

                if (FindNode(a_nValue, ref current, ref parent) == true)
                {
                    //=============DELETING ROOT FUNCTION===================
                    if (parent == null)
                    {
                        if (!current.hasLeft() && !current.hasRIght())
                        {
                            m_pRoot = null;
                            //delete current
                            current = nullValue;
                        }
                        else if (current.hasLeft() && current.hasRIght())
                        {
                            TreeNode tempValue = current.getRight();
                            if (tempValue.hasLeft())
                            {
                                while (tempValue.hasLeft())
                                {
                                    parent = tempValue;
                                    tempValue = tempValue.getLeft();
                                }
                                current.setData(tempValue.getData());
                                if (tempValue.getRight() != null)
                                {
                                    parent.setLeft(tempValue.getRight());
                                }
                                else
                                {
                                    parent.setLeft(null);
                                }
                                //delete tempValue
                                tempValue = nullValue;
                            }
                            else
                            {
                                parent = current.getRight();
                                parent.setLeft(current.getLeft());
                                m_pRoot = parent;

                                //delete current
                                current = nullValue;
                            }
                        }
                        else if (current.hasLeft() && !current.hasRIght())
                        {
                            parent = current.getLeft();
                            m_pRoot = parent;
                            //delete current
                            current = nullValue;
                        }
                        else if (current.hasRIght() && !current.hasLeft())
                        {
                            parent = current.getRight();
                            m_pRoot = parent;

                            //delete current
                            current = nullValue;
                        }
                    }
                    //========================END DELETING ROOT FUNCTION==============

                    //======================DELETING RIGHT SIDE OF PARENT========================
                    else if (parent.getRight() == current)
                    {
                        if (!current.hasRIght() && !current.hasLeft())
                        {
                            parent.setRight(null);
                            //delete current
                            current = nullValue;
                        }
                        else if (!current.hasLeft() && current.hasRIght())
                        {
                            TreeNode tempValue = current.getRight();
                            if (tempValue.hasLeft())
                            {
                                while (tempValue.hasLeft())
                                {
                                    parent = tempValue;
                                    tempValue = tempValue.getLeft();
                                }
                                current.setData(tempValue.getData());
                                if (tempValue.hasRIght())
                                {
                                    parent.setLeft(tempValue.getRight());
                                }
                                else
                                {
                                    parent.setLeft(null);
                                }
                                //delete tempValue
                                tempValue = nullValue;
                            }
                            else
                            {
                                parent.setRight(current.getRight());
                            }
                        }
                        else if (current.hasLeft() && !current.hasRIght())
                        {
                            TreeNode tempValue = current.getLeft();
                            if (tempValue.hasRIght())
                            {
                                while (tempValue.hasRIght())
                                {
                                    parent = tempValue;
                                    tempValue = tempValue.getRight();
                                }
                                current.setData(tempValue.getData());
                                if (tempValue.hasLeft())
                                {
                                    parent.setRight(tempValue.getLeft());
                                }
                                else
                                {
                                    current.setRight(null);
                                }
                            }
                            else
                            {
                                current.setData(tempValue.getData());
                                current.setLeft(null);
                            }
                            //delete tempValue
                            tempValue = nullValue;
                        }
                        else if (current.hasLeft() && current.hasRIght())
                        {
                            TreeNode tempValue = current.getRight();
                            if (tempValue.hasLeft())
                            {
                                while (tempValue.hasLeft())
                                {
                                    parent = tempValue;
                                    tempValue = tempValue.getLeft();
                                }
                                current.setData(tempValue.getData());
                                if (tempValue.hasRIght())
                                {
                                    parent.setLeft(tempValue.getRight());
                                }
                                else
                                {
                                    parent.setLeft(null);
                                }
                            }
                            else
                            {
                                current.setData(tempValue.getData());
                                if (tempValue.hasRIght())
                                {
                                    current.setRight(tempValue.getRight());
                                }
                                else
                                {
                                    current.setRight(null);
                                }
                            }
                            //delete tempValue
                            tempValue = nullValue;
                        }
                        //===============END  DELETE RIGHT SIDE OF PARENT======================


                    }
                    //====================DELETE LEFT SIDE OF PARENT======================
                    else if (parent.getLeft() == current)
                    {
                        if (current.getRight() == null && current.getLeft() == null)
                        {
                            parent.setLeft(null);
                            //delete current
                            current = nullValue;
                        }
                        else if (current.hasLeft() && !current.hasRIght())
                        {
                            TreeNode tempValue = current.getLeft();
                            if (tempValue.hasRIght())
                            {
                                while (tempValue.hasRIght())
                                {
                                    parent = tempValue;
                                    tempValue = tempValue.getRight();
                                }
                                current.setData(tempValue.getData());
                                if (tempValue.hasLeft())
                                {
                                    parent.setRight(tempValue.getLeft());
                                }
                                else
                                {
                                    parent.setRight(null);
                                }
                                //delete tempValue
                                tempValue = nullValue;
                            }
                            else
                            {
                                parent.setLeft(current.getLeft());
                            }

                        }
                        else if (!current.hasLeft() && current.hasRIght())
                        {
                            TreeNode tempValue = current.getRight();
                            if (tempValue.hasLeft())
                            {
                                while (tempValue.hasLeft())
                                {
                                    parent = tempValue;
                                    tempValue = tempValue.getLeft();
                                }
                                current.setData(tempValue.getData());
                                if (tempValue.hasRIght())
                                {
                                    parent.setLeft(tempValue.getRight());
                                }
                                else
                                {
                                    parent.setLeft(null);
                                }
                            }
                            else
                            {
                                current.setData(tempValue.getData());
                                if (tempValue.hasRIght())
                                {
                                    current.setRight(tempValue.getRight());
                                    current.setLeft(null);
                                    current.setRight(null);
                                }
                            }
                            //delete tempValue
                            tempValue = null;
                        }
                        else if (current.hasLeft() && current.hasRIght())
                        {
                            TreeNode tempValue = current.getRight();
                            if (tempValue.hasLeft())
                            {
                                while (tempValue.hasLeft())
                                {
                                    parent = tempValue;
                                    tempValue = tempValue.getLeft();
                                }
                                current.setData(tempValue.getData());
                                if (tempValue.hasRIght())
                                {
                                    parent.setLeft(tempValue.getRight());
                                }
                                else
                                {
                                    parent.setLeft(null);
                                }
                            }
                            else
                            {
                                current.setData(tempValue.getData());
                                current.setRight(tempValue.getRight());
                            }
                            //delete tempValue
                            tempValue = nullValue;
                        }
                    }
                }
            }

            public TreeNode Find(int a_nValue)
            {
                TreeNode current = new TreeNode(a_nValue);
                TreeNode parent = new TreeNode(a_nValue);
                FindNode(a_nValue, ref current, ref parent);
                return current;
            }

            public void draw(TreeNode selected = null)
            {
                if (m_pRoot != null && selected != null)
                    Console.WriteLine("Root: " + m_pRoot.getData() + "Selected: " + selected.getData());
                if (m_pRoot != null && selected == null)
                    Console.WriteLine("Root: " + m_pRoot.getData());
                if (m_pRoot == null && selected != null)
                    Console.WriteLine("Selected: " + selected.getData());
            }
            //============Public functions============

        }

        public class TreeNode
        {
            //============Private member variables============
            private int m_value;

            private TreeNode m_left = null;
            private TreeNode m_right = null;
            //============Private member variables============


            //============Public functions============
            public TreeNode() { }

            public TreeNode(int value)
            {
                m_value = value;

                m_left = null;
                m_right = null;
            }

            public bool hasLeft()
            {
                return (m_left != null);
            }

            public bool hasRIght()
            {
                return (m_right != null);
            }

            public int getData()
            {
                return m_value;
            }


            //Gets the Nodes Properties
            public TreeNode getLeft()
            {
                return m_left;
            }
            public TreeNode getRight()
            {
                return m_right;
            }

            //Setting Constructors
            public void setData(int value)
            {
                m_value = value;
            }
            public void setLeft(TreeNode node)
            {
                m_left = node;
            }
            public void setRight(TreeNode node)
            {
                m_right = node;
            }
            //============Public functions============



        }
    }
}
