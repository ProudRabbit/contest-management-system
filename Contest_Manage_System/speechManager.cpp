#include "speechManager.h"

speechManager::speechManager()
{

}

speechManager::~speechManager()
{

}

void speechManager::showMenu()
{
	cout << "************************************" << endl;
	cout << "***********欢迎参加演讲比赛*********" << endl;
	cout << "***********1.开始演讲比赛***********" << endl;
	cout << "***********2.查看往届记录***********" << endl;
	cout << "***********3.清空比赛记录***********" << endl;
	cout << "***********0.退出比赛系统***********" << endl;
	cout << "************************************" << endl;
	cout << endl;

}

void speechManager::exit_system()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}