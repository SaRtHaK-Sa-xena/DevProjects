using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class itemFunctionOnPickUp : MonoBehaviour
{
    public GameObject playerObj;
    public GameObject playeritemHolder;
    //public GameObject parentOfItem;

    private void OnTriggerEnter(Collider other)
    {
        playeritemHolder = GameObject.Find("itemHolder");
        playerObj = GameObject.FindGameObjectWithTag("Player");

        //If the player is not currently holding an item
        if (playerObj.GetComponent<itemManager>().HoldingItem == false)
        {
            gameObject.GetComponentInParent<itemOnPosition>().HasItem = false;

            //Remove Collider of item
            gameObject.GetComponent<BoxCollider>().enabled = false;

            //Set Parent of Item to Player
            gameObject.transform.SetParent(playeritemHolder.transform);
            gameObject.transform.SetPositionAndRotation(playeritemHolder.transform.position, Quaternion.identity);
            playerObj.GetComponent<itemManager>().HoldingItem = true;
        }
        
    }

    // Start is called before the first frame update
    void Start()
    {
        playeritemHolder = GameObject.Find("itemHolder");
        playerObj = GameObject.FindGameObjectWithTag("Player");
    }

    // Update is called once per frame
    void Update()
    {
        playeritemHolder = GameObject.Find("itemHolder");
        playerObj = GameObject.FindGameObjectWithTag("Player");
    }
}
