using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class gameEngine : MonoBehaviour {

    private GameObject slider;
    private int deltaTime = 0;

	// Update is called once per frame
	void Update ()
    {
        deltaTime = deltaTime + 1;

        slider = GameObject.Find("StressMeter");
        slider.GetComponent<Slider>().value = deltaTime;
	}
}
