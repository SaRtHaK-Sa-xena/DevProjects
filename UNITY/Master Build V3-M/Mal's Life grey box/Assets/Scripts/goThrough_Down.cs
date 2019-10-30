using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class goThrough_Down : MonoBehaviour
{
    public GameObject ledge;

    private void OnTriggerStay(Collider other)
    {
        if (Input.GetKeyDown("s"))
        {
            ledge.GetComponent<BoxCollider>().enabled = false;
        }
    }
}
