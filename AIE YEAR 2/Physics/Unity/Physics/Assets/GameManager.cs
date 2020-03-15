using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    //  call enemy spawn once
    bool callOnce = true;

    //  call Destroy
    bool callOnceAgain = true;

    //  spawn enemy 
    public bool spawnEnemy = false;

    //  enemy prefab assigned through editor
    public GameObject enemy_pref;

    //  list of enemy spawns
    public Transform[] listOfSpawns;

    public GameObject[] toDeleteList;
   
    // Start is called before the first frame update
    void Start()
    {
        //Hide Cursor
        Cursor.visible = false;

        // Lock Cursor to centre of screen
        Cursor.lockState = CursorLockMode.Locked;
    }

    // Update is called once per frame
    void Update()
    {
        //  unlock cursor
        if (Input.GetKeyDown(KeyCode.Escape))
        {
            Cursor.lockState = CursorLockMode.None;
        }
        if(Input.GetKeyDown(KeyCode.L))
        {
            Cursor.lockState = CursorLockMode.Locked;
        }

        //store all rigidbodies
        GameObject[] listOfEnemies = GameObject.FindGameObjectsWithTag("KEY_enemy");

        //  if all enemies dead
        if (listOfEnemies.Length <= 0)
        {
            if(callOnceAgain)
            {
                //  Destroy objects and allow player to travel up the lift
                for (int i = 0; i < toDeleteList.Length; i++)
                {
                    Destroy(toDeleteList[i].gameObject);
                }
                callOnceAgain = true;
            }
            

            //  if spawn enemy been set to true from trigger event
            if (spawnEnemy)
            {
                //  call spawn once
                if (callOnce)
                {
                    //  turn bool false, to not run again
                    callOnce = false;

                    //  spawn enemies on list of spawns
                    for (int i = 0; i < listOfSpawns.Length; i++)
                    {
                        //  assign enemy on each spawn position
                        Instantiate(enemy_pref, listOfSpawns[i].transform);
                    }
                }
            }
        }
    }
}
