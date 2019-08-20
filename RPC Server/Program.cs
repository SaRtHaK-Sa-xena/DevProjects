using System;
using System.Runtime.Remoting;
using System.Runtime.Remoting.Channels.Tcp;
using System.Runtime.Remoting.Channels;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RPC
{
    class Program
    {
        static void Main(string[] args)
        {
            int port = 8888; //just a random port, that isn't being used by anyone
            TcpServerChannel channel = new TcpServerChannel(port); //of port
            ChannelServices.RegisterChannel(channel, false); //boolean value to see if it should be encrypted or not

            //Register Player                    //type of class we register, name for that class, whether processed by new object or singleton
            RemotingConfiguration.RegisterWellKnownServiceType(typeof(Player), "Player", WellKnownObjectMode.SingleCall);

            Console.WriteLine("Listening for requests. \nPress enter to exit...\n");
            Console.ReadLine();
        }
    }

    class Player : MarshalByRefObject
    {
        //functions to call remotely
        public void GetInput(string text)
        {
            Console.WriteLine("The client says: " + text);

            //returns time
            if (text == "getTime")
            {
                Console.WriteLine("Server: Current Time ");
                Console.WriteLine(DateTime.Now.ToString("h:mm:ss tt"));
            }

            //returns your welcome makes it more intuitive
            if (text.StartsWith("t" + "h" + "a" + "n" + "k") || text == "thank you server")
            {
                Console.WriteLine("Server: Your Welcome");
            }
        }
    }
}
