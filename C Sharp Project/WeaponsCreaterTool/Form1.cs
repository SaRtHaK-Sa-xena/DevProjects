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
        public bool drawButtonRed = true;

        public Form1()
        {
            InitializeComponent();
            g = DrawArea.CreateGraphics();
            p.SetLineCap(System.Drawing.Drawing2D.LineCap.Round, System.Drawing.Drawing2D.LineCap.Round, System.Drawing.Drawing2D.DashCap.Round);
            eraser.SetLineCap(System.Drawing.Drawing2D.LineCap.Round, System.Drawing.Drawing2D.LineCap.Round, System.Drawing.Drawing2D.DashCap.Round);
            surface = new Bitmap(DrawArea.Width, DrawArea.Height);
            graph = Graphics.FromImage(surface);
            DrawArea.Image = surface;
            //pictureBox2.BackgroundImageLayout = ImageLayout.None;
            this.SetStyle(ControlStyles.AllPaintingInWmPaint, true);
            this.SetStyle(ControlStyles.OptimizedDoubleBuffer, true);
            this.SetStyle(ControlStyles.UserPaint, true);
            pictureBox1.AllowDrop = true;
            ChangeColour();
        }

        //Changes Colour to display if user saved image
        public void ChangeColour()
        {
            if (drawButtonRed == true)
            {
                CreateWeaponButton.BackColor = Color.Red;
            }
            else
            {
                CreateWeaponButton.BackColor = Color.LightGreen;
            }
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
            drawButtonRed = false;
            //Saving Image
            surface.Save(s, ImageFormat.Png);
            s += i;
            i++;
            ChangeColour();
        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void CreateWeapon_Click(object sender, EventArgs e)
        {
            //Go To Next Form, which will be adding attributes
            Form3 newMDIChild = new Form3();
            newMDIChild.Show();
        }

        private void pictureBox2_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                current = e.Location;
                //uses p which equals black
                graph.DrawLine(p, old, current);
                old = current;
                DrawArea.Invalidate();
            }
            if (e.Button == MouseButtons.Right)
            {
                current = e.Location;
                //now uses white as eraser
                graph.DrawLine(eraser, old, current);
                old = current;
                DrawArea.Invalidate();
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

        //Reference PictureBox Image
        private void pictureBox1_DragEnter(object sender, DragEventArgs e)
        {
            e.Effect = DragDropEffects.Copy;
        }

        private void pictureBox1_DragDrop(object sender, DragEventArgs e)
        {
            foreach(string pic in (string[])e.Data.GetData(DataFormats.FileDrop))
            {
                Image img = Image.FromFile(pic);
                pictureBox1.Image = img;
                DrawArea.BackgroundImage = img;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            //Clear Button
            Image img = null;
            pictureBox1.Image = null;
            DrawArea.BackgroundImage = img;
        }

        private void button2_MouseHover(object sender, EventArgs e)
        {
            //If mouse on save button
            button2.BackColor = Color.Green;
        }

        private void button2_MouseLeave(object sender, EventArgs e)
        {
            //if mouse not on save button
            button2.BackColor = Color.LightGray;
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
