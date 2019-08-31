using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Serialization;
using System.IO;

namespace WeaponsCreaterTool
{

    public partial class MainScreen : Form
    {

        public MainScreen()
        {
            InitializeComponent();

            //Create a new weapon list
            List<WeaponsClass> listOfWeapons = new List<WeaponsClass>();
            AddTolist();
        }

        public void AddTolist()
        {
            // Create an instance of the ListBox
            ListBox listBox1 = new ListBox();

            // Set the size and location of the Listbox
            listBox1.Size = new System.Drawing.Size(200, 100);
            listBox1.Location = new System.Drawing.Point(10, 90);

            // Add the listBox to form
            this.Controls.Add(listBox1);

            // Set the ListBox to display items in multiple columns
            listBox1.MultiColumn = true;

            // Set the selection mode to multiple and extended
            listBox1.SelectionMode = SelectionMode.MultiExtended;

            // Shutdown the painting of the Listbox as items are added
            listBox1.BeginUpdate();

            //Create List Of Weapon Names
            List<string> Weapons = new List<string>();

            //files will equal the file of current directory, that has .xml as filter
            var files = Directory.GetFiles(Directory.GetCurrentDirectory(), "*.xml");

            //Keeps Track of amount of files
            int increment = 0;

            foreach (var file in files)
            {

                //now replacement holds strings
                string replacement = file.ToString();

                //now we have states what to remove from string
                string toRemove = "Debug\\";
                //firstLetter equal to replacement string's first letter
                string firstLetter = replacement.Substring(0, 1);

                string NewString = string.Empty;
                int i = replacement.IndexOf(toRemove) + 6; //6 is equal to the extra letters in Debug
                int firstIndex = replacement.IndexOf(firstLetter);
                if (i >= 0)
                {
                    //removes per letter till length of amount till debug
                    NewString = replacement.Remove(firstIndex, i);
                }
                //MainListOfWeapons.Text = NewString.ToString();

                //MainListBoxOfWeapons.Text = NewString;

                //============Adds the NewString to list==============

                //added to weapons list
                Weapons.Add(NewString);
                increment++;
            }
            //When here Weapons list should have all weapons
            //Now we can sort by alphabetical order
            Weapons.Sort();


            //==========This will now be placed in List===========
            //Place created String into listBox item number of X
            for(int i = 0; i < increment; i++)
            {
                //Should add one list item for weapon name from weapon list each iteration
                listBox1.Items.Add("Weapon: " + Weapons[i]);
            }
            // Allow the ListBox to repaint and display the new items.
        }

        private void newFileToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Each time a new file is created, a list will be generated.
            AddTolist();
            WeaponGenerator newMDIChild = new WeaponGenerator();
            newMDIChild.MdiParent = this;
            newMDIChild.Show();
            WeaponsClass CreateWeapon = new WeaponsClass();
            newMDIChild.NewWeapon = CreateWeapon;

            
            //WindowState = FormWindowState.Minimized;
        }

        private void LoadWeaponButton_Click(object sender, EventArgs e)
        {

            //=================Error Handling=========================
            //Try to load weapon
            try
            {
                Stream streamToOpen = File.Open(/*The .xml file name:*/WeaponsToSearchBox.Text + ".xml", FileMode.Open);

                XmlSerializer serializer = new XmlSerializer(typeof(WeaponsClass));

                WeaponsClass testObj2 = null;
                testObj2 = (WeaponsClass)serializer.Deserialize(streamToOpen);
                streamToOpen.Close();

                WeaponsClass TemporaryClass = new WeaponsClass();

                //TemporaryClass = testObj2

                //Set Text Boxes To Loaded TestObj2
                LoadedWeaponTEXT.Text = testObj2.returnName;
                LoadedAttributeTEXT.Text = testObj2.returnAttributes.ToString();

                //Load Png
                LoadedImage.Image = Image.FromFile(testObj2.imagePath);
            }
            //Clears Image, attribute, and name
            //Stops from an unhandled exception error
            catch (System.IO.IOException ex)
            {
                MessageBox.Show("Exception Occured" + "\n Please Enter a valid Weapon Name");
                LoadedAttributeTEXT.Text = null;
                LoadedWeaponTEXT.Text = null;
                LoadedImage.Image = null;
            }
            //=================Error Handling==============================

        }

        private void button1_Click(object sender, EventArgs e)
        {
            // Create an instance of the ListBox
            ListBox listBox2 = new ListBox();

            // Set the size and location of the Listbox
            listBox2.Size = new System.Drawing.Size(200, 100);
            listBox2.Location = new System.Drawing.Point(10, 90);

            // Add the listBox to form
            this.Controls.Add(listBox2);

            // Set the ListBox to display items in multiple columns
            listBox2.MultiColumn = true;

            // Set the selection mode to multiple and extended
            listBox2.SelectionMode = SelectionMode.MultiExtended;

            // Shutdown the painting of the Listbox as items are added
            listBox2.BeginUpdate();

            //Create List Of Weapon Names
            List<string> WeaponsName = new List<string>();

            //Create List Of WeaponAttributes
            List<WeaponsClass> WeaponsStats = new List<WeaponsClass>();

            //files will equal the file of current directory, that has .xml as filter
            var files = Directory.GetFiles(Directory.GetCurrentDirectory(), "*.xml");

            //Keeps Track of amount of files
            int increment = 0;

            foreach (var file in files)
            {

                //now replacement holds strings
                string replacement = file.ToString();

                //now we have states what to remove from string
                string toRemove = "Debug\\";
                //firstLetter equal to replacement string's first letter
                string firstLetter = replacement.Substring(0, 1);

                string NewString = string.Empty;
                int i = replacement.IndexOf(toRemove) + 6; //6 is equal to the extra letters in Debug
                int firstIndex = replacement.IndexOf(firstLetter);
                if (i >= 0)
                {
                    //removes per letter till length of amount till debug
                    NewString = replacement.Remove(firstIndex, i);
                }
                //MainListOfWeapons.Text = NewString.ToString();

                //MainListBoxOfWeapons.Text = NewString;

                //============Adds the NewString to list==============

                //added to weapons list
                WeaponsName.Add(NewString);
                increment++;
            }

            //Weapons Currently holds all .xml names

            //Now get variables and place them into a sorted list
            try
            {


                //for however many weapons
                for (int i = 0; i < increment; i++)
                {
                    //pass in weapon name
                    Stream streamToOpen = File.Open(/*The .xml file name:*/WeaponsName[i], FileMode.Open);

                    XmlSerializer serializer = new XmlSerializer(typeof(WeaponsClass));

                    WeaponsClass testObj2 = null;
                    testObj2 = (WeaponsClass)serializer.Deserialize(streamToOpen);
                    streamToOpen.Close();

                    //Create new temporary Weapon to be set in list
                    WeaponsClass temporaryWeapon = new WeaponsClass();

                    //Extract member variables
                    temporaryWeapon.returnName = testObj2.returnName;
                    temporaryWeapon.returnAttributes = testObj2.returnAttributes;

                    //set Img
                    temporaryWeapon.imagePath = testObj2.imagePath;

                    //Add to list of weapons
                    WeaponsStats.Add(temporaryWeapon);
                }

                //Now each weapon should be corresponding
                //Now sort by weapon attributes
                for (int i = 0; i < increment-1; i++)
                {
                    //if position current att greater than position after att
                    if (WeaponsStats[i].returnAttributes > WeaponsStats[i + 1].returnAttributes)
                    {
                        //then continue
                    }
                    //current att less than after att
                    else if (WeaponsStats[i].returnAttributes == WeaponsStats[i + 1].returnAttributes)
                    {
                        //Don't do anything
                        break;
                    }
                    else
                    {
                        //perform switch
                        int previousValue = WeaponsStats[i].returnAttributes;
                        WeaponsStats[i].returnAttributes = WeaponsStats[i + 1].returnAttributes;
                        WeaponsStats[i + 1].returnAttributes = previousValue;
                        //switch complete
                        i = 0;
                    }
                }

                //Now a for loop to add them into list
                for(int i = 0; i < increment; i++)
                {
                    listBox2.Items.Add("Weapon: " + WeaponsStats[i].returnName);
                }
            }
            //Clears Image, attribute, and name
            //Stops from an unhandled exception error
            catch (System.IO.IOException ex)
            {
                MessageBox.Show("Exception Occured" + "\n Please Enter a valid Weapon Name");
                LoadedAttributeTEXT.Text = null;
                LoadedWeaponTEXT.Text = null;
                LoadedImage.Image = null;
            }

            //// Create an instance of the ListBox
            //ListBox listBox1 = new ListBox();

            //// Set the size and location of the Listbox
            //listBox1.Size = new System.Drawing.Size(200, 100);
            //listBox1.Location = new System.Drawing.Point(50, 90);

            //// Add the listBox to form
            //this.Controls.Add(listBox1);

            //// Set the ListBox to display items in multiple columns
            //listBox1.MultiColumn = true;

            //// Set the selection mode to multiple and extended
            //listBox1.SelectionMode = SelectionMode.MultiExtended;


            ////Create List Of Weapon Names
            //List<WeaponsClass> Weapons = new List<WeaponsClass>();

            ////files will equal the file of current directory, that has .xml as filter
            //var files = Directory.GetFiles(Directory.GetCurrentDirectory(), "*.xml");

            ////Keeps Track of amount of files
            //int increment = 0;

            //foreach (var file in files)
            //{
            //    Stream streamToOpen = File.Open(/*The .xml file name:*/WeaponsToSearchBox.Text + ".xml", FileMode.Open);

            //    XmlSerializer serializer = new XmlSerializer(typeof(WeaponsClass));

            //    WeaponsClass testObj2 = null;
            //    testObj2 = (WeaponsClass)serializer.Deserialize(streamToOpen);
            //    streamToOpen.Close();
            //    //============Adds the NewString to list==============

            //    //added to weapons list
            //    WeaponsClass temporary = new WeaponsClass();
            //    temporary.returnName = testObj2.returnName;
            //    temporary.returnAttributes = testObj2.returnAttributes;
            //    Weapons.Add(temporary);
            //    increment++;
            //}
            ////When here Weapons list should have all weapons
            ////Now we can sort by alphabetical order
            //Weapons.Sort();


            ////==========This will now be placed in List===========
            ////Place created String into listBox item number of X
            //for (int i = 0; i < increment; i++)
            //{
            //    //Should add one list item for weapon name from weapon list each iteration
            //    listBox1.Items.Add("Weapon: " + Weapons[i]);
            //}
            //// Allow the ListBox to repaint and display the new items.
        }
    }
}
