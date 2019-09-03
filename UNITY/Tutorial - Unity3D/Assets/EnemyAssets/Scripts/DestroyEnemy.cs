using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DestroyEnemy : MonoBehaviour {

    // Use this for initialization
    void update()
    {
        Vector3 mousePos = Input.MousePosition;
        Ray mouseRay = Camera.main.ScreenPointToRay(mousePos);
        Plane playerPlane = new Plane(Vector3.up, transform.position);
        float rayDistance = 0;
        playerPlane.Raycast(mouseRay, out rayDistance);
        Vector3 castPoint = mouseRay.GetPoint(rayDistance);

    }
}
