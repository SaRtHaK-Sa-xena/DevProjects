using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class chrouchDownThroughPlatform : MonoBehaviour
{
    public GameObject storeVal;
    public GameObject player;

    private void Start()
    {
        player = GameObject.FindGameObjectWithTag("Player");
    }

    private void OnTriggerStay(Collider other)
    {
        storeVal = other.gameObject;
        if (Input.GetKeyDown("s"))
        {
            other.GetComponent<BoxCollider>().enabled = false;
        }
        //if(other.GetComponent<BoxCollider>().enabled == false)
        //{
        //    Debug.Log("Not On");
        //    other.GetComponent<BoxCollider>().enabled = true;
        //    //storeVal.GetComponent<BoxCollider>().enabled = true;
        //}
    }
    private void OnTriggerExit(Collider other)
    {
        other.GetComponent<BoxCollider>().enabled = true;
        //storeVal.GetComponent<BoxCollider>().enabled = true;
    }


}


//Press Space