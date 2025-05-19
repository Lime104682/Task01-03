/*
===== 벡터 연산 테스트 =====
v1: (1, 2, 3)
v2: (4, 5, 6)
v1 + v2: (5, 7, 9)
v1 - v2: (-3, -3, -3)
v1 * 2: (2, 4, 6)
v1 · v2: 32
v1 × v2: (-3, 6, -3)
길이(v1): 3.74166
정규화(v1): (0.267261, 0.534522, 0.801784)
정규화된 벡터의 길이: 1

===== 타겟 추적 테스트 =====

대상 위치: (5, 0, 5)
방향 벡터: (0.707107, 0, 0.707107)
방향 벡터 길이: 1
거리: 7.07107
타겟 위치: 오른쪽
시야각 내 여부: 시야 내

대상 위치: (-5, 0, 5)
방향 벡터: (-0.707107, 0, 0.707107)
방향 벡터 길이: 1
거리: 7.07107
타겟 위치: 왼쪽
시야각 내 여부: 시야 내

대상 위치: (0, 0, -10)
방향 벡터: (0, 0, -1)
방향 벡터 길이: 1
거리: 10
타겟 위치: 정확히 같은 선상
시야각 내 여부: 시야 밖

대상 위치: (0, 0, 10)
방향 벡터: (0, 0, 1)
방향 벡터 길이: 1
거리: 10
타겟 위치: 정확히 같은 선상
시야각 내 여부: 시야 내

대상 위치: (0, 0, 0)
방향 벡터: (0, 0, 1)
방향 벡터 길이: 1
거리: 0
타겟 위치: 정확히 같은 선상
시야각 내 여부: 시야 내
*/

#include <iostream> //입출력
#include <cmath> //수학공식
#include <vector> //백터
#include "Vector.hpp" //사용자 정의 백터 헤더파일

class Object
{
private:
	Vector3 position; //위치 기준 벡터
	Vector3 forward;  //앞뒤 기준 벡터 
	Vector3 right;	  //좌우 기준 벡터 
	Vector3 up;		  //상하 기준 벡터
	float viewAngle;  //시각 각도 

public:
	// 생성자
	Object(const Vector3& pos, const Vector3& fwd, float angle = 120.0f) //생성자 정의
		: position(pos), forward(fwd.Normalized()), viewAngle(angle) //초기화, forward는 정규화 후 초기화
	{
		Vector3 worldUp(0.0f, 1.0f, 0.0f); //월드의 위쪽 기준 벡터 

		right = forward.Cross(worldUp).Normalized(); //right에 forward와 worlUp의 외적 값을 정규화하여 할당

		up = right.Cross(forward).Normalized(); //up에 right와 forward의 외적 값을 정규화하여 할당
	}

	// TASK 1: 타겟 방향으로의 단위 벡터 계산
	Vector3 GetDirectionToTarget(const Vector3& targetPosition) const
	{
		// 여기에 코드를 작성하세요
		// 힌트: 타겟 위치 - 현재 위치를 계산한 후 정규화
		Vector3 val_task01 = targetPosition - position;
		return val_task01.Normalized();
	}

	// TASK 2: 현재 위치와 타겟 간의 정확한 거리 계산
	float GetDistanceToTarget(const Vector3& targetPosition) const
	{
		// 여기에 코드를 작성하세요
		// 힌트: 두 점 사이의 거리 공식을 사용
		float val_task02 = sqrt(
			pow(targetPosition.x - position.x, 2) +
			pow(targetPosition.y - position.y, 2) +
			pow(targetPosition.z - position.z, 2)
		);
		return val_task02;
	}

	// TASK 3: 타겟이 오브젝트 기준 왼쪽/오른쪽 판별
	// 반환값: 1(오른쪽), -1(왼쪽), 0(정확히 같은 선상)
	int IsTargetOnRight(const Vector3& targetPosition) const
	{
		// 여기에 코드를 작성하세요
		// 힌트: 외적을 사용하여 방향 판별
		Vector3 val_task03 = GetDirectionToTarget(targetPosition);
		Vector3 cross_val = forward.Cross(val_task03);
		if (cross_val.y == 0) return 0;
		else if (cross_val.y > 0) return 1;
		else return -1;
	}

	// TASK 4: 타겟이 시야각 내에 있는지 판별
	bool IsTargetInViewAngle(const Vector3& targetPosition) const
	{
		// 여기에 코드를 작성하세요
		// 힌트: 내적을 사용하여 각도 계산
		Vector3 val_task04 = GetDirectionToTarget(targetPosition);
		float dot_val = forward.Dot(val_task04);
		float angle = acos(dot_val) * (180.0f / 3.14);
		return angle <= (viewAngle * 0.5f);
	}

	const Vector3& GetPosition() const { return position; }

	const Vector3& GetForward() const { return forward; }

	void SetPosition(const Vector3& pos) { position = pos; } //외부에서 position 접근 가능

	//외부에서 forward 접근 가능
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
		std::cout << "v1: (" << v1.x << ", " << v1.y << ", " << v1.z << ")" << std::endl;
		std::cout << "v2: (" << v2.x << ", " << v2.y << ", " << v2.z << ")" << std::endl;
	}

	Vector3 sum = v1 + v2; //sum에 v1과 v2의 덧셈 값을 대입한다. sum = v1.operator+(v2);
	Vector3 diff = v1 - v2; //diff에 v1과 v2의 뺄셈 값을 대입한다. diff = v1.operator-(v2);
	Vector3 scaled = v1 * 2.0f; //곱셈(스칼라 곱)의 수식이 왜 v1 * 2.0f인지 모르겠습니다. 2.0f * v1; 도 가능

	// TASK 2 : 벡터의 덧셈, 뺄셈, 곱셈(스칼라 곱)을 출력
	{
		/*
		* TASK 2 지시문 부분 해석 및 문제 및 풀이
		* 해석
		* : 주어진 벡터 v1, v2의 연산(덧셈, 뺄셈, 곱셈(스칼라 곱)) 출력
		* 문제
		* : 덧셈과 뺄셈은 기본적으로 제시된 sum과 diff을 출력하기만 하면 되는데 지시문의 곱셈(스칼라 곱)에 해당되는 scaled는 지시문의 요구사항과 수식이 틀림,
		문제는 출력예시물에 표시된 v1 * 2의 값은 scaled 벡터 값을 요구함
		* 풀이1 - 출력예시물에 표시된 것에 따른다.
		* : 다른 벡터 계산들과 마찬가지로 대응하는 벡터(scaled) 출력
		* 풀이2 - 지시문에 따른다.
		* : 지시문에 알맞는 값(두 벡터의 곱셈(스칼라 곱) 즉 두 벡터(v.1 , v.2)의 내적 값)을 구하고 출력한다.
		*/

		std::cout << "v1 + v2: (" << sum.x << ", " << sum.y << ", " << sum.z << ")" << std::endl;
		std::cout << "v1 - v2: (" << diff.x << ", " << diff.y << ", " << diff.z << ")" << std::endl;

		//풀이1
		std::cout << "v1 * 2: (" << scaled.x << ", " << scaled.y << ", " << scaled.z << ")" << std::endl;

		//풀이2
		float dot02 = v1.Dot(v2);
		std::cout << "곱셈(스칼라 곱): " << dot02 << std::endl;
	}

	float dot = v1.Dot(v2); //dot에 v1과 v2의 내적값을 대입한다.
	Vector3 cross = v1.Cross(v2); //cross에 v1과 v2의 외적값을 대입한다.
	float length = v1.Length(); //length에 v1의 길이를 대입한다

	// TASK 3 : 벡터의 외적, 내적, 길이를 출력
	{
		std::cout << "내적(v1 · v2): " << dot << std::endl;
		std::cout << "외적(v1 × v2): (" << cross.x << ", " << cross.y << ", " << cross.z << ")" << std::endl;
		std::cout << "길이(v1): " << length << std::endl;
	}

	Vector3 normalized = v1.Normalized(); //normalized에 v1의 정규화 값을 대입한다.

	// TASK 4 : 정규화된 벡터와 길이를 출력
	{
		std::cout << "정규화(v1) : (" << normalized.x << ", " << normalized.y << ", " << normalized.z << ")" << std::endl;
		std::cout << "정규화된 벡터의 길이 : " << normalized.Length() << std::endl;
	}
}

void TestTargetTracking()
{
	std::cout << "\n===== 타겟 추적 테스트 =====" << std::endl;

	/*
	* obj 객체 로컬 좌표계(Y-UP ?손 좌표계) 값
	* position 값 : (0,0,0)
	* forward(Z축) 값 : (0,0,1)
	* right(X축) 값 : (-1,0,0)
	* up(Y축) 값 : (0,1,0)
	* viewAngle 값 : 120.f
	*/
	Object obj(Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 1.0f)); //오브젝트 생성

	//목표물 벡터값
	Vector3 targets[] =
	{
		Vector3(5.0f, 0.0f, 5.0f),
		Vector3(-5.0f, 0.0f, 5.0f),
		Vector3(0.0f, 0.0f, -10.0f),
		Vector3(0.0f, 0.0f, 10.0f),
		Vector3(0.0f, 0.0f, 0.0f)
	};

	for (const auto& target : targets) //targets의 벡터들 1번씩 실행
	{
		Vector3 task01 = obj.GetDirectionToTarget(target);
		float task02 = obj.GetDistanceToTarget(target);
		int task03 = obj.IsTargetOnRight(target);
		bool task04 = obj.IsTargetInViewAngle(target);

		std::cout << "\n대상 위치: (" << target.x << ", " << target.y << ", " << target.z << ")" << std::endl;

		// TASK 1: 방향 벡터 계산 테스트
		// 여기에 코드를 추가하세요
		std::cout << "방향 벡터 : (" << task01.x << ", " << task01.y << ", " << task01.z << ")" << std::endl;
		std::cout << "방향 벡터 길이 : " << task01.Length() << std::endl;

		// TASK 2: 거리 계산 테스트
		// 여기에 코드를 추가하세요
		std::cout << "거리 : " << task02 << std::endl;

		// TASK 3: 왼쪽/오른쪽 판별 테스트
		// 여기에 코드를 추가하세요
		if (task03 == 0) std::cout << "타겟 위치: 정확히 같은 선상" << std::endl;
		else if (task03 == 1) std::cout << "타겟 위치: 오른쪽" << std::endl;
		else  std::cout << "타겟 위치: 왼쪽" << std::endl;

		// TASK 4: 시야각 판별 테스트
		// 여기에 코드를 추가하세요
		if (task04)	std::cout << "시야각 내 여부 : 시야 내" << std::endl;
		else std::cout << "시야각 내 여부 : 시야 밖" << std::endl;
	}
}

int main()
{
	TestVectorOperations(); //벡터 연산 테스트 함수

	TestTargetTracking(); //타겟 추적 테스트 함수

	return 0;
}