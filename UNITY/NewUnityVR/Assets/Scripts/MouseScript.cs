using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class MouseScript : MonoBehaviour
{
    //Creation Of variables
    public Transform GunPoint;
    public GameObject particleExplosion;
    private Material Red;
    public float Score = 0;
    public float Counter = 0;
    public float Difficulty = 50;

    //To Create a Link To This GameObject
    private GameObject ValueStorage;

    void Start()
    {
        Score = 0;
        Difficulty = 50;
    }

    private void Update()
    {
        if(Counter == 5)
        {
            //Increment Difficulty
            Difficulty = Difficulty + 50;

            //Reset Counter
            Counter = 0;
        }

        //Shoot RayCast
        if (Input.GetButtonDown("Fire1"))
        {
            ShootGun();
        }
        //Highlight Enemy
        Target();

        //Find And Create Link
        ValueStorage = GameObject.FindGameObjectWithTag("TimerTally");
    }

    void Target()
    {
        RaycastHit targetHit;
        if(Physics.Raycast(GunPoint.position, GunPoint.forward, out targetHit))
        {
            if (targetHit.collider.gameObject.CompareTag("Target"))
            {
                //Create Renderer On Object
                Renderer rend = targetHit.collider.gameObject.GetComponent<Renderer>();

                //Set Colour To Red
                rend.material.shader = Shader.Find("Specular");
                rend.material.color = Color.red;
                rend.material.SetColor("_SpecColor", Color.red);

            }
        }
    }
    

    void ShootGun()
    {
        RaycastHit detectHit;
        if (Physics.Raycast(GunPoint.position, GunPoint.forward, out detectHit))
        {
            //if detected hit equals to Target
            if (detectHit.collider.gameObject.CompareTag("Target"))
            {
                GameObject explosionFX = Instantiate(particleExplosion, detectHit.collider.transform.position, Quaternion.identity) as GameObject;

                //Destroy Target
                Destroy(detectHit.collider.gameObject);
                Destroy(explosionFX, 3);
                
                //Add Score
                Score++;

                //Add To Counter
                Counter++;

                //Add Time To Timer
                ValueStorage.GetComponent<Timer>().Time = ValueStorage.GetComponent<Timer>().Time + 100;
            }
            //Other wise nothing
        }
    }

}
