#pragma once
#include <vulkan/vulkan_core.h>
#include "InstanceBuilderBase.hpp"

class InstanceBuilder : public InstanceBuilderBase
{
public:
    virtual ~InstanceBuilder();

private:
    /* data */
    VkApplicationInfo appInfo;
    VkInstanceCreateInfo createInfo;

private:
    InstanceBuilder();
    

    friend class Instance;
};




