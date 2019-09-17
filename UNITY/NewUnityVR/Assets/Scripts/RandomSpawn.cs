using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RandomSpawn : MonoBehaviour
{
    //Prefab to spawn
    public GameObject prefab;

    public float enemiesKilled = 0;

    //target to spawn at
    public Transform EnemySpawner;

    //timer to wait until spawn
    private float timer = 250;

    //amount of enemies to keep
    private float maxEnemy = 0;

    private GameObject[] ArrayOEnemy;

    // Start is called before the first frame update
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        ////spawn more Enemies
        //if (maxEnemy < 5)
        //{
        //    //decrement timer if max alive not at max 
        //    timer = timer - 1;

        //    //if timer reaches 0
        //    if (timer <= 0)
        //    {
        //        //Spawn at position of Transform EnemySpawner's x and z
        //        //Then create on various y axis
        //        Vector3 position = new Vector3(EnemySpawner.position.x, Random.Range(-1.0f, 3.0f), EnemySpawner.position.z);
        //        Instantiate(prefab, position, Quaternion.identity);
        //        timer = 5;
        //        maxEnemy++;
        //        enemiesKilled--;
        //    }
        //}


        ////Find all Objects With Name Target
        //ArrayOEnemy = GameObject.FindGameObjectsWithTag("Target");
        //foreach (GameObject item in ArrayOEnemy)
        //{
        //    //Increment How Many Enemies Alive
        //    enemiesKilled++;
        //}

        ////Check How Many Enemies Alive
        //if (enemiesKilled < 5)
        //{
        //    //Find How many Less Than 10
        //    float numberToDecrement = maxEnemy - enemiesKilled;

        //    //Decrement From Max That much
        //    for (int i = 0; i < numberToDecrement; i++)
        //    {
        //        maxEnemy--;
        //    }
        //}



        if (maxEnemy < 5)
        {
            //decrement timer if max alive not at max 
            timer = timer - 1;

            //if timer reaches 0
            if (timer <= 0)
            {
                //Spawn at position of Transform EnemySpawner's x and z
                //Then create on various y axis
                Vector3 position = new Vector3(EnemySpawner.position.x, Random.Range(-1.0f, 3.0f), EnemySpawner.position.z);
                Instantiate(prefab, position, Quaternion.identity);
                timer = 250;
            }
        }


        ArrayOEnemy = GameObject.FindGameObjectsWithTag("Target");
        foreach (GameObject item in ArrayOEnemy)
        {
            //Increment How Many Enemies Alive
            enemiesKilled++;
        }
        maxEnemy = enemiesKilled;
        enemiesKilled = 0;
    }
}
