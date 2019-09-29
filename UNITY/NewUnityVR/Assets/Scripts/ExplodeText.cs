using System.Collections;
using System.Collections.Generic;
using UnityEngine;


/// <summary>
/// Was To Be Used In Future Development Of Other Games. Was Used To Learn Forces To be Placed On RigidBodies. 
/// This Script Allows Identified Object To Explode into bits, Upon Cast
/// </summary>
public class ExplodeText : MonoBehaviour
{
    //Get Needed Components
    public float minForce;
    public float maxForce;
    public float radius;

    private float timer = 850;

    public void Start()
    {
        //Was Used In Start As A Test
        Explode();
    }

    //Casts Explosive Foce, between min and max, upon position and blast radius
    public void Explode()
    {
        var rb = transform.GetComponent<Rigidbody>();
        rb.AddExplosionForce(Random.Range(minForce, maxForce), transform.position, radius);
    }

    //Casted After to Prevent Memory Leak
    public void Update()
    {
        timer = timer - 1;
        if(timer <= 0)
        {
            Destroy(this.gameObject);
        }
    }
}
