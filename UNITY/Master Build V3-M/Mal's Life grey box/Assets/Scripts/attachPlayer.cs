using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class attachPlayer : MonoBehaviour
{
    public Animator myAnim;
    public GameObject player;

    private void OnTriggerEnter(Collider other)
    {
        myAnim.enabled = true;
        other.transform.parent = this.transform;
        player.GetComponent<Rigidbody>().constraints = RigidbodyConstraints.FreezePositionY;
        player.GetComponent<Rigidbody>().constraints = RigidbodyConstraints.FreezeRotation;
    }

    // Start is called before the first frame update
    void Start()
    {
        myAnim.enabled = false;
        player = GameObject.FindGameObjectWithTag("Player");
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
