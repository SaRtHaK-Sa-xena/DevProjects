using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace WeaponsCreater
{
    class Program
    {
        //makes static spriteSheet
        static SpriteSheetClass spriteSheet = null;

        //makes the weapon static
        static Weapon weapon = null;

        static List<Weapon> weapons = new List<Weapon>();

        static void Main(string[] args)
        {
            //path and name to be entered by User
            string path;
            string name;

            //returns current directory
            Console.WriteLine("Working directory is " + Directory.GetCurrentDirectory());

            Console.WriteLine("Enter the relative path of the sprite sheet texture: ");
            path = Console.ReadLine(); //store relative path in path

            Console.WriteLine("Make a new character (y/n): ");
            while (Console.ReadLine().ToLower().StartsWith("y") == true)
            {
                Console.WriteLine("Enter the name of the weapon to create: ");
                name = Console.ReadLine(); //store name in Name

                spriteSheet = new SpriteSheetClass(Directory.GetCurrentDirectory() + "\\" + path);
                if (spriteSheet == null)
                {
                    Console.WriteLine("Error loading sprite sheet. Exiting program.");
                    return;
                }

                Weapon weapon = new Weapon(name, spriteSheet);

                Console.WriteLine("Enter the x tile index: ");
                int x = int.Parse(Console.ReadLine()); //stores read line, and converts it into integer

                Console.WriteLine("Enter the y tile index: ");
                int y = int.Parse(Console.ReadLine());

                //sets weapon tile coordinates to new point at given x and y
                weapon.tileCoordinates = new System.Drawing.Point(x, y);

                weapons.Add(weapon); //adds to list of weapons

                Console.WriteLine("Make a new Weapon (y/n): ");
            }

            //clears console with all the previous writing
            Console.Clear();


            foreach (Weapon m_weapon in weapons)
            {
                //converts it into a string
                Console.WriteLine(m_weapon.ToString());
            }
            //activated by key
            Console.ReadKey();  
        }
    }
}
