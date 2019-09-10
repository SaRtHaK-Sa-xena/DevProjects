using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RayCasting : MonoBehaviour
{
    public Transform controller;
    public ParticleSystem explosion;
    public GameObject particleExplosion;
    public Vector3 explodeOffset;

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

            //Create Next Instance To Get Shot
            //GameObject cube = GameObject.CreatePrimitive(PrimitiveType.Cube);
            //cube.transform.position = new Vector3(0, 0.5f, 0);
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
                //Set position to hit collider
                //explosion.transform.position = detectHit.collider.gameObject.transform.position;
                //particleExplosion.transform.position = detectHit.collider.gameObject.transform.position;

                //Start Explosion
                //explosion = Instantiate(explosion, particleExplosion.transform);

                GameObject explosionFX = Instantiate(particleExplosion, detectHit.collider.transform.position, Quaternion.identity) as GameObject;
                

                //Destroy Target
                Destroy(detectHit.collider.gameObject);
                //Destroy(explosion);
            }
            //Other wise nothing
        }
    }

    //private IEnumerator StopAnimation()
    //{
    //    yield return new WaitForSeconds(.4f);
    //    //explosion.GetComponent<ParticleSystem>().enableEmission = false;
    //    explosion.Stop();
    //}

}
