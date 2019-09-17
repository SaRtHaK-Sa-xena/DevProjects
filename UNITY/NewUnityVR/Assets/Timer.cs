using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Timer : MonoBehaviour
{
    public Text timerText;
    public float Time = 5000;

    // Start is called before the first frame update
    void Start()
    {
        timerText.text = Time.ToString();
        timerText.color = Color.green;
    }

    // Update is called once per frame
    void Update()
    {
        Time = Time - 1;
        timerText.text = Time.ToString();

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

            //Display End Screen
            //End Screen Displays Score And Button To Play Again
            
        }
    }
}
