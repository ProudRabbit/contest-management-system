#include<iostream>
#include<string>
#include"speechManager.h"

using namespace std;


int main()
{
	speechManager SM;		//ʵ����һ���ݽ�����Ķ���
	

	int choose = 0;

	while (true)
	{
		SM.showMenu();

		cout << "���������ѡ��" << endl;
		cin >> choose;

		switch (choose)
		{
			case 1:				//��ʼ����
				break;
			case 2:				//�鿴��¼
				break;
			case 3:				//��ռ�¼
				break;
			case 0:				//�˳�ϵͳ
				SM.exit_system();
				break;
			default:
				system("cls");	//����
				break;
		}
	}


	system("pause");
	return 0;
}