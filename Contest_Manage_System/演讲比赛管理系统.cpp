#include<iostream>
#include<string>
#include"speechManager.h"

using namespace std;


int main()
{
	speechManager SM;		//实例化一个演讲管理的对象
	

	int choose = 0;

	while (true)
	{
		SM.showMenu();

		cout << "请输入你的选择：" << endl;
		cin >> choose;

		switch (choose)
		{
			case 1:				//开始比赛
				break;
			case 2:				//查看记录
				break;
			case 3:				//清空记录
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