#pragma once

// Important: The project needs to be configured to compile in versions equal to or higher than C++17.
// If you are using versions below C++17, check compatibility with the tools in this header.
namespace GLOBAL_ENGINE_DATA{
    inline constexpr struct VERSION {
        int MAJOR = 0;
        int MINOR = 1;
        int PATCH = 0;
    } VERSION;
};