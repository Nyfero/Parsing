#include "../inc/parsing.hpp"

int testeur(Parser parse) {
    CheckNbArg(parse);
    CheckIsChar(parse);
    CheckIsNb(parse);
    CheckIsFile(parse);
    CheckIsFolder(parse);
    return 0;
}


int CheckNbArg(Parser parse) {
    int ret = 0;

    try {
        std::cout << "Less than 3 arguments" << std::endl;
        parse.Check_size_less_than(3);
        std::cout << "\e[92mOK\e[39m" << std::endl;
    }
    catch (const std::exception& e){
        std::cout << "\e[91mKO\e[39m" << std::endl;
        ret = 1;
    }
    
    try {
        std::cout << "More than 5 arguments" << std::endl;
        parse.Check_size_greater_than(5);
        std::cout << "\e[92mOK\e[39m" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "\e[91mKO\e[39m" << std::endl;
        ret = 1;
    }

    try {
        std::cout << "1 argument" << std::endl;
        parse.Check_size_less_than(2);
        parse.Check_size_greater_than(0);
        std::cout << "\e[92mOK\e[39m" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "\e[91mKO\e[39m" << std::endl;
        ret = 1;
    }

    try {
        std::cout << "No argument" << std::endl;
        parse.Check_size_less_than(1);
        std::cout << "\e[92mOK\e[39m" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "\e[91mKO\e[39m" << std::endl;
        ret = 1;
    }

    return ret;
}

int CheckIsChar(Parser parse) {
    int ret = 0;

    try {
        std::cout << "All args are alpha" << std::endl;
        parse.Check_args_char();
        std::cout << "\e[92mOK\e[39m" << std::endl;
    }
    catch (const std::exception& e){
        std::cout << "\e[91mKO\e[39m" << std::endl;
        ret = 1;
    }
    
    try {
        std::cout << "Args 1 is alpha" << std::endl;
        parse.Check_args_char_i(1);
        std::cout << "\e[92mOK\e[39m" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "\e[91mKO\e[39m" << std::endl;
        ret = 1;
    }

    return ret;
}

int CheckIsNb(Parser parse) {
    int ret = 0;

    try {
        std::cout << "All args are number" << std::endl;
        parse.Check_args_nb();
        std::cout << "\e[92mOK\e[39m" << std::endl;
    }
    catch (const std::exception& e){
        std::cout << "\e[91mKO\e[39m" << std::endl;
        ret = 1;
    }
    
    try {
        std::cout << "Args 1 is number" << std::endl;
        parse.Check_args_nb_i(1);
        std::cout << "\e[92mOK\e[39m" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "\e[91mKO\e[39m" << std::endl;
        ret = 1;
    }

    return ret;
}

int CheckIsFile(Parser parse) {
    int ret = 0;

    try {
        std::cout << "All args are files" << std::endl;
        parse.Check_args_file();
        std::cout << "\e[92mOK\e[39m" << std::endl;
    }
    catch (const std::exception& e){
        std::cout << "\e[91mKO\e[39m" << std::endl;
        ret = 1;
    }
    
    try {
        std::cout << "Args 1 is a file" << std::endl;
        parse.Check_args_file_i(1);
        std::cout << "\e[92mOK\e[39m" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "\e[91mKO\e[39m" << std::endl;
        ret = 1;
    }

    return ret;
}

int CheckIsFolder(Parser parse) {
    int ret = 0;

    try {
        std::cout << "All args are folders" << std::endl;
        parse.Check_args_folder();
        std::cout << "\e[92mOK\e[39m" << std::endl;
    }
    catch (const std::exception& e){
        std::cout << "\e[91mKO\e[39m" << std::endl;
        ret = 1;
    }
    
    try {
        std::cout << "Args 1 is a folder" << std::endl;
        parse.Check_args_folder_i(1);
        std::cout << "\e[92mOK\e[39m" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "\e[91mKO\e[39m" << std::endl;
        ret = 1;
    }

    return ret;
}