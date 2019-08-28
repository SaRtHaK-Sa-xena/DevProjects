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
            //files will equal the file of current directory, that has .xml as filter
            var files = Directory.GetFiles(Directory.GetCurrentDirectory(), "*.xml");
            foreach (var file in files)
            {
                //now replacement holds strings
                string replacement = file.ToString();

                //now we have states what to remove from string
                //string toRemove = "C:\\Users\\sarthak\\Documents\\GitHub\\TestProject2D\\C Sharp Project\\WeaponsCreaterTool\\bin\\Debug\\";
                string toRemove = "Debug\\";

                string NewString = string.Empty;
                int i = replacement.IndexOf(toRemove);
                if (i >= 0)
                {
                    //removes per letter till length of 'toRemove' string
                    NewString = replacement.Remove(i, -toRemove.Length);
                }
            }
        }

        private void newFileToolStripMenuItem_Click(object sender, EventArgs e)
        {
            WeaponGenerator newMDIChild = new WeaponGenerator();
            newMDIChild.MdiParent = this;
            newMDIChild.Show();
            WeaponsClass CreateWeapon = new WeaponsClass();
            newMDIChild.NewWeapon = CreateWeapon;
            //WindowState = FormWindowState.Minimized;
        }

        private void LoadWeaponButton_Click(object sender, EventArgs e)
        {

            //Open FileStream
            Stream streamToOpen = File.Open(/*The .xml file name:*/ /*testObj2.returnWeaponName + */"TestNumberTwoXML.xml", FileMode.Open);
            XmlSerializer serializer = new XmlSerializer(typeof(WeaponsClass));

            WeaponsClass testObj2 = null;
            testObj2 = (WeaponsClass)serializer.Deserialize(streamToOpen);
            streamToOpen.Close();

            WeaponsClass TemporaryClass = new WeaponsClass();

            //TemporaryClass = testObj2

            //Set Text Boxes To Loaded TestObj2
            LoadedWeaponTEXT.Text = testObj2.returnWeaponName;
            LoadedAttributeTEXT.Text = testObj2.returnAttributes.ToString();

            //Load Png
            LoadedImage.Image = Image.FromFile(testObj2.imagePath);
            //LoadedImage.Image = Image.FromFile("../bin/debug/TestNumberIMG");

        }
    }
}
