using System.Collections;
using System.Collections.Generic;
using UnityEngine;



/// <summary>
/// Main Highlight Function Stored In Enemy 'Target' Prefab
/// </summary>
public class HighlightBehavior : MonoBehaviour
{
    //Sets Float Timer
    public float timer = 2;

    // Start is called before the first frame update
    void Start()
    {
    }

    // Update is called once per frame

    /// <summary>
    /// Handles The Amount Of Time The Targets Are Glowing
    /// </summary>
    void Update()
    {
        //if colour Red Start Timer
        if (this.GetComponent<Renderer>().material.GetColor("_Color") == Color.red)
        {
            //Start Timer
            timer = timer - 1;
        }


        if (timer <= 0)
        {
            //Set it to the default Color
            Renderer rend = this.GetComponent<Renderer>();

            //Set Colour To White
            rend.material.shader = Shader.Find("Specular");
            rend.material.color = Color.white;
            rend.material.SetColor("_Color", Color.white);
            rend.material.SetColor("_SpecColor", Color.white);

            //Set Timer Back To 2
            timer = 2;
        }
    }
}
