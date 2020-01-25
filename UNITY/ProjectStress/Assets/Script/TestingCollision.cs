using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TestingCollision : MonoBehaviour
{

    public Animator anim;

    // Use this for initialization
    void Start()
    {
        anim.enabled = false;
    }

    // Update is called once per frame
    void Update()
    {
    }

    private void OnTriggerEnter(Collider other)
    {
        anim.enabled = true;
    }

    private void OnTriggerExit(Collider other)
    {
        anim.enabled = false;
    }
}
