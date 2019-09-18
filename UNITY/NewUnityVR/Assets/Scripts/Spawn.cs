using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Spawn : MonoBehaviour
{
    private GameObject player;
    private GameObject TimerReference;
    private GameObject resetter;
    private GameObject[] Targets;

    public Transform SPWNPoint;
    public Transform facingDirection;
    

    public void RespawnPlayer()
    {
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

            resetter.GetComponent<StartGame>().restart = true;
        }

        else
        {
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

            resetter.GetComponent<StartGame>().restart = true;
        }
    }
}
