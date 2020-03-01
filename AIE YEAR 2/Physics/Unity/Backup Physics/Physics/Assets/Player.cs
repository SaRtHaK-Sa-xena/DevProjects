using System.Collections;
using System.Collections.Generic;
using UnityEngine;


[RequireComponent(typeof(CharacterController))]
[RequireComponent(typeof(Animator))]
public class Player : MonoBehaviour
{
    CharacterController controller = null;
    Animator animator = null;

    //default
    public float speed = 80.0f;
    public float pushPower = 2.0f;
    
    //[SerializeField]
    public Transform newPosition;

    //value of speed

    // Start is called before the first frame update
    void Start()
    {
        controller = GetComponent<CharacterController>();
        animator = GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        float vertical = Input.GetAxis("Vertical");
        float horizontal = Input.GetAxis("Horizontal");
        //Vector3 newPosition = new Vector3(transform.position.x, transform.position.y, transform.position.z + 1);



        //controller.SimpleMove(transform.up * Time.deltaTime);
        //transform.position = Vector3.MoveTowards(transform.position, newPosition.position, Time.deltaTime);
        transform.LookAt(newPosition);
        //transform.Rotate(transform.up, horizontal * speed * Time.deltaTime);
        animator.SetFloat("Speed", 0);
        //animator.SetFloat("Speed", vertical * speed * Time.deltaTime);
    }

    private void OnControllerColliderHit(ControllerColliderHit hit)
    {
        Rigidbody body = hit.collider.attachedRigidbody;
        if (body == null || body.isKinematic)
            return;
        if (hit.moveDirection.y < -0.3f)
            return;
        Vector3 pushDir = new Vector3(hit.moveDirection.x, 0, hit.moveDirection.z);
        body.velocity = pushDir * pushPower;
    }
}
