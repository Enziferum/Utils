#pragma once

#define COMMON_MAJOR_VERSION 0
#define COMMON_MINOR_VERSION 1

#if defined(_WIN32)
    #define COMMON_WINDOWS
#elif defined(__APPLE__)
    #define COMMON_MACOS
#elif defined(__unix__)
    #define COMMON_LINUX
#endif