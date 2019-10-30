using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class wayPoint : MonoBehaviour
{

    public GameObject[] goals;

    public GameObject waypointTo = null;

    public GameObject player;

    public GameObject FrontFace_leftIndicator;
    public GameObject FrontFace_rightIndicator;


    public GameObject leftFace_leftIndicator;
    public GameObject leftFace_rightIndicator;

    public GameObject backFace_leftIndicator;
    public GameObject backFace_rightIndicator;

    public GameObject rightFace_leftIndicator;
    public GameObject rightFace_rightIndicator;

    // Start is called before the first frame update
    void Start()
    {
        //Renderers
        FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //Animations
        FrontFace_leftIndicator.GetComponent<Animator>().enabled = true;
        FrontFace_rightIndicator.GetComponent<Animator>().enabled = true;

        leftFace_leftIndicator.GetComponent<Animator>().enabled = true;
        leftFace_rightIndicator.GetComponent<Animator>().enabled = true;

        backFace_leftIndicator.GetComponent<Animator>().enabled = true;
        backFace_rightIndicator.GetComponent<Animator>().enabled = true;

        rightFace_leftIndicator.GetComponent<Animator>().enabled = true;
        rightFace_rightIndicator.GetComponent<Animator>().enabled = true;
    }

    // Update is called once per frame
    void Update()
    {
        gameObject.transform.LookAt(GameObject.Find("TrackThisOne").transform);
        player = GameObject.Find("Player");

        //If Not Null

        //The RandomWindow script will make goal equal to waypointTo
        //So it can be checked in the waypoint
        if(waypointTo != null)
        {
            //Find it's position

            //If it is on the front Face
            if(waypointTo.transform.position.z == 2.680348)
            {
                //If Player On front Face
                if(player.transform.rotation.x == 0)
                {
                    //Then Do Nothing
                }

                //If Player On right Face
                if(player.transform.rotation.x == -90)
                {
                    //Do Something With it
                    rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true ;
                }

                //If Player On left Face
                if (player.transform.rotation.x == 90)
                {
                    leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;
                }

                //If player on back Face
                if (player.transform.rotation.x == -180)
                {
                    backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;
                    backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;
                }
            }

            //If it is on the left Face
            if (waypointTo.transform.position.x == -2.48)
            {
                //If Player On front Face
                if(player.transform.rotation.x == 0)
                {
                    FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;
                }

                //If Player On right Face
                if (player.transform.rotation.x == -90)
                {
                    rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;
                    rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;
                }

                //If Player On left Face
                if (player.transform.rotation.x == 90)
                {
                    //then do nothing
                }

                //If player on back Face
                if(player.transform.rotation.x == -180)
                {
                    backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;
                }
            }

            //If it is on the back Face
            if (waypointTo.transform.position.z == 8.2)
            {
                //If Player On front Face
                if(player.transform.rotation.x == 0)
                {
                    FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;
                    FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;
                }

                //If Player On right Face
                if(player.transform.rotation.x == -90)
                {
                    rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;
                }

                //If Player On left Face
                if(player.transform.rotation.x == 90)
                {
                    leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;
                }

                //If player on back Face
                if(player.transform.rotation.x == -180)
                {
                    //Then do nothing
                }
            }


            //If it is on the right Face
            if (waypointTo.transform.position.x == 2.99)
            {
                //If Player On front Face
                if(player.transform.rotation.x == 0)
                {
                    FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;
                }

                //If Player On right Face
                if(player.transform.rotation.x == -90)
                {
                    //Then Do Nothing
                }

                //If Player On left Face
                if(player.transform.rotation.x == 90)
                {
                    leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;
                    leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;
                }

                //If player on back Face
                if(player.transform.rotation.x == -180)
                {
                    backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;
                }
            }
            //If it's between x,y,z then 

                //If player X is 0, 90, 180, -90, then
                //Display The arrow


            //Get Rid Of Data In WaypointTo
            waypointTo = null;
        }
    }
}
