#include "speechManager.h"

speechManager::speechManager()
{
	//��ʼ������
	this->initspeech();
}

speechManager::~speechManager()
{

}

void speechManager::showMenu()
{
	cout << "************************************" << endl;
	cout << "***********��ӭ�μ��ݽ�����*********" << endl;
	cout << "***********1.��ʼ�ݽ�����***********" << endl;
	cout << "***********2.�鿴�����¼***********" << endl;
	cout << "***********3.��ձ�����¼***********" << endl;
	cout << "***********0.�˳�����ϵͳ***********" << endl;
	cout << "************************************" << endl;
	cout << endl;

}

void speechManager::exit_system()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void speechManager::initspeech()
{
	//��֤����Ϊ��
	this->v1.clear();
	this->v2.clear();
	this->vVictor.clear();
	this->m_Speaker.clear();

	//��ʼ����������
	this->m_index = 1;
}

void speechManager::createSpeaker()
{
	string nameseed = "ABCDEFGHIJKL";
}