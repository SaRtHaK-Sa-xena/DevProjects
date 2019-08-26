using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WFA_Tool
{
    public partial class MDIForm : Form
    {
        public MDIForm()
        {
            InitializeComponent();
        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form1 newMDIChild = new Form1();
            newMDIChild.MdiParent = this;
            newMDIChild.Show();
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form activeChild = this.ActiveMdiChild;
            if(activeChild != null)
            {
                if(activeChild.GetType() == typeof(Form1))
                {
                    //Cast the activeChild and call the appropriate function here
                    
                }
            }
        }
    }
}
