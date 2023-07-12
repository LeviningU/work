#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <iostream>


class User {
public:
	void reg();//注册，记录用户名，密码，生成id
	int login();
	int login(std::string name);
	//登录，匹配用户名和密码，若都匹配输出登录成功，
	//用户名无匹配提示无该用户请注册，用户名匹配密码不匹配提示密码错误
	void create();//创建file记录内容
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
	int user_id;//用户标识
};

class File /*:public Folder*/ {
	//todo 文件，内容
public:
	File(int now_id,int user_id);//仅需创建文件
	void read();//查看
	void create();//创建
	void edit();//编辑
	void remind_f();//提醒
	void import_f();//导入
	void export_f();//导出
	void del();//删除


private:
	int user_id;
	int file_id;//文件标识
	int remind = 0;//是否提醒 是1 否0
	time_t remind_time;//提醒时间
	int state = 0;//事件状态 无状态(非待办)0 已完成1 进行中2 未开始3
	std::fstream fs;

};

void search();//查找

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