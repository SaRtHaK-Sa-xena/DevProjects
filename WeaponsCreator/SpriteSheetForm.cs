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

namespace WeaponsCreator
{
    public partial class SpriteSheetForm : Form
    {
        //adding needed components
        SpriteSheetForm spriteSheet = null;
        Bitmap drawArea;

        int gridWidth = 16;
        int gridHeight = 16;
        int spacing = 0;
        private string fileName;

        public SpriteSheetForm()
        {
            //initialize
            InitializeComponent();
            //set bitmap size
            drawArea = new Bitmap(pictureBox1.Width, pictureBox1.Height);
        }

        public SpriteSheetForm(string fileName)
        {
            this.fileName = fileName;
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void buttonLoad_Click(object sender, EventArgs e)
        {
            OpenFileDialog dlg = new OpenFileDialog();
            if (dlg.ShowDialog() == DialogResult.OK)
            {
                if (dlg.CheckFileExists == true)
                {
                    //sprite
                    spriteSheet = new SpriteSheetForm(dlg.FileName);
                    drawGrid();
                }
            }
        }

        private void drawGrid()
        {
            //the draw area size
            pictureBox1.DrawToBitmap(drawArea, pictureBox1.Bounds);

            Graphics g;
            g = Graphics.FromImage(drawArea);

            g.Clear(Color.White);

            if (spriteSheet != null)
            {
                g.DrawImage(spriteSheet.BackgroundImage, 0, 0);
            }

            //set colour of pen
            Pen pen = new Pen(Brushes.Black);

            int height = pictureBox1.Height;
            int width = pictureBox1.Width;
            for (int y = 0; y < height; y += gridHeight + spacing)
            {
                g.DrawLine(pen, 0, y, width, y);
            }

            for (int x = 0; x < width; x += gridWidth + spacing)
            {
                g.DrawLine(pen, x, 0, x, height);
            }

            g.Dispose();

            pictureBox1.Image = drawArea;
        }


        private void textBoxHeight_TextChanged(object sender, EventArgs e)
        {
            if (int.TryParse(textBoxHeight.Text, out gridHeight) == true)
            {
                drawGrid();
            }

            textBoxHeight.Text = gridHeight.ToString();
        }

        private void textBoxWidth_TextChanged(object sender, EventArgs e)
        {
            if (int.TryParse(textBoxWidth.Text, out gridWidth) == true)
            {
                drawGrid();
            }

            textBoxWidth.Text = gridHeight.ToString();
        }

        private void textBoxSpacing_TextChanged(object sender, EventArgs e)
        {
            if (int.TryParse(textBoxSpacing.Text, out spacing) == true)
            {
                drawGrid();
            }

            textBoxSpacing.Text = spacing.ToString();
        }

        private void SpriteSheetForm_Shown(object sender, EventArgs e)
        {
            drawGrid();
        }
    }
}
