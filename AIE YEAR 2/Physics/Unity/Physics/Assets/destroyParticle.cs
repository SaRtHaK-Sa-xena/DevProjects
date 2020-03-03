using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class destroyParticle : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void PostShot(RaycastHit rayInfo)
    {
        //Decerment health
        GameObject.Find("Player").GetComponent<shoot>().checkDamage(rayInfo);

        //Add force of 100
        rayInfo.collider.gameObject.GetComponentInParent<Rigidbody>().AddForce(-rayInfo.normal * 100f);
    }

    private void OnDestroy()
    {
        //  startPoint
        Vector3 startPoint = transform.position;

        // EndPoint
        Vector3 endPoint = transform.GetChild(0).transform.position;
    }
}
