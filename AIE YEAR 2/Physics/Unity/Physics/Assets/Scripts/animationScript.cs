using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class animationScript : MonoBehaviour
{
    public Animator anim;
    float InputX;
    float InputZ;

    private void Start()
    {
        anim = GetComponent<Animator>();
    }

    private void Update()
    {
        InputZ = Input.GetAxis("Vertical"); //UP and DOWN arrow key
        anim.SetFloat("InputZ", InputZ);
    }
}
