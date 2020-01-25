using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class attachPlayer : MonoBehaviour
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

        if(ledgeChangeAnim.enabled == true)
        {
            time = time - 1;
            if(time <= 0)
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

//========Set Clamp to 30 - 60 - 90 Each update to nearest

//private void OnTriggerEnter(Collider other)
//{
//    //If player enter collider
//    if (other.gameObject.tag == "Player")
//    {
//        ledgeChangeAnim.enabled = true;
//        other.transform.parent = this.transform;

//    }
//    else
//    {
//        ledgeChangeAnim.enabled = false;
//    }
//}

//private void Start()
//{
//    ledgeChangeAnim.enabled = false;
//    playerGameObj = GameObject.FindGameObjectWithTag("Player");
//}

//private void Update()
//{
//    float timer = 4;

//    //Check if player on other side
//    if (ledgeChangeAnim.enabled == true)
//    {
//        timer = timer - 1;
//        Debug.Log("Timer: " + timer);

//        if (timer <= 0)
//        {
//            ledgeChangeAnim.enabled = false;
//            timer = 4;
//            //reset
//            Debug.Log("Timer: " + timer + " Now at end");
//        }
//    }
//}