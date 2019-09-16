using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ExplodeText : MonoBehaviour
{
    public float minForce;
    public float maxForce;
    public float radius;

    private float timer = 850;

    public void Start()
    {
        Explode();
    }

    public void Explode()
    {
        //foreach (Transform t in transform)
        //{
        //    var rb = t.GetComponent<Rigidbody>();

        //    if(rb != null)
        //    {
        //        rb.AddExplosionForce(Random.Range(minForce, maxForce), transform.position, radius);
        //    }
        //}
        var rb = transform.GetComponent<Rigidbody>();
        rb.AddExplosionForce(Random.Range(minForce, maxForce), transform.position, radius);
    }

    public void Update()
    {
        timer = timer - 1;
        if(timer <= 0)
        {
            Destroy(this.gameObject);
        }
    }
}
