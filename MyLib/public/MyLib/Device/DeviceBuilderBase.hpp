#pragma once
#include <vulkan/vulkan_core.h>
#include <tuple>



class Device;

class DeviceBuilderBase
{
public:
    class DeviceBuilderExtensions extensions();
    virtual ~DeviceBuilderBase();
    operator VkPhysicalDevice ();

protected:
    Device* _devices;
    uint32_t& _deviceCount;

    DeviceBuilderBase(uint32_t& deviceCount);
    DeviceBuilderBase(DeviceBuilderBase&& other);
};