using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(Rigidbody))]


public class PhysicsObject : MonoBehaviour
{
    public Material awakeMaterial = null;
    public Material sleepingMaterial = null;

    private Rigidbody _rigidbody = null;

    bool wasSleeping = false;

    // Start is called before the first frame update
    void Start()
    {
        _rigidbody = GetComponent<Rigidbody>();
    }

    // Update is called once per frame
    void Update()
    {

    }


    // To calculate Physics
    private void FixedUpdate()
    {
        if (_rigidbody.IsSleeping() && !wasSleeping && sleepingMaterial != null)
        {
            wasSleeping = true;

            //change mat to sleep mat
            GetComponent<MeshRenderer>().material = sleepingMaterial;
        }

        if (!_rigidbody.IsSleeping() && wasSleeping && awakeMaterial != null)
        {
            wasSleeping = false;

            //change mat to awake mat
            GetComponent<MeshRenderer>().material = awakeMaterial;
        }
    }
}
