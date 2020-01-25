using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class testingPositionTargetting : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("World Position = " + gameObject.transform.rotation.y);


        if(gameObject.transform.rotation.y == -0.4617486)
        {
            Destroy(gameObject);
        }
    }

    // Update is called once per frame
    void Update()
    {

    }
}
