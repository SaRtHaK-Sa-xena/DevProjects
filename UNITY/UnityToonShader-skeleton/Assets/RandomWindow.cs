using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RandomWindow : MonoBehaviour
{
    private GameObject[] windows;
    private bool timerStart = true;
    // Start is called before the first frame update
    void Start()
    {
        //Generate List From Windows
        windows = GameObject.FindGameObjectsWithTag("windows");
    }

    // Update is called once per frame
    void Update()
    {
        if (timerStart)
        {
            //Find random from range of min and max
            //each update
            int randomValue = Random.Range(0, windows.Length);
            windows[randomValue].GetComponentInChildren<Material>().color = Color.red;

            timerStart = true;
        }
    }
}
