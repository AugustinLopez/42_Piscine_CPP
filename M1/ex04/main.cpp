#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int file_to_str(std::string &buffer, char *filename) {
    std::ifstream ifs(filename);
    std::ostringstream sstr;

    if (!ifs) {
        std::cout << "Could not open " << filename << std::endl;
        return (-1);
    }
    sstr << ifs.rdbuf();
    buffer = sstr.str();
    return (0);
}

int str_to_file(std::string &buffer, std::string &filename){
    std::ofstream ofs(filename.c_str());

    if (!ofs) {
        std::cout << "Could not open " << filename << std::endl;
        return (-1);
    }
    ofs << buffer;
    return (0);
}

int replace(char **av) {
    std::string content;
    std::string modified("");
    std::string string1(av[2]);
    std::string string2(av[3]);
    size_t pos;
    size_t l1;

    if (file_to_str(content, av[1]) == -1)
        return (-1);
    pos = content.find(string1);
    l1 = string1.length();
    while (pos != std::string::npos) {
        modified +=  content.substr(0,pos) + string2;
        content.erase(0, pos+l1);
        pos = content.find(string1);
    }
    modified += content;
    content = av[1];
    content += ".REPLACE";
    return(str_to_file(modified, content));
}

int main(int ac, char **av) {
    if (ac != 4) {
        std::cout << "usage: ./replace [filename] [string1] [string2]" << std::endl;
        return (-1);
    }
    else if (av[2][0] == '\0' || av[3][0] == '\0') {
        std::cout << "string1 and string2 cannot be empty" << std::endl;
        return (-1);
    }
    return (replace(av));
}
