using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Pool;


/*
 * ������Ʈ Ǯ��
 * https://youtu.be/JxP-kqstMAY?si=WC9Y_MHl8eHbajSq
 * 
 * ����Ƽ ���콺 �̵�
 * https://www.ibatstudio.com/%EC%9C%A0%EB%8B%88%ED%8B%B0-%EB%A7%88%EC%9A%B0%EC%8A%A4-%ED%81%B4%EB%A6%AD-%EC%9D%B4%EB%8F%99-%EB%B0%8F-%ED%9A%8C%EC%A0%84-%EB%B0%A9%EB%B2%95/
 *
 * �˻���
 * ObjectPool<EnemyPool>()
 * ����Ƽ ���� ������ƮǮ��
 */

public class EnemyPool : MonoBehaviour
{
    private Vector3 Direction; //�̵� ����

    [SerializeField]
    private float Speed = 1f; //�̵� �ӵ�

    private IObjectPool<EnemyPool> ManagedPool; //Enemy ������Ʈ Ǯ ����

    //�Ű������� ���� ������Ʈ Ǯ�� ����
    public void SetManagedPool(IObjectPool<EnemyPool> pool)
    {
        ManagedPool = pool;
    }

    // Update is called once per frame
    void Update()
    {
        transform.Translate(Direction * Time.deltaTime * Speed); //�̵�
    }

    //�浹 ���� �Լ�
    private void OnTriggerEnter(Collider other)
    {
        //Player Ȥ�� Ground Tag�� �浹������ Pool�� ��ȯ
        if (other.CompareTag("Player") || other.CompareTag("Ground"))
        {
            DestroyMonster(); // Ǯ�� ��ȯ

            //Player Tag�� ���� ������Ʈ�� �浹�� Game Over ���
            if (other.CompareTag("Player")) print("Game Over");
        }
    }

    //Ǯ���� ������Ʈ�� ���� �� ȣ���ϴ� �ʱ�ȭ �Լ�
    public void ObjDefaultSet(Vector3 dir)
    {
        Direction = dir.normalized;     //���� ����ȭ
        gameObject.SetActive(true);     //������Ʈ ����ȭ
        Invoke("DestroyMonster", 5.0f); //5�� �� �ڵ� ��ȯ
    }

    //������ ������Ʈ�� Pool�� ��ȯ��Ű�� �Լ�
    public void DestroyMonster()
    {
        if (gameObject.activeSelf) //���� ����ȭ �Ǿ��ִٸ�
        {
            CancelInvoke(); //Invoke("DestroyMonster", 5.0f); ���
            ManagedPool.Release(this); //Ǯ�� ��ȯ
        }
    }
}
