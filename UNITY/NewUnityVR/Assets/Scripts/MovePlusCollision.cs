using System.Collections;
using System.Collections.Generic;
using UnityEngine;



/// <summary>
/// Handles The Movement And Collision Of Targets When Spawned By 'Spawn' Script in GameEngine
/// </summary>
public class MovePlusCollision : MonoBehaviour
{
    //Create RigidBody
    private Rigidbody rb;

    //Create Transform
    public Transform Collider;
    
    //Data container
    private GameObject PlayerData;


    //Done So Can Be Seen Through Debug
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

        //Add Force To The Left
        rb.AddForce(Vector3.left * speed);
    }

    // Update is called once per frame
    void Update()
    {
        transform.LookAt(Collider.position);
    }

    //Teleport Back When Collided
    private void OnTriggerEnter(Collider other)
    {
        transform.position = new Vector3(transform.position.x + 8, transform.position.y, transform.position.z);
    }
}
