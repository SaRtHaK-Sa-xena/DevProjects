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

    public Transform DebugHelper;

    public GameObject particle;
    public Transform particle_Point;

    private Vector3 EnemiesPositionAfterwards_distance;
    private float bullet_velocity = 10.0f;


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
            shootGun();
        }

        Debug.DrawRay(gunPoint.position, gunPoint.forward * 10.0f, Color.green);
        DebugHelper.position = EnemiesPositionAfterwards_distance;
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

    public void shootGun()
    {
        //  instantiate raycast
        RaycastHit firedRayCast;

        //  if raycast successfull
        if (Physics.Raycast(gunPoint.transform.position, gunPoint.transform.forward, out firedRayCast))
        {
            //  if raycast hits enemy
            if (firedRayCast.collider.gameObject.CompareTag("Enemy"))
            {
                // contact point
                Vector3 contactPoint = firedRayCast.collider.gameObject.transform.position;

                //============Spawn Particle==================
                GameObject ParticleSystem = Instantiate(particle, particle_Point.transform);

                ParticleSystem.transform.SetParent(null);

                //  Rotate to contact point
                ParticleSystem.transform.LookAt(contactPoint);

                //  Transform
                ParticleSystem.transform.GetChild(0).transform.position = contactPoint;

                ParticleSystem.GetComponent<destroyParticle>().PostShot(firedRayCast);

                firedRayCast.collider.gameObject.GetComponentInParent<Zombie>().AfterEachShot(firedRayCast);
                //============Spawn Particle==================
            }
        }
    }


    public void firedProjectile()
    {
        //  speed = distance/time

        //  therefore 
        //  time = distance/speed

        // known speed of bullet
        //float speed = 10.0f;

        //  Calculate distance between enemy and gunPoint
        //float distance = Vector3.Distance(enemy.transform.position,gunPoint.transform.position);

        //  time taken to hit that point
        //float time = distance / speed;


        //  Fire RayCast
        RaycastHit firedRayCast;

        //  If Fired
        if(Physics.Raycast(gunPoint.transform.position, gunPoint.transform.forward, out firedRayCast))
        {
            //  if hitpoint is ENEMY
            if (firedRayCast.collider.gameObject.CompareTag("Enemy"))
            {
                //  Contact Point
                Vector3 contactPoint = firedRayCast.collider.gameObject.transform.position;

                // speed enemyTravelling at
                float enemyVelocity = firedRayCast.collider.gameObject.GetComponentInParent<Zombie>().speedEnemyTravellingAt * Time.deltaTime;

                //  The direction Enemy is currently travelling in
                Vector3 directionEnemyTravellingIn = firedRayCast.collider.gameObject.GetComponentInParent<Zombie>().newPosition.position - contactPoint;
                //  Find only direction
                directionEnemyTravellingIn = Vector3.Normalize(directionEnemyTravellingIn);


                //  Distance of Enemy from current position to end point
                float distanceToEndPoint = Vector3.Distance(firedRayCast.collider.gameObject.GetComponentInParent<Zombie>().newPosition.position, contactPoint);


                //Speed = distance/time <:> 

                //future position
                EnemiesPositionAfterwards_distance = contactPoint * enemyVelocity;

                //Future Distance
                float futureDistance = Vector3.Distance(contactPoint, EnemiesPositionAfterwards_distance);

                //Calculation
                float timeTakenForAction_Enemy = futureDistance / enemyVelocity;



                //move over that much
                //contactPoint *= enemyVelocity;

                //=====================================================================
                //Bullet Speed 
                // 10.0f is known speed of bullet
                //  Calculate distance between enemy and gunPoint
                float distanceForBullet = Vector3.Distance(contactPoint, gunPoint.transform.position);

                //  time taken to hit that point
                float timeTakenForAction_Bullet = distanceForBullet / bullet_velocity;

                Debug.Log("Time Taken For [Bullet]: " + timeTakenForAction_Bullet);
                Debug.Log("Time Taken For [Enemy]: " + timeTakenForAction_Enemy);

                if (timeTakenForAction_Bullet < timeTakenForAction_Enemy)
                {
                    Debug.Log("Hit Will Be Registered");
                    DebugHelper.position = EnemiesPositionAfterwards_distance;
                    ParticleSystem particle = new ParticleSystem();
                    
                }
                else
                {
                    Debug.Log("Hit Will Not Be Registered");
                }

                //============Spawn Particle==================
                GameObject ParticleSystem = Instantiate(particle, particle_Point.transform);

                ParticleSystem.transform.SetParent(null);

                //  Rotate to contact point
                ParticleSystem.transform.LookAt(contactPoint);

                //  Transform
                ParticleSystem.transform.GetChild(0).transform.position = contactPoint;

            }
        }

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


