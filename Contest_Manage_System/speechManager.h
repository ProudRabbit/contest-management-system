#pragma once

#include<iostream>
#include<vector>
#include<map>
#include<string>
#include"speak.h"
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<fstream>

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

	//��ʼ�ݽ��������������̵Ŀ��ƺ���
	void startSpeech();

	//��ǩ
	void DrawSpeech();

	//����
	void SpeechContest();

	//��ʾ�������
	void showScore();

	//�������
	void saveRecord();

	//��ȡ�����¼
	void loadRecord();

	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	//��������¼������
	map<int, vector<string>> m_Record;

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

