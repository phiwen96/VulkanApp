#include "Instance/InstanceBuilder.hpp"
#include <vulkan/vulkan_core.h>


InstanceBuilder::~InstanceBuilder()
{
    
}
InstanceBuilder::InstanceBuilder() : 
    appInfo{
    .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
    .pApplicationName = "My App",
    .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
    .pEngineName = "no Engine",
    .engineVersion = VK_MAKE_VERSION(1, 0, 0),
    .apiVersion = VK_API_VERSION_1_0
}, 
    createInfo{
    .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
    .pApplicationInfo = &appInfo,
    .enabledExtensionCount = 0,
    .ppEnabledExtensionNames = nullptr,
    .enabledLayerCount = 0,
    .ppEnabledLayerNames = nullptr
}, 
    InstanceBuilderBase(appInfo, createInfo)
{
    createInfo.pApplicationInfo = &appInfo;
    // createInfo.ppEnabledExtensionNames = new char*[3];
}