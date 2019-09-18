using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class MenuRayCast : MonoBehaviour
{
    //Data Storage
    private GameObject UICanvas;
    private GameObject Player;
    private GameObject EventData;
    private GameObject GazePointer;

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {

        //if System Desktop
        if (SystemInfo.deviceType == DeviceType.Desktop)
        {
            //Initialize Data Containers
            UICanvas = GameObject.FindGameObjectWithTag("MainMenu");
            Player = GameObject.FindGameObjectWithTag("Player");
            EventData = GameObject.FindGameObjectWithTag("EventSystemTag");
            GazePointer = GameObject.Find("OVRGazePointer");

            //Set World camera To Player's Camera
            UICanvas.GetComponent<Canvas>().worldCamera = Player.GetComponent<PlayerEngine>().cam;

            //Set Ray Transform To Player's Camera And Make It Pointer
            GazePointer.GetComponent<OVRGazePointer>().rayTransform = Player.GetComponent<PlayerEngine>().cam.transform;
            EventData.GetComponent<UnityEngine.EventSystems.OVRInputModule>().rayTransform = Player.GetComponent<PlayerEngine>().cam.transform;
            UICanvas.GetComponent<OVRRaycaster>().pointer = Player.GetComponent<PlayerEngine>().cam.gameObject;
        }
        else
        {
            UICanvas = GameObject.FindGameObjectWithTag("MainMenu");
            Player = GameObject.FindGameObjectWithTag("PlayerVR");

            //Set World camera To Player's Camera
            UICanvas.GetComponent<Canvas>().worldCamera = Player.GetComponent<Camera>();
        }
    }
}
