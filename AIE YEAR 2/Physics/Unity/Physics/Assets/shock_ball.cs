using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class shock_ball : MonoBehaviour
{
    RaycastHit objectHit;
    float value;

    // Update is called once per frame
    void Update()
    {
        value = value +1;
        Quaternion q = Quaternion.AngleAxis(100 * Time.time, Vector3.up);
        Vector3 d = transform.forward * 20;
        Debug.DrawRay(transform.position, q * d, Color.green);

        if (Physics.Raycast(transform.position, q*d, out objectHit, Mathf.Infinity, ~8))
        {
            Debug.Log("Hit!");
        }
    }
}
