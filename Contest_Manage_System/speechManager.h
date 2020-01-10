#pragma once

#include<iostream>
#include<vector>
#include<map>
#include<string>
#include"speak.h"
using namespace std;


//�ݽ�������
class speechManager
{
public:

	//���캯��
	speechManager();

	//��������
	~speechManager();

	//��ʾ�˵�
	void showMenu();

	//�˳�ϵͳ
	void exit_system();

	//��ʼ������
	void initspeech();

	//����12��ѡ��
	void createSpeaker();

	//����ѡ������  ��һ��12��
	vector<int> v1;

	//����ѡ������ �ڶ���6��
	vector<int>	v2;

	//��ʤǰ����
	vector<int> vVictor;

	//��ű���Լ���Ӧ��ѡ�־�����Ϣ
	map<int, Speak> m_Speaker;

	//��������
	int m_index;
};

