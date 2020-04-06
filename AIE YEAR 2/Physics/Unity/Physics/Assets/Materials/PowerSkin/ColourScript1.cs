using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ColourScript1 : MonoBehaviour
{
    public Material[] listOfMaterials;

    Color modified_mid_inner;
    Color modified_mid_outer;

    bool clampHigh = false;

    int i = 255;

    //  name based
    //  position 0 = original_Inner
    //  position 1 = original_Outer

    //  position 2 = mid_Power_inner 
    //  position 3 = mid_Power_Outer 


    // Start is called before the first frame update
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        if(clampHigh == false)
        {
            Color modified_original_inner = listOfMaterials[0].color;
            Color modified_original_outer = listOfMaterials[1].color;

            modified_original_inner.a = modified_original_inner.a - 0.01f;
            modified_original_outer.a = modified_original_outer.a - 0.01f;

            if (modified_original_inner.a <= 0 && modified_original_outer.a <= 0)
            {
                modified_original_outer.a = 0;
                modified_original_inner.a = 0;

                modified_mid_inner = listOfMaterials[2].color;
                modified_mid_outer = listOfMaterials[3].color;

                modified_original_inner.a = modified_original_inner.a - 0.01f;
                modified_original_outer.a = modified_original_outer.a - 0.01f;
            }


            listOfMaterials[0].color = modified_original_inner;
            listOfMaterials[1].color = modified_original_outer;
        }

        

        

        Debug.Log("Aplha of 0: " + listOfMaterials[0].color.a);
        Debug.Log("Aplha of 1: " + listOfMaterials[1].color.a);

        

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
