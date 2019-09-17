using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RandomSpawn : MonoBehaviour
{

    //Prefab to spawn
    public GameObject prefab;

    //amountOEnemiesKilled
    public float enemiesKilled = 0;

    //target to spawn at
    public Transform EnemySpawner;

    //timer to wait until spawn
    private float timer = 250;

    //amount of enemies to keep
    private float maxEnemy = 0;

    //Creating Array Of GameObjects
    private GameObject[] ArrayOEnemy;

    //GameObject To Store TimerObj Values
    private GameObject ValueStorage;

    //Bool To Create Enemies
    bool CreateEnemies = true;
    
    // Start is called before the first frame update
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        ValueStorage = GameObject.FindGameObjectWithTag("TimerTally");

        //If Timer World Object Reaches Zero
        if (ValueStorage.GetComponent<Timer>().Time <= 0)
        {
            //Don't Create Enemies
            CreateEnemies = false;
            ArrayOEnemy = GameObject.FindGameObjectsWithTag("Target");
            foreach (GameObject item in ArrayOEnemy)
            {
                Destroy(item);
            }
        }

        //Checks If Enemy needs to be created
        if (CreateEnemies == true)
        {
            //=================================Makes Only 5 Enemies Alive At Once======================================
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
                    timer = 250; //Time To Spawn next
                }
            }

            //Check How Many Enemies Need To Be Spawned
            ArrayOEnemy = GameObject.FindGameObjectsWithTag("Target");
            foreach (GameObject item in ArrayOEnemy)
            {
                //Increment How Many Enemies Alive
                enemiesKilled++;
            }
            maxEnemy = enemiesKilled;
            enemiesKilled = 0;
            //=================================Makes Game Only Have 5 Enemies Alive At Once============================
        }
    }
}
