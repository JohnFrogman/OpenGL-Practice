#include <stdio.h>
#include <iostream>
#include "DebugLog.hpp"
#include "ViewPort.hpp"
#include <string>

int main()
{
	DebugLog* Log = new DebugLog();
	ViewPort* MainViewPort = new ViewPort(800, 600, Log);
	return 0;
}