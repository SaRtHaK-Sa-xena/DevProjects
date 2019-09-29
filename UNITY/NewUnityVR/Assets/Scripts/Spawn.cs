using System.Collections;
using System.Collections.Generic;
using UnityEngine;


/// <summary>
/// Handles The Player Spawn After The Timer Reaches 0 and The player Hits the Restart Button.
/// Stops Enemies Form Spawing, Removes Memory, Transports Player and Restarts Game.
/// </summary>
public class Spawn : MonoBehaviour
{

    //Get Needed Components
    private GameObject player;
    private GameObject TimerReference;
    private GameObject resetter;
    private GameObject[] Targets;

    public Transform SPWNPoint;
    public Transform facingDirection;
    

    public void RespawnPlayer()
    {

        //If Platform PC
        if (SystemInfo.deviceType == DeviceType.Desktop)
        {
            //Instantiate Data Containers
            player = GameObject.FindGameObjectWithTag("Player");
            TimerReference = GameObject.FindGameObjectWithTag("TimerTally");
            resetter = GameObject.FindGameObjectWithTag("GameEngine");

            //Stop Enemy Spawning From Spawner
            resetter.GetComponent<RandomSpawn>().CreateEnemies = false;

            //Call Destroyer On Existing Targets
            Targets = GameObject.FindGameObjectsWithTag("Target");
            foreach (GameObject item in Targets)
            {
                Destroy(item);
            }

            //Transport Correct Player To Platform
            player.transform.position = SPWNPoint.position;
            player.transform.LookAt(facingDirection);

            //Set Restart Function To True
            resetter.GetComponent<StartGame>().restart = true;
        }

        //If Platform VR
        else
        {
            //Get Needed Components For VR
            player = GameObject.FindGameObjectWithTag("PlayerVR");
            TimerReference = GameObject.FindGameObjectWithTag("TimerTally");
            resetter = GameObject.FindGameObjectWithTag("GameEngine");

            //Stop Enemy Spawning From Spawner
            resetter.GetComponent<RandomSpawn>().CreateEnemies = false;

            //Call Destroyer On Existing Targets
            Targets = GameObject.FindGameObjectsWithTag("Target");
            foreach (GameObject item in Targets)
            {
                Destroy(item);
            }

            //Transport Correct Player To Platform
            player.transform.position = SPWNPoint.position;
            player.transform.LookAt(facingDirection);

            //Set Restart Function To True
            resetter.GetComponent<StartGame>().restart = true;
        }
    }
}
