using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class detach : MonoBehaviour
{
    public Animator myAnim;

    public GameObject leftToRight;
    public GameObject rightToLeft;

    private void DestroyLeftToRight()
    {
        leftToRight.GetComponent<CapsuleCollider>().enabled = false;
    }


    private void DestroyRightToLeft()
    {
        rightToLeft.GetComponent<CapsuleCollider>().enabled = false;
    }


    private void Reposition()
    {
        if(leftToRight.GetComponent<CapsuleCollider>().enabled == false)
        {
            leftToRight.GetComponent<CapsuleCollider>().enabled = true;
            leftToRight.GetComponent<Animator>().Rebind();
            leftToRight.GetComponent<Animator>().enabled = false;

        }
        if (rightToLeft.GetComponent<CapsuleCollider>().enabled == false)
        {
            rightToLeft.GetComponent<CapsuleCollider>().enabled = true;
            rightToLeft.GetComponent<Animator>().Rebind();
            rightToLeft.GetComponent<Animator>().enabled = false;
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


//public Animator myAnim;


//public Transform SpawnPointLeft;
//public Transform SpawnPointRight;

//public GameObject ledgeLeft;
//public GameObject leftPrefab;

//public GameObject ledgeRight;
//public GameObject rightPrefab;


//private void destroyLeft()
//{
//    Destroy(ledgeLeft);

//}

//private void detachAllChildren()
//{
//    transform.DetachChildren();
//}


//private void Reposition()
//{
//    //transform.position.Set(-0.4, 3.829999, -9.99);
//    //transform.SetPositionAndRotation(Vector3(-0.4, 3.82999, -9.99), Quaternion.identity);

//    if (ledgeLeft == null)
//    {
//        Instantiate(leftPrefab, SpawnPointLeft.transform);
//    }
//    if (ledgeRight == null)
//    {
//        Instantiate(rightPrefab, SpawnPointRight.transform);
//    }

//}