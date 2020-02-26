using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(Rigidbody))]

public class CannonBall : MonoBehaviour
{
    public float forceOnFire = 9000;

    bool fire = false;
    bool canFire = true;

    Rigidbody rb = null;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    private void Awake()
    {
        rb = GetComponent<Rigidbody>();
        rb.isKinematic = true;
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.anyKeyDown && canFire)
        {
            rb.isKinematic = false;
            rb.AddForce(transform.forward * forceOnFire);
            canFire = false;
        }
    }
}
