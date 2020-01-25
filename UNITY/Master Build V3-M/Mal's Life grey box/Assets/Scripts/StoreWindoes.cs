using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class StoreWindoes : MonoBehaviour
{

    public GameObject storedWindowsScore;

    public int score;

    public int StoredValue;

    // Start is called before the first frame update
    void Start()
    {
        DontDestroyOnLoad(gameObject);
    }

    // Update is called once per frame
    void Update()
    {
        //If Not In GameOver
        //In Game
        if (SceneManager.GetSceneByBuildIndex(1).isLoaded)
        {
            storedWindowsScore = GameObject.Find("GameEngine");

            //store score
            score = storedWindowsScore.GetComponent<WinOrLoseCheck>().goalsHit;
        }
        
        //If GameOver Screen Place Score On Board
        if(SceneManager.GetSceneByBuildIndex(3).isLoaded)
        {
            GameObject.Find("windowTextBox").GetComponent<Text>().text = score.ToString();
        }

        //Win Screen
        if(SceneManager.GetSceneByBuildIndex(2).isLoaded)
        {
            GameObject.Find("score").GetComponent<Text>().text = score.ToString();
        }

        //StoredValue = score;
    }
}
