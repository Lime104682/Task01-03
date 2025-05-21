using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;
using System.IO;
using System.Text;
using System.Runtime.CompilerServices;
using System.Threading;


[System.Serializable]//직렬화
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
    string csvPath;  //csv 파일 경로 저장 장소
    string jsonPath1; //Json 파일 경로 저장 장소

    string saveData; //Json으로 저장할 데이터 장소
    string loadData; //저장된 Json 데이터를 불러와서 저장할 장소

    private void Awake()
    {
        //DataTable.csv을 찾기 위한 경로
        csvPath = Application.dataPath + "/Task03_DataTable.csv";

        //MonsterData.json을 찾기 위한 경로
        jsonPath1 = Application.dataPath + "/MonsterData.json";
    }

    // Start is called before the first frame update
    void Start()
    {
        //csv 파일 저장
        MonsterList monsterList = ToMonsterList(csvPath);

        //csv -> Json 파일로 저장
        saveData = JsonUtility.ToJson(monsterList,true);//monsterList 정보를 Json으로 saveData에 저장
        File.WriteAllText(jsonPath1, saveData); //saveData의 데이터를 외부에 파일로 저장

        //Json 파일 불러오기
        loadData = File.ReadAllText(jsonPath1); //ReadAllText()의 매개변수로 받은 경로의 파일을 loadData 저장
        MonsterList loadList = JsonUtility.FromJson<MonsterList>(loadData); //loadList에 loadData Json파일 데이터를 저장

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
        //path 경로의 파일(csv)을 줄 단위로 읽어와 배열로 저장
        string[] allLines = File.ReadAllLines(path);

        //MonsterData 객체들을 리스트 저장
        List<MonsterData> monsterLists = new List<MonsterData>();

        //csv파일의 각 줄을 1번씩 실행
        foreach (string allLine in allLines)
        {
            //줄을 쉼표로 나누어 각 배열에 저장
            string[] splitData = allLine.Split(',');

            try
            {
                int id = int.Parse(splitData[0].Trim());
                string name = splitData[1].Trim();
                float atk = float.Parse(splitData[2].Trim());
                float def = float.Parse(splitData[3].Trim());
                int maxhp = int.Parse(splitData[4].Trim());

                //csv파일의 데이터에 맞게 몬스터 데이터 생성
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

                //생성된 몬스터 데이터를 리스트에 저장
                monsterLists.Add(monster);
            }
            catch
            {
                Debug.Log("csv 파일 데이터 나감");
            }

            
        }

        //monsterLists를 Monslist에 담아서 반환
        return new MonsterList { Monslist = monsterLists};
    }
}
