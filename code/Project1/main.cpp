#include "header.h"

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

int main()
{
	
	int log = 0/*,newf = 0*/;//判断登录状态
	std::cout << "请注册：" << std::endl;
	Table start;//用户链表起始点
	Table* now = &start;
	Table_file* nowf;//任务链表起始点
	if ((*now).u.login())
		log = 1;
	Table_file begin;
	//newf = 1;
	nowf = &begin;
	
	while (1)
	{
		if (log == 1)
		{
			menu();
			int num;
			std::cin >> num;
			if (num == 1)
			{
				Table_file* f1 = new Table_file;
				(*f1).createf((*now).u.names(), (*now).u.ids());
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
				int n1;
				std::cout << "输入编号修改任务状态（输入-1返回上一界面）：";
				std::cin >> n1;
				while (1)
				{
					if (n1 == -1)
						break;
					else
					{
						Table_file* ifile = &begin;
						for (int i = 0; i <= n1; ifile = (*ifile).nextf, i++)
						{
						}
						(*ifile).f.state_c();
						break;
					}
				}
			}
			else if (num == 4)
			{
				(*now).u.see(&begin);
				int n1;
				std::cout << "输入编号修改任务内容（输入-1返回上一界面）：";
				std::cin >> n1;
				while (1)
				{
					if (n1 == -1)
						break;
					else
					{
						Table_file* ifile = &begin;
						for (int i = 0; i <= n1; ifile = (*ifile).nextf, i++)
						{
						}
						(*ifile).f.edit();
						break;
					}
				}
			}
			else if (num == 5)
			{
				(*now).u.see(&begin);
				int n1;
				std::cout << "输入编号删除任务（输入-1返回上一界面）：";
				std::cin >> n1;
				while (1)
				{
					if (n1 == -1)
						break;
					else
					{
						Table_file* ifile = &begin;
						for (int i = 0; i <= n1; ifile = (*ifile).nextf, i++)
						{
						}
						(*ifile).f.del();
						break;
					}
				}
			}
			else if (num == 6)
			{
				log = 0;
			}
		}
		else
		{
			int n;
			std::cout << "登录/注册" << std::endl;
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
					}
					continue;
				}
				if (whe == 0)
					std::cout << "无该用户，请注册" << std::endl;
			}
			else
			{
				Table* u1 = new Table;
				(*now).next = u1;
				//(*now).u.login();
				now = u1;
			}
		}
	}
}