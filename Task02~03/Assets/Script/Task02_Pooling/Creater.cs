using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Pool;

public class Creater : MonoBehaviour
{

    [SerializeField]
    private GameObject EnemyPrefab; //Enemy 프리팹 오브젝트 지정

    [SerializeField]
    private GameObject Player; //Player 오브젝트 지정

    private IObjectPool<EnemyPool> Pool; //EnemyPool 객체를 관리할 오브젝트 풀
    private float SpawnTime = 3.0f; //Enemy 생성 주기
    public float Timer = 0; //시간 측정

    private void Awake()
    {
        Pool = new ObjectPool<EnemyPool>( //오브젝트 풀 생성
            Create,    //새 오브젝트 생성 함수
            OnGet,     //풀에서 꺼내는 함수
            OnRelease, //풀로 반환시키는 함수
            OnDes,     //파괴하는 함수
            maxSize:10); //pool 최대 슬롯
    }

    // Update is called once per frame
    void Update()
    {
        Timer += Time.deltaTime; //시간측정
        if(Timer >= SpawnTime)   //Timer가 3 이상인지 체크
        {
            Timer = 0; //Timer 값을 0으로 초기화
            Spawn();   //Enemy 오브젝트 생성
        }
    }

    //Pool에 저장된 오브젝트 생성
    private void Spawn()
    {
        Vector3 dir = Player.transform.position - transform.position; //Player 오브젝트 위치 계산
        var enemy = Pool.Get(); //풀에서 오브젝트 가져오기
        enemy.transform.position = transform.position + dir.normalized; //생성 위치 조정
        enemy.ObjDefaultSet(dir); //오브젝트 초기화
    }

    //오브젝트 복사생성
    private EnemyPool Create()
    {
        //EnemyPrefab 오브젝트 복사생성 후 GetComponent로 EnemyPool.cs 가져옴
        EnemyPool enemy = Instantiate(EnemyPrefab).GetComponent<EnemyPool>();  
        enemy.SetManagedPool(Pool); //생성한 오브젝트 풀에 연결
        return enemy; //enemy 반환
    }

    //오브젝트 가시화
    private void OnGet(EnemyPool enemy)
    {
        enemy.gameObject.SetActive(true);
    }

    //오브젝트 비가시화
    private void OnRelease(EnemyPool enemy)
    {
        enemy.gameObject.SetActive(false);
    }

    //오브젝트 파괴
    private void OnDes(EnemyPool enemy)
    {
        Destroy(enemy.gameObject);
    }
}
