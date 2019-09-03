using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerActor : MonoBehaviour
{
    public GameObject projectilePrefab;
    private CharacterController controller;
    public float speed = 5.0f;

    public enum WeaponType
    { 
        WEAPON_HITSCAN,WEAPON_SINGLESHOT
    }

    public WeaponType weaponType;

    private Vector3 PlatformGetPlayerFireDirection()
    {
        Vector3 mousePos = Input.mousePosition;
        Ray mouseRay = Camera.main.ScreenPointToRay(mousePos);
        Plane playerPlane = new Plane(Vector3.up, transform.position);
        float rayDistance = 0;
        playerPlane.Raycast(mouseRay, out rayDistance);
        Vector3 castPoint = mouseRay.GetPoint(rayDistance);


        Vector3 toCastPoint = castPoint - transform.position;
        toCastPoint.Normalize();

        return toCastPoint;
    }

    bool PlatformPlayerShouldFire()
    {
        return Input.GetMouseButton(0);
    }


    void FireHitscan()
    {
        Vector3 fireDirection = PlatformGetPlayerFireDirection();
        RaycastHit info;
        Ray fireRay = new Ray(transform.position, fireDirection);

        if (Physics.Raycast(fireRay, out info, 1000))
        {
            if (info.collider.tag == "EnemyTag")
            {
                Destroy(info.collider.gameObject);
            }
        }
    }

    void FireSingleShot()
    {
        GameObject projectile = (GameObject)Instantiate(projectilePrefab);

        projectile.transform.position = transform.position;

        ProjectileActor projectileConponent = projectile.GetComponent<ProjectileActor>();

        projectileConponent.direction = PlatformGetPlayerFireDirection();
    }

    // Use this for initialization
    void Start()
    {
        controller = gameObject.GetComponent<CharacterController>();

    }



    // Update is called once per frame
    void Update()
    {
        //Vector3 move_direction = new Vector3(1, 0, 0);

        //if (Input.GetKey(KeyCode.S))
        //{
        //    move_direction.Set(0, 0, -1);
        //    controller.Move(move_direction * Time.deltaTime * speed);
        //}
        //if (Input.GetKey(KeyCode.W))
        //{
        //    move_direction.Set(0, 0, 1);
        //    controller.Move(move_direction * Time.deltaTime * speed);
        //}
        //if (Input.GetKey(KeyCode.A))
        //{
        //    move_direction.Set(-1, 0, 0);
        //    controller.Move(move_direction * Time.deltaTime * speed);
        //}
        //if (Input.GetKey(KeyCode.D))
        //{
        //    move_direction.Set(1, 0, 0);
        //    controller.Move(move_direction * Time.deltaTime * speed);
        //}

        //X
        float h_input = Input.GetAxis("Horizontal");
        //Z
        float v_input = Input.GetAxis("Vertical");

        //Gives us a direction the player is moving in
        Vector3 direction = new Vector3(h_input, 0, v_input);

        //scale by speed
        direction *= Time.deltaTime * speed;
        controller.Move(direction);

        Vector3 fireDirection = PlatformGetPlayerFireDirection();

        Ray fireRay = new Ray(transform.position, fireDirection);
        RaycastHit info;

        if(PlatformPlayerShouldFire())
        {
            switch (weaponType)
            {
                case WeaponType.WEAPON_HITSCAN:
                    FireHitscan();
                    break;
                case WeaponType.WEAPON_SINGLESHOT:
                    //singleShotWeaponCallGoesHere
                    
                    break;
                default:
                    break;
            }
        }

        //if (PlatformPlayerShouldFire() && Physics.Raycast(fireRay, out info, 1000))
        //{
        //    if (info.collider.tag == "EnemyTag")
        //    {
        //        Destroy(info.collider.gameObject);
        //    }
        //}

        //====Shooting Enemy=======
        //Vector3 mousePos = Input.mousePosition;
        //Ray mouseRay = Camera.main.ScreenPointToRay(mousePos);
        //Plane playerPlane = new Plane(Vector3.up, transform.position);
        //float rayDistance = 0;
        //playerPlane.Raycast(mouseRay, out rayDistance);
        //Vector3 castPoint = mouseRay.GetPoint(rayDistance);


        //Vector3 toCastPoint = castPoint - transform.position;
        //toCastPoint.Normalize();
        //Ray fireRay = new Ray(transform.position, toCastPoint);

        //RaycastHit info;
        //if (Input.GetMouseButtonDown(0) && Physics.Raycast(fireRay, out info))
        //{
        //    if (info.collider.tag == "EnemyTag")
        //        Destroy(info.collider.gameObject);
        //}
        //====Shooting Enemy=======

    }

    

}
