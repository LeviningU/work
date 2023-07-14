#include "header.h"
extern Table* now = NULL;
extern Table_file* nowf = NULL;
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

void loadUserData(std::string& fileName) {
	std::fstream file;
	file.open(fileName, std::ios::in | std::ios::out | std::ios::app);// ���ļ��Խ��ж�����
	std::string data;
	if (file.is_open()) { // ����ļ��Ƿ�ɹ���
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
		file.close(); // �ر��ļ�
		//std::cout << "�ѳɹ����ļ��������ݣ�" << fileName << std::endl;
	}
	else {
		std::cout << "�޷����ļ���" << fileName << std::endl;
	}
}

void loadFileData(std::string& fileName) {
	std::fstream file;
	file.open(fileName, std::ios::in | std::ios::out | std::ios::app);// ���ļ��Խ��ж�����
	std::string data;
	if (file.is_open()) { // ����ļ��Ƿ�ɹ���
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
		file.close(); // �ر��ļ�
		//std::cout << "�ѳɹ����ļ��������ݣ�" << fileName << std::endl;
	}
	else {
		std::cout << "�޷����ļ���" << fileName << std::endl;
	}
}

int main()
{
	
	int log = 0/*,newf = 0*/;//�жϵ�¼״̬
	
	Table start("admin","passwd");//�û�������ʼ��
	now = &start;
	std::string f_name = "user.xhh";
	loadUserData(f_name);
	Table_file begin;//����������ʼ��
	nowf = &begin;
	//newf = 1;
	
	while (1)
	{
		if (log == 1)//��¼�ɹ�����˵�
		{
			menu();
			int num;
			while (1)
			{

				//std::cin >> n1;

				std::string input;//�ж������Ƿ�Ϊ������
				std::getline(std::cin, input);

				std::istringstream iss(input);
				if (iss >> num && iss.eof())
				{
					if (num >= 1 && num <= 6)
					{
					}
					else
					{
						std::cout << "��������ȷ��ֵ��";
						continue;
					}
				}
				else {
					std::cout << "��������ȷ��ֵ��";
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
				std::cout << "�������޸�����״̬������-1������һ���棩��";
				while (1)
				{
					int n1;
					//std::cin >> n1;

					std::string input;//�ж������Ƿ�Ϊ������
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
							std::cout << "��������ȷ��ֵ��";
							continue;
						}
					}
					else {
						std::cout << "��������ȷ��ֵ��";
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
						std::cout << "�޸ñ���ļ������������룺";
						continue;

					}
					(*ifile).f.state_c();
					break;
				}
			}
			else if (num == 4)
			{
				(*now).u.see(&begin);
				std::cout << "�������޸��������ݣ�����-1������һ���棩��";

				//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				while (1)
				{
					int n1;
					//std::cin >> n1;

					std::string input;//�ж������Ƿ�Ϊ������
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
							std::cout << "��������ȷ��ֵ��";
							continue;
						}
					}
					else {
						std::cout << "��������ȷ��ֵ��";
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
						std::cout << "�޸ñ���ļ������������룺";
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
				std::cout << "������ɾ����������-1������һ���棩��";

				//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				while (1)
				{
					int n1;
					//std::cin >> n1;

					std::string input;//�ж������Ƿ�Ϊ������
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
							std::cout << "��������ȷ��ֵ��";
							continue;
						}
					}
					else {
						std::cout << "��������ȷ��ֵ��";
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
						std::cout << "�޷����ļ���" << std::endl;
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
				std::cout << "�޸����ֱ�Ż��������ݷǷ�������������" << std::endl;
			}
		}

		else//δ��¼
		{
			int n;
			std::cout << "��¼��0��/ע�ᣨ1��" << std::endl;
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
					std::cout << "�޸��û�����ע�ᡣ" << std::endl;
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
				std::cout << "��������ȷ��ֵ" << std::endl;
			}
		}
	}
}