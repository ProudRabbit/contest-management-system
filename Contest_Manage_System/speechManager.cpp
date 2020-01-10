#include "speechManager.h"

speechManager::speechManager()
{
	//初始化属性
	this->initspeech();
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

void speechManager::initspeech()
{
	//保证容器为空
	this->v1.clear();
	this->v2.clear();
	this->vVictor.clear();
	this->m_Speaker.clear();

	//初始化比赛轮数
	this->m_index = 1;
}

void speechManager::createSpeaker()
{
	string nameseed = "ABCDEFGHIJKL";
}