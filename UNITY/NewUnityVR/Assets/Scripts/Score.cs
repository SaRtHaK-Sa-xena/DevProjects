using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


/// <summary>
/// The Score Works With Raycasting From VR and MouseScript From PC To Handle Score When Targets Hit. 
/// As well as displays Score.
/// </summary>
public class Score : MonoBehaviour
{
    //Get Needed Components
    public Text scoreText;
    public Text finalScoreText;
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
        //If Platform PC
        if (SystemInfo.deviceType == DeviceType.Desktop)
        {
            //Get Info On Player PC
            player = GameObject.FindGameObjectWithTag("Player");
            
            //Get Score From That Script And Add To Both Canvas
            scoreText.text = player.GetComponent<MouseScript>().Score.ToString();
            finalScoreText.text = player.GetComponent<MouseScript>().Score.ToString();
        }

        //If Platform VR
        else
        {
            //Get Info On Player VR
            playerVR = GameObject.FindGameObjectWithTag("PlayerVR");

            //Get Score From That Script And Add To Both Canvas
            scoreText.text = playerVR.GetComponent<RayCasting>().Score.ToString();
            finalScoreText.text = playerVR.GetComponent<RayCasting>().Score.ToString();
        }
    }
}
