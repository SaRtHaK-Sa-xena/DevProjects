using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace WeaponsCreater
{

    class Weapon
    {
        //name of weapon
        public string name;

        //the sprite sheet to use
        public SpriteSheetClass spriteSheet;

        //tile coordinates to use
        //refer to the sprite on sprite Sheet
        public Point tileCoordinates = new Point(0, 0);

        public Weapon(string name, SpriteSheetClass spriteSheet)
        {
            //makes this name = name given by code
            //makes this sheet = sheet given by code
            this.name = name;
            this.spriteSheet = spriteSheet;
        }

        //override function ToString();
        public override string ToString()
        {
            return base.ToString() + "\n\tpath: \t" + spriteSheet.path + "\n\ttile coordinates: \t" + tileCoordinates.ToString();
        }
    }



    class SpriteSheetClass
    {
        private Image image = null;

        public string path;

        public int getWidth()
        {
            //implementation returns width
            return 2;
        }

        public int getHeight()
        {
            if (image == null)
            {
                Console.WriteLine("Error! No Image Loaded");
                return 0;
            }
            else
            {
                return 2;
            }
            //implementation returns height
        }

        public SpriteSheetClass(string path)
        {
            this.path = path;
            Load();
        }

        public void Load()
        {
            image = Image.FromFile(path);
        }

        //override function ToString();
        public override string ToString()
        {
            return base.ToString() + ": " + path.ToString();
        }

    }
}
