/**
 * @file persion_publisher.cpp
 * @author your name (you@domain.com)
 * @brief 该例子将发布 /person_info 话题，消息类型为 learning_topic::Person
 * @version 0.1
 * @date 2025-09-10
 * 
 * @copyright Copyright (c) 2025
 */

#include <ros/ros.h>
#include "learning_topic/Person.h" // 包含自定义消息的头文件


int main(int argc, char **argv)
{
    ros::init(argc, argv, "person_publisher"); // 初始化 ROS 节点，节点名称为 person_publisher
    ros::NodeHandle nh; // 创建节点句柄

    // 创建发布者，发布 /person_info 话题，消息队列长度为 10
    ros::Publisher person_pub = nh.advertise<learning_topic::Person>("/person_info", 10);

    ros::Rate loop_rate(1); // 设置循环频率为 1 Hz

    while (ros::ok())
    {
        learning_topic::Person person_msg; // 创建 Person 消息对象
        person_msg.name = "Alice"; // 设置姓名
        person_msg.age = 30; // 设置年龄
        person_msg.sex = learning_topic::Person::male; // 设置性别

        person_pub.publish(person_msg); // 发布消息
        ROS_INFO("Published Person: name=%s, age=%d, height=%d", 
                 person_msg.name.c_str(), person_msg.age, person_msg.sex);

        loop_rate.sleep(); // 按照设定的频率休眠
    }

    return 0;
}