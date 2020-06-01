using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUI : MonoBehaviour
{
    //  condition to know if menu displaying
    bool showDebugMenu = false;

    //  colour picker GameObject
    public GameObject materialColourChanger;

    //  material picker GameObject
    public GameObject materialChanger;

    //  list of gameObjects
    public GameObject[] boxes;

    //  list of materials
    public Material[] box_mats;

    //  effects
    public GameObject[] effects;

    // Update is called once per frame
    void Update()
    {
        if(gameObject.name == "GUI_Manager")
        {
            //  if 'esc' pressed
            if (Input.GetKeyDown(KeyCode.Escape))
            {
                if (showDebugMenu == false)
                {
                    //  bring up menu
                    //  remove helper text
                    transform.GetChild(0).gameObject.SetActive(false);

                    for (int i = 1; i < 4; i++)
                    {
                        transform.GetChild(i).gameObject.SetActive(true);
                    }

                    //  set condition for debug Menu to true
                    //  'displaying'
                    showDebugMenu = true;
                    return;
                }
                if (showDebugMenu == true)
                {
                    transform.GetChild(0).gameObject.SetActive(true);

                    for (int i = 1; i < 4; i++)
                    {
                        transform.GetChild(i).gameObject.SetActive(false);
                    }

                    //  deactivate colour picker under materials
                    materialColourChanger.SetActive(false);

                    //  deactivate material picker under materials
                    materialChanger.SetActive(false);

                    //  set condition for debug menu to false
                    //  'not displaying'
                    showDebugMenu = false;
                    return;
                }
            }
        }
    }

    //  button press For Material
    public void clickMaterialsButton()
    {
        //  only turn active if previously inactive
        if(!materialColourChanger.activeInHierarchy)
        {
            //  turn color picker on
            materialColourChanger.SetActive(true);

            //  turn material picker on
            materialChanger.SetActive(true);

            //  turn off all headers in Debug Menu
            GameObject guiHeader = GameObject.Find("GUI_Manager");
            guiHeader.transform.GetChild(1).gameObject.SetActive(false);
            guiHeader.transform.GetChild(2).gameObject.SetActive(false);
            guiHeader.transform.GetChild(3).gameObject.SetActive(false);
        }
    }

    // Exit Application
    public void quitApplication()
    {
        Application.Quit();
    }

    // When 'Effects' Pressed
    public void TurnOffEffects()
    {
        for(int i = 0; i < 2; i++)
        {
            //  if effects already on
            if(effects[i].gameObject.activeSelf)
            {
                //  turn off effects
                effects[i].gameObject.SetActive(false);
            }
            else
            {
                //  turn on effects
                effects[i].gameObject.SetActive(true);
            }
        }
    }

    //  changes the material on the given boxes
    //  to the selected index based on user input
    public void DropDown_valueChanged(int index)
    {
        // KEY:
        // 0 = Default Material
        // 1 = Cel Shaded
        // 2 = Rim Light

        if (index == 0)
        {
            // Default
            foreach (GameObject box in boxes)
            {
                box.GetComponent<Renderer>().material = box_mats[0];
            }
        }
        if (index == 1)
        {
            //  Cel Shaded
            foreach (GameObject box in boxes)
            {
                box.GetComponent<Renderer>().material = box_mats[1];
            }
        }
        if (index == 2)
        {
            //  Rim Light
            foreach (GameObject box in boxes)
            {
                box.GetComponent<Renderer>().material = box_mats[2];
            }
        }
    }
}
