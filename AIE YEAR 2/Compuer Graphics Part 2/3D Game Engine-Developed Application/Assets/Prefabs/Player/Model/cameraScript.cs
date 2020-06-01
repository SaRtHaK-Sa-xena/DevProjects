using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Handles RigidBody Rotation on Player, and Camera Rotation
/// </summary>
public class cameraScript : MonoBehaviour
{
    //Determines the limitations of vertical camera movement
    private const float Y_ANGLE_MIN = -15.0f;//10
    private const float Y_ANGLE_MAX = 15.0f;//15

    public Transform character; //What the camera is looking at..the main character

    private float currentX = 0.0f; // Holds value of X mouse movement
    private float currentY = 0.0f; // Holds value of Y mouse movement

    public GameObject player_pref;

    public GameObject player_model;

    [SerializeField]
    private float distance = 10f; // Distance to stay from character

    void Update()
    {
        //If held
        if (Input.GetAxis("Mouse X") != null || Input.GetAxis("Mouse Y") != null)
        {
            currentX += Input.GetAxis("Mouse X");
            currentY += -Input.GetAxis("Mouse Y");
        }

        //clamp variable
        currentY = Mathf.Clamp(currentY, Y_ANGLE_MIN, Y_ANGLE_MAX);
    }

    void LateUpdate()
    {
        //change player model rotation
        player_pref.GetComponent<Rigidbody>().MoveRotation(Quaternion.Euler(currentY, currentX, 0));

        //  only for Open-World Sim
        #region Open-World Sim
        //Rotation around character............/...Keeps distance from character          
        //gameObject.transform.position = character.position + Quaternion.Euler(currentY, currentX, 0) * new Vector3(0, 0, distance);
        //gameObject.transform.LookAt(character.position);//Points camera at character
        //player_model.GetComponent<Rigidbody>().MoveRotation(Quaternion.Euler(0, currentX, 0));
        #endregion
    }
}
