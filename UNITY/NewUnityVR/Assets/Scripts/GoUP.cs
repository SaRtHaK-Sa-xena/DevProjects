using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Used For Future Development To include Balloons, as an obstacle. Allows ballon to fly up in a realistic way.
/// </summary>
public class GoUP : MonoBehaviour {

    public float speed;

	// Use this for initialization
	void Start () {
	}
	
    void FixedUpdate()
    {
        //Creates movement upon fixed
        //Adds correct speed;
        GetComponent<Rigidbody>().AddForce(Vector3.up * speed);
    }

	// Update is called once per frame
	void Update () {

    }
}
