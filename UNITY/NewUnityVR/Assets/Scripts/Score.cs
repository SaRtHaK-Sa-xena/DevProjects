using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Score : MonoBehaviour
{
    public Text scoreText;
    public MouseScript scriptToUse;
    public GameObject player;

    // Start is called before the first frame update
    void Start()
    {
        //Make Text Equal To Score
    }

    // Update is called once per frame
    void Update()
    {
        player = GameObject.FindGameObjectWithTag("Player");
        //player.GetComponent<MouseScript>().Score.ToString();
        scoreText.text = player.GetComponent<MouseScript>().Score.ToString();
        //scoreText.text = scriptToUse.Score.ToString();
        //Debug.Log(scriptToUse.Score);
        //scoreText.text = 
    }
}
