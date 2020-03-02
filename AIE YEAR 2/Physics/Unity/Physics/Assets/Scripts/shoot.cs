using System.Collections;
using System.Collections.Generic;
using UnityEngine;


/// <summary>
/// Player Shoot Script, using RAY CAST
/// </summary>
public class shoot : MonoBehaviour
{
    public Transform gunPoint;

    public GameObject objToLookAt;

    public GameObject enemy;

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        // if LEFT MOUSE pressed
        if(Input.GetKeyDown(KeyCode.Mouse0))
        {
            shootForward();
            Debug.Log("Shot!");
        }

        Debug.DrawRay(gunPoint.position, gunPoint.forward * 10.0f, Color.green);

        //Look At
        //transform.LookAt(objToLookAt.transform);
    }

    public void shootForward()
    {
        //  instantiate raycast
        RaycastHit objectHit;

        //  if raycast successfull
        if (Physics.Raycast(gunPoint.transform.position, gunPoint.transform.forward, out objectHit))
        {
            //  if raycast hits enemy
            if (objectHit.collider.gameObject.CompareTag("Enemy"))
            {
                //  Let Debug Know
                Debug.Log("Enemy Shot!");

                //  Stop Enemy, 
                //objectHit.collider.gameObject.GetComponentInParent<Zombie>().speed = 0;

                //  Add Knockback to Enemy
                objectHit.collider.gameObject.GetComponentInParent<Rigidbody>().AddForce(Vector3.back);

                //  Turn Enemy Ragdoll on
                //objectHit.collider.gameObject.GetComponentInParent<Ragdoll>().RagdollOn = true;

                //Calculate Damage
                //objectHit.collider.gameObject.GetComponentInParent<Zombie>().modifyHealth(-10);
                checkDamage(objectHit);
            }
        }
    }

    public void firedProjectile()
    {
        //  speed = distance/time

        //  therefore 
        //  time = distance/speed

        // known speed of bullet
        float speed = 10.0f;

        //  Calculate distance between enemy and gunPoint
        float distance = Vector3.Distance(enemy.transform.position,gunPoint.transform.position);

        //  time taken to hit that point
        float time = distance / speed;

    }

    public void checkDamage(RaycastHit raycast)
    {
        //  Head
        if (raycast.collider.gameObject.name == "Head")
        {
            //Apply Max Damage
            raycast.collider.gameObject.GetComponentInParent<Zombie>().modifyHealth(-50);
        }
        else
        {
            raycast.collider.gameObject.GetComponentInParent<Zombie>().modifyHealth(-10);
        }
    }
}


