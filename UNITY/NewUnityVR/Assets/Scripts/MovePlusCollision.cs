using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MovePlusCollision : MonoBehaviour
{
    private Rigidbody rb;

    public Transform Collider;

    [SerializeField]
    private float speed = 5;

    // Start is called before the first frame update
    void Start()
    {
        rb = GetComponent<Rigidbody>();
        speed = Random.Range(50, 100);
        rb.AddForce(Vector3.left * speed);
    }

    // Update is called once per frame
    void Update()
    {
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
