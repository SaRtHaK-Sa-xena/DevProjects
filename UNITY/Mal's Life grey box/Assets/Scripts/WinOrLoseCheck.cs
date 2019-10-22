using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class WinOrLoseCheck : MonoBehaviour
{

    public GameObject canvasObj;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        canvasObj = GameObject.Find("Canvas");

        //If Timer reaches zero
        if(canvasObj.GetComponent<Timer>().time <= 0)
        {
            //Display End Screen
            
        }
        

    }
}
