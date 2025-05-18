using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Pool;


/*
 * 오브젝트 풀링
 * https://youtu.be/JxP-kqstMAY?si=WC9Y_MHl8eHbajSq
 * 
 * 유니티 마우스 이동
 * https://www.ibatstudio.com/%EC%9C%A0%EB%8B%88%ED%8B%B0-%EB%A7%88%EC%9A%B0%EC%8A%A4-%ED%81%B4%EB%A6%AD-%EC%9D%B4%EB%8F%99-%EB%B0%8F-%ED%9A%8C%EC%A0%84-%EB%B0%A9%EB%B2%95/
 *
 * 검색어
 * ObjectPool<EnemyPool>()
 * 유니티 공식 오브젝트풀링
 */

public class EnemyPool : MonoBehaviour
{
    private Vector3 Direction; //이동 벡터

    [SerializeField]
    private float Speed = 1f; //이동 속도

    private IObjectPool<EnemyPool> ManagedPool; //Enemy 오브젝트 풀 관리

    //매개변수로 받은 오브젝트 풀을 연결
    public void SetManagedPool(IObjectPool<EnemyPool> pool)
    {
        ManagedPool = pool;
    }

    // Update is called once per frame
    void Update()
    {
        transform.Translate(Direction * Time.deltaTime * Speed); //이동
    }

    //충돌 감지 함수
    private void OnTriggerEnter(Collider other)
    {
        //Player 혹은 Ground Tag와 충돌했으면 Pool로 반환
        if (other.CompareTag("Player") || other.CompareTag("Ground"))
        {
            DestroyMonster(); // 풀로 반환

            //Player Tag를 가진 오브젝트와 충돌시 Game Over 출력
            if (other.CompareTag("Player")) print("Game Over");
        }
    }

    //풀에서 오브젝트를 꺼낼 때 호출하는 초기화 함수
    public void ObjDefaultSet(Vector3 dir)
    {
        Direction = dir.normalized;     //방향 정규화
        gameObject.SetActive(true);     //오브젝트 가시화
        Invoke("DestroyMonster", 5.0f); //5초 후 자동 반환
    }

    //생성된 오브젝트를 Pool로 반환시키는 함수
    public void DestroyMonster()
    {
        if (gameObject.activeSelf) //씬에 가시화 되어있다면
        {
            CancelInvoke(); //Invoke("DestroyMonster", 5.0f); 취소
            ManagedPool.Release(this); //풀로 반환
        }
    }
}
