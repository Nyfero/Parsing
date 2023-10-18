#pragma once

#include <unistd.h>
#include <iostream>
#include <filesystem>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
#include "../class/Parser.hpp"

class Parser;

int main(int ac, char **av);


// tester.cpp
int testeur(Parser parse);
int CheckNbArg(Parser parse);    
int CheckIsChar(Parser parse);
int CheckIsNb(Parser parse);
int CheckIsFile(Parser parse);
int CheckIsFolder(Parser parse);