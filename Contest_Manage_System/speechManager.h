#pragma once

#include<iostream>
#include<vector>
#include<map>
#include<string>
#include"speak.h"
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

