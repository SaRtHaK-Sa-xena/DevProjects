using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlatformThroughLedge : MonoBehaviour
{

    public GameObject topWallGamobj;

    private void OnTriggerEnter(Collider other)
    {
        topWallGamobj.GetComponent<CapsuleCollider>().enabled = false;
    }
    private void OnTriggerExit(Collider other)
    {
        topWallGamobj.GetComponent<CapsuleCollider>().enabled = true;
    }
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }


    //Place collidor on top of player.
    //make that colldior get data from collision and delete their collidor.
}
