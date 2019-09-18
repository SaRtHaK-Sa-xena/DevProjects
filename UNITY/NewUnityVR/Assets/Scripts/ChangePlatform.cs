using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ChangePlatform : MonoBehaviour
{
    //Player to Spawn
    public GameObject Player;

    private GameObject RayCasterScript;

    private GameObject Storage;

    //Position To spawn player
    public Vector3 position;

    private Quaternion Rotation;

    //VR Rig To Destroy
    public GameObject vrRig;

    //timer to remove constraints
    private float timer = 5;

    private Rigidbody accessabileBody;

    // Start is called before the first frame update
    void Start()
    {
        if (SystemInfo.deviceType == DeviceType.Desktop)
        {
            //Fix Controller point to Middle
            //Allow Camera Rig to be movable by Mouse Input

            Destroy(vrRig);

            //Attach Camera Movable by Mouse Script
            Rigidbody playerRB = Instantiate(Player, position, Rotation).GetComponent<Rigidbody>();

            accessabileBody = playerRB;

            //Find RayCaster And Turn Off Ray Caster
            RayCasterScript = GameObject.Find("RayCaster");
            RayCasterScript.gameObject.SetActive(false);



        }
        else
        {
            
        }
    }

    // Update is called once per frame
    void Update()
    {
        //If Player in Hieararchy
        if (Player.activeInHierarchy)
        {
            //start timer only if Player Spawned
            timer = timer - 1;
        }

        //Fixed Bug where player flys off screen
        //By Setting Kinematic To True Then False
        if(timer <=  0)
        {
            accessabileBody.isKinematic = false;   
        }
    }
}
