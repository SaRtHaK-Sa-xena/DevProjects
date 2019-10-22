using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class Timer : MonoBehaviour
{
    public GameObject textMeshPro;

    public float currentTime = 30;

    public float time;

    public bool startTime;

    // Start is called before the first frame update
    void Start()
    {
        startTime = true;
    }

    // Update is called once per frame
    void Update()
    {

        if (startTime)
        {
            //Get time
            time = currentTime - Time.time;

            if (time <= 0)
            {
                startTime = false;
            }

            //Create Seconds String
            string seconds = (time % 60).ToString("f2");

            //display time
            textMeshPro.GetComponent<TMPro.TextMeshProUGUI>().text = ":" + seconds;
        }
        else
        {
            textMeshPro.GetComponent<TMPro.TextMeshProUGUI>().text = "0.00";
        }
    }
}
