#pragma once
#include <vulkan/vulkan.h>
#include <vector>
#include <iostream>

typedef struct LtVersionBuilder 
{
    uint32_t major;
    uint32_t minor;
    uint32_t patch;
} LtVersionBuilder;

typedef struct LtDataEngine
{
    const char *name;
    LtVersionBuilder version;
} LtDataEngine;

typedef struct LtDataApplication
{
    const char *name;
    LtVersionBuilder version;
} LtDataApplication;

class Vulkan
{
private:
    static VkApplicationInfo LtApplicationInfo;

public:
    static VkInstance LtVulkanCreateInstance(LtDataApplication *Application, LtDataEngine *Engine);
};