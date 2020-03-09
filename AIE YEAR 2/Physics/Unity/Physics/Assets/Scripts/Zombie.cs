using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;


/// <summary>
/// This Zombie Script dictates zombie's life period and functions it takes
/// </summary>


[RequireComponent(typeof(Animator))]

public class Zombie : MonoBehaviour
{ 
    Animator animator = null;

    //gets set by the zombie manager script
    public float speedEnemyTravellingAt;
    public float pushPower = 2.0f;

    //==========Health=================
    private int maxHealth = 100;

    public int currentHealth;

    public event Action<float> OnHealthPctChanged = delegate { };

    public void modifyHealth(int amount)
    {
        currentHealth += amount;
        float currentHealthPct = (float)currentHealth / (float)maxHealth;
        OnHealthPctChanged(currentHealthPct);
    }
    //==========Health=================


    //  Check if zombie dead
    public bool isAlive = true;

    //  Time To Despawn
    float despawnTime = 10;

    // Last RayCast Used
    private RaycastHit raycastUsed;

    //[SerializeField]
    public Transform newPosition;

    GameObject player_obj;

    // Start is called before the first frame update
    void Start()
    {
        animator = GetComponent<Animator>();
        currentHealth = maxHealth;
        
        //set new position
        newPosition = GameObject.FindGameObjectWithTag("Player").transform.GetChild(0).transform;
    }

    // Update is called once per frame
    void Update()
    {

        if (isAlive)
        {
            //Store Player Info in player_obj
            player_obj = GameObject.Find("Player");

            //  Set Where to go
            transform.LookAt(newPosition);
            //  Set Speed 
            animator.SetFloat("Speed", speedEnemyTravellingAt * Time.fixedDeltaTime);

            // Make Decision
            makeDecision();
        }
        else
        {
            //  Decrement time
            despawnTime = despawnTime - Time.fixedDeltaTime;

            //  If Timer less than zero
            if(despawnTime <= 0)
            {
                //  Destroy Zombie
                Destroy(gameObject);
            }
        }


        //transform.position = Vector3.MoveTowards(transform.position, newPosition.position, Time.deltaTime);
        //animator.SetFloat("Speed", vertical * speed * Time.deltaTime);
    }

    private void OnControllerColliderHit(ControllerColliderHit hit)
    {


        //PushBack
        Rigidbody body = hit.collider.attachedRigidbody;
        if (body == null || body.isKinematic)
            return;
        if (hit.moveDirection.y < -0.3f)
            return;
        Vector3 pushDir = new Vector3(hit.moveDirection.x, 0, hit.moveDirection.z);
        body.velocity = pushDir * pushPower;
    }

    // Assign raycast info, and store
    public void AfterEachShot(RaycastHit rayInfo)
    {
        raycastUsed = rayInfo;
    }

    public void makeDecision()
    {
        //Health Check
        if(currentHealth <= 0)
        {
            if (raycastUsed.collider)
            {
                //  Add force of 100
                raycastUsed.collider.gameObject.GetComponentInParent<Rigidbody>().AddForce(-raycastUsed.normal * 100f);
            }

            //  Activate Ragdoll
            GetComponent<Ragdoll>().RagdollOn = true;

            //  Set Zombie to dead in script
            isAlive = false;
        }

        //https://www.mixamo.com/#/?page=1&query=getting+up&type=Motion%2CMotionPack
    }
}
