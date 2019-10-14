using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OtherLedgeRotation : MonoBehaviour
{
    public Animator ledgeChangeAnim;


    public GameObject playerGameObj;


    private void OnTriggerEnter(Collider other)
    {
        //start rotation
        ledgeChangeAnim.enabled = true;

        //parent player to rotating obj
        other.transform.parent = this.transform;

        playerGameObj.GetComponent<Rigidbody>().constraints = RigidbodyConstraints.FreezePositionY;
        playerGameObj.GetComponent<Rigidbody>().constraints = RigidbodyConstraints.FreezeRotation;
    }

    //private void OnTriggerExit(Collider other)
    //{
    //    transform.DetachChildren();
    //}

    private void Start()
    {
        //start with no animation
        ledgeChangeAnim.enabled = false;

        //Find Player
        playerGameObj = GameObject.FindGameObjectWithTag("Player");
    }


    private void Update()
    {
        float time = 2;



        Debug.Log("In  Update");

        if (ledgeChangeAnim.enabled == true)
        {
            time = time - 1;
            if (time <= 0)
            {
                Debug.Log("Entered Time Loop");
                playerGameObj.GetComponent<Rigidbody>().constraints = RigidbodyConstraints.None;

                //stop rotation
                ledgeChangeAnim.enabled = false;

                //unparent player
                transform.DetachChildren();

                //reset time
                time = 5;
            }
        }
    }
}
