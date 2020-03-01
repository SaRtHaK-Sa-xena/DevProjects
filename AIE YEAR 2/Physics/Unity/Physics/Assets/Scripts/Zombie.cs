using System.Collections;
using System.Collections.Generic;
using UnityEngine;


/// <summary>
/// This Zombie Script dictates zombie's life period and functions it takes
/// </summary>


[RequireComponent(typeof(Animator))]

public class Zombie : MonoBehaviour
{ 
    Animator animator = null;

    //gets set by the zombie manager script
    public float speed;
    public float pushPower = 2.0f;

    //[SerializeField]
    public Transform newPosition;

    GameObject player_obj;

    // Start is called before the first frame update
    void Start()
    {
        animator = GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        //Store Player Info in player_obj
        player_obj = GameObject.Find("Player");

        //Set Where to go
        transform.LookAt(newPosition);
        //transform.position = Vector3.MoveTowards(transform.position, newPosition.position, Time.deltaTime);
        animator.SetFloat("Speed", speed * Time.deltaTime);
        //animator.SetFloat("Speed", vertical * speed * Time.deltaTime);
    }

    private void OnControllerColliderHit(ControllerColliderHit hit)
    {
        Rigidbody body = hit.collider.attachedRigidbody;
        if (body == null || body.isKinematic)
            return;
        if (hit.moveDirection.y < -0.3f)
            return;
        Vector3 pushDir = new Vector3(hit.moveDirection.x, 0, hit.moveDirection.z);
        body.velocity = pushDir * pushPower;
    }

    public void makeDecision()
    {
        //If Zombie in range
        if(Vector3.Distance(transform.position, player_obj.transform.position) < 10.50f)
        {
            //start to move towards player otherwise

        }

        //Finds Player then sets new position to player position


        //getting up Animation
        //https://www.mixamo.com/#/?page=1&query=getting+up&type=Motion%2CMotionPack
    }
}
