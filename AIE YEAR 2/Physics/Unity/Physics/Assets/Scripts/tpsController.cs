using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class tpsController : MonoBehaviour
{
    //determine the direction the character faces
    public Transform cam;

    float speed = 5f;    //How fast the player can move
    float turnSpeed = 50;    //How fast the player can rotate

    Rigidbody rigidBody;

    float vertical;
    float horizontal;

    public GameObject objToLookAt;

    //private float currentX = 0.0f; // Holds value of X mouse movement
    //private float currentY = 0.0f; // Holds value of Y mouse movement


    void Start()
    {
        //Initialize appropriate components
        rigidBody = GetComponent<Rigidbody>();
        //cam = Camera.main.transform;
    }

    //private void Update()
    //{
    //    // vertical = Input.GetAxis("Vertical");
    //    //horizontal = Input.GetAxis("Horizontal");

    //    if (Input.GetAxis("Mouse X") != null || Input.GetAxis("Mouse Y") != null)
    //    {
    //        currentX += Input.GetAxis("Mouse X");
    //        currentY += Input.GetAxis("Mouse Y");
    //    }
    //}


    private void Update()
    {
        transform.LookAt(objToLookAt.transform);
    }

    void FixedUpdate()
    {
        //right is shorthand for (1,0,0) or the x value            forward is short for (0,0,1) or the z value 
        Vector3 dir = (cam.right* Input.GetAxis("Horizontal")) + (cam.forward* Input.GetAxis("Vertical"));

        dir.y = 0;//Keeps character upright against slight fluctuations

        if (Input.GetAxis("Horizontal") != 0 || Input.GetAxis("Vertical") != 0)
        {
            //rotate from this /........to this............../.........at this speed 
            //rigidBody.rotation = Quaternion.Slerp(transform.rotation, Quaternion.LookRotation(dir), turnSpeed * Time.deltaTime);
            //rigidBody.velocity = transform.forward * speed;
        }
        //rigidBody.rotation = Quaternion.Slerp(transform.rotation, Quaternion.LookRotation(dir), turnSpeed * Time.deltaTime);
    }
}
