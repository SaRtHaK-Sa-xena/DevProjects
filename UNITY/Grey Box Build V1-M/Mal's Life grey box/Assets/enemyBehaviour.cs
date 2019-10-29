using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class enemyBehaviour : MonoBehaviour
{
    //Enemy Object
    public GameObject enemyObj;

    //caluclate distance it moves on deltaTime
    public float step;

    //the speed that is multipled by deltaTime and added to step
    public float speed;

    public bool firstSpeed = true;

    //Follow Player Check
    public bool followPlayer;

    public bool stunned;

    //Player Container
    public GameObject playerObj;


    //Create Locations
    public Transform[] targetLocations;


    //Iterate to Next Location [int]
    public int iterator = 0;


    //Timer To Release Player From Stun
    public float stunTimer = 300;


    //StressMeter
    public GameObject gameEngine;


    // Start is called before the first frame update
    void Start()
    {
        speed = 1f;
        iterator = 0;
        //travelToFirst = true;
    }

    // Update is called once per frame
    void Update()
    {
        //First Get GameEngine
        gameEngine = GameObject.Find("GameEngine");

        //Find Player In Scene
        playerObj = GameObject.FindGameObjectWithTag("Player");

        //Get Stress Value from gameEngine component
        speed = gameEngine.GetComponent<gameEngine>().deltaTime / 150;

        if (speed <= 1)
        {
            speed = 1f;
        }

        step = speed * Time.deltaTime;



        //================================Previous Attempt at Patrol Movement=============================================
        //if (enemyObj.transform.position == positionA.position)
        //{
        //    travelToFirst = true;
        //    travelToSecond = false;
        //    travelToThird = false;
        //    travelToFourth = false;
        //}
        //if(enemyObj.transform.position == positionB.position)
        //{
        //    travelToSecond = true;
        //    travelToFirst = false;
        //    travelToThird = false;
        //    travelToFourth = false;
        //}
        //if(travelToFirst)
        //{
        //    enemyObj.transform.position = Vector3.MoveTowards(enemyObj.transform.position, positionB.position, step);
        //}
        //if(travelToSecond)
        //{
        //    enemyObj.transform.position = Vector3.MoveTowards(enemyObj.transform.position, positionA.position, step);
        //}
        //if(followPlayer)
        //{
        //    enemyObj.transform.position = Vector3.MoveTowards(enemyObj.transform.position, playerLocation.position, step);
        //}
        //================================Previous Attempt at Patrol Movement=============================================


        //Move To Locations
        transform.position = Vector3.MoveTowards(transform.position, targetLocations[iterator].transform.position, step);

        //If player at the position increase the iterator
        if (transform.position == targetLocations[iterator].transform.position)
        {
            iterator++;
        }

        //If the iterator reaces greater than the amount in list then set it back to zero
        if (iterator >= targetLocations.Length)
        {
            iterator = 0;
        }


        //if(playerObj.GetComponent<Rigidbody>().isKinematic == true)
        //{
        //    stunTimer++;

        //    //Make It as Time
        //    stunTimer = stunTimer * Time.deltaTime;

        //    //Real Life 3 seconds
        //    if(stunTimer >= 10)
        //    {
        //        //Release Player
        //        playerObj.GetComponent<Rigidbody>().isKinematic = false;

        //        //reset StunTimer
        //        stunTimer = 1;
        //    }
        //}

        if (stunned)
        {
            stunTimer--;

            if(stunTimer <= 0)
            {
                
                stunTimer = 300;
                stunned = false;
                playerObj.GetComponent<PlayerControl>().speed = 5;
                playerObj.GetComponent<jumpScript>().jumpVelocity = 10;
            }
        }
       


    }

    //=====================Attack Behaviour====================
    //private void OnTriggerStay(Collider other)
    //{
    //    if(other.CompareTag("Player"))
    //    {
    //        //If Tag Equals Player
    //        playerLocation.position = other.transform.position;
    //        followPlayer = true;
    //    }
    //}
    //=====================Attack Behaviour====================

    private void OnTriggerEnter(Collider other)
    {
        if(other.CompareTag("Player"))
        {
            other.GetComponent<PlayerControl>().speed = 0;
            other.GetComponent<jumpScript>().jumpVelocity = 0;
        }

        //Increase Stress by 150
        gameEngine.GetComponent<gameEngine>().deltaTime = gameEngine.GetComponent<gameEngine>().deltaTime + 150;


        stunned = true;

        //Stun player by freezing player
        //playerObj.GetComponent<Rigidbody>().isKinematic = true;
    }
   
}
