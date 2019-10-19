using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class checkIfGoal : MonoBehaviour
{
    public GameObject timer;
    public bool ifGoal;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //Access Timer Script
        timer = GameObject.Find("Canvas");
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
            GetComponent<Renderer>().material.color = Color.blue;
            timer.GetComponent<Timer>().currentTime = timer.GetComponent<Timer>().currentTime + 10;
        }

        //Add +10 to timer

        //set If Goal to false
        ifGoal = false;
    }
}
