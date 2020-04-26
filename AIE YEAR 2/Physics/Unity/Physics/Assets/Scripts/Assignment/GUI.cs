using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GUI : MonoBehaviour
{
    bool showDebugMenu = false;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
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

                //  set condition for debug menu to false
                //  'not displaying'
                showDebugMenu = false;
                return;
            }
        }
        
    }
}
