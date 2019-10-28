using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DownThrough : MonoBehaviour
{
    //On trigger enter player
    private void OnTriggerEnter(Collider other)
    {
        if(Input.GetKeyDown("s"))
        {
            other.GetComponent<SphereCollider>().enabled = false;
        }
    }
    private void OnTriggerExit(Collider other)
    {
        other.GetComponent<SphereCollider>().enabled = true;
    }
}
