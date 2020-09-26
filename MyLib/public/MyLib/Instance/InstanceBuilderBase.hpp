#pragma once
#include <vulkan/vulkan_core.h>

class InstanceBuilderBase
{
public:
    virtual ~InstanceBuilderBase();
    operator VkInstance ();

protected:
    VkApplicationInfo& appInfo;
    VkInstanceCreateInfo& createInfo;

protected:
    InstanceBuilderBase(VkApplicationInfo& appInfo, VkInstanceCreateInfo& createInfo);
    
};




