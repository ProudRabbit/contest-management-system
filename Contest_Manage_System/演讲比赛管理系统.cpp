#include<iostream>
#include<string>
#include"speechManager.h"
#include<ctime>
using namespace std;


int main()
{
	srand((unsigned int)time(NULL));
	speechManager SM;		//ʵ����һ���ݽ�����Ķ���
	
	//for (map<int, Speak>::iterator it = SM.m_Speaker.begin(); it != SM.m_Speaker.end(); it++)
	//{
	//	cout << "ѡ�ֱ��" << it->first << "ѡ������:" << it->second.m_name << "ѡ�ַ�����" << it->second.m_score[0] << endl;
	//}

	int choose = 0;

	while (true)
	{
		SM.showMenu();

		cout << "���������ѡ��" << endl;
		cin >> choose;

		switch (choose)
		{
			case 1:				//��ʼ����
				SM.startSpeech();
				break;
			case 2:				//�鿴��¼
				SM.showRecord();
				break;
			case 3:				//��ռ�¼
				SM.clearRecord();
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