using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MovePlusCollision : MonoBehaviour
{
    private Rigidbody rb;

    public Transform Collider;
    
    //Data container
    private GameObject PlayerData;

    [SerializeField]
    private float speed;

    // Start is called before the first frame update
    void Start()
    {

        rb = GetComponent<Rigidbody>();
        if (SystemInfo.deviceType == DeviceType.Desktop)
        {
            //Get Data From PC Player's Shooting Script
            PlayerData = GameObject.FindGameObjectWithTag("Player");
            speed = PlayerData.GetComponent<MouseScript>().Difficulty;
        }
        else
        {
            //Get Data From VR Player's Shooting Script
            PlayerData = GameObject.FindGameObjectWithTag("PlayerVR");
            speed = PlayerData.GetComponent<RayCasting>().Difficulty;
        }

        //Add Force
        rb.AddForce(Vector3.left * speed);
    }

    // Update is called once per frame
    void Update()
    {
        transform.LookAt(Collider.position);
        //Add Force Forward Where it's facing
    }

    private void FixedUpdate()
    {
    }

    //Teleport Back When Collided
    private void OnTriggerEnter(Collider other)
    {
        transform.position = new Vector3(transform.position.x + 8, transform.position.y, transform.position.z);
    }
}
