using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NewBehaviourScript : MonoBehaviour
{
    public Material[] listOfMaterials;

    //  name based
    //  position 0 = original_Inner
    //  position 1 = original_Outer

    //  position 2 = mid_Power_inner 
    //  position 3 = mid_Power_Outer 
    
        
    // Start is called before the first frame update
    void Start()
    {
        //  create colours from materials
        Color modified_inner = listOfMaterials[2].color;
        Color modified_outer = listOfMaterials[3].color;

        //  modify starting value
        modified_inner.a = 130;
        modified_outer.a = 130;

        //  set modified colours to materials' colour
        listOfMaterials[2].color = modified_inner;
        listOfMaterials[3].color = modified_outer;
    }

    // Update is called once per frame
    void Update()
    {
        for(int i = 255; i > 0; i--)
        {
            Color modified_original_inner = listOfMaterials[0].color;
            Color modified_original_outer = listOfMaterials[1].color;

            modified_original_inner.a = i;
            modified_original_inner.a = i;

            listOfMaterials[0].color = modified_original_inner;
            listOfMaterials[1].color = modified_original_outer;
        }



        //  change first 2 positions alpha value to zero
        
        //  then if both at zero
        //  change last 2 positions alpha value to zero

        //  if it's at zero
        //  change last 2 posiitons alpha value to 130

        //  if last 2 positions alpha value equal to 130
        //  change first 2 positions alpha value to 255

        //  if at 255, decrement to zero, then 130 -> zero, zero -> 130, zero -> 255, 255 -> zero



    }
}
