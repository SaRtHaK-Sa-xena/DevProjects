using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Timer : MonoBehaviour
{
    public Text timerText;
    public float Time = 5000;
    public bool startTimer = true;

    private GameObject valueToStore;
    public Transform SpawnPoint;

    public Transform FinalSPWNPoint;
    public Transform FinalSPWNPointFacing;
    private GameObject player;

    // Start is called before the first frame update
    void Start()
    {
        timerText.text = Time.ToString();
        timerText.color = Color.green;
    }

    // Update is called once per frame
    void Update()
    {
        valueToStore = GameObject.FindGameObjectWithTag("ScoreTally");
        if (SystemInfo.deviceType == DeviceType.Desktop)
        {
            player = GameObject.FindGameObjectWithTag("Player");
        }
        else
        {
            player = GameObject.FindGameObjectWithTag("PlayerVR");
        }

        timerText.text = Time.ToString();

        if (startTimer == true)
        {
            Time = Time - 1;
            if (Time < 2500)
            {
                timerText.color = Color.yellow;
            }
            if (Time < 500)
            {
                timerText.color = Color.red;
            }
            if (Time <= 0)
            {
                Time = 0;
                startTimer = false;

                //Teleport Player To End Position
                player.transform.position = FinalSPWNPoint.position;
                player.transform.LookAt(FinalSPWNPointFacing);

                //Display End Screen
                //End Screen Displays Score And Button To Play Again
            }
        }
        else
        {
            //Set Time To Default
            Time = 5000;
        }
    }
}
