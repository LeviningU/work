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

void File::Files(std::string name, int user_id, int save_f, int stat)
{
    file_id = nu;
    owner_name = name;
    state = stat;
    //file_id = static_cast<int>(std::time(0));
    this->user_id = user_id;
    std::string filename = name + std::to_string(file_id) + ".xhh";
    fs.open(filename, std::ios::in | std::ios::out | std::ios::app);
    if (!fs.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
    nu++;
    if (save_f)
    {
        std::string f_name = name + "file.xhh";
        std::string data = std::to_string(1) + "\n" + std::to_string(user_id) + "\n" + owner_name + "\n";
        saveData(f_name, data);
        create();
    }
    
}

void File::read(int i) {
	std::string line;
    std::string filename = owner_name + std::to_string(file_id) + ".xhh";
    fs.open(filename, std::ios::in | std::ios::out | std::ios::app);
    fs.imbue(std::locale("en_US.UTF-8"));
    fs.clear();
    fs.seekg(0, std::ios::beg);
    std::getline(fs, line);
    sscanf_s(line.c_str(), "%d", &state);
	std::cout << i << ".��������Ϊ" << state_c(1) << ":\n";
	while (std::getline(fs, line)) {
		std::cout << line << '\n';
	}
}
void File::create() {
    std::cout << "��������(������н�������)��\n";
    std::string line;
    std::string content;
    //std::cin.ignore();
    content += std::to_string(2) + '\n';
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
            std::cout << "��������ɹ�\n";
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

    std::cout << "����������(������н�������)��\n";
    std::string line;
    std::string content;
    //std::cin.ignore();
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
    std::cout << "�����޸ĳɹ�\n";
}

void File::remind_f() {//δ����
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

void File::import_f() {//δ����
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

void File::export_f() {//δ����
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
    STD:
    std::cin >> st;
    if (st != 1 && st != 2)
    {
        std::cout << "��������ȷ״̬��";
        goto STD;
    }
    state = st;
    std::string filename = owner_name + std::to_string(file_id) + ".xhh";

    std::fstream file_s(filename, std::ios::in | std::ios::out);
    if (file_s.is_open()) {
        std::string firstLine;
        std::getline(file_s, firstLine);

        file_s.seekg(0, std::ios::beg);

        std::string newFirstLine = std::to_string(state);
        file_s << newFirstLine;

        file_s.close();
    }
    else {
        std::cout << "�޷����ļ���" << std::endl;
    }

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
    //del();
}

void File::del() {
    //fs.close();
    //std::string filename = owner_name + std::to_string(file_id) + ".xhh";
    //if (std::remove(filename.c_str()) == 0) {
    //    std::cout << "File deleted successfully.\n";
    //}
    //else {
    //    //std::cerr << "Failed to delete file: " << filename << '\n';
    //}
    del_state = 0;
    std::cout << "ɾ������ɹ�\n";
}