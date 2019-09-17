using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class MouseScript : MonoBehaviour
{

    public Transform GunPoint;
    public GameObject particleExplosion;
    private Material Red;
    private float timer = 5;
    public float Score = 0;
    void Start()
    {
        Score = 0;
    }

    private void Update()
    {
        if (Input.GetButtonDown("Fire1"))
        {
            ShootGun();
        }
        Target();
    }

    void Target()
    {
        RaycastHit targetHit;
        if(Physics.Raycast(GunPoint.position, GunPoint.forward, out targetHit))
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
                Score++;
            }
            //Other wise nothing
        }
    }

}
