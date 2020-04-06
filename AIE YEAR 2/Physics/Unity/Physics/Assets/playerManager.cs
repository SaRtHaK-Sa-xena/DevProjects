using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class playerManager : MonoBehaviour
{
    //  check if player holding item
    public bool holdingItem;

    //  get item reference
    public GameObject itemReference;

    //  camera reference for raycasting
    public GameObject camera;


    public bool clampHigh = false;

    //  throwing power
    [SerializeField]
    [Range(1, 10)]
    private float throwPower;

    //  used to make force more realistic
    float scalar = 120f;

    //  amount in pct (%)
    float pctAmount = 0;

    private void Start()
    {
        throwPower = 1f;
        pctAmount = throwPower;
    }

    // Update is called once per frame
    void Update()
    {
        Debug.Log("ThrowPower: " + throwPower);

        //  Check if player holding item
        //if Holding item
        if(holdingItem)
        {
            // if holding right click (RMB), can shoot
            if(Input.GetButton("Fire2"))
            {
                //  update power bar
                updatePowerBar();

                // by pressing left click (LMB)
                if (Input.GetButtonDown("Fire1"))
                {
                    //  shoot function---------------------------

                    //  remove parent
                    itemReference.transform.parent = null;

                    //  make kinematic equal false
                    itemReference.GetComponent<Rigidbody>().isKinematic = false;

                    RaycastHit raycast;
                    if(Physics.Raycast(camera.transform.position, camera.transform.forward, out raycast))
                    {
                        //if hit

                        //find direction to fire
                        Vector3 dirToFire = raycast.point - itemReference.transform.position;

                        //  add force in that direction
                        itemReference.GetComponent<Rigidbody>().AddForce(dirToFire * (throwPower * scalar));
                    }
                    else
                    {
                        // other wise add default force
                        //  add force
                        itemReference.GetComponent<Rigidbody>().AddForce(Vector3.forward * (throwPower * scalar));
                    }

                    //  turn on collidor (turn trigger false)
                    itemReference.GetComponent<SphereCollider>().isTrigger = false;

                    //  destroy item
                    Destroy(itemReference, 5);
                }
            }
            else
            {
                //  disable power bar
                GameObject.Find("powerBar").GetComponent<Image>().enabled = false;

                // reset throw power while not charging attack
                throwPower = 0f;
            }
        }

        //  add force, from camera.forward
    }

    void updatePowerBar()
    {
        //  enable power bar
        GameObject.Find("powerBar").GetComponent<Image>().enabled = true;

        //  if clamp high 
        //  increment throwingPower
        if (clampHigh)
        {
            throwPower += 0.1f;
        }
        //  else
        //  decrement throwingPower
        else
        {
            throwPower -= 0.1f;
        }

        // condition to set clamp

        //  if throwPower greater than max,
        //  set clampHigh to false
        if (throwPower >= 10)
        {
            clampHigh = false;
        }

        //else set to true
        else if (throwPower <= 0)
        {
            clampHigh = true;
        }

        //  make pctAmount to diplay equal to throw power
        pctAmount = throwPower;

        // change to percentage
        pctAmount /= 10;

        //  add to fill Amount
        GameObject.Find("powerBar").GetComponent<Image>().fillAmount = pctAmount;
    }
}
