#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <iostream>


class User {
public:
	void reg();//ע�ᣬ��¼�û��������룬����id
	int login();
	int login(std::string name);
	//��¼��ƥ���û��������룬����ƥ�������¼�ɹ���
	//�û�����ƥ����ʾ�޸��û���ע�ᣬ�û���ƥ�����벻ƥ����ʾ�������
	void create();//����file��¼����
	User()
	{
		reg();
	}
	std::string names() 
	{
		return name;
	}
private:
	std::string name;
	std::string password;
	int user_id;//�û���ʶ
};

class File /*:public Folder*/ {
	//todo �ļ�������
public:
	File(int now_id,int user_id);//���贴���ļ�
	void read();//�鿴
	void create();//����
	void edit();//�༭
	void remind_f();//����
	void import_f();//����
	void export_f();//����
	void del();//ɾ��


private:
	int user_id;
	int file_id;//�ļ���ʶ
	int remind = 0;//�Ƿ����� ��1 ��0
	time_t remind_time;//����ʱ��
	int state = 0;//�¼�״̬ ��״̬(�Ǵ���)0 �����1 ������2 δ��ʼ3
	std::fstream fs;

};

void search();//����

//class Folder {
//public:
//	Folder();
//	void Creat();//����
//	void delect();//ɾ��
//	void Rename();//������
//
//private:
//	int folder_id;
//	std::string name;
//	
//};

#endif