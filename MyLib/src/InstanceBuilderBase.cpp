#include "Instance/InstanceBuilderBase.hpp"
#include <vulkan/vulkan_core.h>
#include <iostream>


InstanceBuilderBase::~InstanceBuilderBase()
{
    
}

InstanceBuilderBase::operator VkInstance ()
{
    VkInstance instance;
    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
    {
        throw std::runtime_error("Failed to create instance!");
    }

    return instance;
    
}

InstanceBuilderBase::InstanceBuilderBase(VkApplicationInfo& appInfo, VkInstanceCreateInfo& createInfo) : appInfo(appInfo), createInfo(createInfo)
{
}