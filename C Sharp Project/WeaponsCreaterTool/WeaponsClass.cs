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
        List<WeaponsClass> listOfWeapons; //= new List<WeaponsClass>();


        //Weapons Class items are filled with
        //variable of name
        public string weaponName { get; set; }

        //variable of attributes
        public int attributes { get; set; }

        //custom made weaponImage
        public Image weaponImage { get; set; }

        public WeaponsClass returnClass
        {
            get
            {
                WeaponsClass temp = new WeaponsClass();
                return temp;
            }

        }


    }
}
