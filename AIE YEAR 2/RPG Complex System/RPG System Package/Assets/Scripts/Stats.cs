using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Stats : MonoBehaviour
{
    //  Stat Types
    public enum StatType
    {
        characterLife, characterEnergy,
        characterDamage, characterDefense,
        characterAccuracy, characterDodge
    };

    public float statValue;

}
