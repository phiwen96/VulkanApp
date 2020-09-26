#pragma once
#include "DeviceBuilder.hpp"
#include <tuple>
#include <vulkan/vulkan_core.h>


class Device
{
public:
    static DeviceBuilder                                        build       (const VkInstance& instance);
    static std::tuple<Device*, uint32_t>                        devices     (const VkInstance& instance);
    static std::tuple<VkPhysicalDevice*, uint32_t>              pdevices    (const VkInstance& instance);
    static VkPhysicalDeviceProperties                           properties  (const VkPhysicalDevice& device);
    static VkPhysicalDeviceFeatures                             features    (const VkPhysicalDevice& device);
    static std::tuple<VkExtensionProperties*, uint32_t>         extensions  (const VkPhysicalDevice& device);
    static std::tuple<VkPhysicalDeviceProperties*, uint32_t>    properties  (VkPhysicalDevice* devices, const uint32_t& deviceCount);



    const VkPhysicalDevice&           device()          const;
    const VkPhysicalDeviceProperties& properties()      const;
    const VkPhysicalDeviceFeatures&   features()        const;
    const VkExtensionProperties&      extension(int i)  const;
    const uint32_t&                   extensionsCount() const;
    std::tuple<VkExtensionProperties*, uint32_t> extensions();


  
    Device (VkPhysicalDevice*&& device);
    virtual ~Device();








private:
    Device();
    void init(VkPhysicalDevice*&&);
    class DeviceImp* _imp;
    friend class DeviceImp;

};



