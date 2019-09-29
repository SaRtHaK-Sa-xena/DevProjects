using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


/// <summary>
/// Works By Canvas, In Scene To Add Correct Components Of Correct Platform. For PC Takes Player Component, 
/// For VR Does nothing since it is already set to VR from beginning
/// </summary>
public class SwitchByPlatform : MonoBehaviour
{
    //Display Board
    private GameObject UICanvas;

    //Final Board
    private GameObject FinalScoreBoard;

    //Player Data   
    private GameObject Player;

    //Event System
    private GameObject EventData;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //if//System Desktop)
        if (SystemInfo.deviceType == DeviceType.Desktop)
        {
            //Create Data Storage
            UICanvas = GameObject.FindGameObjectWithTag("DisplayBoard");
            FinalScoreBoard = GameObject.FindGameObjectWithTag("TestingTag");

            Player = GameObject.FindGameObjectWithTag("Player");
            EventData = GameObject.FindGameObjectWithTag("EventSystemTag");

            //Cange Component camera Of Canvas to player Camera
            UICanvas.GetComponent<Canvas>().worldCamera = Player.GetComponent<PlayerEngine>().cam;
            FinalScoreBoard.GetComponent<Canvas>().worldCamera = Player.GetComponent<PlayerEngine>().cam;

            //EventData InputModule RayTransform assigned to Player camera
            EventData.GetComponent<UnityEngine.EventSystems.OVRInputModule>().rayTransform = Player.GetComponent<PlayerEngine>().cam.transform;

            //Set Pointer Of Display Board's Pointer ot Player Cam
            UICanvas.GetComponent<OVRRaycaster>().pointer = Player.GetComponent<PlayerEngine>().cam.gameObject;
        }
        else
        {
            //Stores reference For Debug Puposes

            //Store Both Canvas Data
            UICanvas = GameObject.FindGameObjectWithTag("ScoreBoard");
            FinalScoreBoard = GameObject.FindGameObjectWithTag("TestingTag");

            //Store player Data                         Of VR
            Player = GameObject.FindGameObjectWithTag("PlayerVR");

        }
    }
}
