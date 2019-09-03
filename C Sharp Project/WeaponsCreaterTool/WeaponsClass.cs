using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace WeaponsCreaterTool
{
    //Base Class
    public class BaseItemsClass
    {
        private string itemName;

        public virtual string returnName
        {
            get
            {
                return itemName;
            }
            set
            {
                itemName = value;
            }
        }

        public string imagePath = "../../bin/Debug/";
    }



    public class WeaponsClass : BaseItemsClass
    {
        //Creates a list of weapons from weapons class items
        List<WeaponsClass> listOfWeapons = new List<WeaponsClass>();

        //default Constructor //--Example of Inheritance
        public WeaponsClass() : base() { }


        //Weapons Class items are filled with
        //variable of name
        private string weaponName;

        //Example Of Polymorphism
        public override string returnName
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

    }
}
