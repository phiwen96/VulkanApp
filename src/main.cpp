#include <iostream>
#include <tuple>
#include <Hund.hpp>
// #include <MyLib/Person.hpp>
#include <MyLib/Instance/Instance.hpp>
#include <vulkan/vulkan_core.h>
#include <MyLib/Device/Device.hpp>
// #include <MyLib/InstanceBuilder.hpp>
// #include <MyLib/InstanceBuilderBase.hpp>
#include <MyLib/Device/DeviceBuilderExtensions.hpp>
// #include <MyLib/Device/DeviceBuilderBase.hpp>
// #include <MyLib/Device/DeviceBuilder.hpp>
#include <MyLib/Utility/Vector.hpp>
#include <functional>
#include <concepts>
// #include <Person.hpp>
using namespace std;


struct T
{
    const char* _str;
    T(const char* str) : _str(str)
    {

    }
    friend ostream& operator<<(ostream& os, const T& t)
    {
        os << t._str;
        return os;
    }

};


int main()
{


    Vector<int> vec;
    

    auto printVec = [&vec]
    {
        vec.for_each([](const int& i){
            cout << i << endl;
        });
    };
    vec.push_back(2);
    vec.push_back(6);
    vec.push_back(10);
    vec += 3;
    vec += 5;
    vec += -11;

    printVec();

    vec -= 3;
    []template<class T>{}();
    [&](int elem){
        for (int i = 0; i < vec._count; ++i)
        {
            if (*vec._t[i] == elem)
            {
                delete vec._t[i];
                cout << "!!" << *vec._t[i] << endl;
                for (int j = i + 1; j < vec._count; ++j)
                {
                    cout << *vec._t[j] << endl;
                    vec._t[j - 1] =  vec._t[j];
                }
                vec._count--;
            }
            
        }
        cout << "-----" << endl;
        printVec();
    }(3);


    
    cout << "return 0" << endl;
    return 0;
    int* numbers = new int[10]{[0 ... 9] = 0};
    
    const char* str = "hej";

    T* ts = new T[3]{[0 ... 2] = str};
   
    
    for (T* i = ts; i < ts + 3; i++)
    {
        cout << (ts + 3) - i << endl;
        cout << *ts << endl;
    }
    
    
    


    return 0;

    VkInstance instance = Instance::build();
    VkPhysicalDevice gpu = Device::build(instance).extensions().require("hej");

    // auto [a, b] = Device::devices (instance);
    // cout << a->properties().deviceName << endl;

    // auto [devices, deviceCount] = Device::pdevices (instance);
    // auto properties = Device::properties (devices[0]);
    // auto features = Device::features (devices[0]);
    // auto [extensions, extensionCount] = Device::extensions (devices[0]);
    
    
    

    // uint32_t deviceCount = 0;
    // vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
    // VkPhysicalDevice* devices = new VkPhysicalDevice[deviceCount];
    // vkEnumeratePhysicalDevices(instance, &deviceCount, devices);
    // cout << deviceCount << endl;
    // for (size_t i = 0; i < deviceCount; i++)
    // {
    //     VkPhysicalDeviceProperties deviceProperties;
    //     vkGetPhysicalDeviceProperties(devices[i], &deviceProperties);
    //     cout << deviceProperties.deviceName << endl;
    // }
    


    // Person p;
    Hund hund;
    cout << "Hello World!" << endl;
    return 0;
}