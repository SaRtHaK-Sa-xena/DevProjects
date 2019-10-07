﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class stressMeter : MonoBehaviour
{

    private GameObject paperObj1;
    private GameObject UIStress;
    private Transform eyes;
    private GameObject gameEngine;

    // Use this for initialization
    void Start()
    {
        paperObj1 = GameObject.FindGameObjectWithTag("Good");
    }

    // Update is called once per frame
    void Update()
    {
        gameEngine = GameObject.Find("GameEngine");
        eyes = GameObject.Find("Camera").transform;

        RaycastHit detectHit;
        if (Physics.Raycast(eyes.position, eyes.forward, out detectHit))
        {
            //if detected hit equals to Target
            if (detectHit.collider.gameObject.CompareTag("Good"))
            {
                //Decrease Stress
                UIStress = GameObject.Find("StressMeter");
                UIStress.GetComponent<Slider>().value = UIStress.GetComponent<Slider>().value - 5;
                gameEngine.GetComponent<gameEngine>().deltaTime = UIStress.GetComponent<Slider>().value;
                gameEngine.GetComponent<gameEngine>().startStress = false;
            }
            else
            {
                gameEngine.GetComponent<gameEngine>().startStress = true;
            }
        }
    }
}