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


//演讲管理类
class speechManager
{
public:

	//构造函数
	speechManager();

	//析构函数
	~speechManager();

	//显示菜单
	void showMenu();

	//退出系统
	void exit_system();

	//初始化属性
	void initspeech();

	//创建12名选手
	void createSpeaker();

	//开始演讲，比赛整个流程的控制函数
	void startSpeech();

	//抽签
	void DrawSpeech();

	//比赛
	void SpeechContest();

	//显示比赛结果
	void showScore();

	//保存分数
	void saveRecord();

	//读取往届记录
	void loadRecord();

	//判断文件是否为空
	bool fileIsEmpty;

	//存放往届记录的容器
	map<int, vector<string>> m_Record;

	//比赛选手容器  第一轮12人
	vector<int> v1;

	//比赛选手容器 第二轮6人
	vector<int>	v2;

	//获胜前三名
	vector<int> vVictor;

	//存放编号以及对应的选手具体信息
	map<int, Speak> m_Speaker;

	//比赛轮数
	int m_index;
};

