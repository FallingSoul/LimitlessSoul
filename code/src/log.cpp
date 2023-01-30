#include <chrono>
#include <string>
#include <io.h>
#include <sys/stat.h>
#include "log.h"

std::ofstream Logger::logfile;

Logger::Logger()
{
    if (logfile.is_open() == false)
    {
        char buffer[25] = {0};
        auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::strftime(buffer, 25, "./log/%Y%m%D%H%M%S.log", std::localtime(&t));
        logfile.open(buffer);
        if (logfile.is_open() == false)
        {
            throw "Cannot create log file!";
        }
    }
}
Logger::~Logger()
{
    this->logfile.close();
}

void Logger::clear()
{
    _finddata_t fd = {0};
    uintptr_t handle = _findfirst("./log/*.log",&fd);
    if(handle == 0)
    {
        return;
    }
    do
    {
        if(fd.attrib & S_IFREG)
        {
            std::remove(("./log/" + std::string(fd.name)).data());
        }
    } while (_findnext(handle,&fd) == 0);
}
