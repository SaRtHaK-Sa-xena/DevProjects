using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerActor : MonoBehaviour {

    private CharacterController controller;

	// Use this for initialization
	void Start () {
        controller = gameObject.GetComponent<CharacterController>();
	}

    // Update is called once per frame
    void Update()
    {
        Vector3 move_direction = new Vector3(1, 0, 0);

        if (Input.GetKey(KeyCode.S))
        {
            move_direction.Set(0, 0, -1);
            controller.Move(move_direction * Time.deltaTime * 15);
        }
        if (Input.GetKey(KeyCode.W))
        {
            move_direction.Set(0, 0, 1);
            controller.Move(move_direction * Time.deltaTime * 15);
        }
        if (Input.GetKey(KeyCode.A))
        {
            move_direction.Set(-1, 0, 0);
            controller.Move(move_direction * Time.deltaTime * 15);
        }
        if (Input.GetKey(KeyCode.D))
        {
            move_direction.Set(1, 0, 0);
            controller.Move(move_direction * Time.deltaTime * 15);
        }
    }
}
