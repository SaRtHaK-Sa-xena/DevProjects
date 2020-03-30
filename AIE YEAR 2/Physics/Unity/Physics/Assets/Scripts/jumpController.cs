using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class jumpController : MonoBehaviour
{
    [SerializeField]
    [Range(1,10)]
    private float jumpVelocity;


    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetButtonDown("Jump"))
        {
            GetComponent<Rigidbody>().velocity = Vector3.up * jumpVelocity;
        }
    }
}
