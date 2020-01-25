using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class leftColliderScript : MonoBehaviour
{
    public GameObject boxColliderOnRight;


    private void OnTriggerEnter(Collider other)
    {
        boxColliderOnRight.GetComponent<BoxCollider>().enabled = false;
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
