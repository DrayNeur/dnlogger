# dnlogger
 
> dnlogger is a lightweight library for logging easily, error report, warnings with an option to open a messagebox on fatal error compatible on all OS.


Let me know if you find any bug in the issue page or by contacting me on telegram or on my website.

```C++
dnlogger* logger = new dnlogger("lastest.log", true);
logger->clearLog();

logger->log("This is a log");
//(26-12-2021 15:54:58) [main] - This is a log

logger->warning("This is a warning");
//(26-12-2021 15:54:58) [main] - WARNING: This is a warning

logger->error("This is an error", false);
//(26-12-2021 15:54:58) [main] - ERROR: This is an error

logger->error("This is a fatal error that open a messagebox", true);
//(26-12-2021 15:54:58) [main] - FATAL ERROR! This is a fatal error that open a messagebox
// + Open a messagebox because it's a fatal error !
```

### Features
- Logging
- Messageboxes
- Console colors

Thanks to [Eleobert](https://github.com/Eleobert) for his messagebox [repository](https://github.com/Eleobert/MessageBox-X11).
