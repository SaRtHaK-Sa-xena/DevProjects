using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class jumpScript : MonoBehaviour
{
    public float jumpVelocity;

    public LayerMask groundLayers;

    public SphereCollider col;

    private void Start()
    {
        col = GetComponent<SphereCollider>();
    }

    // Update is called once per frame
    void Update()
    {
        if (isGrounded() && Input.GetButtonDown("Jump"))
        {
            GetComponent<Rigidbody>().velocity = Vector3.up * jumpVelocity;
            //GameObject.Find("GameEngine").GetComponent<gameEngine>().startStress = true;
            GameObject.Find("GameEngine").GetComponent<gameEngine>().deltaTime += 25;
            GameObject.Find("StressMeter").GetComponent<Slider>().value = GameObject.Find("GameEngine").GetComponent<gameEngine>().deltaTime;
        }
        //else
        //{
        //    GameObject.Find("GameEngine").GetComponent<gameEngine>().startStress = false;
        //}
    }

    private bool isGrounded()
    {
        return Physics.CheckCapsule(col.bounds.center, new Vector3(col.bounds.center.x, col.bounds.min.y, col.bounds.center.z), col.radius * .9f, groundLayers);
    }
}
