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
    }
}
