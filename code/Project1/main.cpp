#include "header.h"
extern Table* now = NULL;
extern Table_file* nowf = NULL;
void menu()
{
	std::cout << "-----菜单-----" << std::endl;
	std::cout << "1，新建任务" << std::endl;
	std::cout << "2，查看任务列表" << std::endl;
	std::cout << "3，修改任务状态" << std::endl;
	std::cout << "4，编辑任务" << std::endl;
	std::cout << "5，删除任务" << std::endl;
	std::cout << "6，登出" << std::endl;
	std::cout << "-----菜单-----" << std::endl;
}

void loadUserData(std::string& fileName) {
	std::fstream file;
	file.open(fileName, std::ios::in | std::ios::out | std::ios::app);// 打开文件以进行读操作
	std::string data;
	if (file.is_open()) { // 检查文件是否成功打开
		std::getline(file, data);
		std::getline(file, data);
		std::getline(file, data);
		while (std::getline(file, data)) {
			std::string id = data;
			std::getline(file, data);
			std::string name = data;
			std::getline(file, data);
			std::string passwd = data;
			Table* u1 = new Table(name, passwd);
			(*now).next = u1;
			//(*now).u.login();
			now = u1;
		}
		file.close(); // 关闭文件
		//std::cout << "已成功从文件加载数据：" << fileName << std::endl;
	}
	else {
		std::cout << "无法打开文件：" << fileName << std::endl;
	}
}

void loadFileData(std::string& fileName) {
	std::fstream file;
	file.open(fileName, std::ios::in | std::ios::out | std::ios::app);// 打开文件以进行读操作
	std::string data;
	if (file.is_open()) { // 检查文件是否成功打开
		while (std::getline(file, data)) {
			if (data != "1")
			{
				std::getline(file, data);
				std::getline(file, data);
				File::nu++;
				continue;
			}
			std::getline(file, data);
			std::string user_id = data;
			/*int state;
			sscanf_s(data.c_str(), "%d", &state);*/
			std::getline(file, data);
			std::string owner_name = data;

			Table_file* f1 = new Table_file;
			(*f1).createf((*now).u.names(), (*now).u.ids(), 0);
			(*nowf).nextf = f1;
			nowf = f1;
		}
		file.close(); // 关闭文件
		//std::cout << "已成功从文件加载数据：" << fileName << std::endl;
	}
	else {
		std::cout << "无法打开文件：" << fileName << std::endl;
	}
}

int main()
{
	
	int log = 0/*,newf = 0*/;//判断登录状态
	
	Table start("admin","passwd");//用户链表起始点
	now = &start;
	std::string f_name = "user.xhh";
	loadUserData(f_name);
	Table_file begin;//任务链表起始点
	nowf = &begin;
	//newf = 1;
	
	while (1)
	{
		if (log == 1)//登录成功进入菜单
		{
			menu();
			int num;
			while (1)
			{

				//std::cin >> n1;

				std::string input;//判断输入是否为正整数
				std::getline(std::cin, input);

				std::istringstream iss(input);
				if (iss >> num && iss.eof())
				{
					if (num >= 1 && num <= 6)
					{
					}
					else
					{
						std::cout << "请输入正确数值：";
						continue;
					}
				}
				else {
					std::cout << "请输入正确数值：";
					continue;
				}

				break;
			}

			if (num == 1)
			{
				Table_file* f1 = new Table_file;
				(*f1).createf((*now).u.names(), (*now).u.ids(),1);
				(*nowf).nextf = f1;
				nowf = f1;
			}
			else if (num == 2)
			{
				(*now).u.see(&begin);
			}
			else if (num == 3)
			{
				(*now).u.see(&begin);
				std::cout << "输入编号修改任务状态（输入-1返回上一界面）：";
				while (1)
				{
					int n1;
					//std::cin >> n1;

					std::string input;//判断输入是否为正整数
					std::getline(std::cin, input);

					std::istringstream iss(input);
					if (iss >> n1 && iss.eof()) 
					{
						if (n1 >= 0) 
						{
						}
						else if (n1 == -1)
						{
							break;
						}
						else 
						{
							std::cout << "请输入正确数值：";
							continue;
						}
					}
					else {
						std::cout << "请输入正确数值：";
						continue;
					}

					Table_file* ifile = &begin;
					int i;
					for (i = 0; i <= n1; ifile = (*ifile).nextf, i++)
					{
						if ((*ifile).nextf == NULL)
						{
							break;
						}
					}
					if (i != n1 + 1)
					{
						std::cout << "无该编号文件，请重新输入：";
						continue;

					}
					(*ifile).f.state_c();
					break;
				}
			}
			else if (num == 4)
			{
				(*now).u.see(&begin);
				std::cout << "输入编号修改任务内容（输入-1返回上一界面）：";

				//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				while (1)
				{
					int n1;
					//std::cin >> n1;

					std::string input;//判断输入是否为正整数
					std::getline(std::cin, input);

					std::istringstream iss(input);
					if (iss >> n1 && iss.eof())
					{
						if (n1 >= 0)
						{
						}
						else if (n1 == -1)
						{
							break;
						}
						else
						{
							std::cout << "请输入正确数值：";
							continue;
						}
					}
					else {
						std::cout << "请输入正确数值：";
						continue;
					}

					Table_file* ifile = &begin;
					int i;
					for (i = 0; i <= n1; ifile = (*ifile).nextf, i++)
					{
						if ((*ifile).nextf == NULL)
						{
							break;
						}
					}
					if (i != n1 + 1)
					{
						std::cout << "无该编号文件，请重新输入：";
						continue;

					}
					(*ifile).f.edit();
					break;
				}

				//int n1;
				//std::cin >> n1;
				//while (1)
				//{
				//	if (n1 == -1)
				//		break;
				//	else
				//	{
				//		Table_file* ifile = &begin;
				//		for (int i = 0; i <= n1; ifile = (*ifile).nextf, i++)
				//		{
				//		}
				//		(*ifile).f.edit();
				//		break;
				//	}
				//}
			}
			else if (num == 5)
			{
				(*now).u.see(&begin);
				std::cout << "输入编号删除任务（输入-1返回上一界面）：";

				//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				while (1)
				{
					int n1;
					//std::cin >> n1;

					std::string input;//判断输入是否为正整数
					std::getline(std::cin, input);

					std::istringstream iss(input);
					if (iss >> n1 && iss.eof())
					{
						if (n1 >= 0)
						{
						}
						else if (n1 == -1)
						{
							break;
						}
						else
						{
							std::cout << "请输入正确数值：";
							continue;
						}
					}
					else {
						std::cout << "请输入正确数值：";
						continue;
					}

					Table_file* ifile = &begin;
					int i;
					for (i = 0; i < n1; ifile = (*ifile).nextf, i++)
					{
					}
					Table_file* l_ifile = ifile;
					ifile = (*ifile).nextf;
					(*l_ifile).nextf = (*ifile).del_f();
					

					std::string f_name2 = (*now).u.names() + "file.xhh";
					std::fstream file_s(f_name2, std::ios::in | std::ios::out);
					if (file_s.is_open()) {
						std::string firstLine;
						std::getline(file_s, firstLine);

						file_s.seekg((*ifile).f.f_ids() * 3, std::ios::beg);

						std::string newFirstLine = std::to_string(0);
						file_s << newFirstLine;

						file_s.close();
					}
					else {
						std::cout << "无法打开文件！" << std::endl;
					}
					delete ifile;

					break;
				}
				
			}
			else if (num == 6)
			{
				log = 0;
			}
			else
			{
				std::cout << "无该数字编号或输入内容非法，请重新输入" << std::endl;
			}
		}

		else//未登录
		{
			int n;
			std::cout << "登录（0）/注册（1）" << std::endl;
			std::cin >> n;
			if (n == 0)
			{
				int whe = 0;
				std::cout << "输入用户名:";
				//find
				std::string us;
				std::cin >> us;
				Table* x = &start;
				for (; (*x).next != NULL; x = (*x).next)
				{
					if (((*x).u.names().compare(us)) == 0)
					{
						whe = 1;
						if ((*x).u.login(us))
						{
							now = x;
							log = 1;
							std::string f_name1 = (*now).u.names() + "file.xhh";
							loadFileData(f_name1);
							break;
						}

					}
				}
				if (((*x).u.names().compare(us)) == 0)
				{
					if (log == 0 &&(*x).u.login(us))
					{
						now = x;
						log = 1;
						std::string f_name1 = (*now).u.names() + "file.xhh";
						loadFileData(f_name1);
					}
					continue;
				}
				if (whe == 0)
					std::cout << "无该用户，请注册。" << std::endl;
			}
			else if (n == 1)
			{
				Table* u1 = new Table;
				(*now).next = u1;
				//(*now).u.login();
				now = u1;
			}
			else 
			{
				std::cout << "请输入正确数值" << std::endl;
			}
		}
	}
}