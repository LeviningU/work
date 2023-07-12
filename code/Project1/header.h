#include <iostream>
#include <string>
#include <ctime>

class user {
	std::string name;
	std::string password;
	int id;//用户标识

public:
	void reg();//注册，记录用户名，密码，生成id
	void login();
	//登录，匹配用户名和密码，若都匹配输出登录成功，
	//用户名无匹配提示无该用户请注册，用户名匹配密码不匹配提示密码错误
	void creat();//创建file记录内容
};

class file {
	int owner_id;
	int folder_id;//文件夹标识
	int id;//文件标识
	int remind;//是否提醒 是1 否0
	time_t remind_time;//提醒时间
	int state;//事件状态 无状态(非待办)0 已完成1 进行中2 未开始3
	
	//todo 文件，内容



};

class folder {
	int id;
	std::string name;

};