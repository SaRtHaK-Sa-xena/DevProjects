using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class wreckingBall : MonoBehaviour
{
    private Rigidbody rb;
    public GameObject ball;

    // Start is called before the first frame update
    void Start()
    {
        rb = GetComponent<Rigidbody>();
    }

    // Update is called once per frame
    void Update()
    {
        //Debug.Log(rb.velocity.magnitude);
        if (rb.velocity.magnitude < 0)
        {
            //   Remove Wrecking Ball
            Destroy(gameObject);
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Enemy"))
        {
            if (rb.velocity.magnitude > 0)
            {
                other.GetComponentInParent<Zombie>().modifyHealth(-1000);
                other.GetComponentInParent<Zombie>().isAlive = false;
                other.GetComponentInParent<Ragdoll>().RagdollOn = true;
            }
            else
            {

            }
        }
        else
        {

        }
    }
}
