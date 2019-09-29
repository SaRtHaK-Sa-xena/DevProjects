using System.Collections;
using System.Collections.Generic;
using UnityEngine;


/// <summary>
/// Works In The Beginning Of Game in GameEngine To Set The Correct Player Into Position
/// If Player PC then Deletes PLAYER VR, otherwise nothing
/// </summary>
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
            //Destory VR RIG
            //To prevent memory Leak
            Destroy(vrRig);

            //Attach Camera Movable by Mouse Script
            Rigidbody playerRB = Instantiate(Player, position, Rotation).GetComponent<Rigidbody>();

            //Store Reference Of Player's Rigid Body onto Accessabile Body
            accessabileBody = playerRB;
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
