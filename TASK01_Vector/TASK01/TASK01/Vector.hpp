#pragma once //�ߺ�ȸ��

#include <cmath> //���а���

struct Vector3 //Vector3�� ����ü
{
	float x; //Vector3�� x�� ��� ����
	float y; //Vector3�� y�� ��� ����
	float z; //Vector3�� z�� ��� ����

	//������ �� ������ 0���� �ʱ�ȭ
	Vector3() : x(0.0f), y(0.0f), z(0.0f) {} 

	//�Ű����� ������ �� ������ �� �ο� ����
	Vector3(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z)
	{
	}

	//�������
	Vector3(const Vector3& other)
		: x(other.x), y(other.y), z(other.z)
	{
	}

	/*���Ϳ� �Ű������� �� ���Ͱ��� ���� �����ϴ� ���
	* ����
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	* Vector3 v2(4.0f, 5.0f, 6.0f);
	*
	* v1.operator=(v2);
	*
	* ���� (v1.operator=(v2)).x ��½� 4 ��µ�
	*/
	Vector3& operator=(const Vector3& rhs)
	{
		x = rhs.x; //v1�� ���� x���� v2�� ���� x���� ����
		y = rhs.y; //v1�� ���� y���� v2�� ���� y���� ����
		z = rhs.z; //v1�� ���� z���� v2�� ���� z���� ����
		return *this; //���� �� ��ȯ
	}

	/*���Ϳ� �Ű������� �� ���Ͱ��� ���� ���ϴ� ���
	* ����
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	* Vector3 v2(4.0f, 5.0f, 6.0f);
	*
	* v1.operator+(v2);
	*
	* ���� (v1.operator+(v2)).x ��½� 5 ��µ�
	*/
	Vector3 operator+(const Vector3& rhs) const
	{
		//�� ���Ͱ��� ���ؼ� ��ȯ
		return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
	}

	/*���Ϳ� �Ű������� �� ���Ͱ��� ���� ���� ���
	* ����
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	* Vector3 v2(4.0f, 5.0f, 6.0f);
	*
	* v1.operator-(v2);
	*
	* ���� (v1.operator-(v2)).x ��½� -3 ��µ�
	*/
	Vector3 operator-(const Vector3& rhs) const
	{
		//�� ���Ͱ��� ���� ��ȯ
		return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
	}

	/*���Ϳ� ��Į�� ���� ���� ���ϴ� ũ�� ��ȯ ���
	* ����
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	* float sca = 32.0f;
	*
	* v1.operator*(sca);
	*
	* ���� (v1.operator*(sca)).x ��½� 32 ��µ�
	*/
	Vector3 operator*(float scalar) const
	{
		//�� ���Ͱ��� scalar�� ��ŭ ���� ũ�⺯ȯ �� ��ȯ
		return Vector3(x * scalar, y * scalar, z * scalar);
	}

	/*���Ϳ� ��Į�� ���� ���� ������ ũ�� ��ȯ ���
	* ����
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	* float sca = 2.0f;
	*
	* v1.operator/(sca);
	*
	* ���� (v1.operator/(sca)).x ��½� 0.5 ��µ�
	*/
	Vector3 operator/(float scalar) const
	{
		if (scalar != 0.0f)
		{
			//�� ���Ͱ��� scalar�� ��ŭ ������ ũ�⺯ȯ �� ��ȯ
			return Vector3(x / scalar, y / scalar, z / scalar);
		}
		//�׳� ���� ���� �� ��ȯ
		return *this; // Return without change if division by zero
	}

	/*���Ϳ� �Ű������� �� ���Ͱ��� ���� �������� �ϴ� ���
	* ����
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	* Vector3 v2(4.0f, 5.0f, 6.0f);
	*
	* v1.operator+=(v2);
	*
	* ���� (v1.operator+=(v2)).x ��½� 5 ��µ�
	*/
	Vector3& operator+=(const Vector3& rhs)
	{
		x += rhs.x; //v1�� ���� x���� v2�� ���� x���� ��������
		y += rhs.y; //v1�� ���� y���� v2�� ���� y���� ��������
		z += rhs.z; //v1�� ���� z���� v2�� ���� z���� ��������
		return *this; //���� �� ��ȯ
	}

	/*���Ϳ� �Ű������� �� ���Ͱ��� ���� �������� ���
	* ����
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	* Vector3 v2(4.0f, 5.0f, 6.0f);
	*
	* v1.operator-=(v2);
	*
	* ���� (v1.operator-=(v2)).x ��½� -3 ��µ�
	*/
	Vector3& operator-=(const Vector3& rhs)
	{
		x -= rhs.x; //v1�� ���� x���� v2�� ���� x���� ��������
		y -= rhs.y; //v1�� ���� y���� v2�� ���� y���� �y������
		z -= rhs.z; //v1�� ���� z���� v2�� ���� z���� ��������
		return *this; //���� �� ��ȯ
	}

	/*���Ϳ� �Ű������� �� ������ ���� ��� ���
	* ����
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	* Vector3 v2(4.0f, 5.0f, 6.0f);
	*
	* float dot = v1.Dot(v2);
	*
	* ���� dot ��½� 32 ��µ�
	*/
	float Dot(const Vector3& rhs) const
	{
		//���� ��� �� ��ȯ
		return x * rhs.x + y * rhs.y + z * rhs.z;
	}

	/*���Ϳ� �Ű������� �� ������ ���� ��� ���
	* ����
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	* Vector3 v2(4.0f, 5.0f, 6.0f);
	*
	* Vector3 cross = v1.Cross(v2);
	*
	* ���� cross.x ��½� -3 ��µ�
	*/
	Vector3 Cross(const Vector3& rhs) const
	{
		return Vector3(
			y * rhs.z - z * rhs.y, //��� ����� ��ȯ ������ x��. ��) 12(y * rhs.z) - 15(z * rhs.y) = -3
			z * rhs.x - x * rhs.z, //��� ����� ��ȯ ������ y��. ��) 12(z * rhs.x) - 6(x * rhs.z) = 6
			x * rhs.y - y * rhs.x  //��� ����� ��ȯ ������ Z��. ��) 5(x * rhs.y) - 8(y * rhs.x) = -3
		);
	}

	/*������ �������� ���� �ȵ� ���� ��� ���
	* ����
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	*
	* v1.LengthSquared();
	*
	* ���� v1.LengthSquared() ��½� 14 ��µ�
	*/
	float LengthSquared() const
	{
		//������ �� ������ ���� ������ �� ��ȯ
		return x * x + y * y + z * z;
	}

	/*������ ���� ��� ���
	* ����
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	*
	* v1.Length();
	*
	* ���� v1.Length() ��½� 3.74166 ��µ�
	*/
	float Length() const
	{
		//LengthSquared()�� ������ �� ��ȯ
		return sqrt(LengthSquared());
	}

	/*���͸� ����ȭ�Ѵ�.
	* ����
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	*
	* Vector3 normalized = v1.Normalize();
	*
	* ���� normalized.x ��½� 0.267261 ��µ�
	*/
	void Normalize()
	{
		float length = Length(); //length�� Length() �� ����
		if (length != 0.0f)
		{
			x /= length;
			y /= length;
			z /= length;
		}
	}

	/*���͸� �����Ͽ� ����ȭ�Ѵ�.
	* ����
	* Vector3 v1(1.0f, 2.0f, 3.0f);
	*
	* Vector3 normalized = v1.Normalized();
	*
	* ���� normalized.x ��½� 0.267261 ��µ�
	*/
	Vector3 Normalized() const
	{
		Vector3 result = *this; //result�� ���� ���Ͱ� ����
		result.Normalize(); //result�� ����ȭ ��Ŵ
		return result; //result �� ��ȯ
	}
};

inline Vector3 operator*(float scalar, const Vector3& vec)
{
	return vec * scalar;
}

/*
* �˻���
* c++ ���� Dot, Cross, 3���� ���� ���� ����
* https://rhksgml78.tistory.com/124
* 
* inline �Լ�
* 
*/