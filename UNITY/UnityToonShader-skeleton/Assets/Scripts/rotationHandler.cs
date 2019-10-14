using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class rotationHandler : MonoBehaviour
{
    public Animator myAnim;

    





    // Start is called before the first frame update
    void Start()
    {
        DestroyImmediate(ledgeLeft);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}


//have one collider collide with player
//Upon Collision have one function disable other gameobject referenced.