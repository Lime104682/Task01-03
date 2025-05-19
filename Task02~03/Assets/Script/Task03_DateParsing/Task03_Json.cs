using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;

[System.Serializable]
public class MonsterState
{
    public float attack;
    public float defense;
    public int maxHP;
}

[System.Serializable]
public class Monster
{
    public int ID;
    public string name;
    public MonsterState state;
}

[System.Serializable]
public class MonsterList
{
    public List<Monster> monsters;
}

public class Task03_Json : MonoBehaviour
{
    void Start()
    {
        string path = Application.dataPath + "/Task03_DataTable.csv";

        string[] lines = File.ReadAllLines(path);

        List<Monster> monsters = new List<Monster>();

        for (int i = 1; i < lines.Length; i++)
        {
            string[] parts = lines[i].Split(',');

            Monster m = new Monster
            {
                ID = int.Parse(parts[0]),
                name = parts[1],
                state = new MonsterState
                {
                    attack = float.Parse(parts[2]),
                    defense = float.Parse(parts[3]),
                    maxHP = int.Parse(parts[4])
                }
            };
            monsters.Add(m);
        }

        string json = JsonUtility.ToJson(new Wrapper<Monster> { items = monsters.ToArray() }, true);
        Debug.Log(json);

        File.WriteAllText(path, json);
    }

    [System.Serializable]
    private class Wrapper<T>
    {
        public T[] items;
    }
}
