/**
 * @file velocity_turtle_vel_publisher.cpp
 * @author your name (you@domain.com)
 * @brief 该例子将发布 turtle1/comd_vel 话题，消息类型为 geometry_msgs/Twist
 * @date 2025-09-10
 * 
 * @copyright Copyright (c) 2025
 */

 #include <ros/ros.h>
 #include <geometry_msgs/Twist.h>

 int main(int argc, char** argv)
 {
    // 1. 初始化 ROS 节点
    ros::init(argc, argv, "velocity_publisher");

    // 2. 创建节点句柄
    ros::NodeHandle n;

    // 3. 创建发布者对象
    ros::Publisher turtle_vel_pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);

    // 4. 设置循环频率,单位: Hz
    ros::Rate loop_rate(10);

    // 5. 循环发布消息
    while (ros::ok())
    {
        // a. 创建并配置消息
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.x = 0.5;   // 设置线速度，单位：m/s
        vel_msg.angular.z = 0.2;  // 设置角速度，单位：rad/s

        // b. 发布消息
        turtle_vel_pub.publish(vel_msg);

        // c. 输出日志信息
        ROS_INFO("turtle_vel_published velocity command: linear.x = %.2f, angular.z = %.2f",
             vel_msg.linear.x, vel_msg.angular.z);

        // d. 按照设定的频率延时
        loop_rate.sleep();
    }

    return 0;
 }