using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class HealthBar : MonoBehaviour
{
    public Image healthBar;

    [SerializeField]
    private float updateSpeedSeconds = 0f;
    // Start is called before the first frame update
    void Start()
    {
        if(gameObject.transform.parent.CompareTag("Enemy"))
        {
            GetComponentInParent<Zombie>().OnHealthPctChanged += HandleHealthChanged;
        }
        if(gameObject.transform.parent.CompareTag("Player"))
        {
            GetComponentInParent<PlayerHealth>().OnHealthPctChanged += HandleHealthChanged;
        }
    }

    private void HandleHealthChanged(float pct)
    {
        StartCoroutine(ChangeToPct(pct));
    }

    private IEnumerator ChangeToPct(float pct)
    {
        Image Health = healthBar;
        if(Health)
        {
            float preChangePct = healthBar.fillAmount;
            float elapsed = 0f;

            while (elapsed < updateSpeedSeconds)
            {
                elapsed += Time.deltaTime;
                healthBar.fillAmount = Mathf.Lerp(preChangePct, pct, elapsed / updateSpeedSeconds);
                yield return null;
            }

            healthBar.fillAmount = pct;
        }
    }

    // Update is called once per frame
    void Update()
    {
        if(healthBar.fillAmount <= 0)
        {
            Destroy(this.gameObject);
        }
    }

    // On Destroy
    private void OnDestroy()
    {
        // if not null
        if(this)
        {
            //Enemy
            if (gameObject.transform.parent.CompareTag("Enemy"))
            {
                GetComponentInParent<Zombie>().OnHealthPctChanged -= HandleHealthChanged;
            }
            
            //Player
            if (gameObject.transform.parent.CompareTag("MainCamera"))
            {
                GetComponentInParent<PlayerHealth>().OnHealthPctChanged -= HandleHealthChanged;
            }
        }
    }
}
