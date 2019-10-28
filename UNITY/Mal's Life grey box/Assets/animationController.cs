using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class animationController : MonoBehaviour
{

    //public GameObject rightFoot;
    //public GameObject leftFoot;

    //RightFootMoving Right and Left
    public GameObject rightFoot_movingRight;
    public GameObject rightFoot_movingLeft;

    //LeftFootMoving Right and Left
    public GameObject leftFoot_movingRight;
    public GameObject leftFoot_movingLeft;

    // Start is called before the first frame update
    void Start()
    {
        rightFoot_movingRight = GameObject.Find("RightFeet [GoingRight]");
        rightFoot_movingLeft = GameObject.Find("RightFeet [GoingLeft]");


        leftFoot_movingRight = GameObject.Find("LeftFeet [GoingRight]");
        leftFoot_movingLeft = GameObject.Find("LeftFeet [GoingLeft]");
    }

    // Update is called once per frame
    void Update()
    {
        rightFoot_movingRight = GameObject.Find("RightFeet [GoingRight]");
        rightFoot_movingLeft = GameObject.Find("RightFeet [GoingLeft]");


        leftFoot_movingRight = GameObject.Find("LeftFeet [GoingRight]");
        leftFoot_movingLeft = GameObject.FindGameObjectWithTag("thisTag");

        if (Input.GetKeyDown(KeyCode.A))
        {
            //Disable rightFootMovingRight 
            //Disable leftFootMovingRight
            rightFoot_movingLeft.GetComponent<MeshRenderer>().enabled = true;
            leftFoot_movingLeft.GetComponent<MeshRenderer>().enabled = true;


        }
        if (Input.GetKeyDown(KeyCode.D))
        {
            rightFoot_movingLeft.GetComponent<MeshRenderer>().enabled = false;
            leftFoot_movingLeft.GetComponent<MeshRenderer>().enabled = false;
        }

        else
        {
            rightFoot_movingRight.GetComponent<MeshRenderer>().enabled = false;
            leftFoot_movingRight.GetComponent<MeshRenderer>().enabled = false;

            rightFoot_movingLeft.GetComponent<MeshRenderer>().enabled = false;
            leftFoot_movingLeft.GetComponent<MeshRenderer>().enabled = false;
        }
        
    }
}
