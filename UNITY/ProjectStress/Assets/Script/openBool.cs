using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class openBool : MonoBehaviour
{

    [SerializeField]
    private Animator animationController;

    private void OnTriggerEnter(Collider other)
    {
        if (other.tag == "Player")
        {
            animationController.SetBool("openDoors", true);
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.tag == "Player")
        {
            animationController.SetBool("openDoors", false);
        }
    }
}
