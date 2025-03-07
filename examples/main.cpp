
#include "../include/SimpleLogger.h"

using namespace sLogger;

int main(int argc, char **argv)
{


	logger log("test.txt");
	//log.log(WARNING, "testing usage of log");	
	log.log(WARNING, "testing usage of log", LOG_TO_TERMINAL);

	return 0;
}
