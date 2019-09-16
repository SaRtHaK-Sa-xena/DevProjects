using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpawnBlocks : MonoBehaviour
{
    public GameObject Prefab;

    private float timer = 50;

    // Start is called before the first frame update
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        timer = timer - 1;

        if (timer <= 0)
        {
            Vector3 position = new Vector3(Random.Range(-10.0f, 10.0f), Random.Range(-10.0f, 10.0f), Random.Range(-10.0f, 10.0f));
            Instantiate(Prefab, position, Quaternion.identity);
            timer = 50;
        }
    }
}
