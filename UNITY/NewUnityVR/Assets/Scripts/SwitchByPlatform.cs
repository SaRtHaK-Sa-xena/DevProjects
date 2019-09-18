using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SwitchByPlatform : MonoBehaviour
{
    private GameObject UICanvas;

    private GameObject Player;

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
            UICanvas = GameObject.FindGameObjectWithTag("ScoreBoard");
            Player = GameObject.FindGameObjectWithTag("Player");
            EventData = GameObject.FindGameObjectWithTag("EventSystemTag");

            UICanvas.GetComponent<Canvas>().worldCamera = Player.GetComponent<PlayerEngine>().cam;
            EventData.GetComponent<UnityEngine.EventSystems.OVRInputModule>().rayTransform = Player.GetComponent<PlayerEngine>().cam.transform;
            UICanvas.GetComponent<OVRRaycaster>().pointer = Player.GetComponent<PlayerEngine>().cam.gameObject;
        }
        else
        {
            UICanvas = GameObject.FindGameObjectWithTag("ScoreBoard");
            Player = GameObject.FindGameObjectWithTag("PlayerVR");

            UICanvas.GetComponent<Canvas>().worldCamera = Player.GetComponent<Camera>();
        }
    }
}
