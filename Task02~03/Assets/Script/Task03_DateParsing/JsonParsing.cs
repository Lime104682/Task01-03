using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;
using System.IO;
using System.Text;
using System.Runtime.CompilerServices;
using System.Threading;

/*
- �ش� ������ ���̺��� �����ʰ� ���� Json �����ͷ� �Ľ��Ѵ�.
- ������� �ٽ� ���α׷����� �ҷ��� �ش� Json �����͸� ����Ѵ�.
- ��� ���� ���̺귯���� ����ص� ������. (Unity Engine ����)
 */

/*
 * �����ϴ� ���
 * ������ �����Ͱ� ����
 * �����͸� ���̽����� ��ȯ
 * ���̽��� �ܺο� ����
 * 
 * �ҷ����� ���
 * �ܺο� ����� ���̽��� ������
 * ���̽��� ���������·� ��ȯ
 * �ҷ��� �����͸� ���
 */

/*
 * �˻��� 
 * json ����Ƽ
 * https://www.youtube.com/watch?v=fHXN1DJKDk0&t=934s
 * https://www.youtube.com/watch?v=N9r2ju3xJGk&t=823s
    * [System.Serializable]
        * ����ȭ �ϱ� ���� �ڵ�  
    * JsonUtility.FromJsonOverwrite()
    * Application.datapath
        * https://geukggom.tistory.com/9
        * https://3dmpengines.tistory.com/1745
        * �ش� ������Ʈ Assets ����
 *  
 * ����Ƽ ���� ���� json ���� �ҷ�����
 * https://bonnate.tistory.com/355
 * 
 * ����Ƽ csv ���� �б�
 * https://dongsik-blog.tistory.com/101
 * https://yoonstone-games.tistory.com/14#google_vignette
 * https://yundongdong.tistory.com/4
 * https://velog.io/@dbdnjstkd369/%EC%9C%A0%EB%8B%88%ED%8B%B0%EC%97%90%EC%84%9C-CSV%EB%A5%BC-Scriptable-Object%EB%A1%9C-%EB%A7%8C%EB%93%A4%EC%96%B4%EC%A3%BC%EA%B8%B0
 */

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
    string jsonPath; //Json ���� ��� ���� ���

    string saveData; //Json���� ������ ������ ���
    string loadData; //����� Json �����͸� �ҷ��ͼ� ������ ���

    private void Awake()
    {
        //DataTable.csv�� ã�� ���� ���
        csvPath = Application.dataPath + "/Task03_DataTable.csv";

        //MonsterData.json�� ã�� ���� ���
        jsonPath = Application.dataPath + "/MonsterData.json";
    }

    // Start is called before the first frame update
    void Start()
    {
        //csv ���� ����
        MonsterList monsterList = ToMonsterList(csvPath);

        //Json ���Ϸ� ����
        saveData = JsonUtility.ToJson(monsterList);//monsterList ������ Json���� saveData�� ����
        File.WriteAllText(jsonPath, saveData); //saveData�� �����͸� �ܺο� ���Ϸ� ����

        //Json ���� �ҷ�����
        loadData = File.ReadAllText(jsonPath); //ReadAllText()�� �Ű������� ���� ����� ������ Data�� ����
        MonsterList loadList = JsonUtility.FromJson<MonsterList>(loadData); //nowMonster�� Data Json������ ����


        foreach (var allLine in loadList.Monslist)
        {
            Debug.Log("ID : " + allLine.ID + "\n");
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

            //splitData�� ��Ұ� 5���� �ƴ϶�� �Ѿ
            //if (splitData.Length != 5) continue;

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
            catch { }

            
        }

        //monsterLists�� Monslist�� ��Ƽ� ��ȯ
        return new MonsterList { Monslist = monsterLists};
    }
}
