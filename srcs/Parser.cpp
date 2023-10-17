#include "../class/Parser.hpp"


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

void Parser::Set_flags() {
    for (size_t i = 0; i < this->_size; i++) {
        if (this->_args[i][0] == '-') {
            this->_flags.push_back(_args[i]);
        }
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

int Parser::Check_size_less_than(size_t i) const {
    if (this->_size >= i)
        throw ToMuchArgs();
    return 0;
}

int Parser::Check_size_greater_than(size_t i) const {
    if (this->_size <= i)
        throw NotEnoughtArgs();
    return 0;
}


/***********/
/*  Throw  */
/***********/

const char* Parser::ToMuchArgs::what() const throw() {
	return ("To much arguments");
}

const char* Parser::NotEnoughtArgs::what() const throw() {
	return ("Not enought arguments");
}