using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class testingBoxCollision : MonoBehaviour
{
    public GameObject spawn_pref;

    public GameObject player_pref;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //spawn_pref.transform.position = player_pref.GetComponent<BoxCollider>().ClosestPoint();
    }
}
