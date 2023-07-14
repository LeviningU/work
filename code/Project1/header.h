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
	std::string reg(std::string name, std::string passwd, int save = 0);//注册，记录用户名，密码，生成id
	int login();
	int login(std::string name);
	//登录，匹配用户名和密码，若都匹配输出登录成功，
	//用户名无匹配提示无该用户请注册，用户名匹配密码不匹配提示密码错误
	void create();//创建file记录内容
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
	int user_id;//用户标识

};

class File /*:public Folder*/ {
	//todo 文件，内容
public:
	~File();
	File() {}
	File(std::string name,int user_id);//仅需创建文件
	void Files(std::string name, int user_id, int save_f = 0, int stat = 2);
	void read(int i = 0);//查看
	void create();//创建
	void edit();//编辑
	void remind_f();//提醒
	void import_f();//导入
	void export_f();//导出
	void del();//删除
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
	int file_id;//文件标识
	int remind = 0;//是否提醒 是1 否0
	time_t remind_time;//提醒时间
	int state;//事件状态 无状态(非待办)0 已完成1 未完成2 进行中3
	std::fstream fs;
	std::string owner_name;

};


void search();//查找

class Table {
public:
	Table()
	{
		std::string name,password;
		std::cout << "请输入用户名:";
		std::cin >> name;
		std::cout << "请输入密码:";
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
//	void Creat();//创建
//	void delect();//删除
//	void Rename();//重命名
//
//private:
//	int folder_id;
//	std::string name;
//	
//};

#endif