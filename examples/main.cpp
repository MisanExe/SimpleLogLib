#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include "../include/SimpleLogger.h"

using namespace std::chrono;
using namespace sLogger;

int main(int argc, char **argv)
{


	logger log("test.txt");
	log.log(WARNING, "testing usage of log");	

	return 0;
}
