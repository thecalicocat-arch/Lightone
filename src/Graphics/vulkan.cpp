#include "./vulkan.h"

VkApplicationInfo Vulkan::vk_application_info{};

VkInstance Vulkan::vk_create_instance(VkDataApplication *Application, VkDataEngine *Engine)
{
    vk_application_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    vk_application_info.pApplicationName = Application->name;
    vk_application_info.applicationVersion = VK_MAKE_VERSION(
        Application->version.major,
        Application->version.minor,
        Application->version.patch
    );
    vk_application_info.pEngineName = Engine->name;
    vk_application_info.engineVersion = VK_MAKE_VERSION(
        Engine->version.major, 
        Engine->version.minor, 
        Engine->version.patch
    );
    vk_application_info.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo CreateInfo{};
    CreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    CreateInfo.pApplicationInfo = &vk_application_info;
    CreateInfo.pNext = nullptr;
    CreateInfo.flags = 0;
    CreateInfo.enabledExtensionCount = 0;
    CreateInfo.ppEnabledExtensionNames = nullptr;
    CreateInfo.enabledLayerCount = 0;
    CreateInfo.ppEnabledLayerNames = nullptr;

    VkInstance Instance;
    VkResult Result = vkCreateInstance(&CreateInfo, nullptr, &Instance);

    if (Result != VK_SUCCESS)
    {
        std::cerr << "The Vulkan instance could not be initialized. Details: " << Result << std::endl;
    }

    return Instance;
}