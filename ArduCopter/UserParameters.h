#pragma once

#include <AP_Param/AP_Param.h>

class UserParameters {

public: 
    UserParameters() {
    data_gas=0;  //气体数据缓存信息
    i_gas=0; //气体数组维护标签
    for (int i=0;i<9;i++)
    {
        gas_info[i]=0x00; //气体数据初始化
    }
    }
    static const struct AP_Param::GroupInfo var_info[];
    // Put accessors to your parameter variables here
     //UserCode usage example: g2.user_parameters.get_int8Param()
    AP_Int8 get_int8Param() const { return _int8; }
    AP_Int16 get_int16Param() const { return _int16; }
    AP_Float get_floatParam() const { return _float; }
    void read_data();
    void send_data();

private:
    // Put your parameter variable definitions here
    uint8_t data_gas;  //气体数据缓存信息
    unsigned int i_gas; //气体数组维护标签
    uint8_t gas_info[9];//气体数组缓存数据

    AP_Int8 _int8;
    AP_Int16 _int16;
    AP_Float _float;
};
