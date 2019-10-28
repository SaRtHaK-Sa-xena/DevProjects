using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class itemManager : MonoBehaviour
{
    public bool HoldingItem;

    //Item Prefab
    public GameObject item_prefab;
    //item Transform Parent List
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



        ////Check if each Spawn Point's script has HasItem ticked
        //for (int i = 0; i < ItemPosition.Length; i++)
        //{
        //    //if No then include it in list
        //    if (ItemPosition[i].GetComponent<itemOnPosition>().HasItem == false)
        //    {
        //        //Add that
        //        workingItemPosition.Add(ItemPosition[i]);
        //        Debug.Log("Adding To Working Item Position");
        //    }
        //    else
        //    {
        //        // Do Nothing
        //    }
        //}

        //if (workingItemPosition.Count < 10)
        //{

        //    //Generate random number from min. to max which is the item_Placement.Length()
        //    int RandomNumber = Random.Range(0, workingItemPosition.Count);

        //    //Instantiate Item Prefab as child of that Transform Point
        //    Instantiate(item_prefab, workingItemPosition[RandomNumber].transform);

        //    //set That transform's script for HasItem to ticked
        //    workingItemPosition[RandomNumber].GetComponent<itemOnPosition>().HasItem = true;

        //    workingItemPosition.RemoveRange(0, workingItemPosition.Count);
        //}


        //int DebugValue = 0;

        //for (int i = 0; i < ItemPosition.Length; i++)
        //{
        //    if (ItemPosition[i].GetComponent<itemOnPosition>().HasItem == false)
        //    {
        //        //set it to that transform
        //        Instantiate(item_prefab, ItemPosition[i].transform);

        //        //Store Parent
        //        item_prefab.GetComponent<itemOnPosition>().parentOfItem = ItemPosition[i];

        //        //Set the item Parent's script to Has Item
        //        ItemPosition[i].GetComponent<itemOnPosition>().HasItem = true;
        //    }
        //    else
        //    {
        //        //Debug.Log("This one is Already Exists");
        //        //DebugValue = +1;
        //    }
        //}

        //if(DebugValue == 10)
        //{
        //Debug.Log("Now there are all items assigned");
        //DebugValue = 0;
        //}




        //if (itemsInGame.Length == 1)
        //{
        //    //Do Not Do Anything
        //}
        //if (itemsInGame.Length <= 0)
        //{
        //    //If there are no Items in Game


        //    //Iterate through each item parent list
        //    for (int i = 0; i < ItemPosition.Length; i++)
        //    {
        //        //If that transform's script has HasItem set to false
        //        if(ItemPosition[i].GetComponent<itemOnPosition>().HasItem == false)
        //        {
        //            //Add it to the other list
        //            workingnewList[i] = ItemPosition[i];
        //        }
        //        else
        //        {
        //            //Do Nothing
        //        }
        //    }

        //Now the workingnewList should contain all item Positions which don't hold an item

        //Create Item

        //On Random Place
        //}

        //Find all Items 
        ItemPosition = GameObject.FindGameObjectsWithTag("ItemPos");


        int incrementIfItem = 0;
        //Search if there is an item
        for(int i = 0; i < ItemPosition.Length; i++)
        {
            //if there is an item
            if(ItemPosition[i].GetComponent<itemOnPosition>().HasItem == true)
            {
                //increase this
                incrementIfItem = 1;
            }
            else
            {
                //Do Nothing
            }
        }

        //if the incrementIfItem equals to 1
        if(incrementIfItem == 1)
        {
            //Return
            return;
        }
        else
        {
            //This will be triggered if there is no Item on screen

            //generate Random Number
            int randomNumber = Random.Range(0, ItemPosition.Length);

            //use random number as index
            //To set the Position
            Instantiate(item_prefab, ItemPosition[randomNumber].transform);

            //Set that transform's hasItem to true
            ItemPosition[randomNumber].GetComponent<itemOnPosition>().HasItem = true;

            //Set Item script's parent to this transform
            item_prefab.GetComponent<itemFunctionOnPickUp>().parentOfItem = ItemPosition[randomNumber];
        }





    }






}
