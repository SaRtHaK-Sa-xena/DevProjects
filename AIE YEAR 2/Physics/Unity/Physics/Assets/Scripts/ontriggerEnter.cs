using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ontriggerEnter : MonoBehaviour
{
    public Transform playerHand;

    //private void Start()
    //{
    //    //  #debug force test 
    //    if(gameObject.CompareTag("ITEM"))
    //    {
    //        GetComponent<Rigidbody>().AddForce(Vector3.forward * 1000f);
    //    }
    //}

    private void OnTriggerEnter(Collider other)
    {
        //  if player collided with
        if(other.name == "Player")
        {
            //  turn bool condition to
            //  spawn to true
            FindObjectOfType<GameManager>().spawnEnemy = true;
            Destroy(gameObject);
        }

        //  if Coin collided with
        if(other.name == "Coin")
        {
            //  shoot cannon ball
            GameObject.Find("cannonBall").GetComponent<Rigidbody>().isKinematic = false;
            GameObject.Find("cannonBall").GetComponent<Rigidbody>().AddForce(transform.forward * 600);
        }

       
        //  if it collided with enemy
        if (other.CompareTag("Enemy"))
        {
            Debug.Log("Woah!");

            //  Set Rotation to look at player
            other.transform.LookAt(GameObject.FindGameObjectWithTag("Player").transform.position);

            //  Set throwing anim to true
            other.GetComponentInParent<Animator>().SetBool("holdingItem", true);

            //  Found False
            //other.GetComponent<enemyAnim>().anim.SetBool("targetFound", false);
        }

        //  if on trigger script on hangable object
        if(gameObject.CompareTag("hangable"))
        {
            Debug.Log("On Wall!");

            //  if player interacts with this
            if(other.gameObject.CompareTag("Player"))
            {
                //  play anim
                //  lock player at top of wall
                GameObject.FindGameObjectWithTag("Player").GetComponentInChildren<Animator>().SetTrigger("isHang");

                // lock y position
                //other.GetComponentInParent<Rigidbody>().constraints = RigidbodyConstraints.FreezePositionY;
                other.GetComponentInParent<Rigidbody>().constraints = RigidbodyConstraints.FreezeRotation | RigidbodyConstraints.FreezePositionY;
            }
        }

        //  if on trigger script on item
        if(gameObject.CompareTag("ITEM"))
        {
            // if in contact with player
            if(other.gameObject.CompareTag("Player"))
            {
                //parent it,
                gameObject.transform.parent = playerHand;

                //  then move to hand position
                gameObject.transform.position = playerHand.position;

                //  set holding item to true
                other.GetComponentInParent<playerManager>().holdingItem = true;

                //  send item reference to player manager
                other.GetComponentInParent<playerManager>().itemReference = gameObject;
            }
        }
    }
}
