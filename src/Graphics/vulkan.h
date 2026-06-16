#pragma once
#include <vulkan/vulkan.h>
#include <vector>
#include <iostream>

typedef struct VkVersionBuilder 
{
    uint32_t major;
    uint32_t minor;
    uint32_t patch;
} VkVersionBuilder;

typedef struct VkDataEngine
{
    const char *name;
    VkVersionBuilder version;
} VkDataEngine;

typedef struct VkDataApplication
{
    const char *name;
    VkVersionBuilder version;
} VkDataApplication;

class Vulkan
{
private:
    static VkApplicationInfo vk_application_info;

public:
    static VkInstance vk_create_instance(VkDataApplication *Application, VkDataEngine *Engine);
};