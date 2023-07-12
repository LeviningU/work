#include "header.h"
//file类函数实现
File::File(int file_id,int user_id):user_id(user_id)
{
    this->file_id = file_id;
	std::string filename = "file_" + std::to_string(file_id) + ".txt";
	fs.open(filename, std::ios::in | std::ios::out | std::ios::app);
	if (!fs.is_open()) {
		std::cerr << "Failed to open file: " << filename << std::endl;
	}
    create();
}
void File::read() {
	std::string line;
	std::cout << "File content:\n";
	while (std::getline(fs, line)) {
		std::cout << line << '\n';
	}
}
void File::create() {
    std::string content;
    std::cout << "Enter file content:\n";
    std::cin.ignore(); // Ignore any leftover newline characters
    std::getline(std::cin, content);

    fs << content << '\n';
    std::cout << "File created successfully.\n";
    remind_f();
}

void File::edit() {
    read();
    fs.clear();
    fs.seekp(0, std::ios::end);
    std::cout << "Enter new content:\n";
    std::cin.ignore();
    std::string content;
    std::getline(std::cin, content);
    fs << content << '\n';
    std::cout << "File edited successfully.\n";
}

void File::remind_f() {
    std::cout << "输入提醒时间（若无需提醒则输入0）:\n";
    std::cin >> remind_time;
    if (remind_time != 0)
    {
        remind = 1;
        std::cout << "提醒设置成功。\n";
    }
    else
    {
        std::cout << "你选择了无需提醒。\n";
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

void File::del() {
    fs.close();
    std::string filename = "file_" + std::to_string(file_id) + ".txt";
    if (std::remove(filename.c_str()) == 0) {
        std::cout << "File deleted successfully.\n";
    }
    else {
        std::cerr << "Failed to delete file: " << filename << '\n';
    }
}