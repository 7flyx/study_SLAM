/**
 * @file parameter_config.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-11
 * 
 * @copyright Copyright (c) 2025
 */
#include <ros/ros.h>
#include <std_srvs/Empty.h>

int main(int argc, char **argv)
{
    int red, blue, green; // 颜色参数值

    ros::init(argc, argv, "parameter_config");
    ros::NodeHandle nh;
    
    // 读取背景颜色参数--- 从参数服务器读取参数，存储在第二个参数中
    ros::param::get("/background_red", red);
    ros::param::get("/background_blue", blue);
    ros::param::get("/background_green", green);
    ROS_INFO("Read background color parameters: red=%d, blue=%d, green=%d", red, blue, green);


    // 设置颜色参数，并存储进 parameter server
    ros::param::set("/background_red", 255);
    ros::param::set("/background_blue", 0);
    ros::param::set("/background_green", 0);

    ROS_INFO("Set background color parameters: red=%d, blue=%d, green=%d", red, blue, green);


    // 调用服务，清屏
    ros::service::waitForService("/clear"); 
    ros::ServiceClient clear_client = nh.serviceClient<std_srvs::Empty>("/clear");
    std_srvs::Empty clear_srv;
    clear_client.call(clear_srv);


    return 0;
}
