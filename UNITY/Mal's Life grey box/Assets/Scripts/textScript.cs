using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class textScript : MonoBehaviour
{
    public Animator myAnim;

    private void DestroyItself()
    {
        //itself = GameObject.FindGameObjectWithTag("popUp");
        Destroy(gameObject);
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
