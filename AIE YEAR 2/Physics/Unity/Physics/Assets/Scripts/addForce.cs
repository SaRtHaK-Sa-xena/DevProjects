using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class addForce : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //  Start collision
    }

    private void OnTriggerEnter(Collider other)
    {
        // if other is enemy
        if(other.CompareTag("Enemy"))
        {
            RaycastHit info;
            if (Physics.Raycast(other.ClosestPoint(transform.position), Vector3.Normalize(other.ClosestPoint(transform.position) - transform.position), out info))
            {
                info.collider.gameObject.GetComponentInParent<Ragdoll>().RagdollOn = true;
                info.collider.gameObject.GetComponentInParent<Rigidbody>().AddForce(-info.normal * 100f);
            }
        }
        //  Start Ray Cast from position, to 
    }


    // What we need
    //  Add force from the ray created after collision
    //  Ray created from position of sphere to point.
    //  Add force along that, and make enemy ragdoll
}
