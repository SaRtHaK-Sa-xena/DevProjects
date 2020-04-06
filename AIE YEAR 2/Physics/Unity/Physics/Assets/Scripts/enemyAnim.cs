using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class enemyAnim : MonoBehaviour
{
    //  Get Anim
    public Animator anim;
    
    //  Speed to control anim
    private float m_speed = 15f;

    //  Enemy walking towards
    public Transform targetItem;

    //  condition found target
    private bool foundItem = false;

    //  time to end anim
    private float time = 50f;

    //  store all item positions
    private GameObject[] listOfItems;

    //  Track distance between
    private float distance;

    //  NULL FLOAT
    float nullValue;

    // Start is called before the first frame update
    void Start()
    {
        //  Set Anim
        anim = GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        //  Find out if there is target,
        //  To make condition true
        if (targetItem == null) { 
            targetItem = returnClosestItem();
            foundItem = false;
        }
        else {
            foundItem = true;
        }


        //  If Found Item To Walk Towards
        if(foundItem)
        {
            //  Rotate Model To Target
            transform.LookAt(targetItem);

            //  Move model to location
            transform.position = Vector3.MoveTowards(transform.position, targetItem.position, Time.deltaTime);

            //  Set speed, to move it
            anim.SetFloat("speed", m_speed * Time.fixedDeltaTime);

            //  Set walking anim on
            anim.SetBool("targetFound", true);
        }
        else
        {
            //  Set speed, to move it
            anim.SetFloat("speed", 0);

            //  Set to Idle
            anim.SetBool("targetFound", false);
        }

        if(anim.GetBool("holdingItem") == true)
        {
            //  decrement time
            time -= 1;
        }

        if(time <= 0)
        {
            anim.SetBool("holdingItem", false);
            time = 50f;
        }

    }

    private void OnTriggerEnter(Collider other)
    {
        ////  If item is 'picked up'
        //if (other.gameObject.name == "item")
        //{
        //    anim.SetBool("holdingItem", true);
        //}

        ////  If item is 'picked up'
        //if(other.CompareTag("ITEM"))
        //{
        //    anim.SetBool("holdingItem", true);
        //}
    }

    public void uncheckCondition()
    {
        anim.SetBool("holdingItem", false);
    }

    private Transform returnClosestItem()
    {
        //  Search Through all items
        listOfItems = GameObject.FindGameObjectsWithTag("ITEM");

        //  Make it the first Item
        Transform closestItem = listOfItems[0].transform;

        //  Go Through list with distance check
        for(int i = 0;i < listOfItems.Length; i++)
        {
            //  get Temp
            float distanceTemp = Vector3.Distance(listOfItems[i].transform.position, transform.position);

            if(distanceTemp < Vector3.Distance(closestItem.position, transform.position))
            {
                closestItem = listOfItems[i].transform;
            }

            ////  if the distance is equal to nullValue
            //if(distance == nullValue)
            //{
            //    distance = distanceTemp;
            //}

            ////  if found distance less than distance
            //if (distanceTemp < distance)
            //{
            //    distance = distanceTemp;
            //    closestItem = listOfItems[i].transform;
            //}
        }

        //  Return closest item
        return closestItem;
    }
}
