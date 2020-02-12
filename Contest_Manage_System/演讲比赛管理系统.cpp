#include<iostream>
#include<string>
#include"speechManager.h"
#include<ctime>
using namespace std;


int main()
{
	srand((unsigned int)time(NULL));
	speechManager SM;		//实例化一个演讲管理的对象
	
	//for (map<int, Speak>::iterator it = SM.m_Speaker.begin(); it != SM.m_Speaker.end(); it++)
	//{
	//	cout << "选手编号" << it->first << "选手姓名:" << it->second.m_name << "选手分数：" << it->second.m_score[0] << endl;
	//}

	int choose = 0;

	while (true)
	{
		SM.showMenu();

		cout << "请输入你的选择：" << endl;
		cin >> choose;

		switch (choose)
		{
			case 1:				//开始比赛
				SM.startSpeech();
				break;
			case 2:				//查看记录
				SM.showRecord();
				break;
			case 3:				//清空记录
				SM.clearRecord();
				break;
			case 0:				//退出系统
				SM.exit_system();
				break;
			default:
				system("cls");	//清屏
				break;
		}
	}


	system("pause");
	return 0;
}