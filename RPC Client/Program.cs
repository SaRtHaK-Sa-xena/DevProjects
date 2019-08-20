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
            int port = 8888;
            string playerName = "Player";
            TcpClientChannel channel = new TcpClientChannel();
            ChannelServices.RegisterChannel(channel, false); //boolean value to see if it should be encrypted or not

            //Get a reference of Player object from Server
            string playerURL = "tcp://localhost:" + port + "/" + playerName;
            Player player = (Player)Activator.GetObject(typeof(Player), playerURL);

            //loop
            while (true)
            {
                Console.Write("Type a message to the server or type 'quit' to exit\n");
                string text = Console.ReadLine();

                if (text == "quit")
                {
                    break;
                }
                //RPC: Call Function on server
                player.GetInput(text); //getInput

                
            }
        }
    }



    class Player : MarshalByRefObject
    {
        //functions to call remotely
        public void GetInput(string text)
        {
            //plus adds to the line like "<<"
            Console.WriteLine("The client says: " + text);

            if (text == "getTime")
            {
                Console.WriteLine("Server: Current Time ");
                Console.WriteLine(DateTime.Now.ToString("h:mm:ss tt"));
            }

            if (text.StartsWith("t" + "h" + "a" + "n" + "k") || text == "thank you server")
            {
                Console.WriteLine("Server: Your Welcome");
            }
        }
    }

}
