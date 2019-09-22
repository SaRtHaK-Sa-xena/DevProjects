using System.Collections;
using System.Collections.Generic;
using UnityEngine;


/// <summary>
/// Handles The Entire Game To Restart Function. Makes Everything Default and returns player to original position
/// </summary>
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
            //If Platform PC
            if (SystemInfo.deviceType == DeviceType.Desktop)
            {
                //Get needed Components For Desktop
                enemySpawner = GameObject.FindGameObjectWithTag("GameEngine");
                timeContainer = GameObject.FindGameObjectWithTag("TimerTally");
                playerContainer = GameObject.FindGameObjectWithTag("Player");

                //Make Create Enemies Form RandomSpawn To True
                enemySpawner.GetComponent<RandomSpawn>().CreateEnemies = true;

                //Start Timer From 5000 Again
                timeContainer.GetComponent<Timer>().Time = 5000;
                timeContainer.GetComponent<Timer>().startTimer = true;

                //Set Counter, Difficulty And Score To Default
                playerContainer.GetComponent<MouseScript>().Score = 0;
                playerContainer.GetComponent<MouseScript>().Counter = 0;
                playerContainer.GetComponent<MouseScript>().Difficulty = 50;

            }
            //If Platform VR
            else
            {
                //Get Needed Compoenents For VR
                enemySpawner = GameObject.FindGameObjectWithTag("GameEngine");
                timeContainer = GameObject.FindGameObjectWithTag("TimerTally");
                vrPlayerContainer = GameObject.FindGameObjectWithTag("PlayerVR");


                //Make Create Enemies Form RandomSpawn To True
                enemySpawner.GetComponent<RandomSpawn>().CreateEnemies = true;

                //Start Timer From 5000 Again
                timeContainer.GetComponent<Timer>().Time = 5000;
                timeContainer.GetComponent<Timer>().startTimer = true;


                //Set Counter, Difficulty And Score To Default
                vrPlayerContainer.GetComponent<RayCasting>().Score = 0;
                vrPlayerContainer.GetComponent<RayCasting>().Counter = 0;
                vrPlayerContainer.GetComponent<RayCasting>().Difficulty = 50;
            }

            //Hit Once only when called
            restart = false;
        }
    }
}
