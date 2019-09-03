using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemySpawnActor : MonoBehaviour {

    public GameObject enemy_prefab;

    public float spawnTime;
    public float spawnRadius;

    private PlayerActor player;
    private float spawnTimer;

	// Use this for initialization
	void Start () {
        spawnTimer = spawnTime;
        player = GameObject.FindObjectOfType<PlayerActor>();
	}

    // Update is called once per frame
    void Update()
    {
        spawnTimer -= Time.deltaTime;

        if (spawnTimer < 0)
        {
            //reset the timer
            spawnTimer = spawnTime;

            //Pick a random angle in radians and set the spawn point
            float spawnAngle = Random.Range(0, 2 * Mathf.PI);
            Vector3 spawnDirection = new Vector3(Mathf.Sin(spawnAngle), 0, Mathf.Cos(spawnAngle));
            spawnDirection *= spawnRadius;

            Vector3 spawnPoint = player.transform.position + spawnDirection;
            //Spawn the enemy at the desired location
            Instantiate(enemy_prefab, spawnPoint, Quaternion.identity);
        }
    }
}
