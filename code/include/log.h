#ifndef __LIMITLESSSOUL_LOG__
#define __LIMITLESSSOUL_LOG__

#include <fstream>

class Logger
{
public:
    Logger();
    ~Logger();
    void clear();
    template <class InType>
    Logger &operator<<(const InType &arg)
    {
        logfile << arg;
        return *this;
    }

private:
    static std::ofstream logfile;
};

#endif //!__LIMITLESSSOUL_LOG__