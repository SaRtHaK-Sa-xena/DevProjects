using System.Collections;
using System.Collections.Generic;
using UnityEngine;


[RequireComponent(typeof(PlayerEngine))]

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
        float xMov = Input.GetAxisRaw("Horizontal");
        float zMov = Input.GetAxisRaw("Vertical");

        Vector3 movHorizontal = transform.right * xMov;
        Vector3 movVertical = transform.forward * zMov;

        Vector3 m_velocity = (movHorizontal + movVertical).normalized * speed;

        engine.Move(m_velocity);

        float xRotation = Input.GetAxisRaw("Mouse X");

        Vector3 m_rotation = new Vector3(0f, xRotation, 0f) * lookSensitivity;

        engine.Rotate(m_rotation);


        float yRotation = Input.GetAxisRaw("Mouse Y");

        Vector3 cameraRotation = new Vector3(yRotation, 0f, 0f) * lookSensitivity;

        engine.RotateCamera(cameraRotation);
    }
}
