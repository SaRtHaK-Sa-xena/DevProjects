using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HighlightBehavior : MonoBehaviour
{
    private float timer = 5;

    // Start is called before the first frame update
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        //if colour Red Start Timer
        if (this.GetComponent<Renderer>().material.GetColor("_Color") == Color.red)
        {
            //Start Timer
            timer = timer - 5;
        }


        if(timer <= 0)
        {
            //Set it to the default Color
            this.GetComponent<Renderer>().material.SetColor("_Color", Color.white);
            timer = 5;
        }
    }
}
