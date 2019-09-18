using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AddCamera : MonoBehaviour
{
    private GameObject Camera;
    private GameObject PlayerVR;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (SystemInfo.deviceType == DeviceType.Desktop)
        {

        }
        else
        {
            Camera = GameObject.FindGameObjectWithTag("ScoreBoard");
            PlayerVR = GameObject.FindGameObjectWithTag("PlayerVR");
            Camera.GetComponent<Canvas>().worldCamera = PlayerVR.GetComponent<OVRCameraRig>().centerEyeAnchor.GetComponent<Camera>();
        }
    }
}
