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
            WeaponsClass weaponToBeCreated = new WeaponsClass();
        }

        private void newFileToolStripMenuItem_Click(object sender, EventArgs e)
        {
            WeaponGenerator newMDIChild = new WeaponGenerator();
            newMDIChild.MdiParent = this;
            newMDIChild.Show();
            //WindowState = FormWindowState.Minimized;
        }
    }
}
