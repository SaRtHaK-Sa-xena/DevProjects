using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class IsActive : MonoBehaviour
{
    public Animator myAnim;
    public GameObject itself;

    //rightToLeft Prefab
    public GameObject rightToLeft_pref;
    
    //leftToRight Prefab
    public GameObject leftToRight_pref;


    private void removeCollidorFromRightToLeft()
    {
        rightToLeft_pref.GetComponent<CapsuleCollider>().enabled = false;
    }

    private void removeCollidorFromLeftToRight()
    {
        leftToRight_pref.GetComponent<CapsuleCollider>().enabled = false;
    }

    private void Reposition()
    {
        if (leftToRight_pref.GetComponent<CapsuleCollider>().enabled == false)
        {
            leftToRight_pref.GetComponent<CapsuleCollider>().enabled = true;
            leftToRight_pref.GetComponent<Animator>().Rebind();
            leftToRight_pref.GetComponent<Animator>().enabled = false;

        }
        if (rightToLeft_pref.GetComponent<CapsuleCollider>().enabled == false)
        {
            rightToLeft_pref.GetComponent<CapsuleCollider>().enabled = true;
            rightToLeft_pref.GetComponent<Animator>().Rebind();
            rightToLeft_pref.GetComponent<Animator>().enabled = false;
        }
    }


    private void detachAllChildren()
    {
        transform.DetachChildren();
    }

    // Start is called before the first frame update
    void Start()
    {
        myAnim.enabled = false;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
