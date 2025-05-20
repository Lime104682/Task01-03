using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;
using System.IO;
using System.Text;
using System.Runtime.CompilerServices;
using System.Threading;

/*
- 해당 데이터 테이블을 오른쪽과 같은 Json 데이터로 파싱한다.
- 결과물을 다시 프로그램에서 불러와 해당 Json 데이터를 출력한다.
- 어떠한 언어와 라이브러리를 사용해도 괜찮다. (Unity Engine 포함)
 */

/*
 * 저장하는 방법
 * 저장할 데이터가 존재
 * 데이터를 제이슨으로 변환
 * 제이슨을 외부에 저장
 * 
 * 불러오는 방법
 * 외부에 저장된 제이슨을 가져옴
 * 제이슨을 데이터형태로 변환
 * 불러온 데이터를 사용
 */

/*
 * 검색어 
 * json 유니티
 * https://www.youtube.com/watch?v=fHXN1DJKDk0&t=934s
 * https://www.youtube.com/watch?v=N9r2ju3xJGk&t=823s
    * [System.Serializable]
        * 직렬화 하기 위한 코드  
    * JsonUtility.FromJsonOverwrite()
    * Application.datapath
        * https://geukggom.tistory.com/9
        * https://3dmpengines.tistory.com/1745
        * 해당 프로젝트 Assets 파일
 *  
 * 유니티 엑셀 파일 json 저장 불러오기
 * https://bonnate.tistory.com/355
 * 
 * 유니티 csv 파일 읽기
 * https://dongsik-blog.tistory.com/101
 * https://yoonstone-games.tistory.com/14#google_vignette
 * https://yundongdong.tistory.com/4
 * https://velog.io/@dbdnjstkd369/%EC%9C%A0%EB%8B%88%ED%8B%B0%EC%97%90%EC%84%9C-CSV%EB%A5%BC-Scriptable-Object%EB%A1%9C-%EB%A7%8C%EB%93%A4%EC%96%B4%EC%A3%BC%EA%B8%B0
 */

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
    string jsonPath; //Json 파일 경로 저장 장소

    string saveData; //Json으로 저장할 데이터 장소
    string loadData; //저장된 Json 데이터를 불러와서 저장할 장소

    private void Awake()
    {
        //DataTable.csv을 찾기 위한 경로
        csvPath = Application.dataPath + "/Task03_DataTable.csv";

        //MonsterData.json을 찾기 위한 경로
        jsonPath = Application.dataPath + "/MonsterData.json";
    }

    // Start is called before the first frame update
    void Start()
    {
        //csv 파일 저장
        MonsterList monsterList = ToMonsterList(csvPath);

        //Json 파일로 저장
        saveData = JsonUtility.ToJson(monsterList);//monsterList 정보를 Json으로 saveData에 저장
        File.WriteAllText(jsonPath, saveData); //saveData의 데이터를 외부에 파일로 저장

        //Json 파일 불러오기
        loadData = File.ReadAllText(jsonPath); //ReadAllText()의 매개변수로 받은 경로의 파일을 Data에 저장
        MonsterList loadList = JsonUtility.FromJson<MonsterList>(loadData); //nowMonster에 Data Json파일을 대입


        foreach (var allLine in loadList.Monslist)
        {
            Debug.Log("ID : " + allLine.ID + "\n");
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

            //splitData의 요소가 5개가 아니라면 넘어감
            //if (splitData.Length != 5) continue;

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
            catch { }

            
        }

        //monsterLists를 Monslist에 담아서 반환
        return new MonsterList { Monslist = monsterLists};
    }
}
