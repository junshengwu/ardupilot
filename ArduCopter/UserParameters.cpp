#include "UserParameters.h"
#include "Copter.h"
#include "GCS_Mavlink.h"
#include <AP_Param/AP_Param.h>

// "USR" + 13 chars remaining for param name 
const AP_Param::GroupInfo UserParameters::var_info[] = {
    
    // Put your parameters definition here
    // Note the maximum length of parameter name is 13 chars
    AP_GROUPINFO("_INT8", 0, UserParameters, _int8, 0),
    AP_GROUPINFO("_INT16", 1, UserParameters, _int16, 0),
    AP_GROUPINFO("_FLOAT", 2, UserParameters, _float, 0),
    AP_GROUPEND
};

void UserParameters::send_data()
{

    while(hal.uartE->available()>0)//当串口有数据输入 
    {
        data_gas=hal.uartE->read();
        gas_info[i_gas++]=(uint8_t(data_gas));


        if(i_gas>=9)
    {
        unsigned char j,sum=0;
        for( j=0;j<8;j++)
        {
            sum+=gas_info[j];
        }
        sum=(~sum)+1;
        if(sum==gas_info[8])
        {
            mavlink_msg_on_receive_gas_send(MAVLINK_COMM_1,gas_info[5],gas_info[3],gas_info[4],gas_info[0],gas_info[0],gas_info[0],gas_info[6]);//向上转发浓度信息
        }
        i_gas=0;//指针归零
    }

    }
}

