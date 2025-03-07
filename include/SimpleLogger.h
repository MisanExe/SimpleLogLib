#pragma once
#include <string>

/*
Log config
*/
#define LOG_TO_TERMINAL (1U<<0)

namespace sLogger
{
    enum level_e
    {
        INFO,
        WARNING,
        ERROR,
        DEBUG
    } ;  

    class logger
    {
        public :
            /**
             * @brief : constructor for the logger, takes a filePath to the intended log file.         
             * @param : std::string filePath e.g ./logs/<log file>
             * @return : none
             */
            logger(std::string filePath);
            
            /**
             * @brief : Writes logs to file 
             * @param : level_e level (log level : ERROR, WARNING, INFO, DEBUG), string msg(user specified log messages)
             * @return : none
             */
            void log(level_e level, std::string msg);

           /** @brief : Writes logs to file , with additional config
            * @param : level_e level (log level : ERROR, WARNING, INFO, DEBUG), string msg(user specified log messages)
            * @return : none
            */
           void log(level_e level, std::string msg, int config);

        private :

            std::string _filePath;

            /**
             * @brief : returns time as a string 
             * @param : none
             * @return : time_t 
             */
            time_t _getTime();
            


    };
}