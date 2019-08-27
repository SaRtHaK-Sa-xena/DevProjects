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
    public partial class DisplayWeaponNameScreen : Form
    {
        public DisplayWeaponNameScreen()
        {
            InitializeComponent();
        }

        private void AddWeaponButton_Click(object sender, EventArgs e)
        {
            WeaponGenerator previousForm = new WeaponGenerator();
            DisplayWeaponNameScreen.ActiveForm.Close();
            previousForm.Show();
        }

        //If attribute equals 10,
        //then place in attributes text.text = Attack = 10
    }
}
