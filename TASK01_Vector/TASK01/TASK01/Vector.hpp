#pragma once //중복회피

#include <cmath> //수학공식

struct Vector3 //Vector3의 구조체
{
	float x; //Vector3의 x값 담당 변수
	float y; //Vector3의 y값 담당 변수
	float z; //Vector3의 z값 담당 변수

	//생성시 각 값들을 0으로 초기화
	Vector3() : x(0.0f), y(0.0f), z(0.0f) {} 

	//매개변수 생성시 각 값들의 값 부여 생성
	Vector3(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z)
	{
	}

	//복사생성
	Vector3(const Vector3& other)
		: x(other.x), y(other.y), z(other.z)
	{
	}

	/*벡터에 매개변수로 온 벡터값을 각각 대입하는 기능
	* 예시
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	* Vector3 v2(4.0f, 5.0f, 6.0f);
	*
	* v1.operator=(v2);
	*
	* 만약 (v1.operator=(v2)).x 출력시 4 출력됨
	*/
	Vector3& operator=(const Vector3& rhs)
	{
		x = rhs.x; //v1의 벡터 x값에 v2의 벡터 x값을 대입
		y = rhs.y; //v1의 벡터 y값에 v2의 벡터 y값을 대입
		z = rhs.z; //v1의 벡터 z값에 v2의 벡터 z값을 대입
		return *this; //벡터 값 반환
	}

	/*벡터에 매개변수로 온 벡터값을 각각 더하는 기능
	* 예시
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	* Vector3 v2(4.0f, 5.0f, 6.0f);
	*
	* v1.operator+(v2);
	*
	* 만약 (v1.operator+(v2)).x 출력시 5 출력됨
	*/
	Vector3 operator+(const Vector3& rhs) const
	{
		//각 벡터값들 더해서 반환
		return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
	}

	/*벡터에 매개변수로 온 벡터값을 각각 빼는 기능
	* 예시
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	* Vector3 v2(4.0f, 5.0f, 6.0f);
	*
	* v1.operator-(v2);
	*
	* 만약 (v1.operator-(v2)).x 출력시 -3 출력됨
	*/
	Vector3 operator-(const Vector3& rhs) const
	{
		//각 벡터값들 빼서 반환
		return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
	}

	/*벡터에 스칼라 값을 각각 곱하는 크기 변환 기능
	* 예시
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	* float sca = 32.0f;
	*
	* v1.operator*(sca);
	*
	* 만약 (v1.operator*(sca)).x 출력시 32 출력됨
	*/
	Vector3 operator*(float scalar) const
	{
		//각 벡터값들 scalar값 만큼 곱셈 크기변환 후 반환
		return Vector3(x * scalar, y * scalar, z * scalar);
	}

	/*벡터에 스칼라 값을 각각 나누는 크기 변환 기능
	* 예시
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	* float sca = 2.0f;
	*
	* v1.operator/(sca);
	*
	* 만약 (v1.operator/(sca)).x 출력시 0.5 출력됨
	*/
	Vector3 operator/(float scalar) const
	{
		if (scalar != 0.0f)
		{
			//각 벡터값들 scalar값 만큼 나눗셈 크기변환 후 반환
			return Vector3(x / scalar, y / scalar, z / scalar);
		}
		//그냥 본인 벡터 값 반환
		return *this; // Return without change if division by zero
	}

	/*벡터에 매개변수로 온 벡터값을 각각 덧셈대입 하는 기능
	* 예시
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	* Vector3 v2(4.0f, 5.0f, 6.0f);
	*
	* v1.operator+=(v2);
	*
	* 만약 (v1.operator+=(v2)).x 출력시 5 출력됨
	*/
	Vector3& operator+=(const Vector3& rhs)
	{
		x += rhs.x; //v1의 벡터 x값에 v2의 벡터 x값을 덧셈대입
		y += rhs.y; //v1의 벡터 y값에 v2의 벡터 y값을 덧셈대입
		z += rhs.z; //v1의 벡터 z값에 v2의 벡터 z값을 덧셈대입
		return *this; //벡터 값 반환
	}

	/*벡터에 매개변수로 온 벡터값을 각각 뺄셈대입 기능
	* 예시
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	* Vector3 v2(4.0f, 5.0f, 6.0f);
	*
	* v1.operator-=(v2);
	*
	* 만약 (v1.operator-=(v2)).x 출력시 -3 출력됨
	*/
	Vector3& operator-=(const Vector3& rhs)
	{
		x -= rhs.x; //v1의 벡터 x값에 v2의 벡터 x값을 뺄셈대입
		y -= rhs.y; //v1의 벡터 y값에 v2의 벡터 y값을 뻴셈대입
		z -= rhs.z; //v1의 벡터 z값에 v2의 벡터 z값을 뺄셈대입
		return *this; //벡터 값 반환
	}

	/*벡터와 매개변수로 온 벡터의 내적 계산 기능
	* 예시
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	* Vector3 v2(4.0f, 5.0f, 6.0f);
	*
	* float dot = v1.Dot(v2);
	*
	* 만약 dot 출력시 32 출력됨
	*/
	float Dot(const Vector3& rhs) const
	{
		//내적 계산 값 반환
		return x * rhs.x + y * rhs.y + z * rhs.z;
	}

	/*벡터와 매개변수로 온 벡터의 외적 계산 기능
	* 예시
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	* Vector3 v2(4.0f, 5.0f, 6.0f);
	*
	* Vector3 cross = v1.Cross(v2);
	*
	* 만약 cross.x 출력시 -3 출력됨
	*/
	Vector3 Cross(const Vector3& rhs) const
	{
		return Vector3(
			y * rhs.z - z * rhs.y, //계산 결과가 반환 벡터의 x값. 예) 12(y * rhs.z) - 15(z * rhs.y) = -3
			z * rhs.x - x * rhs.z, //계산 결과가 반환 벡터의 y값. 예) 12(z * rhs.x) - 6(x * rhs.z) = 6
			x * rhs.y - y * rhs.x  //계산 결과가 반환 벡터의 Z값. 예) 5(x * rhs.y) - 8(y * rhs.x) = -3
		);
	}

	/*벡터의 제곱근이 적용 안된 길이 계산 기능
	* 예시
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	*
	* v1.LengthSquared();
	*
	* 만약 v1.LengthSquared() 출력시 14 출력됨
	*/
	float LengthSquared() const
	{
		//벡터의 각 값들의 제곱 값들의 합 반환
		return x * x + y * y + z * z;
	}

	/*벡터의 길이 계산 기능
	* 예시
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	*
	* v1.Length();
	*
	* 만약 v1.Length() 출력시 3.74166 출력됨
	*/
	float Length() const
	{
		//LengthSquared()의 제곱근 값 반환
		return sqrt(LengthSquared());
	}

	/*벡터를 정규화한다.
	* 예시
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	*
	* Vector3 normalized = v1.Normalize();
	*
	* 만약 normalized.x 출력시 0.267261 출력됨
	*/
	void Normalize()
	{
		float length = Length(); //length에 Length() 값 대입
		if (length != 0.0f)
		{
			x /= length;
			y /= length;
			z /= length;
		}
	}

	/*벡터를 복사하여 정규화한다.
	* 예시
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	*
	* Vector3 normalized = v1.Normalized();
	*
	* 만약 normalized.x 출력시 0.267261 출력됨
	*/
	Vector3 Normalized() const
	{
		Vector3 result = *this; //result에 본인 벡터값 대입
		result.Normalize(); //result를 정규화 시킴
		return result; //result 값 반환
	}
};

inline Vector3 operator*(float scalar, const Vector3& vec)
{
	return vec * scalar;
}

/*
* 검색어
* c++ 벡터 Dot, Cross, 3차원 벡터 외적 공식
* https://rhksgml78.tistory.com/124
* 
* inline 함수
* 
*/