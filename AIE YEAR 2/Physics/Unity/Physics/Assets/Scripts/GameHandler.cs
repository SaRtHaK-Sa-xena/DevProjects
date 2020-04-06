using System.Collections;
using System.Collections.Generic;
using UnityEngine;


/// <summary>
/// Handles Game Events
/// </summary>
public class GameHandler : MonoBehaviour
{
    //  manually assign player and enemy prefabs

    [SerializeField]
    private GameObject player_pref;
    private GameObject enemy_pref;
    private Transform playerSpawn;
    private Transform enemySpawn;

    // Start is called before the first frame update
    void Start()
    {
        //spawn player and enemy
        Instantiate(player_pref,playerSpawn);
        player_pref.transform.parent = null;

        Instantiate(enemy_pref, enemySpawn);
        enemy_pref.transform.parent = null;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
