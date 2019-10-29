/* 
 * This file is part of Yahtzee (https://github.com/JolokHD/Yahtzee) 
 * Copyright (C) 2019  Jannes Althoff
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for mordde details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>
 */
#include "cli_paser.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool parseInput(std::string in){
    std::vector<std::string> args;
    std::istringstream iss(in);
    for(std::string s; iss >> s; )
        args.push_back(s);
    if(args.at(0) == "show"){
        if(args.size() == 1){
            std::cout << "Too few arguments" << std::endl;
            return false;
        } else {
            return funcShow(args.at(1));
        }
    } else {
        std::cout << "Invalid Command. For Help type help or help <command>." << std::endl;
        return false;
    }
}
bool funcShow(std::string arg){
    if(arg == "w"){
        std::cout << "This program is distributed in the hope that it will be useful," << std::endl
                  << "but WITHOUT ANY WARRANTY; without even the implied warranty of"  << std::endl
                  << "ERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the"    << std::endl
                  << "GNU General Public License for mordde details."                  << std::endl;
    } else if(arg == "c"){
        std::cout << "This program is free software: you can redistribute it and/or modify" << std::endl
                  << "it under the terms of the GNU General Public License as published by" << std::endl
                  << "the Free Software Foundation, either version 3 of the License, or"    << std::endl
                  << "(at your option) any later version."                                  << std::endl;
    } else {
        std::cout << "Invalid Argument" << std::endl;
    }
    return false;
}