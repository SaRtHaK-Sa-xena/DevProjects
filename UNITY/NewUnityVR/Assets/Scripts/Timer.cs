using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


/// <summary>
/// Timer Functions For handling The Time In Game
/// </summary>
public class Timer : MonoBehaviour
{
    //Create Needed Components
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
        //Set Text To String From 5000 to "5000"
        timerText.text = Time.ToString();
        //Set To Green
        timerText.color = Color.green;
    }

    // Update is called once per frame
    void Update()
    {
        //Get Value From ScoreTally
        valueToStore = GameObject.FindGameObjectWithTag("ScoreTally");

        //IF Desktop Create Player With Tag "Player"
        if (SystemInfo.deviceType == DeviceType.Desktop)
        {
            player = GameObject.FindGameObjectWithTag("Player");
        }

        //IF VR Create Player With Tag "PlayerVR"
        else
        {
            player = GameObject.FindGameObjectWithTag("PlayerVR");
        }

        //Set Float Value To string an onto Canvas 
        timerText.text = Time.ToString();


        //If Timer Should Start
        if (startTimer == true)
        {

            //Decremenet Timer
            Time = Time - 1;

            //If Plenty Time left Create Yellow
            if (Time < 2500)
            {
                timerText.color = Color.yellow;
            }

            //Almost Out Create Red
            if (Time < 500)
            {
                timerText.color = Color.red;
            }

            //If Out
            if (Time <= 0)
            {
                //Display 0
                Time = 0;
                //Don't Start Timer
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
