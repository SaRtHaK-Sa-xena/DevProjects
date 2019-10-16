using System.Collections;
using System.Collections.Generic;
using UnityEngine;


[RequireComponent(typeof(PlayerEngine))]


/// <summary>
/// Player Controls. Lists The Usage Of Keys To Move Camera. This Was Also Used In Accordance To The Player Motor
/// When Testing How RigidBody Works With Player In Reference Of Motions. The Player Motion Controls Of Movement Have Been
/// Removed.
/// </summary>
public class PlayerControl : MonoBehaviour
{
    
    [SerializeField]
    private float speed = 5f;

    [SerializeField]
    private float lookSensitivity = 5f;

    private PlayerEngine engine;

    void Start()
    {
        engine = GetComponent<PlayerEngine>();
    }

    void Update()
    {
        //=================No Player Movement==============
        float xMov = Input.GetAxisRaw("Horizontal");
        //float zMov = Input.GetAxisRaw("Vertical");
        Vector3 movHorizontal = transform.right * xMov;
        Vector3 m_velocity = movHorizontal.normalized * speed;
        engine.Move(m_velocity);
        //=================No Player Movement==============

        //Calculate Horizontal Rotation
        //float xRotation = Input.GetAxisRaw("Mouse X");

        //Vector3 m_rotation = new Vector3(0f, xRotation, 0f) * lookSensitivity;
        //Call rotate
        //engine.Rotate(m_rotation);


        //Calculate Vertical Rotation
        //float yRotation = Input.GetAxisRaw("Mouse Y");

        //Vector3 cameraRotation = new Vector3(yRotation, 0f, 0f) * lookSensitivity;

        //Call rotate
        //engine.RotateCamera(cameraRotation);
    }
}
