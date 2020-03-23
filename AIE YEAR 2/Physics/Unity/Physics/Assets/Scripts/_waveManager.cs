using System.Collections;
using System.Data;
using System.Collections.Generic;
using UnityEngine;

public class _waveManager : MonoBehaviour
{
    //  List of Spawns
    public Transform[] listOfSpawns;

    //  EnemyPrefab
    public GameObject enemyPref;

    // Max Amount Of Zombies
    int maxZombies;

    // Current Zombies in Use
    int zombies;

    // Start is called before the first frame update
    void Start()
    {   
        //  Set default zombies max
        maxZombies = 1;
        spawnWave();
    }

    // Update is called once per frame
    void Update()
    {
        //  Check if current zombies in scene, are alive
        GameObject[] z = GameObject.FindGameObjectsWithTag("KEY_enemy");
        //  all zombies dead
        if(z.Length == 0)
        {
            // Increase difficulty
            incrementWaveDifficulty();

            //Debug.Log("Zombies Max: " + maxZombies);

            //  spawn new wave
            spawnWave();
        }
        else
        {
            // do nothing
        }
        //for(int i = 0; i < z.Length; i++)
        //{
        //    //cast as zombie, to see if it's valid
        //    Zombie currentZombie = z[i].GetComponent<Zombie>();
        //    if(currentZombie && currentZombie.isAlive == false)
        //    {
        //        //If it is true, and dead
        //        //  decrement zombies
        //        zombies -= 1;
        //    }
        //}
    }

    //  ..Spawn Wave function
    void spawnWave()
    {
        //  spawn zombies on list of spawns
        for(int i = 0; i < listOfSpawns.Length; i++)
        {
            
            //  spawn upto max zombies
            for (int count = 0; count < maxZombies; count++)
            {
                //  calculate offset
                float offset = count % maxZombies;

                //  Generate Random
                float random_value = Random.Range(-5, 5);
                offset += random_value;

                //  Create offsetposition from offset
                Vector3 offSetPosition = new Vector3(listOfSpawns[i].position.x + offset, listOfSpawns[i].position.y, listOfSpawns[i].position.z + offset);

                //  spawn zombie on list of spawn, with offset
                Instantiate(enemyPref, offSetPosition, Quaternion.identity);
            }
        }
    }

    //  ..Increment Difficulty
    void incrementWaveDifficulty()
    {
        //  Increment max zombies outputted for each spawn
        maxZombies += 2;
    }
}
