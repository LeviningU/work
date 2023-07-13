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
//	std::ofstream file(fileName, std::ios::in | std::ios::out | std::ios::app); // 打开文件以进行写操作
//	if (file.is_open()) { // 检查文件是否成功打开
//		file << data; // 将数据写入文件
//		file.close(); // 关闭文件
//		std::cout << "数据已成功保存到文件：" << fileName << std::endl;
//	}
//	else {
//		std::cout << "无法打开文件：" << fileName << std::endl;
//	}
//}

class User {
public:
	void reg();//注册，记录用户名，密码，生成id
	int login();
	int login(std::string name);
	//登录，匹配用户名和密码，若都匹配输出登录成功，
	//用户名无匹配提示无该用户请注册，用户名匹配密码不匹配提示密码错误
	void create();//创建file记录内容
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
	int user_id;//用户标识

};

class File /*:public Folder*/ {
	//todo 文件，内容
public:
	~File();
	File() {}
	File(std::string name,int user_id);//仅需创建文件
	void Files(std::string name, int user_id);
	void read();//查看
	void create();//创建
	void edit();//编辑
	void remind_f();//提醒
	void import_f();//导入
	void export_f();//导出
	void del();//删除
	void state_c();
	std::string state_c(int n);

	static int nu;

private:
	int user_id;
	int file_id;//文件标识
	int remind = 0;//是否提醒 是1 否0
	time_t remind_time;//提醒时间
	int state = 2;//事件状态 无状态(非待办)0 已完成1 未完成2 进行中3
	std::fstream fs;
	std::string owner_name;

};


void search();//查找

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