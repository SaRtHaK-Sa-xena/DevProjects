using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class MenuFunctions : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        exitGame();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    //Exit Game
    private void exitGame()
    {
        Application.Quit();
    }
}
