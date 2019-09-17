using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RayCasting : MonoBehaviour
{
    public Transform controller;
    public ParticleSystem explosion;
    public GameObject particleExplosion;
    public Vector3 explodeOffset;
    public float Score;

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        if (OVRInput.GetDown(OVRInput.Button.PrimaryIndexTrigger))
        {
            ShootGun();
        }
        Target();
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
            }
        }
    }
}
