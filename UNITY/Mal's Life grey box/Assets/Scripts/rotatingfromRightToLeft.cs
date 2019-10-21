using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class rotatingfromRightToLeft : MonoBehaviour
{
    public Animator myAnim;

    private void OnTriggerEnter(Collider other)
    {
        myAnim.enabled = true;
        other.transform.SetParent(gameObject.transform);
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
