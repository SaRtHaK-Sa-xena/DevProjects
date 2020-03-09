using System.Collections;
using System.Collections.Generic;
using UnityEngine;


/// <summary>
/// Player Shoot Script, using RAY CAST
/// </summary>
public class shoot : MonoBehaviour
{
    //  gunPoint
    public Transform gunPoint;

    public GameObject particle;
    public Transform particle_Point;

    private Vector3 EnemiesPositionAfterwards_distance;
    private float bullet_velocity = 10.0f;

    //set picking up to true
    private bool pickup = false;

    

    // Update is called once per frame
    void Update()
    {
        // if LEFT MOUSE pressed
        if(Input.GetButtonDown("Fire1"))
        {
           //  Shoot Gun
           shootGun();
        }

        Debug.DrawRay(gunPoint.position, gunPoint.forward * 50.0f, Color.green);
    }

    //  Cast Ray Functions
    public void shootGun()
    {
        //  instantiate raycast
        RaycastHit firedRayCast;
        GameObject ParticleSystem = Instantiate(particle, particle_Point.transform);
        ParticleSystem.transform.SetParent(null);



        //  if raycast hit successful
        if (Physics.Raycast(gunPoint.position, gunPoint.forward, out firedRayCast, Mathf.Infinity, ~8))
        {

            //  Point of contact
            Vector3 contactPoint = firedRayCast.point;

            Debug.Log(Vector3.Distance(contactPoint, gunPoint.position));


            //  Rotate to contact point
            ParticleSystem.transform.LookAt(contactPoint);

            //  Transform
            ParticleSystem.transform.GetChild(0).transform.position = contactPoint;

            //  Send raycast data to particle
            ParticleSystem.GetComponent<destroyParticle>().PostShot(firedRayCast);

            //  if raycast hits enemy
            if (firedRayCast.collider.gameObject.CompareTag("Enemy"))
            {
                //  send raycast data to enemy
                firedRayCast.collider.gameObject.GetComponentInParent<Zombie>().AfterEachShot(firedRayCast);
                firedRayCast.collider.gameObject.GetComponent<Rigidbody>().AddForce(-firedRayCast.normal * 10f);
                //============Spawn Particle==================
            }

            //  if raycast hits interactable button
            if (firedRayCast.collider.gameObject.CompareTag("Button"))
            {
                //  Activate Lift
                firedRayCast.collider.gameObject.GetComponentInParent<liftManager>().liftControls(firedRayCast);
            }
        }
    }

    //  Checks Damage Depending On Position Of Raycasted Impact
    public void checkDamage(RaycastHit raycast)
    {
        //  Head
        if (raycast.collider.gameObject.name == "Head")
        {
            //Apply Max Damage
            raycast.collider.gameObject.GetComponentInParent<Zombie>().modifyHealth(-10);
        }
        else
        {
            raycast.collider.gameObject.GetComponentInParent<Zombie>().modifyHealth(-5);
        }
    }
}


