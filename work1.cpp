#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

class user {
	std::string name;
	std::string password;
	int id;//�û���ʶ

public:
	void reg();//ע�ᣬ��¼�û��������룬����id
	void login();
	//��¼��ƥ���û��������룬����ƥ�������¼�ɹ���
	//�û�����ƥ����ʾ�޸��û���ע�ᣬ�û���ƥ�����벻ƥ����ʾ�������
	void creatfile();//����file��¼����
};

class file {
	int owner_id;
	int folder_id;//�ļ��б�ʶ
	int id;//�ļ���ʶ
	int remind;//�Ƿ����� ��1 ��0
	time_t remind_time;//����ʱ��
	int state;//�¼�״̬ ��״̬(�Ǵ���)0 �����1 ������2 δ��ʼ3

	//todo �ļ�������
	file(int now_id);//���贴���ļ�
public:
	void Read();//�鿴
	void Creat();//����
	void Edit();//�༭
	void Remind();//����
	void Import();//����
	void Export();//����
	void delect();//ɾ��



};

void search();//����

class folder {
	int id;
	std::string name;

	folder();
public:
	void Creat();//����
	void delect();//ɾ��
	void Rename();//������

};

void user::reg() {
	std::cout << "�������û���";
	std::cin >> name;
	std::cout << "����������";
	std::cin >> password;
	id = static_cast<int>(std::time(0));
	std::cout << "�û������ɹ�,ע���IDΪ:" << id;
}

void user::login() {
	std::string nam;
	std::string pas;
	std::cout << std::endl;
	std::cout << "�������û���";
	std::cin >> nam;
	std::cout << "����������";
	std::cin >> pas;
	if (nam != name)
		std::cout << "�޸��û�����ע��";
	else
		if (pas == password)
			std::cout << "��¼�ɹ�";
		else std::cout << "�������";
}

void user::creatfile()
{
	
}

int main()
{
	user user1;
	user1.reg();
	user1.login();
}