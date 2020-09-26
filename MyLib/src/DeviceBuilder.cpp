#include "Device/DeviceBuilder.hpp"
#include <vulkan/vulkan_core.h>
#include <iostream>
#include "Device/Device.hpp"

using namespace std;



DeviceBuilder::DeviceBuilder(const VkInstance& instance) : _deviceCount(0), DeviceBuilderBase(_deviceCount)
{
    auto [devices, deviceCount] = Device::devices(instance);
    _devices = devices;
    _deviceCount = deviceCount;
}

DeviceBuilder::~DeviceBuilder()
{
    delete[] DeviceBuilderBase::_devices;
}


