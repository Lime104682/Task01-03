using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;
using System.IO;
using System.Text;
using System.Runtime.CompilerServices;
using System.Threading;


[System.Serializable]//����ȭ
public class MonsterStats
{
    public float attack;
    public float defense;
    public int maxHP;
}

[System.Serializable]
public class MonsterData
{
    public int ID;
    public string name;
    public MonsterStats stats;
}

[System.Serializable]
public class MonsterList
{
    public List<MonsterData> Monslist;
}


public class JsonParsing : MonoBehaviour
{
    string csvPath;  //csv ���� ��� ���� ���
    string jsonPath1; //Json ���� ��� ���� ���

    string saveData; //Json���� ������ ������ ���
    string loadData; //����� Json �����͸� �ҷ��ͼ� ������ ���

    private void Awake()
    {
        //DataTable.csv�� ã�� ���� ���
        csvPath = Application.dataPath + "/Task03_DataTable.csv";

        //MonsterData.json�� ã�� ���� ���
        jsonPath1 = Application.dataPath + "/MonsterData.json";
    }

    // Start is called before the first frame update
    void Start()
    {
        //csv ���� ����
        MonsterList monsterList = ToMonsterList(csvPath);

        //csv -> Json ���Ϸ� ����
        saveData = JsonUtility.ToJson(monsterList,true);//monsterList ������ Json���� saveData�� ����
        File.WriteAllText(jsonPath1, saveData); //saveData�� �����͸� �ܺο� ���Ϸ� ����

        //Json ���� �ҷ�����
        loadData = File.ReadAllText(jsonPath1); //ReadAllText()�� �Ű������� ���� ����� ������ loadData ����
        MonsterList loadList = JsonUtility.FromJson<MonsterList>(loadData); //loadList�� loadData Json���� �����͸� ����

        foreach (var allLine in loadList.Monslist)
        {
            Debug.Log("ID : " + allLine.ID + "\n" + 
                      "Name : " + allLine.name + "\n" +
                      "Stats" + "\n" +
                      "  attack : " + allLine.stats.attack + "\n" +
                      "  defense : " + allLine.stats.defense + "\n" +
                      "  maxHP : " + allLine.stats.maxHP);
        }
    }

    MonsterList ToMonsterList(string path)
    {
        //path ����� ����(csv)�� �� ������ �о�� �迭�� ����
        string[] allLines = File.ReadAllLines(path);

        //MonsterData ��ü���� ����Ʈ ����
        List<MonsterData> monsterLists = new List<MonsterData>();

        //csv������ �� ���� 1���� ����
        foreach (string allLine in allLines)
        {
            //���� ��ǥ�� ������ �� �迭�� ����
            string[] splitData = allLine.Split(',');

            try
            {
                int id = int.Parse(splitData[0].Trim());
                string name = splitData[1].Trim();
                float atk = float.Parse(splitData[2].Trim());
                float def = float.Parse(splitData[3].Trim());
                int maxhp = int.Parse(splitData[4].Trim());

                //csv������ �����Ϳ� �°� ���� ������ ����
                MonsterData monster = new MonsterData
                {
                    ID = id,
                    name = name,
                    stats = new MonsterStats
                    {
                        attack = atk,
                        defense = def,
                        maxHP = maxhp,
                    }
                };

                //������ ���� �����͸� ����Ʈ�� ����
                monsterLists.Add(monster);
            }
            catch
            {
                Debug.Log("csv ���� ������ ����");
            }

            
        }

        //monsterLists�� Monslist�� ��Ƽ� ��ȯ
        return new MonsterList { Monslist = monsterLists};
    }
}
