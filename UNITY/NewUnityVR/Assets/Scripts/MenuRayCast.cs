using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


/// <summary>
/// Works With The MainMenu Scene To Correctly Switch The Components So The Canvas Is Interactable By Both VR and PC Players.
/// The Platform is determined and then compoenents are found and placed into Event System, canvas and ray caster compoennets
/// </summary>
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
            //EventData.GetComponent<UnityEngine.EventSystems.OVRInputModule>().m_Cursor = GazePointer.GetComponent<OVRGazePointer>();
            UICanvas.GetComponent<OVRRaycaster>().pointer = Player.GetComponent<PlayerEngine>().cam.gameObject;
        }
    }
}
