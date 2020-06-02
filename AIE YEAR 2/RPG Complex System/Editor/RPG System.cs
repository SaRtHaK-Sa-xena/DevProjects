using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

public class RPGSystem : EditorWindow
{
    static PrimaryStatData primaryStatData;
    public static PrimaryStatData primaryStatInfo { get { return primaryStatData; } }


    [MenuItem("Window/RPG System")]
    static void OpenWindow()
    {
        RPGSystem window = (RPGSystem)GetWindow(typeof(RPGSystem));
        window.minSize = new Vector2(600, 300);
        window.Show();
    }

    private void OnEnable()
    {
        InitData();
    }

    public static void InitData()
    {
        primaryStatData = (PrimaryStatData)ScriptableObject.CreateInstance(typeof(PrimaryStatData)); 
    }

    private void OnGUI()
    {
        DrawStatsPage();
    }

    //# Draws Stats Page
    void DrawStatsPage()
    {
        GUILayout.Label("Stats");
        
        // Displays Button to Configure Stats
        if(GUILayout.Button("Configure Stats", GUILayout.Height(35)))
        {
            // Open up Window of Stats
            GeneralSettings.OpenWindow(GeneralSettings.SettingsType.PRIMARY_STATS); 
        }
    }

}

public class GeneralSettings : EditorWindow
{
    // User Can Choose Stats, Entity, Or Items Editing
    public enum SettingsType
    {
        PRIMARY_STATS,
        SECONDARY_STATS
    }

    static SettingsType dataSetting;
    static GeneralSettings window;

    public static void OpenWindow(SettingsType setting)
    {
        dataSetting = setting;
        window = (GeneralSettings)GetWindow(typeof(GeneralSettings));
        window.minSize = new Vector2(250, 200);
        window.Show();
    }

    
    // Draw Function
    private void OnGUI()
    {
        switch (dataSetting)
        {
            case SettingsType.PRIMARY_STATS:
                DrawStatSettings((StatData)RPGSystem.primaryStatInfo);
                break;
        }
    }

    void DrawStatSettings(StatData statData)
    {
        // Name Section
        EditorGUILayout.BeginHorizontal();
        GUILayout.Label("Stat Name");
        statData.statName = EditorGUILayout.TextField(statData.statName);
        EditorGUILayout.EndHorizontal();

        // Value Section
        EditorGUILayout.BeginHorizontal();
        GUILayout.Label("Value");
        statData.statValue = EditorGUILayout.FloatField(statData.statValue);
        EditorGUILayout.EndHorizontal();

        // Conditions to display Save Button
        if (statData.statName == null || statData.statName.Length == 0) 
        {
            EditorGUILayout.HelpBox("Stat requires a [Stat Name] before it can be created.", MessageType.Warning);
        }
        else if(GUILayout.Button("Finish and Save", GUILayout.Height(30)))
        {
            //  Save Data
            SaveStatData();
            
            //  Set Fields to default
            statData.statName = "";
            statData.statValue = 0;
            
            //  Close windows
            window.Close();
        }
    }

    void SaveStatData()
    {

    }

}
