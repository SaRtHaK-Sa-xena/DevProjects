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

    public GameObject rotated180;
    public GameObject rotated90;
    public GameObject rotatedNegative90;
    public GameObject rotated0;

    public GameObject playerObj;



    private void setRotationNegative90()
    {
        playerObj.transform.SetPositionAndRotation(playerObj.transform.position, rotatedNegative90.transform.rotation);
    }

    private void setRotation180()
    {
        playerObj.transform.SetPositionAndRotation(playerObj.transform.position, rotated180.transform.rotation);
    }

    private void setRotationTo90()
    {
        playerObj.transform.SetPositionAndRotation(playerObj.transform.position, rotated90.transform.rotation);
    }

    private void setRotationTo0()
    {
        playerObj.transform.SetPositionAndRotation(playerObj.transform.position, rotated0.transform.rotation);
    }


    private void removeCollidorFromRightToLeft()
    {
        rightToLeft_pref.GetComponent<CapsuleCollider>().enabled = false;
    }

    private void removeCollidorFromLeftToRight()
    {
        leftToRight_pref.GetComponent<CapsuleCollider>().enabled = false;
    }

    private void RepositionLeftToRight()
    {
        leftToRight_pref.GetComponent<CapsuleCollider>().enabled = true;
        leftToRight_pref.GetComponent<Animator>().Rebind();
        leftToRight_pref.GetComponent<Animator>().enabled = false;


    }

    private void RepositionRightToLeft()
    {
        rightToLeft_pref.GetComponent<CapsuleCollider>().enabled = true;
        rightToLeft_pref.GetComponent<Animator>().Rebind();
        rightToLeft_pref.GetComponent<Animator>().enabled = false;
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
        playerObj = GameObject.FindGameObjectWithTag("Player");
    }
}
