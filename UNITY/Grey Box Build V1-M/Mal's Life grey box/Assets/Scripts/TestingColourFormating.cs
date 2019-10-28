using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TestingColourFormating : MonoBehaviour
{
    public GameObject testingItem;

    // Start is called before the first frame update
    void Start()
    {
        testingItem.GetComponent<Renderer>().material.color = Color.red;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
