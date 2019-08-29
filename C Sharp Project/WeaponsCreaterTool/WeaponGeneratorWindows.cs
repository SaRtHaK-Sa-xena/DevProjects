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
using System.Xml.Serialization;
using System.IO;

namespace WeaponsCreaterTool
{

    public partial class WeaponGenerator : Form
    {
        public Point current = new Point();
        public Point old = new Point();
        public Pen p = new Pen(Color.Black, 5);
        public Pen eraser = new Pen(Color.White, 5);
        public Graphics g;
        public Bitmap surface;
        Graphics graph;
        public int Width;
        public string s = "Picture";
        public int i = 1;
        public bool drawButtonRed = true;

        //All Data Filled Checklist
        bool firstCheck = false;
        bool secondCheck = false;
        bool thirdCheck = false;
        bool fourthCheck = false;
        //All Data Filled Checklist

        public WeaponsClass NewWeapon;

        public WeaponGenerator()
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

       


        private void button1_Click(object sender, EventArgs e)
        {
            ColorDialog cd = new ColorDialog();
            if (cd.ShowDialog() == DialogResult.OK)
            {
                p.Color = cd.Color;
            }
        }

        //Save Image File Button
        private void button2_Click(object sender, EventArgs e)
        {
            //indicates interaction with user
            drawButtonRed = false;

            //Add to end
            finalWeaponImage.Image = surface;

            //Saving Image
            surface.Save(CreateImageName.Text, ImageFormat.Png);
            ChangeColour();

            //Allow FinalAddWeaponButton to be enabled
            secondCheck = true;
        }
        //Save Image File Button



        //Transitions To Next Form
        private void CreateWeapon_Click(object sender, EventArgs e)
        {
            //Sets boolean statement to true
        }


        //To constantly keep drawing over pictureBox to Save
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

        //Sets manually the WIDTH of pen
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



        //============DRAG AND DROP FEATURE=====================
        //Reference PictureBox Image
        private void pictureBox1_DragEnter(object sender, DragEventArgs e)
        {
            e.Effect = DragDropEffects.Copy;
        }

        //Picture Box Drag and Drop
        private void pictureBox1_DragDrop(object sender, DragEventArgs e)
        {
            foreach(string pic in (string[])e.Data.GetData(DataFormats.FileDrop))
            {
                Image img = Image.FromFile(pic);
                pictureBox1.Image = img;
                DrawArea.BackgroundImage = img;
            }
        }
        //============DRAG AND DROP FEATURE=====================



        //===============CLEAR BUTTON CLEARS THE REFERENCE IMAGE============
        private void button3_Click(object sender, EventArgs e)
        {
            //Clear Button
            Image img = null;
            pictureBox1.Image = null;
            DrawArea.BackgroundImage = img;
        }
        //===============CLEAR BUTTON CLEARS THE REFERENCE IMAGE=============


        //==================Image Save Button Interaction With User==========
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
        //==========Image Save Button Interaction With User==================

        //Sets the attributes of the newly generated weapon
        private void AttributeBox_MouseDown(object sender, MouseEventArgs e)
        {
            if (radioButton8.Checked)
            {
                NewWeapon.returnAttributes = 10;
                AddAttributesButton.BackColor = Color.Green;
            }
            else if (radioButton7.Checked)
            {
                NewWeapon.returnAttributes = 20;
                AddAttributesButton.BackColor = Color.Green;
            }
            else if (radioButton6.Checked)
            {
                NewWeapon.returnAttributes = 30;
                AddAttributesButton.BackColor = Color.Green;
            }

        }


        //sets the attributes of the newly generated weapon onto final screen
        private void AddAttributesButton_Click_1(object sender, EventArgs e)
        {
            //default is 10
            int AttributeSetter = 10;

            if (radioButton8.Checked)
            {
                NewWeapon.returnAttributes = 10;
                AddAttributesButton.BackColor = Color.Green;
                AttributeSetter = 10;
                thirdCheck = true;
            }
            else if (radioButton7.Checked)
            {
                NewWeapon.returnAttributes = 20;
                AddAttributesButton.BackColor = Color.Green;
                AttributeSetter = 20;
                thirdCheck = true;
            }
            else if (radioButton6.Checked)
            {
                NewWeapon.returnAttributes = 30;
                AddAttributesButton.BackColor = Color.Green;
                AttributeSetter = 30;
                thirdCheck = true;
            }
            finalAttributes.Text = AttributeSetter.ToString();
        }

        private void panel2_Paint_1(object sender, PaintEventArgs e)
        {

        }

        //Save Loadout Button Click Function
        private void SaveLoadoutButton_Click(object sender, EventArgs e)
        {
            //Saves the Entire LoadOut
            string fileName = finalWeaponNameTextBox.Text;
            NewWeapon.returnWeaponName = finalWeaponNameTextBox.Text;

            //Check to enable finalAddWeapon Button
            if (NewWeapon.returnWeaponName == null)
            {
                firstCheck = false;
            }
            else
            {
                firstCheck = true;
            }

            //Used to be here. Just Changed
            //NewWeapon.imagePath = Path.Combine(NewWeapon.imagePath, CreateImageName.Text + ".png");
            NewWeapon.imagePath = Path.Combine(NewWeapon.imagePath, CreateImageName.Text);// + ".png");
            //XML serialize to serialize just img
            XmlSerializer serializer = new XmlSerializer(typeof(WeaponsClass));
            TextWriter writer = new StreamWriter(fileName + ".xml");

            serializer.Serialize(writer, NewWeapon);
            writer.Close();

            //So can't be pressed again
            SaveLoadoutButton.Enabled = false;

            //Allow FinalAddWeaponButtonToBePressed
            fourthCheck = true;
        }




        //Add Weapon Button Click Function
        private void FinalAddWeaponButton_Click(object sender, EventArgs e)
        {

            if (firstCheck == true && secondCheck == true && thirdCheck == true && fourthCheck == true)
            {
                this.Close();
                MessageBox.Show("Weapon successfully created...");
                //Display as green
                //Then on click close form

            }
            if(firstCheck == false)
            {
                MessageBox.Show("No Name Given To Weapon");
            }
            if (secondCheck == false)
            {
                MessageBox.Show("Image Not Saved");
            }
            if (thirdCheck == false)
            {
                MessageBox.Show("No Attribute Selected");
            }
            if(fourthCheck == false)
            {
                MessageBox.Show("Loadout Not Saved");
            }
        }

        private void FinalAddWeaponButton_MouseHover(object sender, EventArgs e)
        {
            if (firstCheck == false || secondCheck == false || thirdCheck == false || fourthCheck == false)
            {
                FinalAddWeaponButton.BackColor = Color.Red;
            }
            else
            {
                FinalAddWeaponButton.BackColor = Color.Green;
            }
        }

        private void FinalAddWeaponButton_MouseLeave(object sender, EventArgs e)
        {
            FinalAddWeaponButton.BackColor = Color.Gray;
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

        //_____________________________________________
        //|Used to debug------------------------------
        //|private void InitializeComponent()
        //|{
        //|    this.SuspendLayout();
        //|    this.ResumeLayout(false);

        //|}
        //|Used to debug------------------------------

    }
}
