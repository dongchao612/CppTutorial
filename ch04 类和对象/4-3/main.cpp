#include<iostream>

using namespace std;

const float PI = 3.141593;				// ����PI��ֵ
const float FENCE_PRICE = 35;			// դ���ļ۸�
const float CONCRETE_PRICE = 20;		// ����ˮ��ĵ���

class Cricle
{
public:
	Cricle(float r);					//���캯��
	float circumference();				//����Բ���ܳ�
	float area();						//����Բ�����

private:
	float radius;
};

//���ʵ��
//���캯�� ��ʼ����Ա radius
Cricle::Cricle(float r)
{
	radius = r;
}
//����Բ���ܳ�
float Cricle::circumference()
{
	return 2 * PI*radius;
}

//����Բ�����
float Cricle::area()
{
	return PI * radius*radius;
}

int main()
{
	float radius = 10;

	Cricle pool(radius);
	Cricle poolRim(radius + 3);

	//����դ���۸����
	cout << "դ���۸� : " << poolRim.circumference()*FENCE_PRICE << endl;

	//��������۸����
	cout << "�����۸� : " << (poolRim.area() - pool.area())*CONCRETE_PRICE << endl;

	return 0;
}