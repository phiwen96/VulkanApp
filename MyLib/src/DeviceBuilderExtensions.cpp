#include "Device/DeviceBuilderExtensions.hpp"
#include "Device/Device.hpp"
#include <vulkan/vulkan_core.h>
#include <tuple>
#include <iostream>
#include <cstring>
using namespace std;

DeviceBuilderExtensions::DeviceBuilderExtensions(DeviceBuilderBase&& other) : DeviceBuilderBase((DeviceBuilderBase&&)other)
{
}

DeviceBuilderExtensions& DeviceBuilderExtensions::require(const char* extensionName)
{
    for (Device* i = _devices; i < _devices + _deviceCount; ++i)
        {
            bool found = [&]{
                auto [extensions, extensionCount] = i->extensions();
                    for (VkExtensionProperties* i = extensions; i < extensions + extensionCount; ++i)
                    {
                        if (strcmp(extensionName, i->extensionName) == 0)
                        {
                            return true;
                        }
                        
                    }
                    return false;
            }(); 
            if (!found)
            {
                
            }
                       
        }
    
    
    
//     for(const auto& i : m_AvailableExtensions){
//             if ( strcmp(extensionName, i.extensionName) == 0 ) {
//                   m_requiredExtensions.push_back(extensionName);
//                   return true;
//             }
// //            if ( strcmp(i.extensionName, extensionName) == 0 ) {
// //                  return true;
// //            }
//       }
    return *this;
}