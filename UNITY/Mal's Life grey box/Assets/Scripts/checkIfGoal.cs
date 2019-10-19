﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class checkIfGoal : MonoBehaviour
{
    public GameObject timer;
    public GameObject stressMeter;
    public bool ifGoal;

    //For Score
    public GameObject scoreHighlight_pref;
    public GameObject player_UI;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //Access Timer Script
        timer = GameObject.Find("Canvas");
        stressMeter = GameObject.Find("GameEngine");
    }


    private void OnTriggerEnter(Collider other)
    {
        //If The Material is already Gold
        //Note: Added Boolean check so that the other collider doesn't just
        //turn it grey
        if(ifGoal == true)
        {
            //foreach (Transform child in transform)
            //{
            //    if (child.gameObject.tag != "skipGameObj")
            //    {
            //        //Turn Material back to original grey
            //        child.gameObject.GetComponent<Renderer>().material.color = Color.blue;
            //    }
            //    else
            //    {
            //        Debug.Log("Skipped Component");
            //    }
            //}

            //Add Visual Score
            player_UI = GameObject.Find("Canvas");

            //Place it on Screen
            Instantiate(scoreHighlight_pref, player_UI.transform);


            GetComponent<Renderer>().material.color = Color.blue;
            timer.GetComponent<Timer>().currentTime = timer.GetComponent<Timer>().currentTime + 10;
            //Get DeltaTime
            stressMeter.GetComponent<gameEngine>().deltaTime = stressMeter.GetComponent<gameEngine>().deltaTime - 250;
            //Make DeltaTime = DeltaTime - 100;
        }

        //Add +10 to timer

        //set If Goal to false
        ifGoal = false;
    }
}
