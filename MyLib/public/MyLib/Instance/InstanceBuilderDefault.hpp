#pragma once
#include "InstanceBuilderBase.hpp"
#include <vulkan/vulkan_core.h>


class InstanceBuilderDefault : public InstanceBuilderBase
{
private:
    /* data */
public:
    InstanceBuilderDefault(VkApplicationInfo& appInfo, VkInstanceCreateInfo& createInfo);
    ~InstanceBuilderDefault();
};

InstanceBuilderDefault::InstanceBuilderDefault(VkApplicationInfo& appInfo, VkInstanceCreateInfo& createInfo) : InstanceBuilderBase(appInfo, createInfo)
{
    
}

InstanceBuilderDefault::~InstanceBuilderDefault()
{
}
