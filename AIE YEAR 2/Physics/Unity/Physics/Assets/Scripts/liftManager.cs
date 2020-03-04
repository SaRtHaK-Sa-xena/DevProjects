using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class liftManager : MonoBehaviour
{
    [SerializeField]
    private GameObject lift;

    private void Start()
    {
        //  Create new Vector3 with inverse y
        Vector3 inverseTargetVelocity = new Vector3(lift.GetComponent<ConfigurableJoint>().targetVelocity.x,
            20,
            lift.GetComponent<ConfigurableJoint>().targetVelocity.z);

        // set it to the inverse vector created above
        lift.GetComponent<ConfigurableJoint>().targetVelocity = inverseTargetVelocity;
    }

    // Update Lift Controls 
    public void liftControls(RaycastHit raycast)
    {
        //Create instance
        RaycastHit useRayCast = raycast;

        //  If not null
        if (useRayCast.collider)
        {
            //  If Up button pressed
            if(useRayCast.collider.name == "UP")
            {
                //  Update lift mechanics...go up

                //  Create new Vector3 with inverse y
                Vector3 inverseTargetVelocity = new Vector3(lift.GetComponent<ConfigurableJoint>().targetVelocity.x,
                    -20,
                    lift.GetComponent<ConfigurableJoint>().targetVelocity.z);

                // set it to the inverse vector created above
                lift.GetComponent<ConfigurableJoint>().targetVelocity = inverseTargetVelocity;

            }

            //  If Down button pressed
            if(useRayCast.collider.name == "DOWN")
            {
                //  Update lift mechanics...go down
                //  Create new Vector3 with inverse y
                Vector3 inverseTargetVelocity = new Vector3(lift.GetComponent<ConfigurableJoint>().targetVelocity.x,
                    20,
                    lift.GetComponent<ConfigurableJoint>().targetVelocity.z);

                // set it to the inverse vector created above
                lift.GetComponent<ConfigurableJoint>().targetVelocity = inverseTargetVelocity;
            }
        }
    }
}
