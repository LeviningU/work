#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <locale>
#include <string>
#include <ctime>
#include <fstream>
#include <iostream>
class Table_file;
class User;
class Table;
class File;

//void saveData(const std::string& fileName, const std::string& data) {
//	std::ofstream file(fileName, std::ios::in | std::ios::out | std::ios::app); // ���ļ��Խ���д����
//	if (file.is_open()) { // ����ļ��Ƿ�ɹ���
//		file << data; // ������д���ļ�
//		file.close(); // �ر��ļ�
//		std::cout << "�����ѳɹ����浽�ļ���" << fileName << std::endl;
//	}
//	else {
//		std::cout << "�޷����ļ���" << fileName << std::endl;
//	}
//}

class User {
public:
	void reg();//ע�ᣬ��¼�û��������룬����id
	int login();
	int login(std::string name);
	//��¼��ƥ���û��������룬����ƥ�������¼�ɹ���
	//�û�����ƥ����ʾ�޸��û���ע�ᣬ�û���ƥ�����벻ƥ����ʾ�������
	void create();//����file��¼����
	void see(Table_file* s);
	User()
	{
		reg();
	}
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
	void Files(std::string name, int user_id);
	void read();//�鿴
	void create();//����
	void edit();//�༭
	void remind_f();//����
	void import_f();//����
	void export_f();//����
	void del();//ɾ��
	void state_c();
	std::string state_c(int n);

	static int nu;

private:
	int user_id;
	int file_id;//�ļ���ʶ
	int remind = 0;//�Ƿ����� ��1 ��0
	time_t remind_time;//����ʱ��
	int state = 2;//�¼�״̬ ��״̬(�Ǵ���)0 �����1 δ���2 ������3
	std::fstream fs;
	std::string owner_name;

};


void search();//����

class Table {
public:
	Table()
	{
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
	void createf(std::string name, int user_id)
	{
		f.Files(name, user_id);
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