#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int main() {
    std::ifstream inputFile("modify_to_json_body.txt"); // 読み込むファイルのパスを指定
    std::ofstream outputFile("modified_to_json_body.txt"); // 書き出すファイルのパスを指定
    std::vector<std::string> lines;

    while (!inputFile.eof()) {
        std::string value;
        getline(inputFile, value);
        value.insert(0, "\"");
        value.insert(value.size(), "\","); //jsonの書式への変更
        lines.push_back(value);
    }

    lines.back().pop_back(); //最後の行はカンマがいらない

    for(auto line : lines) {
        outputFile << line << std::endl;
    }

    std::cout << "Modification successfully completed!" << std::endl;
    std::cin.get();
    return 0;
}