#pragma once
#include "DeviceBuilderBase.hpp"


class DeviceBuilderExtensions : public DeviceBuilderBase
{
private:
    /* data */
public:
    DeviceBuilderExtensions(DeviceBuilderBase&& other);
    DeviceBuilderExtensions& require(const char* extensionName);
    
};




