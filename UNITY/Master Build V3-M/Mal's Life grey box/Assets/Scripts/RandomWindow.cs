using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class RandomWindow : MonoBehaviour
{
    private GameObject[] windows;
    private GameObject[] workingArray;



    private bool timerStart;


    // Start is called before the first frame update
    void Start()
    {

    }


    public void findARandomWindow()
    {
        //Generate List From Windows
        //windows = GameObject.FindGameObjectsWithTag("goal");
        //Find random from range of min and max
        //each update

        //for (int i = 0; i < windows.Length; i++)
        //{
        //    if(windows[i].GetComponent<checkIfGoal>().ifTargetedOnce == false)
        //    {
        //        //workingArray[i].
        //    }
        //}

        //Do all this process when not in Game Over Screen
        if (!SceneManager.GetSceneByBuildIndex(2).isLoaded)
        {
            windows = GameObject.FindGameObjectsWithTag("goal");

            //if (windows.Length == 7)
            //{
            //    //Play Script
            //    Debug.Log("You Win!");
            //}

            int randomValue = Random.Range(0, windows.Length);
            Debug.Log("randomValue for Window-> " + randomValue);

            windows[randomValue].GetComponent<Renderer>().material.color = Color.red;

            //Set in individual script to Is Goal
            windows[randomValue].GetComponent<checkIfGoal>().ifGoal = true;

            GameObject.Find("wayPointHandlers").GetComponent<wayPoint>().waypointTo = windows[randomValue].gameObject;
            //Destroy(windows[randomValue].gameObject);
        }
        //Destroy(windows[randomValue]);
        //========================================First Attempt=====================================================
        //This works but only for the first child in parent
        //windows[randomValue].GetComponentInChildren<Renderer>().material.color = Color.yellow;

        //in the window parent gameobject
        //go through all children and change its material to yellow
        //foreach (Transform child in windows[randomValue].transform)
        //{
        //    if (child.gameObject.tag != "skipGameObj")
        //    {
        //        //Set visual Colour to Goal Colour (Yellow)
        //        child.gameObject.GetComponent<Renderer>().material.color = Color.yellow;

        //        Debug.Log("No Renderer Component");
        //    }
        //    else
        //    {
        //        Debug.Log("Skipped Component");
        //    }
        //}
        //========================================First Attempt=====================================================
    }


    // Update is called once per frame
    void Update()
    {
        if (!SceneManager.GetSceneByBuildIndex(2).isLoaded)
        {
            //Get all window gameobjects
            windows = GameObject.FindGameObjectsWithTag("goal");

            //Iterator to count if there is a window
            int iterator = 0;

            //windows[0].GetComponent<checkIfGoal>().ifGoal = true;

            for (int i = 0; i < windows.Length; i++)
            {
                if (windows[i].GetComponent<checkIfGoal>().ifGoal == true)
                {
                    //break out of statement
                    iterator = 1;
                }
                //else
                //{
                //    //If no open windows, and it actually makes it here
                //    //First output to Log for Debug Purposes
                //    Debug.Log("There is now no windows as goal");

                //    
                //}
            }

            //check if the iterator more than zero
            //if greater
            if (iterator == 0)
            {
                Debug.Log("There is now no windows as goal");
                findARandomWindow();
            }

            //check each window in windows
            //foreach(GameObject window in windows)
            //{
            //    //if the goal for windows in true
            //    if(window.GetComponent<checkIfGoal>().ifGoal == true)
            //    {
            //        //break out of loop since there is a open window
            //        break;
            //    }
            //    else
            //    {
            //        //If no open windows, and it actually makes it here
            //        //First output to Log for Debug Purposes
            //        Debug.Log("There is now no windows as goal");

            //        //Then Run the Find A Random Window System
            //        findARandomWindow();
            //    }
            //}
        }
    }
}



//using System.Collections;
//using System.Collections.Generic;
//using UnityEngine;

//public class RandomWindow : MonoBehaviour
//{
//    private GameObject[] windows;
//    private bool timerStart;
//    // Start is called before the first frame update
//    void Start()
//    {

//    }


//    public void findARandomWindow()
//    {
//        //Generate List From Windows
//        //windows = GameObject.FindGameObjectsWithTag("goal");
//        //Find random from range of min and max
//        //each update

//        windows = GameObject.FindGameObjectsWithTag("goal");


//        int randomValue = Random.Range(0, windows.Length);
//        Debug.Log("randomValue -> " + randomValue);

//        //Set in individual script to Is Goal
//        windows[randomValue].GetComponent<checkIfGoal>().ifGoal = true;
//        windows[randomValue].GetComponent<Renderer>().material.color = Color.red;


//        //========================================First Attempt=====================================================
//        //This works but only for the first child in parent
//        //windows[randomValue].GetComponentInChildren<Renderer>().material.color = Color.yellow;

//        //in the window parent gameobject
//        //go through all children and change its material to yellow
//        //foreach (Transform child in windows[randomValue].transform)
//        //{
//        //    if (child.gameObject.tag != "skipGameObj")
//        //    {
//        //        //Set visual Colour to Goal Colour (Yellow)
//        //        child.gameObject.GetComponent<Renderer>().material.color = Color.yellow;

//        //        Debug.Log("No Renderer Component");
//        //    }
//        //    else
//        //    {
//        //        Debug.Log("Skipped Component");
//        //    }
//        //}
//        //========================================First Attempt=====================================================
//    }


//    // Update is called once per frame
//    void Update()
//    {
//        //Get all window gameobjects
//        windows = GameObject.FindGameObjectsWithTag("goal");

//        //Iterator to count if there is a window
//        int iterator = 0; 

//        for(int i = 0; i < windows.Length; i++)
//        {
//            if(windows[i].GetComponent<checkIfGoal>().ifGoal == true)
//            {
//                //break out of statement
//                iterator = 1;
//            }
//            //else
//            //{
//            //    //If no open windows, and it actually makes it here
//            //    //First output to Log for Debug Purposes
//            //    Debug.Log("There is now no windows as goal");

//            //    
//            //}
//        }

//        //check if the iterator more than zero
//        //if greater
//        if(iterator == 0)
//        {
//            Debug.Log("There is now no windows as goal");
//            findARandomWindow();
//        }

//        //check each window in windows
//        //foreach(GameObject window in windows)
//        //{
//        //    //if the goal for windows in true
//        //    if(window.GetComponent<checkIfGoal>().ifGoal == true)
//        //    {
//        //        //break out of loop since there is a open window
//        //        break;
//        //    }
//        //    else
//        //    {
//        //        //If no open windows, and it actually makes it here
//        //        //First output to Log for Debug Purposes
//        //        Debug.Log("There is now no windows as goal");

//        //        //Then Run the Find A Random Window System
//        //        findARandomWindow();
//        //    }
//        //}
//    }
//}
