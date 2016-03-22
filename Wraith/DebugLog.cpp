#include "DebugLog.hpp"
#include <iostream>
#include <string>
#include <cstdio>

DebugLog::DebugLog()
{
}
void DebugLog::LogInfo( std::string aMessage)
{
	std::cout << aMessage;
	std::cout << std::endl;
}

DebugLog::~DebugLog()
{
}
