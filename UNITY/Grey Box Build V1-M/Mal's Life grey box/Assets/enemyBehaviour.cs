using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class enemyBehaviour : MonoBehaviour
{
    public Transform positionA;
    public Transform positionB;

    public GameObject enemyObj;

    public float step;
    public float speed;


    public bool travelToFirst;
    public bool travelToSecond;
    public bool travelToThird;
    public bool travelToFourth;

    public bool firstSpeed = true;

    public bool followPlayer;

    public Transform playerLocation;
    
    // Start is called before the first frame update
    void Start()
    {
        speed = 5f;
        travelToFirst = true;
    }

    // Update is called once per frame
    void Update()
    {

        step = speed * Time.deltaTime;

        if (enemyObj.transform.position == positionA.position)
        {
            travelToFirst = true;
            travelToSecond = false;
            travelToThird = false;
            travelToFourth = false;
        }
        if(enemyObj.transform.position == positionB.position)
        {
            travelToSecond = true;
            travelToFirst = false;
            travelToThird = false;
            travelToFourth = false;
        }


        if(travelToFirst)
        {
            enemyObj.transform.position = Vector3.MoveTowards(enemyObj.transform.position, positionB.position, step);
        }
        if(travelToSecond)
        {
            enemyObj.transform.position = Vector3.MoveTowards(enemyObj.transform.position, positionA.position, step);
        }

        if(followPlayer)
        {
            enemyObj.transform.position = Vector3.MoveTowards(enemyObj.transform.position, playerLocation.position, step);
        }
    }

    //=====================Attack Behaviour====================
    private void OnTriggerStay(Collider other)
    {
        if(other.CompareTag("Player"))
        {
            //If Tag Equals Player
            playerLocation.position = other.transform.position;
        }
    }
}
