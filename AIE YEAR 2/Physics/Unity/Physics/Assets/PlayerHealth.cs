using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerHealth : MonoBehaviour
{
    public event Action<float> OnHealthPctChanged = delegate { };

    private int maxHealth = 100;
    public int currentHealth;

    public void modifyHealth(int amount)
    {
        currentHealth += amount;
        float currentHealthPct = (float)currentHealth / (float)maxHealth;
        OnHealthPctChanged(currentHealthPct);
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if(currentHealth <= 0)
        {
            currentHealth = 0;
            Die();
        }
    }
    void Die()
    {
        //Call Reset
    }
}
