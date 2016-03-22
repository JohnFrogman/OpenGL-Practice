#pragma once
#include <string>

class DebugLog
{
public:
	DebugLog();
	void LogInfo( std::string aMessage);
	~DebugLog();
};

