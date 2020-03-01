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
        transform.LookAt(objToLookAt.transform);
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
                objectHit.collider.gameObject.GetComponentInParent<Zombie>().speed = 0;

                //  Add Knockback to Enemy
                objectHit.collider.gameObject.GetComponentInParent<Rigidbody>().AddForce(Vector3.back);

                //  Turn Enemy Ragdoll on
                objectHit.collider.gameObject.GetComponentInParent<Ragdoll>().RagdollOn = true;
            }
        }
    }
}
