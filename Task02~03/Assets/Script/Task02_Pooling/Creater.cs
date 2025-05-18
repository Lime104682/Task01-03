using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Pool;

public class Creater : MonoBehaviour
{

    [SerializeField]
    private GameObject EnemyPrefab; //Enemy ������ ������Ʈ ����

    [SerializeField]
    private GameObject Player; //Player ������Ʈ ����

    private IObjectPool<EnemyPool> Pool; //EnemyPool ��ü�� ������ ������Ʈ Ǯ
    private float SpawnTime = 3.0f; //Enemy ���� �ֱ�
    public float Timer = 0; //�ð� ����

    private void Awake()
    {
        Pool = new ObjectPool<EnemyPool>( //������Ʈ Ǯ ����
            Create,    //�� ������Ʈ ���� �Լ�
            OnGet,     //Ǯ���� ������ �Լ�
            OnRelease, //Ǯ�� ��ȯ��Ű�� �Լ�
            OnDes,     //�ı��ϴ� �Լ�
            maxSize:10); //pool �ִ� ����
    }

    // Update is called once per frame
    void Update()
    {
        Timer += Time.deltaTime; //�ð�����
        if(Timer >= SpawnTime)   //Timer�� 3 �̻����� üũ
        {
            Timer = 0; //Timer ���� 0���� �ʱ�ȭ
            Spawn();   //Enemy ������Ʈ ����
        }
    }

    //Pool�� ����� ������Ʈ ����
    private void Spawn()
    {
        Vector3 dir = Player.transform.position - transform.position; //Player ������Ʈ ��ġ ���
        var enemy = Pool.Get(); //Ǯ���� ������Ʈ ��������
        enemy.transform.position = transform.position + dir.normalized; //���� ��ġ ����
        enemy.ObjDefaultSet(dir); //������Ʈ �ʱ�ȭ
    }

    //������Ʈ �������
    private EnemyPool Create()
    {
        //EnemyPrefab ������Ʈ ������� �� GetComponent�� EnemyPool.cs ������
        EnemyPool enemy = Instantiate(EnemyPrefab).GetComponent<EnemyPool>();  
        enemy.SetManagedPool(Pool); //������ ������Ʈ Ǯ�� ����
        return enemy; //enemy ��ȯ
    }

    //������Ʈ ����ȭ
    private void OnGet(EnemyPool enemy)
    {
        enemy.gameObject.SetActive(true);
    }

    //������Ʈ �񰡽�ȭ
    private void OnRelease(EnemyPool enemy)
    {
        enemy.gameObject.SetActive(false);
    }

    //������Ʈ �ı�
    private void OnDes(EnemyPool enemy)
    {
        Destroy(enemy.gameObject);
    }
}
