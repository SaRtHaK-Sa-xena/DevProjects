using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace WeaponsCreaterTool
{
    public class WeaponsClass
    {
        //Creates a list of weapons from weapons class items
        List<WeaponsClass> listOfWeapons = new List<WeaponsClass>();


        //Weapons Class items are filled with
        //variable of name

        private string weaponName;

        public string returnWeaponName
        {
            get
            {
                return weaponName;
            }

            set
            {
                weaponName = value;
            }
        }

        //variable of attributes
        private int attributes;
        public int returnAttributes { get { return attributes; } set { attributes = value;}}

        //custom made weaponImage
        //public Image weaponImage { get; set; }

        //instead of storing image
        //store image path, the path will always be the same
        public string imagePath = "../../bin/debug";


    }
}
