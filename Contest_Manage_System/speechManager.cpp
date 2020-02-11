#include "speechManager.h"

speechManager::speechManager()
{
	//初始化属性
	this->initspeech();
	this->createSpeaker();
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
	
	//创建具体选手
	for (int i = 0; i < nameseed.size(); i++)
	{
		string name = "选手";
		name += nameseed[i];

		Speak Sp;
		Sp.m_name = name;
		for (int j = 0; j < 2; j++)
		{
			Sp.m_score[j] = 0;
		}

		//创建选手编号，并将其放入到V1容器中
		this->v1.push_back(i + 10001);

		//选手的编号和名字放在map容器中
		this->m_Speaker.insert(make_pair(i + 10001,Sp));

	}
}

void speechManager::startSpeech()
{
	//第一轮比赛

	//1.抽签
	this->DrawSpeech();
	//2.演讲
	this->SpeechContest();
	//3.显示晋级结果
	this->showScore();
	//第二轮比赛
	this->m_index++;
	//1.抽签
	this->DrawSpeech();
	//2.演讲
	this->SpeechContest();
	//3.显示最终结果
	this->showScore();
	//4.保存分数到文件中
	this->saveRecord();

	cout << "本届比赛完毕" << endl;
	system("pause");
	system("cls");

}

//抽签
void speechManager::DrawSpeech()
{
	cout << "第" << this->m_index << "轮比赛选手正在抽签" << endl;
	cout << "----------------------------" << endl;
	cout << "抽签后演讲顺序如下:" << endl;
	
	if (1 == this->m_index)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "-------------------" << endl;
	system("pause");
	cout << endl;
}

//比赛
void speechManager::SpeechContest()
{
	cout << "------------第" << this->m_index << "轮比赛正式开始-------------" << endl;

	//创建临时容器存放小组成绩
	multimap<double, int, greater<double>> groupScore;

	int num = 0;	//用于统计6人一组

	//比赛选手容器
	vector<int>v_Src;

	if (this->m_index ==1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}
	
	//遍历所有的选手
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;

		//评委打分
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600)/10.f;	//600~1000
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());	//排序
		
		//去除最高和最低分
		d.pop_front();
		d.pop_back();

		//计算平均分
		double sum = accumulate(d.begin(), d.end(), 0.0f);	//总分	
		double avg = sum / (double)d.size();	//平均分
	
		//cout << "编号：" << *it << " " << "姓名：" << this->m_Speaker[*it].m_name << " " << "分数：" << avg << endl;

		//将平局分放到map容器中
		this->m_Speaker[*it].m_score[this->m_index - 1] = avg;

		//将打分数据放入到临时的小组容器中
		groupScore.insert(make_pair(avg, *it));	//key是分数，value是具体选手编号

		//每6人取出前三名
		if (num % 6 == 0)
		{
			cout << "---------第" << num / 6 << "小组比赛名次----------" << endl;
			for (multimap<double, int,greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号: " << it->second << " 姓名： " << this->m_Speaker[it->second].m_name << " 成绩： " 
					<< this->m_Speaker[it->second].m_score[this->m_index - 1] <<endl;
			}

			//取走前三名
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3 ; it++,count++)
			{
				if (this->m_index == 1)
				{
					v2.push_back(it->second);
				}
				else
				{
					vVictor.push_back(it->second);
				}
			}

			groupScore.clear();
			cout << endl;
		}
	}
	cout << "-----------第" << this->m_index << "轮比赛结束----------" << endl;
	system("pause");
}

//显示比赛结果
void speechManager::showScore()
{
	cout << "----------第" << this->m_index << "轮比赛晋级的选手如下-----------"<<endl;

	vector<int> v;
	if (this->m_index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictor;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手编号：" << *it << " 选手姓名：" << this->m_Speaker[*it].m_name 
			<< " 选手分数：" << this->m_Speaker[*it].m_score[this->m_index - 1]<< endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->showMenu();
}

//保存分数
void speechManager::saveRecord()
{
	ofstream ofs;

	ofs.open("Speech.csv", ios::out | ios::app);	//用追加的方式写文件

	//将选手的数据写入到文件中
	for (vector<int>::iterator it = vVictor.begin(); it != vVictor.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_name << "," << this->m_Speaker[*it].m_score[1]<<",";
	}
	ofs << endl;
	
	//关闭
	ofs.close();
	cout << "记录已经保存" << endl;
}

//读取往届记录
void speechManager::loadRecord()
{
	ifstream ifs("Speech.csv", ios::in);	//读文件

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//文件被清空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件不为空
	this->fileIsEmpty = false;

	ifs.putback(ch);	//将上面读取的字符放回去

	string data;

	while (ifs >> data)
	{
		cout << data << endl;
	}
	ifs.close();
}