using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

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

    //Store The Time To Be Carried On The Next Scene
    public float storetime;

    private void Awake()
    {
        //Keep This Alive, to be displayed in End screens
        //DontDestroyOnLoad(gameObject);
    }

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

        //==============CHECKS IF YOU LOST====================
        //If Timer reaches zero
        //if(!SceneManager.GetSceneByBuildIndex(2).isLoaded)
        //{
        //    if (canvasObj.GetComponent<Timer>().time <= 0)
        //    {
        //        //Trigger Particle Effect

        //        //Display End Screen
        //        SceneManager.LoadScene(2);
        //    }
        //    storetime = canvasObj.GetComponent<Timer>().time;
        //}
        //==============CHECKS IF YOU LOST====================

        //carry variable to next screen

        //==============Checks If you Have Won================
        if (goalsHit == 3)
        {
            //Display Win Screen
            SceneManager.LoadScene(1);
        }
        //==============Checks If you Have Won================

        //=====================================CHECK IF WON============================================
        //if(GameObject.Find("StressMeter").GetComponent<Slider>().value >= GameObject.Find("StressMeter").GetComponent<Slider>().maxValue)
        //{

        //    //Load You Lose Screen
        //    SceneManager.LoadScene(2);
        //}
        //=====================================CHECK IF WON============================================


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
