using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class DisplayScript : MonoBehaviour
{
    //Store Object Details In Here
    private GameObject valueToStore;
    public Text displayText;



    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        valueToStore = GameObject.FindGameObjectWithTag("Player");
        displayText.text = valueToStore.GetComponent<MouseScript>().Score.ToString();
    }
}
