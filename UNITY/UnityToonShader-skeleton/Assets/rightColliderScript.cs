using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class rightColliderScript : MonoBehaviour
{

    public GameObject boxColliderOnLeft;


    private void OnTriggerEnter(Collider other)
    {
        boxColliderOnLeft.GetComponent<BoxCollider>().enabled = false;
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
