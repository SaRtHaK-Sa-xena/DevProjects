using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class shock_ball : MonoBehaviour
{
    RaycastHit objectHit;
    float value;

    public ParticleSystem shock_particle;

    // Update is called once per frame
    void Update()
    {
        //value = value +1;
        //Quaternion q = Quaternion.AngleAxis(250 * Time.time, Vector3.up);
        //Vector3 d = transform.position;
        //Debug.DrawRay(transform.position, q * d, Color.green);

        //if (Physics.Raycast(transform.position, q*d, out objectHit, Mathf.Infinity, ~8))
        //{
        //    Debug.Log("Hit!");
        //}

        Collider[] listOfColliders = Physics.OverlapSphere(transform.position, 5f, ~8);
        for (int i = 0; i < listOfColliders.Length; i++)
        {
            Zombie z = listOfColliders[i].GetComponentInParent<Zombie>();
            if (z && z.isAlive)
            {
                //  create particle
                GameObject particle = Instantiate(shock_particle, transform).gameObject;

                //  point towards collider
                particle.transform.LookAt(listOfColliders[i].transform);

                //  if valid enemy, do damage
                z.modifyHealth(-20);
            }
        }
    }
}
