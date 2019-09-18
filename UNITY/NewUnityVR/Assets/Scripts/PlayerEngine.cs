using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(Rigidbody))]

public class PlayerEngine : MonoBehaviour
{
    [SerializeField]
    public Camera cam;

    private Vector3 velocity = Vector3.zero;
    private Vector3 rotation = Vector3.zero;
    private Vector3 cameraRotation = Vector3.zero;


    private Rigidbody rb;

    void Start()
    {
        rb = GetComponent<Rigidbody>();
    }

    public void Move(Vector3 m_velocity)
    {
        velocity = m_velocity;
    }
    public void Rotate(Vector3 m_rotation)
    {
        rotation = m_rotation;
    }

    public void RotateCamera(Vector3 m_cameraRotation)
    {
        cameraRotation = m_cameraRotation;
    }

    private void FixedUpdate()
    {
        ExecMovement();
        ExecRotation();
    }

    void ExecMovement()
    {
        if(velocity != Vector3.zero)
        {
            rb.MovePosition(rb.position + velocity * Time.fixedDeltaTime);
        }
    }

    void ExecRotation()
    {
        rb.MoveRotation(rb.rotation * Quaternion.Euler(rotation));
        if(cam != null)
        {
            cam.transform.Rotate(-cameraRotation);
        }
    }
}
