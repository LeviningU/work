#include "header.h"

//user�ຯ��ʵ��
void User::reg() {
	std::cout << "�������û���:";
	std::cin >> name;
	std::cout << "����������:";
	std::cin >> password;
	user_id = static_cast<int>(std::time(0));
	std::cout << "�û������ɹ�,ע���IDΪ:" << user_id << std::endl;
}

int User::login() {
	std::string nam;
	std::string pas;
	std::cout << "���¼" << std::endl;
	std::cout << "�������û���:";
	std::cin >> nam;
	std::cout << "����������:";
	std::cin >> pas;
	if (nam != name)
	{
		std::cout << "�޸��û�����ע��" << std::endl;
		return 0;
	}
	else
		if (pas == password)
		{
			std::cout << "��¼�ɹ�" << std::endl;
			return 1;
		}
		else
		{
			std::cout << "�������" << std::endl;
			return 0;
		}
}

int User::login(std::string name) {
	std::string nam = name;
	std::string pas;
	std::cout << "����������:";
	std::cin >> pas;
	if (nam != name)
	{
		std::cout << "�޸��û�����ע��" << std::endl;
		return 0;
	}
	else
		if (pas == password)
		{
			std::cout << "��¼�ɹ�" << std::endl;
			return 1;
		}
		else 
		{
			std::cout << "�������" << std::endl;
			return 0;
		}
}

void User::create()
{
	int file_id = static_cast<int>(std::time(0));
	File f1(file_id, user_id);
}