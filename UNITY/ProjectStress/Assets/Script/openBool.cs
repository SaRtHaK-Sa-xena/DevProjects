using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class openBool : MonoBehaviour
{
    public Animator animationController;


    private void Start()
    {
        animationController.enabled = false;
    }

   

    private void OnTriggerEnter(Collider other)
    {
        animationController.enabled = true;
    }


    //private void OnTriggerEnter(Collider other)
    //{
    //    if (other.tag == "Player")
    //    {
    //        animationController.SetBool("openDoors", true);
    //    }
    //}

    //private void OnTriggerExit(Collider other)
    //{
    //    if (other.tag == "Player")
    //    {
    //        animationController.SetBool("openDoors", false);
    //    }
    //}
}
