#include<iostream>
using namespace std;
class SavingAccount
{
public:
	SavingAccount(int date, int id, double rate);
	~SavingAccount();
	int getId() {
		return id;
	}
	double getBalance() {
		return balance;
	}
	double getRate() {
		return rate;
	}
	//����
	void deposit(int date, double amount);

	//ȡ��
	void withdraw(int date, double amount);

	//������Ϣ
	void settle(int date);

	//��ʾ�˻���Ϣ
	void show();



private:
	int id;//�˺�
	double balance;//���
	double rate;//����������
	int lastDate;//�ϴα������ʱ��
	double accumulation; //�����ۼ�֮��

	//��¼һ���� dateΪ���� amountΪ��� descΪ˵��
	void record(int date, double amount);

	//��õ�ָ������Ϊֹ�Ĵ������ۼ�ֵ
	double accumulate(int date)
	{
		return accumulation + balance * (date - lastDate);
	}
};

SavingAccount::SavingAccount(int date, int id, double rate)
{
	this->id = id;
	this->balance = 0;
	this->rate = rate;
	this->lastDate = date;
	this->accumulation = 0;
	cout << "date:" << date << "\t#" << id << " ��������..." << endl;
}

SavingAccount::~SavingAccount()
{
}
void SavingAccount::deposit(int date, double amount)
{
	return record(date, amount);
}
void SavingAccount::withdraw(int date, double amount)
{
	if (amount > getBalance())
	{
		cout << "error" << endl;
	}
	else
	{
		record(date, -amount);
	}
}
void SavingAccount::settle(int date)
{
	double interest = accumulate(date)*rate / 365;
	if (0 != interest)
	{
		record(date, interest);
	}
	accumulation = 0;
}
void SavingAccount::show()
{
	cout << "#" << id << "\t ���:" << balance << endl;
}
void SavingAccount::record(int date, double amount)
{
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;
	balance += amount;
	cout << date << "\t#" << id << "\t" << amount << "\t" << balance << endl;
}
int main()
{
	//���������˻�
	SavingAccount sa0(1, 001, 0.015);
	SavingAccount sa1(1, 002, 0.015);
	cout << endl;

	cout << "ʱ��\tid\t���\t���" << endl;
	sa0.deposit(5, 5000);
	sa1.deposit(25, 10000);
	sa0.deposit(45, 5500);
	sa1.withdraw(60, 4000);

	sa0.settle(90);
	sa1.settle(90);

	cout << endl;
	sa0.show();
	sa1.show();

	return 0;
}