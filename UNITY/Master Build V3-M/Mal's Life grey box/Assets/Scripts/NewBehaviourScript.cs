using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NewBehaviourScript : MonoBehaviour
{
    //The platform we want ot get the collider of
    public GameObject platform;
    void Start()
    {
    }
    private void OnTriggerStay(Collider other)
    {
        if (Input.GetKeyDown("s"))
        { platform.GetComponent<BoxCollider>().enabled = false; }
    }

    private void OnTriggerExit(Collider other)
    {
        platform.GetComponent<BoxCollider>().enabled = true;
    }



    // Update is called once per frame
    void Update()
    { 

    }
}
