using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class gameEngine : MonoBehaviour {

    private GameObject slider;
    public float deltaTime = 0;

    private GameObject[] platforms;

    public bool startStress = true;

    private void Start()
    {
        platforms = GameObject.FindGameObjectsWithTag("platform");
        for (int i = 0; i < platforms.Length; i++)
        {
            platforms[i].AddComponent<Rigidbody>().useGravity = false;
        }
    }

    // Update is called once per frame
    void Update ()
    {
        if(deltaTime > 100)
        {
            for (int i = 0; i < platforms.Length; i++)
            { 
                platforms[i].GetComponent<Rigidbody>().AddForce(Vector3.up);
            }
        }

        if (startStress)
        {
            deltaTime = deltaTime + 1;

            slider = GameObject.Find("StressMeter");
            slider.GetComponent<Slider>().value = deltaTime;
        }

	}
}
