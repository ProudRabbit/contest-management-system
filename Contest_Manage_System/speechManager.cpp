#include "speechManager.h"

speechManager::speechManager()
{
	//��ʼ������
	this->initspeech();
	this->createSpeaker();
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
	
	//��������ѡ��
	for (int i = 0; i < nameseed.size(); i++)
	{
		string name = "ѡ��";
		name += nameseed[i];

		Speak Sp;
		Sp.m_name = name;
		for (int j = 0; j < 2; j++)
		{
			Sp.m_score[j] = 0;
		}

		//����ѡ�ֱ�ţ���������뵽V1������
		this->v1.push_back(i + 10001);

		//ѡ�ֵı�ź����ַ���map������
		this->m_Speaker.insert(make_pair(i + 10001,Sp));

	}
}

void speechManager::startSpeech()
{
	//��һ�ֱ���

	//1.��ǩ
	this->DrawSpeech();
	//2.�ݽ�
	this->SpeechContest();
	//3.��ʾ�������
	this->showScore();
	//�ڶ��ֱ���
	this->m_index++;
	//1.��ǩ
	this->DrawSpeech();
	//2.�ݽ�
	this->SpeechContest();
	//3.��ʾ���ս��
	this->showScore();
	//4.����������ļ���
	this->saveRecord();

	cout << "����������" << endl;
	system("pause");
	system("cls");

}

//��ǩ
void speechManager::DrawSpeech()
{
	cout << "��" << this->m_index << "�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "----------------------------" << endl;
	cout << "��ǩ���ݽ�˳������:" << endl;
	
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

//����
void speechManager::SpeechContest()
{
	cout << "------------��" << this->m_index << "�ֱ�����ʽ��ʼ-------------" << endl;

	//������ʱ�������С��ɼ�
	multimap<double, int, greater<double>> groupScore;

	int num = 0;	//����ͳ��6��һ��

	//����ѡ������
	vector<int>v_Src;

	if (this->m_index ==1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}
	
	//�������е�ѡ��
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;

		//��ί���
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600)/10.f;	//600~1000
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());	//����
		
		//ȥ����ߺ���ͷ�
		d.pop_front();
		d.pop_back();

		//����ƽ����
		double sum = accumulate(d.begin(), d.end(), 0.0f);	//�ܷ�	
		double avg = sum / (double)d.size();	//ƽ����
	
		//cout << "��ţ�" << *it << " " << "������" << this->m_Speaker[*it].m_name << " " << "������" << avg << endl;

		//��ƽ�ַַŵ�map������
		this->m_Speaker[*it].m_score[this->m_index - 1] = avg;

		//��������ݷ��뵽��ʱ��С��������
		groupScore.insert(make_pair(avg, *it));	//key�Ƿ�����value�Ǿ���ѡ�ֱ��

		//ÿ6��ȡ��ǰ����
		if (num % 6 == 0)
		{
			cout << "---------��" << num / 6 << "С���������----------" << endl;
			for (multimap<double, int,greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "���: " << it->second << " ������ " << this->m_Speaker[it->second].m_name << " �ɼ��� " 
					<< this->m_Speaker[it->second].m_score[this->m_index - 1] <<endl;
			}

			//ȡ��ǰ����
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
	cout << "-----------��" << this->m_index << "�ֱ�������----------" << endl;
	system("pause");
}

//��ʾ�������
void speechManager::showScore()
{
	cout << "----------��" << this->m_index << "�ֱ���������ѡ������-----------"<<endl;

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
		cout << "ѡ�ֱ�ţ�" << *it << " ѡ��������" << this->m_Speaker[*it].m_name 
			<< " ѡ�ַ�����" << this->m_Speaker[*it].m_score[this->m_index - 1]<< endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->showMenu();
}

//�������
void speechManager::saveRecord()
{
	ofstream ofs;

	ofs.open("Speech.csv", ios::out | ios::app);	//��׷�ӵķ�ʽд�ļ�

	//��ѡ�ֵ�����д�뵽�ļ���
	for (vector<int>::iterator it = vVictor.begin(); it != vVictor.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_name << "," << this->m_Speaker[*it].m_score[1]<<",";
	}
	ofs << endl;
	
	//�ر�
	ofs.close();
	cout << "��¼�Ѿ�����" << endl;
}

//��ȡ�����¼
void speechManager::loadRecord()
{
	ifstream ifs("Speech.csv", ios::in);	//���ļ�

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//�ļ������
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->fileIsEmpty = false;

	ifs.putback(ch);	//�������ȡ���ַ��Ż�ȥ

	string data;

	while (ifs >> data)
	{
		cout << data << endl;
	}
	ifs.close();
}