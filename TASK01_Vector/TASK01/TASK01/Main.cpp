/*
===== ���� ���� �׽�Ʈ =====
v1: (1, 2, 3)
v2: (4, 5, 6)
v1 + v2: (5, 7, 9)
v1 - v2: (-3, -3, -3)
v1 * 2: (2, 4, 6)
v1 �� v2: 32
v1 �� v2: (-3, 6, -3)
����(v1): 3.74166
����ȭ(v1): (0.267261, 0.534522, 0.801784)
����ȭ�� ������ ����: 1

===== Ÿ�� ���� �׽�Ʈ =====

��� ��ġ: (5, 0, 5)
���� ����: (0.707107, 0, 0.707107)
���� ���� ����: 1
�Ÿ�: 7.07107
Ÿ�� ��ġ: ������
�þ߰� �� ����: �þ� ��

��� ��ġ: (-5, 0, 5)
���� ����: (-0.707107, 0, 0.707107)
���� ���� ����: 1
�Ÿ�: 7.07107
Ÿ�� ��ġ: ����
�þ߰� �� ����: �þ� ��

��� ��ġ: (0, 0, -10)
���� ����: (0, 0, -1)
���� ���� ����: 1
�Ÿ�: 10
Ÿ�� ��ġ: ��Ȯ�� ���� ����
�þ߰� �� ����: �þ� ��

��� ��ġ: (0, 0, 10)
���� ����: (0, 0, 1)
���� ���� ����: 1
�Ÿ�: 10
Ÿ�� ��ġ: ��Ȯ�� ���� ����
�þ߰� �� ����: �þ� ��

��� ��ġ: (0, 0, 0)
���� ����: (0, 0, 1)
���� ���� ����: 1
�Ÿ�: 0
Ÿ�� ��ġ: ��Ȯ�� ���� ����
�þ߰� �� ����: �þ� ��
*/

#include <iostream> //�����
#include <cmath> //���а���
#include <vector> //����
#include "Vector.hpp" //����� ���� ���� �������

class Object
{
private:
	Vector3 position; //��ġ ���� ����
	Vector3 forward;  //�յ� ���� ���� 
	Vector3 right;	  //�¿� ���� ���� 
	Vector3 up;		  //���� ���� ����
	float viewAngle;  //�ð� ���� 

public:
	// ������
	Object(const Vector3& pos, const Vector3& fwd, float angle = 120.0f) //������ ����
		: position(pos), forward(fwd.Normalized()), viewAngle(angle) //�ʱ�ȭ, forward�� ����ȭ �� �ʱ�ȭ
	{
		Vector3 worldUp(0.0f, 1.0f, 0.0f); //������ ���� ���� ���� 

		right = forward.Cross(worldUp).Normalized(); //right�� forward�� worlUp�� ���� ���� ����ȭ�Ͽ� �Ҵ�

		up = right.Cross(forward).Normalized(); //up�� right�� forward�� ���� ���� ����ȭ�Ͽ� �Ҵ�
	}

	// TASK 1: Ÿ�� ���������� ���� ���� ���
	Vector3 GetDirectionToTarget(const Vector3& targetPosition) const
	{
		// ���⿡ �ڵ带 �ۼ��ϼ���
		// ��Ʈ: Ÿ�� ��ġ - ���� ��ġ�� ����� �� ����ȭ
		Vector3 val_task01 = targetPosition - position;
		return val_task01.Normalized();
	}

	// TASK 2: ���� ��ġ�� Ÿ�� ���� ��Ȯ�� �Ÿ� ���
	float GetDistanceToTarget(const Vector3& targetPosition) const
	{
		// ���⿡ �ڵ带 �ۼ��ϼ���
		// ��Ʈ: �� �� ������ �Ÿ� ������ ���
		float val_task02 = sqrt(
			pow(targetPosition.x - position.x, 2) +
			pow(targetPosition.y - position.y, 2) +
			pow(targetPosition.z - position.z, 2)
		);
		return val_task02;
	}

	// TASK 3: Ÿ���� ������Ʈ ���� ����/������ �Ǻ�
	// ��ȯ��: 1(������), -1(����), 0(��Ȯ�� ���� ����)
	int IsTargetOnRight(const Vector3& targetPosition) const
	{
		// ���⿡ �ڵ带 �ۼ��ϼ���
		// ��Ʈ: ������ ����Ͽ� ���� �Ǻ�
		Vector3 val_task03 = GetDirectionToTarget(targetPosition);
		Vector3 cross_val = forward.Cross(val_task03);
		if (cross_val.y == 0) return 0;
		else if (cross_val.y > 0) return 1;
		else return -1;
	}

	// TASK 4: Ÿ���� �þ߰� ���� �ִ��� �Ǻ�
	bool IsTargetInViewAngle(const Vector3& targetPosition) const
	{
		// ���⿡ �ڵ带 �ۼ��ϼ���
		// ��Ʈ: ������ ����Ͽ� ���� ���
		Vector3 val_task04 = GetDirectionToTarget(targetPosition);
		float dot_val = forward.Dot(val_task04);
		float angle = acos(dot_val) * (180.0f / 3.14);
		return angle <= (viewAngle * 0.5f);
	}

	const Vector3& GetPosition() const { return position; }

	const Vector3& GetForward() const { return forward; }

	void SetPosition(const Vector3& pos) { position = pos; } //�ܺο��� position ���� ����

	//�ܺο��� forward ���� ����
	void SetForward(const Vector3& fwd)
	{
		forward = fwd.Normalized();

		Vector3 worldUp(0.0f, 1.0f, 0.0f);
		right = forward.Cross(worldUp).Normalized();
		up = right.Cross(forward).Normalized();
	} 
};

void TestVectorOperations()
{
	std::cout << "===== ���� ���� �׽�Ʈ =====" << std::endl;

	Vector3 v1(1.0f, 2.0f, 3.0f);
	Vector3 v2(4.0f, 5.0f, 6.0f);

	// TASK 1 : ���� ���
	{
		std::cout << "v1: (" << v1.x << ", " << v1.y << ", " << v1.z << ")" << std::endl;
		std::cout << "v2: (" << v2.x << ", " << v2.y << ", " << v2.z << ")" << std::endl;
	}

	Vector3 sum = v1 + v2; //sum�� v1�� v2�� ���� ���� �����Ѵ�. sum = v1.operator+(v2);
	Vector3 diff = v1 - v2; //diff�� v1�� v2�� ���� ���� �����Ѵ�. diff = v1.operator-(v2);
	Vector3 scaled = v1 * 2.0f; //����(��Į�� ��)�� ������ �� v1 * 2.0f���� �𸣰ڽ��ϴ�. 2.0f * v1; �� ����

	// TASK 2 : ������ ����, ����, ����(��Į�� ��)�� ���
	{
		/*
		* TASK 2 ���ù� �κ� �ؼ� �� ���� �� Ǯ��
		* �ؼ�
		* : �־��� ���� v1, v2�� ����(����, ����, ����(��Į�� ��)) ���
		* ����
		* : ������ ������ �⺻������ ���õ� sum�� diff�� ����ϱ⸸ �ϸ� �Ǵµ� ���ù��� ����(��Į�� ��)�� �ش�Ǵ� scaled�� ���ù��� �䱸���װ� ������ Ʋ��,
		������ ��¿��ù��� ǥ�õ� v1 * 2�� ���� scaled ���� ���� �䱸��
		* Ǯ��1 - ��¿��ù��� ǥ�õ� �Ϳ� ������.
		* : �ٸ� ���� ����� ���������� �����ϴ� ����(scaled) ���
		* Ǯ��2 - ���ù��� ������.
		* : ���ù��� �˸´� ��(�� ������ ����(��Į�� ��) �� �� ����(v.1 , v.2)�� ���� ��)�� ���ϰ� ����Ѵ�.
		*/

		std::cout << "v1 + v2: (" << sum.x << ", " << sum.y << ", " << sum.z << ")" << std::endl;
		std::cout << "v1 - v2: (" << diff.x << ", " << diff.y << ", " << diff.z << ")" << std::endl;

		//Ǯ��1
		std::cout << "v1 * 2: (" << scaled.x << ", " << scaled.y << ", " << scaled.z << ")" << std::endl;

		//Ǯ��2
		float dot02 = v1.Dot(v2);
		std::cout << "����(��Į�� ��): " << dot02 << std::endl;
	}

	float dot = v1.Dot(v2); //dot�� v1�� v2�� �������� �����Ѵ�.
	Vector3 cross = v1.Cross(v2); //cross�� v1�� v2�� �������� �����Ѵ�.
	float length = v1.Length(); //length�� v1�� ���̸� �����Ѵ�

	// TASK 3 : ������ ����, ����, ���̸� ���
	{
		std::cout << "����(v1 �� v2): " << dot << std::endl;
		std::cout << "����(v1 �� v2): (" << cross.x << ", " << cross.y << ", " << cross.z << ")" << std::endl;
		std::cout << "����(v1): " << length << std::endl;
	}

	Vector3 normalized = v1.Normalized(); //normalized�� v1�� ����ȭ ���� �����Ѵ�.

	// TASK 4 : ����ȭ�� ���Ϳ� ���̸� ���
	{
		std::cout << "����ȭ(v1) : (" << normalized.x << ", " << normalized.y << ", " << normalized.z << ")" << std::endl;
		std::cout << "����ȭ�� ������ ���� : " << normalized.Length() << std::endl;
	}
}

void TestTargetTracking()
{
	std::cout << "\n===== Ÿ�� ���� �׽�Ʈ =====" << std::endl;

	/*
	* obj ��ü ���� ��ǥ��(Y-UP ?�� ��ǥ��) ��
	* position �� : (0,0,0)
	* forward(Z��) �� : (0,0,1)
	* right(X��) �� : (-1,0,0)
	* up(Y��) �� : (0,1,0)
	* viewAngle �� : 120.f
	*/
	Object obj(Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 1.0f)); //������Ʈ ����

	//��ǥ�� ���Ͱ�
	Vector3 targets[] =
	{
		Vector3(5.0f, 0.0f, 5.0f),
		Vector3(-5.0f, 0.0f, 5.0f),
		Vector3(0.0f, 0.0f, -10.0f),
		Vector3(0.0f, 0.0f, 10.0f),
		Vector3(0.0f, 0.0f, 0.0f)
	};

	for (const auto& target : targets) //targets�� ���͵� 1���� ����
	{
		Vector3 task01 = obj.GetDirectionToTarget(target);
		float task02 = obj.GetDistanceToTarget(target);
		int task03 = obj.IsTargetOnRight(target);
		bool task04 = obj.IsTargetInViewAngle(target);

		std::cout << "\n��� ��ġ: (" << target.x << ", " << target.y << ", " << target.z << ")" << std::endl;

		// TASK 1: ���� ���� ��� �׽�Ʈ
		// ���⿡ �ڵ带 �߰��ϼ���
		std::cout << "���� ���� : (" << task01.x << ", " << task01.y << ", " << task01.z << ")" << std::endl;
		std::cout << "���� ���� ���� : " << task01.Length() << std::endl;

		// TASK 2: �Ÿ� ��� �׽�Ʈ
		// ���⿡ �ڵ带 �߰��ϼ���
		std::cout << "�Ÿ� : " << task02 << std::endl;

		// TASK 3: ����/������ �Ǻ� �׽�Ʈ
		// ���⿡ �ڵ带 �߰��ϼ���
		if (task03 == 0) std::cout << "Ÿ�� ��ġ: ��Ȯ�� ���� ����" << std::endl;
		else if (task03 == 1) std::cout << "Ÿ�� ��ġ: ������" << std::endl;
		else  std::cout << "Ÿ�� ��ġ: ����" << std::endl;

		// TASK 4: �þ߰� �Ǻ� �׽�Ʈ
		// ���⿡ �ڵ带 �߰��ϼ���
		if (task04)	std::cout << "�þ߰� �� ���� : �þ� ��" << std::endl;
		else std::cout << "�þ߰� �� ���� : �þ� ��" << std::endl;
	}
}

int main()
{
	TestVectorOperations(); //���� ���� �׽�Ʈ �Լ�

	TestTargetTracking(); //Ÿ�� ���� �׽�Ʈ �Լ�

	return 0;
}