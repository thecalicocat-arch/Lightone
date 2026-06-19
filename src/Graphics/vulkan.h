#pragma once

#ifndef VULKAN_GRAPHICS
#define VULKAN_GRAPHICS
#include <vulkan/vulkan.h>
#include <vulkan/vk_enum_string_helper.h>
#endif

#include <globals.h>
#include <vector>
#include <iostream>

#include "./Vk/VkLayersExtensions.h"

class Vulkan
{
private:
    static VkApplicationInfo LtApplicationInfo;

public:
    static VkInstance LtVulkanCreateInstance();
};