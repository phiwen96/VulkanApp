#pragma once
#include "DeviceBuilderBase.hpp"
#include <vulkan/vulkan_core.h>

class Device;




class DeviceBuilder : public DeviceBuilderBase
{
private:
    uint32_t _deviceCount;

public:
    /**
     * @brief                        Brief...
     * 
     * @param    instance            My Param doc
     */
    DeviceBuilder(const VkInstance& instance);
    virtual ~DeviceBuilder();
  
};




