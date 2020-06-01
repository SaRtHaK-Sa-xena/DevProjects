using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class character_preset : MonoBehaviour
{
    //  Character Types
    public enum CharacterType
    { player, enemy};

    


    //  Character statOptions
    public float characterLife,
        characterDamage,
        characterEnergy,
        characterDefense,
        characterAccuracy,
        characterDodge;
}
