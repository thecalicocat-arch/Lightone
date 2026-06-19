#include "./VkLayersExtensions.h"

std::vector<VkExtensionProperties> VkExtensions::VkGetAvailableExtensions(){
    uint32_t VkExtensionsLength = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &VkExtensionsLength, nullptr);

    std::vector<VkExtensionProperties> availableExtensions(VkExtensionsLength);

    vkEnumerateInstanceExtensionProperties(nullptr, &VkExtensionsLength, availableExtensions.data());
    return availableExtensions;
}

void VkExtensions::VkSetupExtensions(VkInstanceCreateInfo* VkInstanceCreateInfoObject, const std::vector<const char*> VkExtensionsList){
    VkInstanceCreateInfoObject->enabledExtensionCount = static_cast<uint32_t>(VkExtensionsList.size());
    VkInstanceCreateInfoObject->ppEnabledExtensionNames = VkExtensionsList.data();
}