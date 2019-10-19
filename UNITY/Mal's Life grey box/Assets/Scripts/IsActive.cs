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

    private void OnTriggerEnter(Collider other)
    {
        myAnim.enabled = true;
        other.transform.SetParent(gameObject.transform);
    }

    private void DestroyItself()
    {
        //itself = GameObject.FindGameObjectWithTag("popUp");
        Destroy(gameObject);
    }

    private void removeCollidorFromRightToLeft()
    {
        rightToLeft_pref.GetComponent<CapsuleCollider>().enabled = false;
    }

    private void removeCollidorFromLeftToRight()
    {
        leftToRight_pref.GetComponent<CapsuleCollider>().enabled = false;
    }

    private void RepositionFromLeftToRight()
    {
        leftToRight_pref.GetComponent<CapsuleCollider>().enabled = true;
    }

    private void RepositionFromRightToLeft()
    {
        rightToLeft_pref.GetComponent<CapsuleCollider>().enabled = true;
    }

    private void Rebind()
    {
        myAnim.Rebind();
    }

    private void detach()
    {
        gameObject.transform.DetachChildren();
    }

    // Start is called before the first frame update
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
