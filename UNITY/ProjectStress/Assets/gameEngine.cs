using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class gameEngine : MonoBehaviour {

    private GameObject slider;
    public float deltaTime = 0;

    public bool startStress = true;

	// Update is called once per frame
	void Update ()
    {
        if(deltaTime > 100)
        {
           
        }

        if (startStress)
        {
            deltaTime = deltaTime + 1;

            slider = GameObject.Find("StressMeter");
            slider.GetComponent<Slider>().value = deltaTime;
        }

	}
}
