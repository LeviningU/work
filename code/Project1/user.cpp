#include "header.h"
//user�ຯ��ʵ��
int File::nu = 0;
std::string User::reg(std::string name, std::string passwd, int save) {
	/*std::cout << "�������û���:";
	std::cin >> name;
	std::cout << "����������:";
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
	return "�û������ɹ�";
}


void saveData(std::string& f_name, std::string& data)
{
	std::fstream file(f_name, std::ios::in | std::ios::out | std::ios::app); // ���ļ��Խ���д����
	file.clear();
	file.seekg(0, std::ios::end);
	if (file.is_open()) { // ����ļ��Ƿ�ɹ���
		file << data; // ������д���ļ�
		file.close(); // �ر��ļ�
	}
	else {
	}
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
	//int file_id = static_cast<int>(std::time(0));
	//Table_file f1(name, user_id);
}

void User::see(Table_file* s)
{
	//int h = File::nu;
	//s = (*s).nextf;
	if ((*s).nextf == NULL)
	{
		std::cout << "���û����������ȴ�������" << std::endl;
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