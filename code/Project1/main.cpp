#include "header.h"

class Table {
public:
	Table() 
	{
	}



//private:
	User u;
	Table* next;

};





int main()
{
	int n;
	int log = 0;
	std::cout << "请注册：" << std::endl;
	Table start;
	Table* now = &start;
	if ((*now).u.login())
		log = 1;
	
	while (1)
	{
		if (log == 1)
		{
			std::cout << "菜单" << std::endl;
			std::cout << "1，新建笔记" << std::endl;
			std::cout << "2，编辑笔记" << std::endl;
			std::cout << "3，查看笔记" << std::endl;
			std::cout << "4，删除笔记" << std::endl;
			std::cout << "5，登出" << std::endl;
			int num;
			std::cin >> num;
			if (num == 1)
			{

			}
			else if (num == 2)
			{

			}
			else if (num == 3)
			{

			}
			else if (num == 4)
			{

			}
			else if (num == 5)
			{
				log = 0;
			}
		}
		else
		{
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