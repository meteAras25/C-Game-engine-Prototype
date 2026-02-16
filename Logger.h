#ifndef AETHER_LOGGER_H
#define AETHER_LOGGER_H

#include <string>

    class Logger {
        public:
            enum class Level {
                Info,
                Warning,
                Error
            };


        static void Log(const std::string& message, Level level = Level::Info);

            private:
                Logger() = delete; 

    };


#endif