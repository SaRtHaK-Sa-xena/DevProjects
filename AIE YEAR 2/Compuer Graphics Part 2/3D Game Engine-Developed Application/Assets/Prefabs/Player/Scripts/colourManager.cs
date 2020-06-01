using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// Manages Colour for each Material Changed
/// </summary>
public class colourManager : MonoBehaviour
{
    // RGB values
    public float r_value, g_value, b_value;

    //  slider to take values from
    public Slider r_slider, g_slider, b_slider;

    //  objects assigned new material
    public GameObject[] objs;

    // Start is called before the first frame update
    void Start()
    {
        //  set default slider values to 'white' values
        r_slider.value = r_slider.maxValue;
        g_slider.value = g_slider.maxValue;
        b_slider.value = b_slider.maxValue;

    }

    // Update is called once per frame
    void Update()
    {
        //  get rgb values
        r_value = r_slider.value;
        g_value = g_slider.value;
        b_value = b_slider.value;

        //  set colour
        setColour(r_value, g_value, b_value);
    }

    //  assign colour to image
    void setColour(float r, float g, float b)
    {
        //  create new color
        Color newColor = new Color(r, g, b);

        // change colour of image to new colour
        transform.GetChild(0).GetComponent<Image>().color = newColor;
        
        //  fill objs list
        objs = GameObject.Find("materialOptions").GetComponent<GUI>().boxes;

        //  set each renderer shader rim colour
        //  to newly created colour
        foreach(GameObject box in objs)
        {
            box.GetComponent<Renderer>().material.SetColor("_RimColor", newColor);
        }
    }
}
