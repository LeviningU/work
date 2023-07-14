#include "header.h"
//user类函数实现
int File::nu = 0;
std::string User::reg(std::string name, std::string passwd, int save) {
	/*std::cout << "请输入用户名:";
	std::cin >> name;
	std::cout << "请输入密码:";
	std::cin >> password;*/
	this->name = name;
	this->password = passwd;
	user_id = static_cast<int>(std::time(0));
	
	if(save)
	{
		std::string data = std::to_string(user_id) + "\n" + name + "\n" + password + "\n";
		std::string f_name = "user.xhh";
		saveData(f_name, data);
	}
	return "用户创建成功";
}


void saveData(std::string& f_name, std::string& data)
{
	std::fstream file(f_name, std::ios::in | std::ios::out | std::ios::app); // 打开文件以进行写操作
	file.clear();
	file.seekg(0, std::ios::end);
	if (file.is_open()) { // 检查文件是否成功打开
		file << data; // 将数据写入文件
		file.close(); // 关闭文件
	}
	else {
	}
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
	//int h = File::nu;
	//s = (*s).nextf;
	if ((*s).nextf == NULL)
	{
		std::cout << "该用户无任务，请先创建任务" << std::endl;
		return;
	}
	int i = 0;
	for (s = (*s).nextf;(*s).nextf != NULL; s = (*s).nextf,i++)
	{
		(*s).f.read(i);
		//s = (*s).nextf;
	}
	(*s).f.read(i);
}