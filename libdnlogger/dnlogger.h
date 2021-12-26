#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include <sstream>
#include <iomanip>

#ifdef _WIN32
#include <Windows.h
#else
#include "messagebox.h"
#endif

class dnlogger
{
private:
    std::string filename;
    bool openpopup;

    std::string currentDateTime();
    void appendLogFile(std::string data);
    void changeColorConsole(int color);
    const wchar_t *GetWC(const char *c);

public:
    dnlogger(std::string filename, bool openpopup = true);

    void log(std::string message, const char *caller = __builtin_FUNCTION());
    void warning(std::string message, const char *caller = __builtin_FUNCTION());
    void error(std::string message, bool fatal, const char *caller = __builtin_FUNCTION());

    void clearLog();
};