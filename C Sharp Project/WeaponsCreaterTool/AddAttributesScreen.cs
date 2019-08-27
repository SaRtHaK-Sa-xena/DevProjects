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
    public partial class AddAttributesScreen : Form
    {
        public AddAttributesScreen()
        {
            InitializeComponent();
        }

        private void AddAttributesButton_Click(object sender, EventArgs e)
        {
            DisplayWeaponNameScreen newForm = new DisplayWeaponNameScreen();
            /*turns of current active form 3*/ AddAttributesScreen.ActiveForm.Close();
            newForm.Show();
        }
    }
}
