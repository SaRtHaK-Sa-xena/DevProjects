using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MouseScript : MonoBehaviour
{

    public Transform GunPoint;
    public GameObject particleExplosion;


    void Start()
    {
        
    }

    private void Update()
    {
        if(Input.GetButtonDown("Fire1"))
        {
            ShootGun();
        }
    }

    void ShootGun()
    {
        RaycastHit detectHit;
        if (Physics.Raycast(GunPoint.position, GunPoint.forward, out detectHit))
        {
            //if detected hit equals to Target
            if (detectHit.collider.gameObject.CompareTag("Target"))
            {
                GameObject explosionFX = Instantiate(particleExplosion, detectHit.collider.transform.position, Quaternion.identity) as GameObject;

                //Destroy Target
                Destroy(detectHit.collider.gameObject);
            }
            //Other wise nothing
        }
    }

}
