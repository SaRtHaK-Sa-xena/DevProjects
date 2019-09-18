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
            //Instantiate Data Containers
            enemySpawner = GameObject.FindGameObjectWithTag("GameEngine");
            timeContainer = GameObject.FindGameObjectWithTag("TimerTally");
            playerContainer = GameObject.FindGameObjectWithTag("Player");



            //Enemy Spawner Enabled
            enemySpawner.GetComponent<RandomSpawn>().CreateEnemies = true;

            //Start Timer From 5000
            timeContainer.GetComponent<Timer>().Time = 5000;
            timeContainer.GetComponent<Timer>().startTimer = true;

            //Reset Score To 0
            playerContainer.GetComponent<MouseScript>().Score = 0;

            //Hit Once only when called
            restart = false;
        }
    }
}
