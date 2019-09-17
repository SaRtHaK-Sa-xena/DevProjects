using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Score : MonoBehaviour
{
    public Text scoreText;
    public MouseScript scriptPC;
    public RayCasting scriptVR;
    public GameObject player;
    public GameObject playerVR;

    // Start is called before the first frame update
    void Start()
    {
        //Make Text Equal To Score
    }

    // Update is called once per frame
    void Update()
    {
        if (SystemInfo.deviceType == DeviceType.Desktop)
        {
            //Get Info On Player
            player = GameObject.FindGameObjectWithTag("Player");
            //Get Score From That Script
            scoreText.text = player.GetComponent<MouseScript>().Score.ToString();
        }
        else
        {
            playerVR = GameObject.FindGameObjectWithTag("PlayerVR");
            scoreText.text = playerVR.GetComponent<RayCasting>().Score.ToString();
        }
    }
}
