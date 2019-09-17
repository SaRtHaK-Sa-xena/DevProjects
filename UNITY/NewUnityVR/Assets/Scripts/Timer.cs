using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Timer : MonoBehaviour
{
    public Text timerText;
    public float Time = 5000;
    private bool startTimer = true;

    private GameObject valueToStore;
    public Transform SpawnPoint;

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

                valueToStore.transform.position = new Vector3(SpawnPoint.position.x + 45, SpawnPoint.position.y + 3, 6f);
                timerText.transform.position = new Vector3(0, 0, 0);
                //Display End Screen
                //End Screen Displays Score And Button To Play Again
            }
        }
    }
}
