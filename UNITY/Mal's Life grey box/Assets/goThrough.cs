using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class goThrough : MonoBehaviour
{
    private void OnTriggerEnter(Collider other)
    {
        GetComponent<BoxCollider>().enabled = false;
    }

    private void OnTriggerExit(Collider other)
    {
        GetComponent<BoxCollider>().enabled = true;
    }

}
