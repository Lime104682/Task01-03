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
	// 생성자
	Object(const Vector3& pos, const Vector3& fwd, float angle = 120.0f)
		: position(pos), forward(fwd.Normalized()), viewAngle(angle)
	{
		Vector3 worldUp(0.0f, 1.0f, 0.0f);

		right = forward.Cross(worldUp).Normalized();

		up = right.Cross(forward).Normalized();
	}

	// TASK 1: 타겟 방향으로의 단위 벡터 계산
	Vector3 GetDirectionToTarget(const Vector3& targetPosition) const
	{
		// 여기에 코드를 작성하세요
		// 힌트: 타겟 위치 - 현재 위치를 계산한 후 정규화
	}

	// TASK 2: 현재 위치와 타겟 간의 정확한 거리 계산
	float GetDistanceToTarget(const Vector3& targetPosition) const
	{
		// 여기에 코드를 작성하세요
		// 힌트: 두 점 사이의 거리 공식을 사용
	}

	// TASK 3: 타겟이 오브젝트 기준 왼쪽/오른쪽 판별
	// 반환값: 1(오른쪽), -1(왼쪽), 0(정확히 같은 선상)
	int IsTargetOnRight(const Vector3& targetPosition) const
	{
		// 여기에 코드를 작성하세요
		// 힌트: 외적을 사용하여 방향 판별
	}

	// TASK 4: 타겟이 시야각 내에 있는지 판별
	bool IsTargetInViewAngle(const Vector3& targetPosition) const
	{
		// 여기에 코드를 작성하세요
		// 힌트: 내적을 사용하여 각도 계산
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
	std::cout << "===== 벡터 연산 테스트 =====" << std::endl;

	Vector3 v1(1.0f, 2.0f, 3.0f);
	Vector3 v2(4.0f, 5.0f, 6.0f);

	// TASK 1 : 벡터 출력
	{

	}

	Vector3 sum = v1 + v2;
	Vector3 diff = v1 - v2;
	Vector3 scaled = v1 * 2.0f;

	// TASK 2 : 벡터의 덧셈, 뺄셈, 곱셈(스칼라 곱)을 출력
	{

	}

	float dot = v1.Dot(v2);
	Vector3 cross = v1.Cross(v2);
	float length = v1.Length();

	// TASK 3 : 벡터의 외적, 내적, 길이를 출력
	{

	}

	Vector3 normalized = v1.Normalized();

	// TASK 4 : 정규화된 벡터와 길이를 출력
	{

	}
}

void TestTargetTracking()
{
	std::cout << "\n===== 타겟 추적 테스트 =====" << std::endl;

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
		std::cout << "\n대상 위치: (" << target.x << ", " << target.y << ", " << target.z << ")" << std::endl;

		// TASK 1: 방향 벡터 계산 테스트
		// 여기에 코드를 추가하세요

		// TASK 2: 거리 계산 테스트
		// 여기에 코드를 추가하세요

		// TASK 3: 왼쪽/오른쪽 판별 테스트
		// 여기에 코드를 추가하세요

		// TASK 4: 시야각 판별 테스트
		// 여기에 코드를 추가하세요
	}
}

int main()
{
	TestVectorOperations();

	TestTargetTracking();

	return 0;
}