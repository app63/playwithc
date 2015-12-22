//
//  OS.cpp
//  playwithc
//
//  Created by Aditya on 12/13/15.
//  Copyright © 2015 Aditya. All rights reserved.
//

#include "OS.hpp"
#include "string"

using namespace std;

string getOsName()
{
#ifdef _WIN32
    return "Windows 32-bit";
#elif _WIN64
    return "Windows 64-bit";
#elif __unix || __unix__
    return "Unix";
#elif __APPLE__ || __MACH__
    return "Mac OSX";
#elif __linux__
    return "Linux";
#elif __FreeBSD__
    return "FreeBSD";
#else
    return "Other";
#endif
}