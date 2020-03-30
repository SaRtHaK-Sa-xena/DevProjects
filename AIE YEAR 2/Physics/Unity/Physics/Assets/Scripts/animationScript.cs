using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class animationScript : MonoBehaviour
{
    public Animator anim;
    float InputX;
    float InputZ;

    //  distance to ground
    float distanceToGround = 12.5f;

    private void Start()
    {
        anim = GetComponent<Animator>();
    }

    private void Update()
    {
        InputZ = Input.GetAxis("Vertical"); //UP and DOWN arrow key
        InputX = Input.GetAxis("Horizontal");
        anim.SetFloat("InputZ", InputZ);
        anim.SetFloat("InputX", InputX);

        //  if player presses space bar
        if(Input.GetButtonDown("Jump"))
        {
            anim.SetTrigger("isJump");
        }

        //  if player is above ground by a certain distance, play freefall anim
        RaycastHit rayCast;
        if (Physics.Raycast(transform.position, Vector3.down, out rayCast, 5f))
        {
            Debug.Log("Collision Detected");

            //if collision
            //do nothing
            anim.SetBool("isFalling", false);
        }
        else
        {
            Debug.Log("[No] Collision Detected");
            //  if there is no collision
            //Play anim
            anim.SetBool("isFalling", true);
        }

        //Debug RayCast
        Debug.DrawRay(transform.position, Vector3.down, Color.green);
    }
}
