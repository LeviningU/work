#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <iostream>

class user {
	std::string name;
	std::string password;
	int id;//�û���ʶ

public:
	void reg();//ע�ᣬ��¼�û��������룬����id
	void login();
	//��¼��ƥ���û��������룬����ƥ�������¼�ɹ���
	//�û�����ƥ����ʾ�޸��û���ע�ᣬ�û���ƥ�����벻ƥ����ʾ�������
	void creat();//����file��¼����
};

class file {
	int owner_id;
	int folder_id;//�ļ��б�ʶ
	int id;//�ļ���ʶ
	int remind;//�Ƿ����� ��1 ��0
	time_t remind_time;//����ʱ��
	int state;//�¼�״̬ ��״̬(�Ǵ���)0 �����1 ������2 δ��ʼ3
	
	//todo �ļ�������
	file(int now_id);//���贴���ļ�
public:
	void Read();//�鿴
	void Creat();//����
	void Edit();//�༭
	void Remind();//����
	void Import();//����
	void Export();//����
	void delect();//ɾ��



};

void search();//����

class folder {
	int id;
	std::string name;

	folder();
public:
	void Creat();//����
	void delect();//ɾ��
	void Rename();//������
	
};