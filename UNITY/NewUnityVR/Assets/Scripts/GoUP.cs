using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GoUP : MonoBehaviour {

    public float speed;
    //public Rigidbody rb;

	// Use this for initialization
	void Start () {
        //rb = GetComponent<Rigidbody>();	
	}
	
    void FixedUpdate()
    {
        GetComponent<Rigidbody>().AddForce(Vector3.up * speed);
    }

	// Update is called once per frame
	void Update () {

    }
}
