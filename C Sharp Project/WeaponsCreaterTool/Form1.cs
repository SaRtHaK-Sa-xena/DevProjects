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
    public partial class Form1 : Form
    {
        public Point current = new Point();
        public Point old = new Point();
        public Pen p = new Pen(Color.Black, 5);
        public Graphics g;

        public Form1()
        {
            InitializeComponent();
            g = panel1.CreateGraphics();
            p.SetLineCap(System.Drawing.Drawing2D.LineCap.Round, System.Drawing.Drawing2D.LineCap.Round, System.Drawing.Drawing2D.DashCap.Round);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void panel1_MouseDown(object sender, MouseEventArgs e)
        {
            old = e.Location;
            if (radioButton1.Checked)
            {
                p.Width = 1;
            }
            else if(radioButton2.Checked)
            {
                p.Width = 5;
            }
            else if(radioButton3.Checked)
            {
                p.Width = 10;
            }
            else if(radioButton4.Checked)
            {
                p.Width = 15;
            }
            else if(radioButton5.Checked)
            {
                p.Width = 30;
            }
        }

        private void panel1_MouseMove(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Left)
            {
                current = e.Location;
                g.DrawLine(p, old, current);
                old = current;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ColorDialog cd = new ColorDialog();
            if(cd.ShowDialog() == DialogResult.OK)
            {
                p.Color = cd.Color;
            }
        }
    }
}
