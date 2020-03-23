using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class gunshot_script : MonoBehaviour
{
    public GameObject impactEffect;
    private RaycastHit raycast;

    public float impactForce = 6000f;

    //  set impact force
    private void Awake()
    {
        impactForce = 600f;
    }

    //  get raycast shot
    public void setShot(RaycastHit a_raycast)
    {
        raycast = a_raycast;
    }

    private void OnTriggerEnter(Collider other)
    {
        Debug.Log("Inside Trigger");
    }

    //  when destroyed
    private void OnDestroy()
    {
        //  If Particle in collision with enemy collider
        if (raycast.collider)
        {
            if(raycast.collider.gameObject.CompareTag("Enemy"))
            {
                GameObject.FindGameObjectWithTag("Player").GetComponent<shoot>().checkDamage(raycast);
            }
            else
            {
                // Hitting anything else, add force
                Rigidbody rb = raycast.collider.GetComponent<Rigidbody>();

                // check if Rigidbody exists
                if (rb)
                    rb.AddForce(-raycast.normal * impactForce);
            }
        }
        
        //Initiate particle impact particle effect
        GameObject impactGO = Instantiate(impactEffect, raycast.point, Quaternion.LookRotation(-raycast.normal));
        Destroy(impactGO, 2f); //Destroy after a while
    }
}
