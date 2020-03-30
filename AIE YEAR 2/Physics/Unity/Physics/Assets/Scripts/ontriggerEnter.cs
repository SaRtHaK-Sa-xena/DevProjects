using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ontriggerEnter : MonoBehaviour
{
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
        if (other.name == "Enemy")
        {
            Debug.Log("Woah!");

            //  Set Rotation to look at player
            other.transform.LookAt(GameObject.FindGameObjectWithTag("Player").transform.position);

            //  Set throwing anim to true
            other.GetComponent<enemyAnim>().anim.SetBool("holdingItem", true);

            //  Found False
            //other.GetComponent<enemyAnim>().anim.SetBool("targetFound", false);
        }
    }
}
