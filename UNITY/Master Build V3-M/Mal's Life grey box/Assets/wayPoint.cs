using System.Collections;
using System.Collections.Generic;
using UnityEngine;


/// <summary>
/// Gives a waypoint to player after finding the goal position and player Position
/// </summary>
public class wayPoint : MonoBehaviour
{
    //find all goals
    public GameObject[] goals;

    //wayPoint will be selected in RandomWindow
    public GameObject waypointTo; //= null;

    //To Find Player position
    public GameObject player;

    //===========Get all the corners of the map===============
    public GameObject FrontFace_leftIndicator;
    public GameObject FrontFace_rightIndicator;


    public GameObject leftFace_leftIndicator;
    public GameObject leftFace_rightIndicator;

    public GameObject backFace_leftIndicator;
    public GameObject backFace_rightIndicator;

    public GameObject rightFace_leftIndicator;
    public GameObject rightFace_rightIndicator;
    //===========Get all the corners of the map===============

    //public MeshRenderer mesh;

    // Start is called before the first frame update
    void Start()
    {

        //mesh = FrontFace_rightIndicator.GetComponent<MeshRenderer>();

        //mesh.enabled = false;

        ////Renderers them all off in the beginning
        FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

    }


    //Update is called once per frame
    void Update()
    {
        //gameObject.transform.LookAt(GameObject.Find("TrackThisOne").transform);
        player = GameObject.Find("Player");

        //If Not Null

        Debug.Log("Player Current Rotation: " + player.transform.rotation.y);

        //The RandomWindow script will make goal equal to waypointTo
        //So it can be checked in the waypoint

        if (waypointTo != null)
        {
            //Find it's position
            Debug.Log("The Position is: " + waypointTo.transform.position);


            //=========================If it is on the front Face==================================
            if (waypointTo.name == "windowFront") //> 2.05f && waypointTo.transform.position.z < 2.20f)
            {
                //If Player On front Face
                if (player.transform.rotation.y == 0)
                {
                    FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
                    //Then Do Nothing
                }

                //If Player On right Face
                if (player.transform.rotation.y == -90.00001)
                {
                    //Do Something With it
                    rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;
                    rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
                }

                //If Player On left Face
                if (player.transform.rotation.y > 85f && player.transform.rotation.y < 95)
                {
                    leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;
                    leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;

                    FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
                }

                //If player on back Face
                if (player.transform.rotation.y == -180)
                {
                    backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;
                    backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;

                    rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;

                }
            }
            //=====================================================================================


            //=============================If it is on the left Face===============================
            if (waypointTo.name == "windowLeft")// > -3.20 && waypointTo.transform.position.x < -3.35)
            {
                //If Player On front Face
                if (player.transform.rotation.y == 0)
                {


                    FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;
                    FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
                }

                //If Player On right Face
                if (player.transform.rotation.y == -90.00001)
                {
                    rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;
                    rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;

                    leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
                }

                //If Player On left Face
                if (player.transform.rotation.y > 85f && player.transform.rotation.y < 95)
                {
                    //then do nothing
                    FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
                }

                //If player on back Face
                if (player.transform.rotation.y == -180)
                {
                    backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;
                    backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;

                    rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
                }
            }
            //=====================================================================================


            //======================If it is on the back Face=====================================
            if (waypointTo.name == "windowBack") //> 8.50f && waypointTo.transform.position.z < 8.70f)
            {
                //If Player On front Face
                if (player.transform.rotation.y == 0)
                {
                    FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;
                    FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;

                    leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
                }

                //If Player On right Face
                if (player.transform.rotation.y == -90.00001)
                {
                    rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;
                    rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
                }

                //If Player On left Face
                if (player.transform.rotation.y > 85f && player.transform.rotation.y < 95)
                {
                    leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;
                    leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;

                    rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
                }

                //If player on back Face
                if (player.transform.rotation.y == -180)
                {
                    leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
                    leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;

                    rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
                    //Then do nothing
                }
            }
            //=====================================================================================

            //3.45 -- 3.55
            //===================If it is on the right Face========================================
            if (waypointTo.name == "windowRight")// > 3.45f && waypointTo.transform.position.x < 3.55f)
            {
                //If Player On front Face
                if (player.transform.rotation.y == 0)
                {
                    FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;
                    FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;

                    leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
                }

                //If Player On right Face
                if (player.transform.rotation.y == -90.00001)
                {
                    //Then Do Nothing
                    FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
                    FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;

                    leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
                }

                //If Player On left Face
                if (player.transform.rotation.y > 85f && player.transform.rotation.y < 95)
                {
                    leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;
                    leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;

                    rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
                }

                //If player on back Face
                if (player.transform.rotation.y == -180)
                {
                    backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;
                    backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

                    FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
                    FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
                }
            }
            //=====================================================================================


            //If it's between x,y,z then 

            //If player X is 0, 90, 180, -90, then
            //Display The arrow


            //Get Rid Of Data In WaypointTo
            //waypointTo = null;
        }



        //if (waypointTo != null)
        //{
        //    //Find it's position
        //    Debug.Log("The Position is: " + waypointTo.transform.position);


        //    //=========================If it is on the front Face==================================
        //    if (waypointTo.transform.position.z > 2.05f && waypointTo.transform.position.z < 2.20f)
        //    {
        //        //If Player On front Face
        //        if (player.transform.rotation.x == 0)
        //        {
        //            FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            //Then Do Nothing
        //        }

        //        //If Player On right Face
        //        if (player.transform.rotation.x == -90.00001)
        //        {
        //            //Do Something With it
        //            rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;
        //            rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
        //        }

        //        //If Player On left Face
        //        if (player.transform.rotation.x == 90.00001)
        //        {
        //            leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;
        //            leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
        //        }

        //        //If player on back Face
        //        if (player.transform.rotation.x == -180)
        //        {
        //            backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;
        //            backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;

        //            rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;

        //        }
        //    }
        //    //=====================================================================================


        //    //=============================If it is on the left Face===============================
        //    if (waypointTo.transform.position.x > -3.20 && waypointTo.transform.position.x < -3.35)
        //    {
        //        //If Player On front Face
        //        if (player.transform.rotation.x == 0)
        //        {


        //            FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;
        //            FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
        //        }

        //        //If Player On right Face
        //        if (player.transform.rotation.x == -90.00001)
        //        {
        //            rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;
        //            rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;

        //            leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
        //        }

        //        //If Player On left Face
        //        if (player.transform.rotation.x == 90.00001)
        //        {
        //            //then do nothing
        //            FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
        //        }

        //        //If player on back Face
        //        if (player.transform.rotation.x == -180)
        //        {
        //            backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;
        //            backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
        //        }
        //    }
        //    //=====================================================================================


        //    //======================If it is on the back Face=====================================
        //    if (waypointTo.transform.position.z > 8.50f && waypointTo.transform.position.z < 8.70f)
        //    {
        //        //If Player On front Face
        //        if (player.transform.rotation.x == 0)
        //        {
        //            FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;
        //            FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;

        //            leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
        //        }

        //        //If Player On right Face
        //        if (player.transform.rotation.x == -90.00001)
        //        {
        //            rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;
        //            rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
        //        }

        //        //If Player On left Face
        //        if (player.transform.rotation.x == 90.00001)
        //        {
        //            leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;
        //            leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
        //        }

        //        //If player on back Face
        //        if (player.transform.rotation.x == -180)
        //        {
        //            leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            //Then do nothing
        //        }
        //    }
        //    //=====================================================================================

        //    //3.45 -- 3.55
        //    //===================If it is on the right Face========================================
        //    if (waypointTo.transform.position.x > 3.45f && waypointTo.transform.position.x < 3.55f)
        //    {
        //        //If Player On front Face
        //        if (player.transform.rotation.x == 0)
        //        {
        //            FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;
        //            FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
        //        }

        //        //If Player On right Face
        //        if (player.transform.rotation.x == -90.00001)
        //        {
        //            //Then Do Nothing
        //            FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
        //        }

        //        //If Player On left Face
        //        if (player.transform.rotation.x == 90.00001)
        //        {
        //            leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = true;
        //            leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;

        //            rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
        //        }

        //        //If player on back Face
        //        if (player.transform.rotation.x == -180)
        //        {
        //            backFace_leftIndicator.GetComponent<MeshRenderer>().enabled = true;
        //            backFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            rightFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            rightFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            leftFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            leftFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;

        //            FrontFace_leftIndicator.GetComponent<MeshRenderer>().enabled = false;
        //            FrontFace_rightIndicator.GetComponent<MeshRenderer>().enabled = false;
        //        }
        //    }
        //    //=====================================================================================


        //    //If it's between x,y,z then 

        //    //If player X is 0, 90, 180, -90, then
        //    //Display The arrow


        //    //Get Rid Of Data In WaypointTo
        //    //waypointTo = null;
        //}
    }
}
