#include <iostream>
#include "./Graphics/vulkan.h"

int main()
{
    Vulkan Vulkan_application;
    VkInstance Instance = Vulkan_application.LtVulkanCreateInstance();

    std::cout << "[SUCESSO] Instancia do Vulkan criada perfeitamente!\n";

    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(Instance, &deviceCount, nullptr);

    std::cout << "Placas de vídeo: " << deviceCount;

    vkDestroyInstance(Instance, nullptr);
    std::cout << "\nInstancia destruida e memoria limpa com sucesso.\n";

    return 0;
}