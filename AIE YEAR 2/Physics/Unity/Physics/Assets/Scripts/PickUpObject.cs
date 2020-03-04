using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PickUpObject : MonoBehaviour
{
    private Vector3 mOffset;
    private float mZCoord;

    //private void OnButtonDown()
    //{
    //    mZCoord = Camera.main.WorldToScreenPoint(gameObject.transform.position).z;

    //    //Store offset = gameobject world pos - mouse world pos
    //    mOffset = gameObject.transform.position - GetMouseWorldPos();
    //}
    private void Update()
    {
        if(Input.GetKey(KeyCode.F))
        {
            mZCoord = Camera.main.WorldToScreenPoint(gameObject.transform.position).z;

            //Store offset = gameobject world pos - mouse world pos
            mOffset = gameObject.transform.position - GetMouseWorldPos();
            transform.position = GetMouseWorldPos() + mOffset;
        }
    }

    //  Helper function
    private Vector3 GetMouseWorldPos()
    {
        //  pixel coordinates (x,y)
        Vector3 mousePOint = Input.mousePosition;

        //  z coordinate of game object on screen
        mousePOint.z = mZCoord;

        return Camera.main.ScreenToWorldPoint(mousePOint);

    }

    //private void OnMouseDrag()
    //{
    //    if (Input.GetKey(KeyCode.F))
    //    {
            
    //    }
    //}
}
