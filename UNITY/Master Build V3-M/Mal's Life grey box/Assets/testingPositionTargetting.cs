using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class testingPositionTargetting : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("World Position = " + gameObject.transform.rotation);

        if(gameObject.transform.rotation.x == 0)
        {
            Destroy(gameObject);
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
