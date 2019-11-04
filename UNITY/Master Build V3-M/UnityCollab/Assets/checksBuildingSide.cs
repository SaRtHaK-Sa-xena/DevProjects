using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class checksBuildingSide : MonoBehaviour
{
    public float value;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }


    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("collidorFront"))
        {
            value = 0;
        }
        if (other.CompareTag("collidorLeft"))
        {
            value = 90;
        }
        if (other.CompareTag("collidorRight"))
        {
            value = -90;
        }
        if (other.CompareTag("collidorBack"))
        {
            value = -180;
        }
    }
}
