using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DestroyAnim : MonoBehaviour
{
    public float minRange;
    public float maxRange;
    public GameObject explodeAnim;

    // Start is called before the first frame update
    void Start()
    {
        Explode();
    }

    // Update is called once per frame
    private void Explode()
    {


        foreach(Transform t in transform)
        {
            //rb = GetComponent<Rigidbody>();

            
        }
    }
}
