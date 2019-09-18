using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class StartGame : MonoBehaviour
{
    // Start is called before the first frame update
    public bool restart = false;

    private GameObject enemySpawner;
    private GameObject timeContainer;
    private GameObject playerContainer;
    private GameObject vrPlayerContainer;

    void Start()
    {
       //Create Blocks
       //Set Time To 5000
       //Set Score to 0

    }

    // Update is called once per frame
    void Update()
    {
        
        if(restart == true)
        {
            if (SystemInfo.deviceType == DeviceType.Desktop)
            {
                enemySpawner = GameObject.FindGameObjectWithTag("GameEngine");
                timeContainer = GameObject.FindGameObjectWithTag("TimerTally");
                playerContainer = GameObject.FindGameObjectWithTag("Player");
                enemySpawner.GetComponent<RandomSpawn>().CreateEnemies = true;
                timeContainer.GetComponent<Timer>().Time = 5000;
                timeContainer.GetComponent<Timer>().startTimer = true;
                playerContainer.GetComponent<MouseScript>().Score = 0;
                playerContainer.GetComponent<MouseScript>().Counter = 0;
                playerContainer.GetComponent<MouseScript>().Difficulty = 50;

            }
            else
            {
                enemySpawner = GameObject.FindGameObjectWithTag("GameEngine");
                timeContainer = GameObject.FindGameObjectWithTag("TimerTally");
                vrPlayerContainer = GameObject.FindGameObjectWithTag("PlayerVR");
                enemySpawner.GetComponent<RandomSpawn>().CreateEnemies = true;
                timeContainer.GetComponent<Timer>().Time = 5000;
                timeContainer.GetComponent<Timer>().startTimer = true;
                vrPlayerContainer.GetComponent<RayCasting>().Score = 0;
                vrPlayerContainer.GetComponent<RayCasting>().Counter = 0;
                vrPlayerContainer.GetComponent<RayCasting>().Difficulty = 50;
            }

            ////Instantiate Data Containers
            //enemySpawner = GameObject.FindGameObjectWithTag("GameEngine");
            //timeContainer = GameObject.FindGameObjectWithTag("TimerTally");
            //playerContainer = GameObject.FindGameObjectWithTag("Player");
            //vrPlayerContainer = GameObject.FindGameObjectWithTag("PlayerVR");


            ////Enemy Spawner Enabled
            //enemySpawner.GetComponent<RandomSpawn>().CreateEnemies = true;

            ////Start Timer From 5000
            //timeContainer.GetComponent<Timer>().Time = 5000;
            //timeContainer.GetComponent<Timer>().startTimer = true;

            ////Reset Score To 0
            //playerContainer.GetComponent<MouseScript>().Score = 0;
            //vrPlayerContainer.GetComponent<RayCasting>().Score = 0;

            ////Set Their Counters to zero
            //playerContainer.GetComponent<MouseScript>().Counter = 0;
            //vrPlayerContainer.GetComponent<RayCasting>().Counter = 0;

            ////And Their Difficulty Incrementers to zero
            //playerContainer.GetComponent<MouseScript>().Difficulty = 0;
            //vrPlayerContainer.GetComponent<RayCasting>().Difficulty = 0;


            //Hit Once only when called
            restart = false;
        }
    }
}
