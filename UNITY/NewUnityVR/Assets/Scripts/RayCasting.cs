using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RayCasting : MonoBehaviour
{
    public Transform controller;
    public GameObject particleExplosion;
    public Vector3 explodeOffset;
    public float Score;
    private GameObject ValueStorage;
    public float Difficulty = 50;
    public float Counter = 0;

    // Start is called before the first frame update
    void Start()
    {
        Difficulty = 50;
    }

    // Update is called once per frame
    void Update()
    {
        //Start Counter For Difficulty
        if(Counter == 5)
        {
            //Raise Difficulty
            Difficulty = Difficulty + 50;
            
            //reset Counter
            Counter = 10;
        }
        if (OVRInput.GetDown(OVRInput.Button.PrimaryIndexTrigger))
        {
            ShootGun();
        }
        Target();
        ValueStorage = GameObject.FindGameObjectWithTag("TimerTally");
    }

    private void Target()
    {
        RaycastHit targetHit;
        if (Physics.Raycast(controller.position, controller.forward, out targetHit))
        {
            if (targetHit.collider.gameObject.CompareTag("Target"))
            {
                //targetHit.collider.gameObject.GetComponent<Material>().SetColor("Green", Color.green);
                Renderer rend = targetHit.collider.gameObject.GetComponent<Renderer>();

                //rend.material.shader = Shader.Find("_Color");

                rend.material.shader = Shader.Find("Specular");
                rend.material.color = Color.red;
                rend.material.SetColor("_SpecColor", Color.red);
            }
        }
    }

    private void ShootGun()
    {
        RaycastHit detectHit;

        if (Physics.Raycast(controller.position, controller.forward, out detectHit))
        {
            //if detected hit equals to Target
            if (detectHit.collider.gameObject.CompareTag("Target"))
            {
                GameObject explosionFX = Instantiate(particleExplosion, detectHit.collider.transform.position, Quaternion.identity) as GameObject;

                //Destroy Target
                Destroy(detectHit.collider.gameObject);
                //Destory Animation After 3 seconds
                Destroy(explosionFX, 3);
                Score++;
                Counter++;
                ValueStorage.GetComponent<Timer>().Time = ValueStorage.GetComponent<Timer>().Time + 100;
            }
        }
    }
}
