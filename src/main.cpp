#include <iostream>
#include "./Graphics/vulkan.h"

int main()
{
    VkVersionBuilder vk_engine_version {
        .major = 1,
        .minor = 0,
        .patch = 0
    };
    VkVersionBuilder vk_application_version {
        .major = 1,
        .minor = 0,
        .patch = 0
    };
    VkDataEngine engine {
        .name = "Fast Engine",
        .version = vk_engine_version
    };
    VkDataApplication application {
        .name = "Fast Engine",
        .version = vk_application_version
    };

    Vulkan Vulkan_application;
    VkInstance Instance = Vulkan_application.vk_create_instance(&application, &engine);

    std::cout << "[SUCESSO] Instancia do Vulkan criada perfeitamente!\n";

    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(Instance, &deviceCount, nullptr);

    std::cout << "Placas de vídeo: " << deviceCount;

    vkDestroyInstance(Instance, nullptr);
    std::cout << "\nInstancia destruida e memoria limpa com sucesso.\n";

    return 0;
}