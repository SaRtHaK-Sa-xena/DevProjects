using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class tpsCamera : MonoBehaviour
{
    //Determines the limitations of vertical camera movement
    private const float Y_ANGLE_MIN = 10.0f;//10
    private const float Y_ANGLE_MAX = 10.0f;//15

    public Transform character; //What the camera is looking at..the main character

    private float distance_other = 3.0f; // Distance to stay from character, Make sure it is negative
    private float currentX = 0.0f; // Holds value of X mouse movement
    private float currentY = 0.0f; // Holds value of Y mouse movement

    private float currentX_other = 0.0f; // Holds value of X mouse movement
    private float currentY_other = 0.0f; // Holds value of Y mouse movement

    public GameObject objToLookAt;

    [SerializeField]
    private float distance = -0.3f; // Distance to stay from character, Make sure it is negative
    
    void start() { }

    void Update()
    {
        if (Input.GetAxis("Mouse X") != null || Input.GetAxis("Mouse Y") != null)
        {
            currentX += Input.GetAxis("Mouse X");
            currentY += Input.GetAxis("Mouse Y");

            currentX_other += Input.GetAxis("Mouse X");
            currentY_other += -Input.GetAxis("Mouse Y");
        }

        currentY = Mathf.Clamp(currentY, Y_ANGLE_MIN, Y_ANGLE_MAX);
        currentY_other = Mathf.Clamp(currentY_other, Y_ANGLE_MIN, Y_ANGLE_MAX);
    }

    void LateUpdate()
    {                                                        //Rotation around character............/...Keeps distance from character          
        gameObject.transform.position = character.position + Quaternion.Euler(currentY, currentX, 0) * new Vector3(0, 0, distance);
        gameObject.transform.LookAt(character.position);//Points camera at character
        objToLookAt.transform.position = character.position + Quaternion.Euler(currentY_other, currentX_other, 0) * new Vector3(0, -1.0f, distance_other);
        objToLookAt.transform.LookAt(character.position);//Points camera at character
    }
}
