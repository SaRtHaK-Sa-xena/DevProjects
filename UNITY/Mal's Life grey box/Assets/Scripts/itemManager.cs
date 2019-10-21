using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class itemManager : MonoBehaviour
{
    public bool HoldingItem;

    public GameObject[] ItemPosition;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //find all instance of Item
        //if there are less than equal 10 then create one more
        

        //Check if each Spawn Point's script has HasItem ticked
        //if Yes Do not include in list

        //If Not Add to list


        //Generate random number from min. to max which is the item_Placement.Length()

        //Instantiate Item Prefab as child of that Transform Point
        //set That transform's script for HasItem to ticked


        //if there are 10 do nothing
    }
}
