#pragma once
#ifndef VULKAN_GRAPHICS
#define VULKAN_GRAPHICS
#include <vulkan/vulkan.h>
#include <vulkan/vk_enum_string_helper.h>
#endif

#include <vector>

class VkExtensions
{
public:
    static std::vector<VkExtensionProperties> VkGetAvailableExtensions();
    static void VkSetupExtensions(VkInstanceCreateInfo* VkInstanceCreateInfoObject, const std::vector<const char*> VkExtensionsList);
};