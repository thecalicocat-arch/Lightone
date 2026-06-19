#pragma once

// Important: The project needs to be configured to compile in versions equal to or higher than C++17.
// If you are using versions below C++17, check compatibility with the tools in this header.
namespace GLOBAL_ENGINE_DATA{
    inline constexpr const char* ENGINE_NAME = "Lightone Engine";
    inline constexpr const char* APPLICATION_NAME = "Lightone";
    inline constexpr struct ENGINE_VERSION {
        int MAJOR = 0;
        int MINOR = 1;
        int PATCH = 0;
    } ENGINE_VERSION;
    inline constexpr struct APPLICATION_VERSION {
        int MAJOR = 0;
        int MINOR = 1;
        int PATCH = 0;
    } APPLICATION_VERSION;
};