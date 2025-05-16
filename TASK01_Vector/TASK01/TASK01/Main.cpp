#include <iostream>
#include <cmath>
#include <vector>
#include "Vector.hpp"

class Object
{
private:
	Vector3 position;
	Vector3 forward;
	Vector3 right;
	Vector3 up;
	float viewAngle;

public:
	// ������
	Object(const Vector3& pos, const Vector3& fwd, float angle = 120.0f)
		: position(pos), forward(fwd.Normalized()), viewAngle(angle)
	{
		Vector3 worldUp(0.0f, 1.0f, 0.0f);

		right = forward.Cross(worldUp).Normalized();

		up = right.Cross(forward).Normalized();
	}

	// TASK 1: Ÿ�� ���������� ���� ���� ���
	Vector3 GetDirectionToTarget(const Vector3& targetPosition) const
	{
		// ���⿡ �ڵ带 �ۼ��ϼ���
		// ��Ʈ: Ÿ�� ��ġ - ���� ��ġ�� ����� �� ����ȭ
	}

	// TASK 2: ���� ��ġ�� Ÿ�� ���� ��Ȯ�� �Ÿ� ���
	float GetDistanceToTarget(const Vector3& targetPosition) const
	{
		// ���⿡ �ڵ带 �ۼ��ϼ���
		// ��Ʈ: �� �� ������ �Ÿ� ������ ���
	}

	// TASK 3: Ÿ���� ������Ʈ ���� ����/������ �Ǻ�
	// ��ȯ��: 1(������), -1(����), 0(��Ȯ�� ���� ����)
	int IsTargetOnRight(const Vector3& targetPosition) const
	{
		// ���⿡ �ڵ带 �ۼ��ϼ���
		// ��Ʈ: ������ ����Ͽ� ���� �Ǻ�
	}

	// TASK 4: Ÿ���� �þ߰� ���� �ִ��� �Ǻ�
	bool IsTargetInViewAngle(const Vector3& targetPosition) const
	{
		// ���⿡ �ڵ带 �ۼ��ϼ���
		// ��Ʈ: ������ ����Ͽ� ���� ���
	}

	const Vector3& GetPosition() const { return position; }

	const Vector3& GetForward() const { return forward; }

	void SetPosition(const Vector3& pos) { position = pos; }

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

	}

	Vector3 sum = v1 + v2;
	Vector3 diff = v1 - v2;
	Vector3 scaled = v1 * 2.0f;

	// TASK 2 : ������ ����, ����, ����(��Į�� ��)�� ���
	{

	}

	float dot = v1.Dot(v2);
	Vector3 cross = v1.Cross(v2);
	float length = v1.Length();

	// TASK 3 : ������ ����, ����, ���̸� ���
	{

	}

	Vector3 normalized = v1.Normalized();

	// TASK 4 : ����ȭ�� ���Ϳ� ���̸� ���
	{

	}
}

void TestTargetTracking()
{
	std::cout << "\n===== Ÿ�� ���� �׽�Ʈ =====" << std::endl;

	Object obj(Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 1.0f));

	Vector3 targets[] =
	{
		Vector3(5.0f, 0.0f, 5.0f),
		Vector3(-5.0f, 0.0f, 5.0f),
		Vector3(0.0f, 0.0f, -10.0f),
		Vector3(0.0f, 0.0f, 10.0f),
		Vector3(0.0f, 0.0f, 0.0f)
	};

	for (const auto& target : targets)
	{
		std::cout << "\n��� ��ġ: (" << target.x << ", " << target.y << ", " << target.z << ")" << std::endl;

		// TASK 1: ���� ���� ��� �׽�Ʈ
		// ���⿡ �ڵ带 �߰��ϼ���

		// TASK 2: �Ÿ� ��� �׽�Ʈ
		// ���⿡ �ڵ带 �߰��ϼ���

		// TASK 3: ����/������ �Ǻ� �׽�Ʈ
		// ���⿡ �ڵ带 �߰��ϼ���

		// TASK 4: �þ߰� �Ǻ� �׽�Ʈ
		// ���⿡ �ڵ带 �߰��ϼ���
	}
}

int main()
{
	TestVectorOperations();

	TestTargetTracking();

	return 0;
}