using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class gameEngine : MonoBehaviour
{

    private GameObject slider;
    public float deltaTime = 0;

    public Animation myAnim;
    public Animation myAnim2;

    public GameObject player;

    //Item Prefab
    public GameObject item_prefab;
    //item Transform Parent List
    public GameObject[] ItemPosition;

    public bool startStress;

    public int Stuntimer = 0;

    private void Start()
    {
        //platforms = GameObject.FindGameObjectsWithTag("platform");
        //for (int i = 0; i < platforms.Length; i++)
        //{
        //    platforms[i].AddComponent<Rigidbody>().useGravity = false;
        //}
        //player_UI = GameObject.Find("Canvas");

        //Instantiate(scoreHighlight_pref);
        //Instantiate(scoreHighlight_pref, player_UI.transform);

        //scoreHighlight_pref.transform.SetParent(player_UI.transform);

        player = GameObject.Find("Player");
        //player.transform.SetPositionAndRotation(player.transform.position, rotated90.transform.rotation);

    }

    // Update is called once per frame
    void Update()
    {
        if (!SceneManager.GetSceneByBuildIndex(2).isLoaded)
        {
            player = GameObject.Find("Player");

            slider = GameObject.Find("StressMeter");

            //slider.GetComponent<Slider>().value = deltaTime;
            //if(deltaTime > 100)
            //{
            //    for (int i = 0; i < platforms.Length; i++)
            //    { 
            //        platforms[i].GetComponent<Rigidbody>().AddForce(Vector3.up);
            //    }
            //}
            //=================================Stress Meter Functionality==================================
            if (startStress)
            {
                deltaTime = deltaTime + 1;

                slider = GameObject.Find("StressMeter");
                slider.GetComponent<Slider>().value = deltaTime;
            }
            //=================================Stress Meter Functionality==================================




            //Items=========================================================================================

            //Store all Transform Item Positions
            ItemPosition = GameObject.FindGameObjectsWithTag("ItemPos");


            int incrementIfItem = 0;
            //Search if there is an item
            for (int i = 0; i < ItemPosition.Length; i++)
            {
                //if there is an item
                if (ItemPosition[i].GetComponent<itemOnPosition>().HasItem == true)
                {
                    //increase this
                    incrementIfItem = 1;
                }
                else
                {
                    //Do Nothing
                }
            }

            //if the incrementIfItem equals to 1
            if (incrementIfItem == 1)
            {
                //Return
                return;
            }
            else
            {
                //This will be triggered if there is no Item on screen
                ItemPosition = GameObject.FindGameObjectsWithTag("ItemPos");


                //generate Random Number
                int randomNumber = Random.Range(0, ItemPosition.Length);// Random.Range(0, ItemPosition.Length);

                //use random number as index
                //To set the Position
                Instantiate(item_prefab, ItemPosition[randomNumber].transform);

                Debug.Log("Random Number =" + randomNumber);

                //Set that transform's hasItem to true
                ItemPosition[randomNumber].GetComponent<itemOnPosition>().HasItem = true;

                Debug.Log("Random Number =" + randomNumber);

                //Set Item script's parent to this transform
                //item_prefab.GetComponent<itemFunctionOnPickUp>().parentOfItem = ItemPosition[randomNumber];

                Debug.Log("Random Number =" + randomNumber);
            }

            //if(player.GetComponent<Rigidbody>().isKinematic == true)
            //{
            //    Stuntimer++;

            //    Debug.Log("Stun Timer: " + Stuntimer);

            //    if (Stuntimer >= 30)
            //    {
            //        Debug.Log("Stun Timer Ended At: " + Stuntimer);
            //        player.GetComponent<Rigidbody>().isKinematic = false;

            //        Stuntimer = 0;
            //    }
            //}

        }
    }
}






//using System.Collections;
//using System.Collections.Generic;
//using UnityEngine;
//using UnityEngine.UI;

//public class gameEngine : MonoBehaviour {

//    private GameObject slider;
//    public float deltaTime = 0;

//    public Animation myAnim;
//    public Animation myAnim2;

//    public GameObject player;
//    //public GameObject rotated90;
//    //public GameObject scoreHighlight_pref;
//    //public GameObject player_UI;

//    //private GameObject[] platforms;

//    public bool startStress = true;

//    private void Start()
//    {
//        //platforms = GameObject.FindGameObjectsWithTag("platform");
//        //for (int i = 0; i < platforms.Length; i++)
//        //{
//        //    platforms[i].AddComponent<Rigidbody>().useGravity = false;
//        //}
//        //player_UI = GameObject.Find("Canvas");

//        //Instantiate(scoreHighlight_pref);
//        //Instantiate(scoreHighlight_pref, player_UI.transform);

//        //scoreHighlight_pref.transform.SetParent(player_UI.transform);

//        player = GameObject.Find("Player");
//        //player.transform.SetPositionAndRotation(player.transform.position, rotated90.transform.rotation);

//    }

//    // Update is called once per frame
//    void Update ()
//    {
//        //if(deltaTime > 100)
//        //{
//        //    for (int i = 0; i < platforms.Length; i++)
//        //    { 
//        //        platforms[i].GetComponent<Rigidbody>().AddForce(Vector3.up);
//        //    }
//        //}

//        if (startStress)
//        {
//            deltaTime = deltaTime + 1;

//            slider = GameObject.Find("StressMeter");
//            slider.GetComponent<Slider>().value = deltaTime;
//        }

//	}
//}
