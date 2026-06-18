#include "./vulkan.h"

VkApplicationInfo Vulkan::LtApplicationInfo{};

VkInstance Vulkan::LtVulkanCreateInstance(LtDataApplication *Application, LtDataEngine *Engine)
{
    // We begin by initializing the application information.
    LtApplicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    LtApplicationInfo.pApplicationName = Application->name;
    LtApplicationInfo.applicationVersion = VK_MAKE_VERSION(
        Application->version.major,
        Application->version.minor,
        Application->version.patch
    );
    LtApplicationInfo.pEngineName = Engine->name;
    LtApplicationInfo.engineVersion = VK_MAKE_VERSION(
        Engine->version.major, 
        Engine->version.minor, 
        Engine->version.patch
    );
    LtApplicationInfo.apiVersion = VK_API_VERSION_1_0;

    // We create the basic information for the Vulkan instance.
    VkInstanceCreateInfo CreateInfo{};
    CreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    CreateInfo.pApplicationInfo = &LtApplicationInfo;
    CreateInfo.pNext = nullptr;
    CreateInfo.flags = 0;
    // Reference your extension and layer structure below.
    // For now, we don't have direct support for layers or extensions.
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