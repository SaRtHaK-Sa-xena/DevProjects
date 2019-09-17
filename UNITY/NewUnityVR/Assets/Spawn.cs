using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Spawn : MonoBehaviour
{
    private GameObject player;
    public Transform SPWNPoint;

    public void RespawnPlayer()
    {
        player = GameObject.FindGameObjectWithTag("Player");
        player.transform.position = SPWNPoint.position;
    }
}
