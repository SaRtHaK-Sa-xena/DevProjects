using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ProjectileActor : MonoBehaviour {

    public float speed;
    public Vector3 direction;
    public float lifetime;

	// Use this for initialization
	void Start () {
		
	}

    

    void OnCollisionEnter(Collision hit)
    {
        if (hit.collider.tag == "EnemyTag")
        {
            //since collider store reference to gameObject
            Destroy(hit.collider.gameObject);
        }
        //after hit destroy itself
        Destroy(gameObject);
    }

    // Update is called once per frame
    void Update()
    {
        transform.position += direction * speed * Time.deltaTime;

        lifetime -= Time.deltaTime;
        if(lifetime < 0)
        {
            Destroy(gameObject);
        }
    }
}
