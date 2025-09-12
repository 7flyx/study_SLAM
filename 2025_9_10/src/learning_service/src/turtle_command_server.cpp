/**
 * @file turtle_command_server.cpp
 * @author your name (you@domain.com)
 * @brief 该例子将创建一个服务端，服务端的服务类型为geometry_msgs::Twist.
 * 服务端的回调函数将根据请求的线速度和角速度，控制海龟移动.
 * @version 0.1
 * @date 2025-09-11
 * 
 * @copyright Copyright (c) 2025
 */

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_srvs/Trigger.h>

ros::Publisher pub;
bool pub_flag = false; // 控制海龟的移动状态

// 回调函数,输入参数 req, 输出参数 resp
bool commandCallback(std_srvs::Trigger::Request &req,
                     std_srvs::Trigger::Response &resp)
{
    pub_flag = !pub_flag;
    ROS_INFO("publish turtle velocitu command, pub_flag: %s", pub_flag == true?"yes":"no");
    // 设置反馈数据
    resp.success = true;
    resp.message = "Change turtle command state!";
}

int main(int argc, char **argv)
{

    // 1. 初始化ROS节点
    ros::init(argc, argv, "turtle_command_server");
    // 2. 创建节点句柄
    ros::NodeHandle nh;

    // 3. 创建服务
    ros::ServiceServer service = nh.advertiseService("turtle_command", commandCallback);
    
    // 4. 创建发布者
    pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);

    ROS_INFO("turtle command server is ready!");

    ros::Rate rate(10); // 设置循环的频率

    while (ros::ok())
    {
        // 5. 循环等待回调函数，查看一次回调函数队列
        ros::spinOnce();
        // 6. 发布消息
        if (pub_flag)
        {
            geometry_msgs::Twist twist;
            twist.linear.x = 0.5;
            twist.angular.z = 0.2;
            pub.publish(twist);
        }
        rate.sleep();
    }

    return 0;
}