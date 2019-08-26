using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Imaging;

namespace WeaponsCreaterTool
{





    public partial class Form1 : Form
    {
        public Point current = new Point();
        public Point old = new Point();
        public Pen p = new Pen(Color.Black, 5);
        public Pen eraser = new Pen(Color.White, 5);
        public Graphics g;
        Bitmap surface;
        Graphics graph;
        public int Width;
        public string s = "Picture";
        public int i = 1;

        public Form1()
        {
            InitializeComponent();
            g = pictureBox2.CreateGraphics();
            p.SetLineCap(System.Drawing.Drawing2D.LineCap.Round, System.Drawing.Drawing2D.LineCap.Round, System.Drawing.Drawing2D.DashCap.Round);
            eraser.SetLineCap(System.Drawing.Drawing2D.LineCap.Round, System.Drawing.Drawing2D.LineCap.Round, System.Drawing.Drawing2D.DashCap.Round);
            surface = new Bitmap(pictureBox2.Width, pictureBox2.Height);
            graph = Graphics.FromImage(surface);
            pictureBox2.BackgroundImage = surface;
            pictureBox2.BackgroundImageLayout = ImageLayout.None;
            this.SetStyle(ControlStyles.AllPaintingInWmPaint, true);
            this.SetStyle(ControlStyles.OptimizedDoubleBuffer, true);
            this.SetStyle(ControlStyles.UserPaint, true);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void panel1_MouseDown(object sender, MouseEventArgs e)
        {
            old = e.Location;
            if (radioButton1.Checked)
            {
                Width = 1;
            }
            else if (radioButton2.Checked)
            {
                Width = 5;
            }
            else if (radioButton3.Checked)
            {
                Width = 10;
            }
            else if (radioButton4.Checked)
            {
                Width = 15;
            }
            else if (radioButton5.Checked)
            {
                Width = 30;
            }
            p.Width = Width;
            eraser.Width = Width;
        }

        //private void panel1_MouseMove(object sender, MouseEventArgs e)
        //{
        //    //if Left Click draw with Black Pen
        //    if (e.Button == MouseButtons.Left)
        //    {
        //        current = e.Location;
        //        //uses p which equals black
        //        graph.DrawLine(p, old, current);
        //        old = current;
        //        panel1.Invalidate();
        //    }
        //    if (e.Button == MouseButtons.Right)
        //    {
        //        current = e.Location;
        //        //now uses white as eraser
        //        graph.DrawLine(eraser, old, current);
        //        old = current;
        //        panel1.Invalidate();
        //    }
        //}

        private void button1_Click(object sender, EventArgs e)
        {
            ColorDialog cd = new ColorDialog();
            if (cd.ShowDialog() == DialogResult.OK)
            {
                p.Color = cd.Color;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            surface.Save(s, ImageFormat.Png);
            s += i;
            i++;
        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void CreateWeapon_Click(object sender, EventArgs e)
        {
            //Go To Next Form, which will be adding attributes

        }

        private void pictureBox2_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                current = e.Location;
                //uses p which equals black
                graph.DrawLine(p, old, current);
                old = current;
                pictureBox2.Invalidate();
            }
            if (e.Button == MouseButtons.Right)
            {
                current = e.Location;
                //now uses white as eraser
                graph.DrawLine(eraser, old, current);
                old = current;
                pictureBox2.Invalidate();
            }
        }

        private void pictureBox2_MouseDown(object sender, MouseEventArgs e)
        {
            old = e.Location;
            if (radioButton1.Checked)
            {
                Width = 1;
            }
            else if (radioButton2.Checked)
            {
                Width = 5;
            }
            else if (radioButton3.Checked)
            {
                Width = 10;
            }
            else if (radioButton4.Checked)
            {
                Width = 15;
            }
            else if (radioButton5.Checked)
            {
                Width = 30;
            }
            p.Width = Width;
            eraser.Width = Width;
        }
    }
    public class TPanel : Panel
    {
        public TPanel()
        {
            this.SetStyle(ControlStyles.AllPaintingInWmPaint, true);
            this.SetStyle(ControlStyles.OptimizedDoubleBuffer, true);
            this.SetStyle(ControlStyles.UserPaint, true);
        }

        //private void InitializeComponent()
        //{
        //    this.SuspendLayout();
        //    this.ResumeLayout(false);

        //}
    }
}
