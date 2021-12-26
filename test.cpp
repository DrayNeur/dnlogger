#include "libdnlogger/dnlogger.h"

int main() {
    dnlogger* logger = new dnlogger("lastest.log", true);
    logger->clearLog();
    
    logger->log("testlmao");
    logger->warning("testlmao");
    logger->error("testlmao", false);
    logger->error("testlmao", true);

    return 0;
}