#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <locale>
#include <string>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <sstream>
class Table_file;
class User;
class Table;
class File;
void saveData(std::string& fileName, std::string& data);
void loadUserData(std::string& fileName);
void loadFileData(std::string& fileName);

class User {
public:
	std::string reg(std::string name, std::string passwd, int save = 0);//ע�ᣬ��¼�û��������룬����id
	int login();
	int login(std::string name);
	//��¼��ƥ���û��������룬����ƥ�������¼�ɹ���
	//�û�����ƥ����ʾ�޸��û���ע�ᣬ�û���ƥ�����벻ƥ����ʾ�������
	void create();//����file��¼����
	void see(Table_file* s);
	User()
	{
		
	}
	/*User()
	{
		reg();
	}*/
	std::string names() 
	{
		return name;
	}
	int ids()
	{
		return user_id;
	}
private:
	std::string name;
	std::string password;
	int user_id;//�û���ʶ

};

class File /*:public Folder*/ {
	//todo �ļ�������
public:
	~File();
	File() {}
	File(std::string name,int user_id);//���贴���ļ�
	void Files(std::string name, int user_id, int save_f = 0, int stat = 2);
	void read(int i = 0);//�鿴
	void create();//����
	void edit();//�༭
	void remind_f();//����
	void import_f();//����
	void export_f();//����
	void del();//ɾ��
	void state_c();
	std::string state_c(int n);
	int f_ids()
	{
		return file_id;
	}
	static int nu;

private:
	int user_id;
	int del_state = 1;
	int file_id;//�ļ���ʶ
	int remind = 0;//�Ƿ����� ��1 ��0
	time_t remind_time;//����ʱ��
	int state;//�¼�״̬ ��״̬(�Ǵ���)0 �����1 δ���2 ������3
	std::fstream fs;
	std::string owner_name;

};


void search();//����

class Table {
public:
	Table()
	{
		std::string name,password;
		std::cout << "�������û���:";
		std::cin >> name;
		std::cout << "����������:";
		std::cin >> password;
		std::cout << u.reg(name, password,1);
	}
	Table(std::string admin,std::string passwd)
	{
		u.reg(admin, passwd);
	}



	//private:
	User u;
	Table* next;

};

class Table_file {
public:
	Table_file()
	{

	}
	void createf(std::string name, int user_id,int save_f,int state = 2)
	{
		f.Files(name, user_id, save_f, state);
	}
	Table_file* del_f()
	{
		f.del();
		return nextf;
	}
	File f;
	Table_file* nextf;
};


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