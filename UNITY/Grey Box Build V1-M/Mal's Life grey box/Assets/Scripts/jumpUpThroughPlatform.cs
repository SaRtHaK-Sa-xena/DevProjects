using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class jumpUpThroughPlatform : MonoBehaviour
{
    public GameObject storeVal;
    public GameObject player;

    private void Start()
    {
        player = GameObject.FindGameObjectWithTag("Player");
    }

    private void OnTriggerEnter(Collider other)
    {
        storeVal = other.gameObject;
        other.GetComponent<BoxCollider>().enabled = false;
        player.GetComponent<SphereCollider>().enabled = false;
    }
    private void OnTriggerExit(Collider other)
    {
        other.GetComponent<BoxCollider>().enabled = true;
        player.GetComponent<SphereCollider>().enabled = true;
    }
}
