using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MovePlusCollision : MonoBehaviour
{
    private Rigidbody rb;
    private GameObject Player;

    public Transform Collider;

    [SerializeField]
    private float speed = 45;

    // Start is called before the first frame update
    void Start()
    {
        rb = GetComponent<Rigidbody>();
        rb.AddForce(Vector3.left * speed);
    }

    // Update is called once per frame
    void Update()
    {
        Player = GameObject.FindGameObjectWithTag("Player");

        if (Player.GetComponent<MouseScript>().Score > 10 && Player.GetComponent<MouseScript>().Score < 20)
        {
            speed = speed * 2;
        }

        transform.LookAt(Collider.position);
        //Add Force Forward Where it's facing
    }

    private void FixedUpdate()
    {
    }

    //Teleport Back When Collided
    private void OnTriggerEnter(Collider other)
    {
        transform.position = new Vector3(transform.position.x + 8, transform.position.y, transform.position.z);
    }
}
