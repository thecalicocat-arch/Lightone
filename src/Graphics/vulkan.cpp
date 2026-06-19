#include "./vulkan.h"

VkApplicationInfo Vulkan::LtApplicationInfo{};

const char *LtTranslateVulkanInstanceException(VkResult Result)
{
    switch (Result)
    {
    case VK_ERROR_OUT_OF_HOST_MEMORY:
        return "Memory could not be allocated to the process. Please check your system compatibility and try again.";
    case VK_ERROR_OUT_OF_DEVICE_MEMORY:
        return "We were unable to allocate graphics memory to the process. Try updating your drivers or checking the compatibility of your devices.";
    case VK_ERROR_INITIALIZATION_FAILED:
        return "The Vulkan instance could not be initialized. Try updating your drivers or checking the compatibility of your devices.";
    case VK_ERROR_INCOMPATIBLE_DRIVER:
        return "The current driver is incompatible with the requested Vulkan version. Try updating your drivers or checking the compatibility of your devices.";
    case VK_ERROR_EXTENSION_NOT_PRESENT:
        return "A required Vulkan extension was not found. Try updating your drivers or checking the compatibility of your devices.";
    case VK_ERROR_LAYER_NOT_PRESENT:
        return "A mandatory validation layer is not installed. Please check your system compatibility and try again.";
    default:
        return "An unknown error occurred while trying to initialize the Vulkan instance. Please try again.";
    }
}

VkInstance Vulkan::LtVulkanCreateInstance()
{

    // We begin by initializing the application information.
    LtApplicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    LtApplicationInfo.pApplicationName = GLOBAL_ENGINE_DATA::APPLICATION_NAME;
    LtApplicationInfo.applicationVersion = VK_MAKE_VERSION(
        GLOBAL_ENGINE_DATA::APPLICATION_VERSION.MAJOR,
        GLOBAL_ENGINE_DATA::APPLICATION_VERSION.MINOR,
        GLOBAL_ENGINE_DATA::APPLICATION_VERSION.PATCH);
    LtApplicationInfo.pEngineName = GLOBAL_ENGINE_DATA::ENGINE_NAME;
    LtApplicationInfo.engineVersion = VK_MAKE_VERSION(
        GLOBAL_ENGINE_DATA::ENGINE_VERSION.MAJOR,
        GLOBAL_ENGINE_DATA::ENGINE_VERSION.MINOR,
        GLOBAL_ENGINE_DATA::ENGINE_VERSION.PATCH);
    LtApplicationInfo.apiVersion = VK_API_VERSION_1_0;

    VkExtensions Extensions;
    std::vector<VkExtensionProperties> availableExtensions = Extensions.VkGetAvailableExtensions();

    for (int i = 0; i < availableExtensions.size(); i++)
    {
        std::cout << availableExtensions[i].extensionName << std::endl;
    }

    // We create the basic information for the Vulkan instance.
    VkInstanceCreateInfo CreateInfo{};
    CreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    CreateInfo.pApplicationInfo = &LtApplicationInfo;
    CreateInfo.pNext = nullptr;
    CreateInfo.flags = 0;
    // Reference your extension and layer structure below.
    // For now, we don't have direct support for layers or extensions.
    Extensions.VkSetupExtensions(&CreateInfo, {
        "VK_KHR_surface"
    });
    CreateInfo.enabledLayerCount = 0;
    CreateInfo.ppEnabledLayerNames = nullptr;

    VkInstance Instance;
    VkResult Result = vkCreateInstance(&CreateInfo, nullptr, &Instance);

    if (Result != VK_SUCCESS)
    {
        const char* message = LtTranslateVulkanInstanceException(Result);
        throw std::runtime_error(message);
    }

    return Instance;
}