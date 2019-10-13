using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class testingScript : MonoBehaviour
{
    private GameObject foundObj;

    // Start is called before the first frame update
    void Start()
    {
        foundObj = GameObject.FindGameObjectWithTag("purp");

        foundObj.GetComponent<Renderer>().material.color = Color.red;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
