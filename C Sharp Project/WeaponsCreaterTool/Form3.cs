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
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void AddAttributesButton_Click(object sender, EventArgs e)
        {
            DisplayWeaponNameScreen newForm = new DisplayWeaponNameScreen();
            /*turns of current active form 3*/ Form3.ActiveForm.Close();
            newForm.Show();
        }
    }
}
