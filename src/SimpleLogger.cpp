
#include "../include/SimpleLogger.h"
#include <iomanip>
#include <chrono>
#include <iostream>
#include <fstream>
using namespace sLogger;

static std::string level_to_string(const level_e& level );

logger::logger(std::string filePath) : _filePath(filePath)
{
    //log since last startup 
    this->log(INFO, "<Starting logger>");
}

time_t logger::_getTime()
{
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    return now;
}

/**
 * @brief : converts log level to string
 * @param : const level_e & level
 * @return : formatted level string
 */
static std::string level_to_string(const level_e& level )
{
    std::string ret;
    switch(level)
    {
        case INFO:
            ret = "[INFO]";
            break;
        case WARNING:
            ret = "[WARNING]";
            break;
        case ERROR:
            ret = "[ERROR]";
            break;
        case DEBUG:
            ret = "[DEBUG]";
            break;
        default:
            ret = "[DEBUG]";
            break;
    }

    return ret;
}


void logger::log(level_e level, std::string msg)
{
    //open the assigned log file using fstream
    std::fstream fs;
    fs.open(_filePath, std::fstream::out | std::fstream::app); //open log file in append mode

    if (fs.is_open())
    {
        auto time = _getTime();
        fs<<std::put_time(std::localtime(&time), "%F %T");
        fs<<" ";
        fs<<level_to_string(level);
        fs<<" ";
        fs<<msg;
        fs<<"\n";
        fs.close();
    }else{
        std::cout<<"unable to open : "<<_filePath<<"\n";
    }
    
}