using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class itemManager : MonoBehaviour
{
    public bool HoldingItem;

    //Item Prefab
    public GameObject item_prefab;

    public GameObject[] ItemPosition;
    public List<GameObject> workingItemPosition;

    public bool startCheck;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //find all instance of Item
        //if there are less than equal 10 then create one more
        ItemPosition = GameObject.FindGameObjectsWithTag("ItemPos");


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

        for (int i = 0; i < ItemPosition.Length; i++)
        {
            if (ItemPosition[i].GetComponent<itemOnPosition>().HasItem == false)
            {
                //set it to that transform
                Instantiate(item_prefab, ItemPosition[i].transform);
                ItemPosition[i].GetComponent<itemOnPosition>().HasItem = true;
            }
            else
            {
                //Debug.Log("This one is Already Exists");
                //DebugValue = +1;
            }
        }

        //if(DebugValue == 10)
        //{
            //Debug.Log("Now there are all items assigned");
            //DebugValue = 0;
        //}
        





    }






}
