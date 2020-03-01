using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class trapSelection : MonoBehaviour
{
    public Camera cam;

    public Material selected_mat;

    // Start is called before the first frame update
    void Start()
    {
        cam = GetComponent<Camera>();
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.E))
        {
            RaycastHit hit;
            Ray ray = cam.ScreenPointToRay(Input.mousePosition);

            if (Physics.Raycast(ray, out hit))
            {
                Transform objectHit = hit.transform;

                hit.collider.gameObject.GetComponent<MeshRenderer>().material = selected_mat;
            }
        }
    }
}
