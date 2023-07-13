#include "header.h"
//user类函数实现
int File::nu = 0;
void User::reg() {
	std::cout << "请输入用户名:";
	std::cin >> name;
	std::cout << "请输入密码:";
	std::cin >> password;
	user_id = static_cast<int>(std::time(0));
	std::cout << "用户创建成功,注册的ID为:" << user_id << std::endl;
	//std::string data = std::to_string(user_id) + "\n" + name + "\n" + password + "\n";
	//saveData("user.xhh", data);
}






int User::login() {
	std::string nam;
	std::string pas;
	std::cout << "请登录" << std::endl;
	std::cout << "请输入用户名:";
	std::cin >> nam;
	std::cout << "请输入密码:";
	std::cin >> pas;
	if (nam != name)
	{
		std::cout << "无该用户，请注册" << std::endl;
		return 0;
	}
	else
		if (pas == password)
		{
			std::cout << "登录成功" << std::endl;
			return 1;
		}
		else
		{
			std::cout << "密码错误" << std::endl;
			return 0;
		}
}

int User::login(std::string name) {
	std::string nam = name;
	std::string pas;
	std::cout << "请输入密码:";
	std::cin >> pas;
	if (nam != name)
	{
		std::cout << "无该用户，请注册" << std::endl;
		return 0;
	}
	else
		if (pas == password)
		{
			std::cout << "登录成功" << std::endl;
			return 1;
		}
		else 
		{
			std::cout << "密码错误" << std::endl;
			return 0;
		}
}

void User::create()
{
	//int file_id = static_cast<int>(std::time(0));
	//Table_file f1(name, user_id);
}

void User::see(Table_file* s)
{
	int h = File::nu;
	s = (*s).nextf;
	for (int i = 0;i < h;i++)
	{
		(*s).f.read();
		s = (*s).nextf;
	}
}