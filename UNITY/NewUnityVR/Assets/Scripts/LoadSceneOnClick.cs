using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

/// <summary>
/// Works With Buttons And Main Menu Functions. 
/// Allows Canvas Buttons To Have Functions
/// </summary>
public class LoadSceneOnClick : MonoBehaviour
{
    //Loads Scene
    public void LoadByIndex(int sceneIndex)
    {
        SceneManager.LoadScene(sceneIndex);
    }

    //Close Game
    public void QuitGame()
    {
        //Close Game
        Application.Quit();
    }
}
