using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class WinOrLoseCheck : MonoBehaviour
{

    //check If Win Iterator
    public int goalsHit;

    //Player Obj
    public GameObject playerObj;

    //Windows
    public GameObject[] windows;
    
    //CanvasObj
    public GameObject canvasObj;

    //StartSearch
    public bool startSearch = true;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        canvasObj = GameObject.Find("Canvas");

        playerObj = GameObject.FindGameObjectWithTag("Player");

        windows = GameObject.FindGameObjectsWithTag("goal");

        //If Timer reaches zero
        if(canvasObj.GetComponent<Timer>().time <= 0)
        {
            //Trigger Particle Effect

            //Display End Screen
            Debug.Log("You Lose");
        }


        if(goalsHit == 3)
        {
            Debug.Log("You Win");
        }
        //int increment = 0;

        //if(startSearch == true)
        //{
        //    for (int i = 0; i < windows.Length; i++)
        //    {
        //        if (windows[i].tag == "Finished")
        //        {
        //            increment = increment + 1;
        //        }
        //        if (increment == 3)
        //        {
        //            //Trigger particle effect
        //            Destroy(playerObj);
        //            break;
        //        }
        //    }
        //}

        //if(increment == 3)
        //{
        //    startSearch = false;
        //}


    }
}
