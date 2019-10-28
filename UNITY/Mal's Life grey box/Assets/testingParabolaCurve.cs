using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class testingParabolaCurve : MonoBehaviour
{
    //Curve
    public float objPos_x;
    public float objPos_z;

    public float speed;

    public GameObject playerObj;

    // Start is called before the first frame update
    void Start()
    {
        speed = 15f;

        objPos_z = 35;
    }

    // Update is called once per frame
    void Update()
    {
        float step = speed * Time.deltaTime;

        playerObj = GameObject.Find("Snake");

        //playerObj.transform.position = new Vector3(playerObj.transform.position.x + 1, playerObj.transform.position.y, playerObj.transform.position.z);


        //New Vector3
        Vector3 newPosition = new Vector3((Mathf.Pow(-playerObj.transform.position.x,2)), playerObj.transform.position.y, playerObj.transform.position.z + 2);

        
        playerObj.transform.position = Vector3.MoveTowards(playerObj.transform.position, newPosition, step);

        //objPos_x = GameObject.Find("Snake").transform.position.x;
        //objPos_z = GameObject.Find("Snake").transform.position.z;

        //objPos_x = objPos_x + 1;
        //objPos_z = objPos_z + 2;


    }
}
