#include "Device/DeviceBuilderBase.hpp"
#include <vulkan/vulkan_core.h>
#include "Device/Device.hpp"
#include "Device/DeviceBuilderExtensions.hpp"

  
DeviceBuilderExtensions DeviceBuilderBase::extensions()
{
    return DeviceBuilderExtensions((DeviceBuilderBase&&)*this);
}
DeviceBuilderBase::~DeviceBuilderBase()
{

}

DeviceBuilderBase::operator VkPhysicalDevice ()
{
    return _devices[0].device();
}

DeviceBuilderBase::DeviceBuilderBase(uint32_t& deviceCount) : _deviceCount(deviceCount), _devices(nullptr)
{
}
DeviceBuilderBase::DeviceBuilderBase(DeviceBuilderBase&& other) : _deviceCount(other._deviceCount), _devices(other._devices)
{

}
