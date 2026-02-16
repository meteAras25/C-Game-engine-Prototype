#include "Logger.h"
#include <iostream>

    void Logger::Log(const std::string& message, Level level) {
        switch(level) {
            case Level::Info:
                std::cout << "[INFO]";
                break;
            case Level::Warning:
                std::cout << "[WARNİNG]";
            case Level::Error:
                std::cout << "[ERROR]";
                break;    
        }

        std::cout << message << std::endl;

    }