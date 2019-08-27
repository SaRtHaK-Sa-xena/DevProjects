using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WeaponsCreaterTool
{
    public partial class MainScreen : Form
    {

        

        public MainScreen()
        {
            InitializeComponent();
            //Create a new weapon
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
            ImageListStreamer streamToOpen = File.Open("output.xml", FileMode.Open);
            XmlSerializer serializer = new XmlSerializer(typeof(WeaponsClass));

            WeaponsClass testObj2 = null;
            testObj2 = (WeaponsClass)serializer.Deserialize(stream2);
            stream2.Close();
        }
    }
}
