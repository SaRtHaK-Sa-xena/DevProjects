using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class destroyParticle : MonoBehaviour
{
    private RaycastHit raycast;

    public void PostShot(RaycastHit rayInfo)
    {
        // Store values
        raycast = rayInfo;
    }

    public void OnDestroy()
    {
        //Decerment health
        GameObject.Find("Player").GetComponent<shoot>().checkDamage(raycast);


        //===Not Needed
        //  startPoint
        //Vector3 startPoint = transform.position;

        // EndPoint
        //Vector3 endPoint = transform.GetChild(0).transform.position;
    }
}
