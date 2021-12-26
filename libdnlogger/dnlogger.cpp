#include "dnlogger.h"

//PRIVATE
std::string dnlogger::currentDateTime()
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y %H:%M:%S");
    auto str = oss.str();
    return str;
}
void dnlogger::appendLogFile(std::string data)
{
    std::ofstream logfile;

    logfile.open(this->filename, std::ios_base::app);
    logfile << data.c_str() << std::endl;
}
void dnlogger::changeColorConsole(int color)
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (color == 1)
    {
        SetConsoleTextAttribute(hConsole, 15);
    }
    else if (color == 2)
    {
        SetConsoleTextAttribute(hConsole, 12);
    }
    else if (color == 3)
    {
        SetConsoleTextAttribute(hConsole, 14);
    }
#else
    if (color == 1)
    {
        std::cout << "\e[0m";
    }
    else if (color == 2)
    {
        // red
        std::cout << "\e[1;31m";
    }
    else if (color == 3)
    {
        // yellow
        std::cout << "\e[1;33m";
    }
#endif
}
const wchar_t *dnlogger::GetWC(const char *c)
{
    const size_t cSize = strlen(c) + 1;
    wchar_t *wc = new wchar_t[cSize];
    mbstowcs(wc, c, cSize);

    return wc;
}


//PUBLIC
dnlogger::dnlogger(std::string filename, bool openpopup)
{
    this->filename = filename;
    this->openpopup = openpopup;
}
void dnlogger::log(std::string message, const char *caller)
{
    std::string time = this->currentDateTime();
    std::string output = "(" + time + ") [" + std::string(caller) + "] - " + message;

    std::cout << output.c_str() << std::endl;

    this->appendLogFile(output);
}

void dnlogger::warning(std::string message, const char *caller)
{
    std::string time = this->currentDateTime();
    std::string output = "(" + time + ") [" + std::string(caller) + "] - WARNING: " + message;

    this->changeColorConsole(3);
    std::cout << output.c_str() << std::endl;
    this->changeColorConsole(1);

    this->appendLogFile(output);
}

void dnlogger::error(std::string message, bool fatal, const char *caller)
{
    std::string time = this->currentDateTime();
    std::string output = "(" + time + ") [" + std::string(caller) + "] - " + (fatal ? "FATAL ERROR!" : "ERROR:") + " " + message;

    this->changeColorConsole(2);
    std::cout << output.c_str() << std::endl;
    this->changeColorConsole(1);

    if (fatal && this->openpopup)
    {
#ifdef _WIN32
        MessageBoxA(0, message.c_str(), "ERROR!", 0);
#else
        char buffer[1024];
        sprintf(buffer, "[%s] %s", caller, message.c_str());
        Button button1[1];
        button1[0].label = (wchar_t *)GetWC("Continue");
        button1[0].result = 0;
        Messagebox("ERROR!", GetWC(buffer), button1, 1);
#endif
    }

    this->appendLogFile(output);
}

void dnlogger::clearLog()
{
    std::ofstream ofs;
    ofs.open(this->filename, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}