#include "header.h"
//file�ຯ��ʵ��
File::File(std::string name,int user_id):user_id(user_id)
{
    file_id = nu;
    //file_id = static_cast<int>(std::time(0));
	std::string filename = name + std::to_string(file_id) + ".xhh";
	fs.open(filename, std::ios::in | std::ios::out | std::ios::app);
	if (!fs.is_open()) {
		std::cerr << "Failed to open file: " << filename << std::endl;
	}
    nu++;
    create();
}

void File::Files(std::string name, int user_id)
{
    file_id = nu;
    owner_name = name;
    //file_id = static_cast<int>(std::time(0));
    this->user_id = user_id;
    std::string filename = name + std::to_string(file_id) + ".xhh";
    fs.open(filename, std::ios::in | std::ios::out | std::ios::app);
    if (!fs.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
    nu++;
    create();
}

void File::read() {
	std::string line;
	std::cout << file_id << ".File content" << state_c(1) << ":\n";
    std::string filename = owner_name + std::to_string(file_id) + ".xhh";
    fs.open(filename, std::ios::in | std::ios::out | std::ios::app);
    fs.imbue(std::locale("en_US.UTF-8"));
    fs.clear();
    fs.seekg(0, std::ios::beg);
	while (std::getline(fs, line)) {
		std::cout << line << '\n';
	}
}
void File::create() {
    std::cout << "Enter new content (press Enter on an empty line to keep the original content):\n";
    std::string line;
    std::string content;
    std::cin.ignore();
    while (std::getline(std::cin, line) && !line.empty()) {
        content += line + '\n';
    }

    if (fs.is_open()) {
        // ����ļ����Ƿ��д��
        if (fs.good()) {
            if (!content.empty()) {
                fs.seekp(0, std::ios::beg);
                fs << content;
            }
            std::cout << "�����ļ��ɹ�\n";
        }
        else {
            std::cout << "�ļ�������д��\n";
        }
    }
    else {
        std::cout << "�޷����ļ�\n";
    }
    fs.close();
    //fs << content << '\n';
    //std::cout << "�����ļ��ɹ�\n";
    //remind_f();
}

void File::edit() {
    read();
    fs.clear();
    fs.seekp(0, std::ios::end);

    std::cout << "Enter new content (press Enter on an empty line to keep the original content):\n";
    std::string line;
    std::string content;
    std::cin.ignore();
    while (std::getline(std::cin, line) && !line.empty()) {
        content += line + '\n';
    }

    if (!content.empty()) {
        fs.seekp(0, std::ios::beg);
        fs << content;
    }

    /*std::cout << "Enter new content:\n";
    std::cin.ignore();
    std::string content;
    std::getline(std::cin, content);
    fs << content << '\n';*/
    fs.close();
    std::cout << "File edited successfully.\n";
}

void File::remind_f() {
    std::cout << "��������ʱ�䣨����������������0��:\n";
    std::cin >> remind_time;
    if (remind_time != 0)
    {
        remind = 1;
        std::cout << "�������óɹ���\n";
    }
    else
    {
        std::cout << "��ѡ�����������ѡ�\n";
    }
}

void File::import_f() {
    std::string filename;
    std::cout << "Enter the name of the file to import:\n";
    std::cin.ignore();
    std::getline(std::cin, filename);
    std::ifstream importFile(filename);
    if (importFile) {
        std::string line;
        while (std::getline(importFile, line)) {
            fs << line << '\n';
        }
        std::cout << "File imported successfully.\n";
    }
    else {
        std::cerr << "Failed to import file: " << filename << '\n';
    }
}

void File::export_f() {
    std::string filename;
    std::cout << "Enter the name of the file to export:\n";
    std::cin.ignore();
    std::getline(std::cin, filename);
    std::ofstream exportFile(filename);
    if (exportFile) {
        std::string line;
        fs.seekg(0);
        while (std::getline(fs, line)) {
            exportFile << line << '\n';
        }
        std::cout << "File exported successfully.\n";
    }
    else {
        std::cerr << "Failed to export file: " << filename << '\n';
    }
}

void File::state_c()
{
    if (state == 0)
    {
        std::cout << "δ����״̬" << std::endl;
    }
    else if (state == 1)
    {
        std::cout << "�����������" << std::endl;
    }
    else if (state == 2)
    {
        std::cout << "������δ���" << std::endl;
    }
    else if (state == 3)
    {
        std::cout << "�����������" << std::endl;
    }
    std::cout << "���޸ĸ�������״̬�������1 δ���2����";
    int st;
    std::cin >> st;
    state = st;
}

std::string File::state_c(int n)
{
    if (state == 0)
    {
        return "(δ����״̬)";
    }
    else if (state == 1)
    {
        return "(�����)";
    }
    else if (state == 2)
    {
        return "(δ���)";
    }
    else if (state == 3)
    {
        return "(������)";
    }
}

File::~File()
{
    del();
}

void File::del() {
    fs.close();
    std::string filename = owner_name + std::to_string(file_id) + ".xhh";
    if (std::remove(filename.c_str()) == 0) {
        std::cout << "File deleted successfully.\n";
    }
    else {
        std::cerr << "Failed to delete file: " << filename << '\n';
    }
}