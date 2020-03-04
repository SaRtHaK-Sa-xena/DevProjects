using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class destroyParticle : MonoBehaviour
{
    public GameObject impactEffect;
    private RaycastHit raycast;

    public float impactForce = 6000f;

    private void Awake()
    {
        impactForce = 600f;
    }

    //  assign raycast and store
    public void PostShot(RaycastHit rayInfo)
    {
        // Store values
        raycast = rayInfo;
    }

    //After particle collides with anything
    public void OnDestroy()
    {
        //Decerment health
        if(raycast.collider)
        {
            if (raycast.collider.gameObject.CompareTag("Enemy"))
            {
                // Hitting Enemy, calculate damage based on 
                GameObject.Find("Player").GetComponent<shoot>().checkDamage(raycast);
            }
            else
            {
                // Hitting anything else, add force
                Rigidbody rb = raycast.collider.GetComponent<Rigidbody>();
                
                //check if Rigidbody exists
                if(rb)
                    rb.AddForce(-raycast.normal * impactForce);
            }

            //  Instantiate particle to spawn after bullet Impact
            GameObject impactGO = Instantiate(impactEffect, raycast.point, Quaternion.LookRotation(-raycast.normal));
            Destroy(impactGO, 2f); //Destroy after a while
        }


        //===Not Needed
        //  startPoint
        //Vector3 startPoint = transform.position;

        // EndPoint
        //Vector3 endPoint = transform.GetChild(0).transform.position;
    }
}
