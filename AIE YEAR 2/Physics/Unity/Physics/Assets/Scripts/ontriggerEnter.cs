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
    }
}
