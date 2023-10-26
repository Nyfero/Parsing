#include <unistd.h>
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
#include <filesystem>
#include <cctype>
#include "Parser.hpp"


/******************/
/*  Constructors  */
/******************/

Parser::Parser(int ac, char **av) {
    this->_size = ac - 1;
    for (int i = 1; i < ac; i++) {
        this->_args.push_back(av[i]);
    }
}

Parser::~Parser() {}


/*************/
/*  Setters  */
/*************/

void Parser::Set_flags(std::vector<std::string> flag) {
    for (size_t i = 0; i < flag.size(); i++) {
        this->_flags.push_back(flag[i]);
    }
}


/*************/
/*  Getters  */
/*************/

size_t Parser::Get_size() const {
    return this->_size;
}

std::vector<std::string> Parser::Get_args() const {
    return this->_args;
}

std::string Parser::Get_args_i(size_t i) const {
    return this->_args[i];
}

std::vector<std::string> Parser::Get_flags() const {
    return this->_flags;
}

std::string Parser::Get_flags_i(size_t i) const {
    return this->_flags[i];
}


/**************/
/*  Checkers  */
/**************/


int Parser::Check_size_is(size_t i) const {
    Check_size_less_than(i);
    Check_size_greater_than(i);
    return 0;
}

int Parser::Check_size_less_than(size_t i) const {
    if (this->_size > i)
        throw ToMuchArgsE();
    return 0;
}

int Parser::Check_size_greater_than(size_t i) const {
    if (this->_size < i)
        throw NotEnoughtArgsE();
    return 0;
}

int Parser::Check_args_char() const {
    for (size_t i = 0; i < this->_size; i++) {
        Check_args_char_i(i);
    }
    return 0;
}

int Parser::Check_args_char_i(size_t i) const {
    for (size_t j = 0; j < this->_args[i].size(); j++) {
        if (!isalpha(this->_args[i][j])) {
            throw IsNotCharE();
        }
    }
    return 0;
}

int Parser::Check_args_nb() const {
    for (size_t i = 0; i < this->_size; i++) {
        Check_args_nb_i(i);
    }
    return 0;
}

int Parser::Check_args_nb_i(size_t i) const {
    for (size_t j = 0; j < this->_args[i].size(); j++) {
        if (!isdigit(this->_args[i][j])) {
            throw IsNotNumberE();
        }
    }
    return 0;
}

int Parser::Checks_args_alpha() const {
    for (size_t i = 0; i < this->_size; i++) {
        Checks_args_alpha_i(i);
    }
    return 0;
}

int Parser::Checks_args_alpha_i(size_t i) const {
    for (size_t j = 0; j < this->_args[i].size(); j++) {
        if (!std::isalnum(static_cast<unsigned char>(this->_args[i][j]))) {
            throw IsNotAlphaNumericE();
        }
    }
    return 0;
}

int Parser::Check_args_file() const {
    for (size_t i = 0; i < this->_size; i++) {
        Check_args_file_i(i);
    }
    return 0;
}

int Parser::Check_args_file_i(size_t i) const {
    if (!std::filesystem::exists(this->_args[i])) {
        throw IsNotFileE();
    }
    return 0;
}

int Parser::Check_args_directory() const {
    for (size_t i = 0; i < this->_size; i++) {
        Check_args_directory_i(i);
    }
    return 0;
}

int Parser::Check_args_directory_i(size_t i) const {
    if (!std::filesystem::is_directory(this->_args[i])) {
        throw IsNotDirectoryE();
    }
    return 0;
}

int Parser::Check_args_flags() const {
    for (size_t i = 0; i < this->_size; i++) {
        if (this->_args[i][0] == '-') {
            Check_args_flags_i(i);
        }
    }
    return 0;
}

int Parser::Check_args_flags_i(size_t i) const {
    for (size_t j = 0; j < this->_flags.size(); j++) {
        if (this->_args[i] == this->_flags[j]) {
            return 0;
        }
    }
    throw UnknowFlagE();
}


/***********/
/*  Throw  */
/***********/

const char* Parser::ToMuchArgsE::what() const throw() {
	return ("Too many arguments");
}

const char* Parser::NotEnoughtArgsE::what() const throw() {
	return ("Not enough arguments");
}

const char* Parser::IsNotCharE::what() const throw() {
	return ("Not strictly alphabetical");
}

const char* Parser::IsNotNumberE::what() const throw() {
	return ("Not strictly numbers");
}

const char* Parser::IsNotAlphaNumericE::what() const throw() {
    return ("Not striclty alphanumeric");
}

const char* Parser::IsNotFileE::what() const throw() {
	return ("Not a file");
}

const char* Parser::IsNotDirectoryE::what() const throw() {
	return ("Not a directory");
}

const char* Parser::UnknowFlagE::what() const throw() {
	return ("Unknow flag");
}