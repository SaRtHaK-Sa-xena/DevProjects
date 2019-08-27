using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Drawing.Imaging;

namespace WFA_Tool
{
    public partial class Form1 : Form
    {
        List<string> position = new List<string>();

        public Form1()
        {
            InitializeComponent();
            this.FormClosing += new FormClosingEventHandler(Form1_FormClosing);

            //create new bitmap
            Bitmap bmp = new Bitmap(200, 200);

            using (Graphics g = Graphics.FromImage(bmp)) g.Clear(Color.Red);

            //Write to string - which then could be written to xml
            string picString = "";

            using (MemoryStream m = new MemoryStream())
            {
                bmp.Save(m, ImageFormat.Png);
                picString = Convert.ToBase64String(m.ToArray());
                m.Close();
            }

            //dispose of bitmap
            bmp.Dispose();

            //read back the string to Bitmap
            byte[] bytes = Convert.FromBase64String(picString);

            Bitmap bmp2 = null;
            using (MemoryStream m = new MemoryStream(bytes))
            {
                //Constructor needd if to close and dispose of memory stream

                //create temporary bitmap of memory stream
                Bitmap bmptemp = new Bitmap(m);

                //make bmp2 equal to the bmptemp
                bmp2 = new Bitmap(bmptemp);

                //dispose previous temp
                bmptemp.Dispose();
                //dispose memory stream
                m.Close();
            }

            //make backgrournd image of form equal to new bitmap
            pictureBox3.Image = bmp2;
        }

        void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (this.BackgroundImage != null)
            {
                this.BackgroundImage.Dispose();
            }
              
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            if(e.GetType() == typeof(MouseEventArgs))
            {
                // mouse coordinates will be written to the textBox
                MouseEventArgs me = e as MouseEventArgs;
                textOutput.Text = me.Location.ToString();
                position.Add(textOutput.Text);
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void buttonExport_Click(object sender, EventArgs e)
        {
            Stream myStream;
            SaveFileDialog saveFileDialog1 = new SaveFileDialog();

            saveFileDialog1.Filter = "txt files (*.txt)|*.txt|All files (*.*)";
            saveFileDialog1.FilterIndex = 2;
            saveFileDialog1.RestoreDirectory = true;

            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                if ((myStream = saveFileDialog1.OpenFile()) != null)
                {
                    myStream.Close();
                }
                else
                {
                    myStream.Close();
                }
            }
        }
    }
}
