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
	std::cout << "��ע�᣺" << std::endl;
	Table start;
	Table* now = &start;
	if ((*now).u.login())
		log = 1;
	
	while (1)
	{
		if (log == 1)
		{
			std::cout << "�˵�" << std::endl;
			std::cout << "1���½��ʼ�" << std::endl;
			std::cout << "2���༭�ʼ�" << std::endl;
			std::cout << "3���鿴�ʼ�" << std::endl;
			std::cout << "4��ɾ���ʼ�" << std::endl;
			std::cout << "5���ǳ�" << std::endl;
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
			std::cout << "��¼/ע��" << std::endl;
			std::cin >> n;
			if (n == 0)
			{
				int whe = 0;
				std::cout << "�����û���:";
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
					std::cout << "�޸��û�����ע��" << std::endl;
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