using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class stressMeter : MonoBehaviour
{

    private GameObject paperObj1;
    private GameObject UIStress;
    private GameObject startButton;
    private Transform eyes;
    private GameObject gameEngine;
    private bool guiText = false;

    // Use this for initialization
    void Start()
    {
        //paperObj1 = GameObject.FindGameObjectWithTag("Good");
        //startButton = GameObject.Find("StartButton");
        gameEngine = GameObject.Find("GameEngine");
    }


    //private void OnTriggerStay(Collider other)
    //{
    //    if(other.tag == "RestPoint")
    //    {
    //        UIStress = GameObject.Find("StressMeter");
    //        //UIStress.GetComponent<Slider>().value = UIStress.GetComponent<Slider>().value - 5;
    //        //gameEngine.GetComponent<gameEngine>().deltaTime = UIStress.GetComponent<Slider>().value;
    //        gameEngine.GetComponent<gameEngine>().startStress = false;
    //    }
    //}

    private void OnTriggerExit(Collider other)
    {
        gameEngine.GetComponent<gameEngine>().startStress = true;
    }

    // Update is called once per frame
    void Update()
    {
        //eyes = GameObject.Find("Camera").transform;

        //RaycastHit detectHit;
        //if (Physics.Raycast(eyes.position, eyes.forward, out detectHit))
        //{
        //    //if detected hit equals to Target
        //    if (detectHit.collider.gameObject.CompareTag("Good"))
        //    {
        //        //Decrease Stress
        //        UIStress = GameObject.Find("StressMeter");
        //        UIStress.GetComponent<Slider>().value = UIStress.GetComponent<Slider>().value - 5;
        //        gameEngine.GetComponent<gameEngine>().deltaTime = UIStress.GetComponent<Slider>().value;
        //        gameEngine.GetComponent<gameEngine>().startStress = false;
        //    }
        //    if (detectHit.collider.gameObject == startButton)
        //    {
        //        //show GUI
        //        guiText = true;
        //    }
        //    else
        //    {
        //        gameEngine.GetComponent<gameEngine>().startStress = true;
        //        guiText = false;
        //    }
        //}


    }

    private void OnGUI()
    {
        if(guiText)
        {
           GUI.Box(new Rect(300, 300, 200, 20), "Press To Continue");
        }
    }
}
