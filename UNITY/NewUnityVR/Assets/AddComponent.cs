using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AddComponent : MonoBehaviour
{
    private Camera playerCam;

    private GameObject playerData;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (SystemInfo.deviceType == DeviceType.Desktop)
        {
            //Get Data
            playerData = GameObject.FindGameObjectWithTag("Player");

            playerData.GetComponent<Camera>();
        }
        else
        {
            playerData = GameObject.FindGameObjectWithTag("PlayerVR");
        }
    }

    
}
