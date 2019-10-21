using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class gameEngine : MonoBehaviour {

    private GameObject slider;
    public float deltaTime = 0;

    public Animation myAnim;
    public Animation myAnim2;

    public GameObject player;
    //public GameObject rotated90;
    //public GameObject scoreHighlight_pref;
    //public GameObject player_UI;

    //private GameObject[] platforms;

    public bool startStress = true;

    private void Start()
    {
        //platforms = GameObject.FindGameObjectsWithTag("platform");
        //for (int i = 0; i < platforms.Length; i++)
        //{
        //    platforms[i].AddComponent<Rigidbody>().useGravity = false;
        //}
        //player_UI = GameObject.Find("Canvas");

        //Instantiate(scoreHighlight_pref);
        //Instantiate(scoreHighlight_pref, player_UI.transform);

        //scoreHighlight_pref.transform.SetParent(player_UI.transform);

        player = GameObject.Find("Player");
        //player.transform.SetPositionAndRotation(player.transform.position, rotated90.transform.rotation);
       
    }

    // Update is called once per frame
    void Update ()
    {
        //if(deltaTime > 100)
        //{
        //    for (int i = 0; i < platforms.Length; i++)
        //    { 
        //        platforms[i].GetComponent<Rigidbody>().AddForce(Vector3.up);
        //    }
        //}

        if (startStress)
        {
            deltaTime = deltaTime + 1;

            slider = GameObject.Find("StressMeter");
            slider.GetComponent<Slider>().value = deltaTime;
        }

	}
}
