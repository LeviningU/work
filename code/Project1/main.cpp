#include "header.h"

void menu()
{
	std::cout << "-----�˵�-----" << std::endl;
	std::cout << "1���½�����" << std::endl;
	std::cout << "2���鿴�����б�" << std::endl;
	std::cout << "3���޸�����״̬" << std::endl;
	std::cout << "4���༭����" << std::endl;
	std::cout << "5��ɾ������" << std::endl;
	std::cout << "6���ǳ�" << std::endl;
	std::cout << "-----�˵�-----" << std::endl;
}

int main()
{
	
	int log = 0/*,newf = 0*/;//�жϵ�¼״̬
	std::cout << "��ע�᣺" << std::endl;
	Table start;//�û�������ʼ��
	Table* now = &start;
	Table_file* nowf;//����������ʼ��
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
				std::cout << "�������޸�����״̬������-1������һ���棩��";
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
				std::cout << "�������޸��������ݣ�����-1������һ���棩��";
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
				std::cout << "������ɾ����������-1������һ���棩��";
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