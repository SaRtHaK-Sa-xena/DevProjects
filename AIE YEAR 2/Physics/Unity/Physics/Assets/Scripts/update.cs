using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class update : MonoBehaviour
{
    SliderJoint2D slider_2d;

    // Start is called before the first frame update
    void Start()
    {
        //  Get slider on obj
        slider_2d = GetComponent<SliderJoint2D>();
        slider_2d.connectedAnchor = transform.position; 
    }

    // Update is called once per frame
    void Update()
    {
    }
}
