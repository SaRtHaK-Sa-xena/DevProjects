using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class checkIfGoal : MonoBehaviour
{
    public GameObject timer;
    public GameObject stressMeter;
    public bool ifGoal;
    public bool ifTargetedOnce;

    //For Score
    public GameObject scoreHighlight_pref;
    public GameObject player_UI;

    //Player obj
    public GameObject playerObj;

    //player Holder Item
    public GameObject playerItemHolder;

    //script container
    public GameObject winOrLose;

    // Start is called before the first frame update
    void Start()
    {

    }
    //Hold referernec


    // Update is called once per frame
    void Update()
    {
        //Access Timer Script
        timer = GameObject.Find("Canvas");
        stressMeter = GameObject.Find("GameEngine");
        playerObj = GameObject.FindGameObjectWithTag("Player");
        playerItemHolder = GameObject.Find("itemHolder");

        //AccessWinOrLoseScript
        winOrLose = GameObject.Find("GameEngine");
    }


    private void OnTriggerEnter(Collider other)
    {
         //If The Material is already Gold
         //Note: Added Boolean check so that the other collider doesn't just
         //turn it grey
         if (ifGoal == true)
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

             if (playerObj.GetComponent<itemManager>().HoldingItem == true)
             {
                 //other.gameObject.GetComponentInParent<itemOnPosition>().HasItem = false;
                 //playerItemHolder.transform.GetChild(0).GetComponent<itemFunctionOnPickUp>().parentOfItem.gameObject.GetComponent<itemOnPosition>().HasItem = false; 

                 //Set Holding To false again
                 playerObj.GetComponent<itemManager>().HoldingItem = false;

                 //delete Item, so delete child
                 Destroy(playerItemHolder.transform.GetChild(0).gameObject);

                 //Add Visual Score
                 player_UI = GameObject.Find("Canvas");

                 //Place it on Screen
                 Instantiate(scoreHighlight_pref, player_UI.transform);

                 //Change Colour To Blue
                 GetComponent<Renderer>().material.color = Color.blue;
                 //Add 10 To the Timer
                 //timer.GetComponent<Timer>().currentTime = timer.GetComponent<Timer>().currentTime + 30;

                 //Add to counter To Find out in Script If Player Won
                 winOrLose.GetComponent<WinOrLoseCheck>().goalsHit = winOrLose.GetComponent<WinOrLoseCheck>().goalsHit + 1;

                 //Get DeltaTime
                 stressMeter.GetComponent<gameEngine>().deltaTime = stressMeter.GetComponent<gameEngine>().deltaTime - 400;
                 //Make DeltaTime = DeltaTime - 100;

                 ifGoal = false;
             }
         }
        
        //Add +10 to timer

        //set If Goal to false
    }
}



//using System.Collections;
//using System.Collections.Generic;
//using UnityEngine;
//using UnityEngine.UI;

//public class checkIfGoal : MonoBehaviour
//{
//    public GameObject timer;
//    public GameObject stressMeter;
//    public bool ifGoal;
//    public bool ifTargetedOnce;

//    //For Score
//    public GameObject scoreHighlight_pref;
//    public GameObject player_UI;

//    //Player obj
//    public GameObject playerObj;

//    //player Holder Item
//    public GameObject playerItemHolder;

//    // Start is called before the first frame update
//    void Start()
//    {

//    }
//    //Hold referernec


//    // Update is called once per frame
//    void Update()
//    {
//        //Access Timer Script
//        timer = GameObject.Find("Canvas");
//        stressMeter = GameObject.Find("GameEngine");
//        playerObj = GameObject.FindGameObjectWithTag("Player");
//        playerItemHolder = GameObject.Find("itemHolder");
//    }


//    private void OnTriggerEnter(Collider other)
//    {
//        //If The Material is already Gold
//        //Note: Added Boolean check so that the other collider doesn't just
//        //turn it grey
//        if(ifGoal == true)
//        {
//            //foreach (Transform child in transform)
//            //{
//            //    if (child.gameObject.tag != "skipGameObj")
//            //    {
//            //        //Turn Material back to original grey
//            //        child.gameObject.GetComponent<Renderer>().material.color = Color.blue;
//            //    }
//            //    else
//            //    {
//            //        Debug.Log("Skipped Component");
//            //    }
//            //}

//            if(playerObj.GetComponent<itemManager>().HoldingItem == true)
//            {
//                //other.gameObject.GetComponentInParent<itemOnPosition>().HasItem = false;
//                //playerItemHolder.transform.GetChild(0).GetComponent<itemFunctionOnPickUp>().parentOfItem.gameObject.GetComponent<itemOnPosition>().HasItem = false; 

//                //Set Holding To false again
//                playerObj.GetComponent<itemManager>().HoldingItem = false;

//                //delete Item, so delete child
//                Destroy(playerItemHolder.transform.GetChild(0).gameObject);

//                //Add Visual Score
//                player_UI = GameObject.Find("Canvas");

//                //Place it on Screen
//                Instantiate(scoreHighlight_pref, player_UI.transform);

//                //Change Colour To Blue
//                GetComponent<Renderer>().material.color = Color.blue;
//                //Add 10 To the Timer
//                timer.GetComponent<Timer>().currentTime = timer.GetComponent<Timer>().currentTime + 30;

//                gameObject.tag = "Finished";

//                //Get DeltaTime
//                stressMeter.GetComponent<gameEngine>().deltaTime = stressMeter.GetComponent<gameEngine>().deltaTime - 250;
//                //Make DeltaTime = DeltaTime - 100;

//                ifGoal = false;
//            }
//        }

//        //Add +10 to timer

//        //set If Goal to false
//    }
//}
