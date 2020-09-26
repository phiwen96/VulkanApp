#include "Device/Device.hpp"




std::tuple<VkPhysicalDevice*, uint32_t> Device::pdevices(const VkInstance& instance)
{
    VkPhysicalDevice* devices = nullptr;
    uint32_t deviceCount (0);

    vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
    if (deviceCount > 0)
    {
        devices = new VkPhysicalDevice[deviceCount];
        vkEnumeratePhysicalDevices(instance, &deviceCount, devices);
    } 
    return {devices, deviceCount};
}
VkPhysicalDeviceProperties Device::properties (const VkPhysicalDevice& device)
{
    VkPhysicalDeviceProperties properties;
    vkGetPhysicalDeviceProperties (device, &properties);
    return properties;
}
VkPhysicalDeviceFeatures Device::features (const VkPhysicalDevice& device)
{
    VkPhysicalDeviceFeatures features;
    vkGetPhysicalDeviceFeatures (device, &features);
    return features;
}
std::tuple<VkExtensionProperties*, uint32_t> Device::extensions (const VkPhysicalDevice& device)
{
    uint32_t deviceExtensionCount;
    VkExtensionProperties* deviceExtensions = nullptr;

    vkEnumerateDeviceExtensionProperties(device, nullptr, &deviceExtensionCount, nullptr);
    
    if (deviceExtensionCount > 0)
    {
        vkEnumerateDeviceExtensionProperties(device, nullptr, &deviceExtensionCount, deviceExtensions);
    }
    
    return {deviceExtensions, deviceExtensionCount};
}
std::tuple<VkPhysicalDeviceProperties*, uint32_t> Device::properties (VkPhysicalDevice* devices, const uint32_t& deviceCount)
{
    VkPhysicalDeviceProperties* properties = new VkPhysicalDeviceProperties[deviceCount];

    for (int i = 0; i < deviceCount; ++i)
    {
        vkGetPhysicalDeviceProperties (devices[i], properties + i);
    }
    
    return {properties, deviceCount};
}
DeviceBuilder Device::build(const VkInstance& instance)
{
    return DeviceBuilder(instance);
}







class DeviceImp
{
public:
    static std::tuple<Device*, uint32_t> devices (const VkInstance& instance);

    const VkPhysicalDevice&           device() const
    {
        return *_device;
    }
    const VkPhysicalDeviceProperties& properties() const
    {
        return *_properties;
    }
    const VkPhysicalDeviceFeatures&   features() const 
    {
        return *_features;
    }
    const VkExtensionProperties&      extension(int i) const
    {
        return _extensions[i];
    }
    const uint32_t&                   extensionsCount() const 
    {
        return *_extensionCount;
    }
    std::tuple<VkExtensionProperties*, uint32_t> extensions()
    {
        return {_extensions, *_extensionCount};
    }

    DeviceImp(VkPhysicalDevice*&& device) : 
        _device         ((VkPhysicalDevice*&&)device), 
        _properties     (new VkPhysicalDeviceProperties), 
        _features       (new VkPhysicalDeviceFeatures), 
        _extensions     (nullptr),
        _extensionCount (new uint32_t(0))
    {
        vkGetPhysicalDeviceProperties (*_device, _properties);
        vkGetPhysicalDeviceFeatures (*_device, _features);
  
        vkEnumerateDeviceExtensionProperties(*_device, nullptr, _extensionCount, nullptr);
        
        if (*_extensionCount > 0)
        {
            _extensions = new VkExtensionProperties[*_extensionCount];
            vkEnumerateDeviceExtensionProperties(*_device, nullptr, _extensionCount, _extensions);
        }
        
    }
    ~DeviceImp()
    {
        delete _device;
        delete _properties;
        delete _features;
        delete[] _extensions;
        delete _extensionCount;
    }


   DeviceImp() : 
        _device         (nullptr), 
        _properties     (new VkPhysicalDeviceProperties), 
        _features       (new VkPhysicalDeviceFeatures), 
        _extensions     (nullptr),
        _extensionCount (new uint32_t(0))
    {
       
    }
    void init (VkPhysicalDevice*&& device);
private:
    

    VkPhysicalDevice*               _device;
    VkPhysicalDeviceProperties*     _properties;
    VkPhysicalDeviceFeatures*       _features;
    VkExtensionProperties*          _extensions;
    uint32_t*                       _extensionCount;
};

void DeviceImp::init (VkPhysicalDevice*&& device)
    {
        _device = (VkPhysicalDevice*&&) device;

        vkGetPhysicalDeviceProperties (*_device, _properties);
        vkGetPhysicalDeviceFeatures (*_device, _features);
  
        vkEnumerateDeviceExtensionProperties(*_device, nullptr, _extensionCount, nullptr);
        
        if (*_extensionCount > 0)
        {
            _extensions = new VkExtensionProperties[*_extensionCount];
            vkEnumerateDeviceExtensionProperties(*_device, nullptr, _extensionCount, _extensions);
        }
    }

std::tuple<Device*, uint32_t> DeviceImp::devices (const VkInstance& instance)
    {
        auto [pdevices, deviceCount] = Device::pdevices(instance);
        Device* devices = new Device[deviceCount];
        for (int i = 0; i < deviceCount; ++i)
        {
            devices[i].init(pdevices+i);
        }
        
        return{devices, deviceCount};
    }

std::tuple<Device*, uint32_t> Device::devices (const VkInstance& instance)
{
    return DeviceImp::devices(instance);
}


Device::Device(VkPhysicalDevice*&& device) : _imp(new DeviceImp((VkPhysicalDevice*&&) device))
{

}

Device::~Device()
{
    delete _imp;
}
const VkPhysicalDevice& Device::device() const
{
    return _imp -> device();
}
const VkPhysicalDeviceProperties& Device::properties() const
{
    return _imp -> properties();
}
const VkPhysicalDeviceFeatures& Device::features() const 
{
    return _imp -> features();
}
const VkExtensionProperties& Device::extension(int i) const
{
    return _imp -> extension(i);
}
const uint32_t& Device::extensionsCount() const 
{
    return _imp -> extensionsCount();
}
std::tuple<VkExtensionProperties*, uint32_t> Device::extensions()
{
    return _imp->extensions();
}
Device::Device()
{
    _imp = new DeviceImp;
}
void Device::init(VkPhysicalDevice*&& device)
{
    _imp -> init((VkPhysicalDevice*&&)device);
}