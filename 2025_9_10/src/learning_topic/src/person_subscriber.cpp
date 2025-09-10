/**
 * @file person_subscriber.cpp
 * @author your name (you@domain.com)
 * @brief 该例子将订阅 /person_info 话题，自定义消息类型为 learning_topic::Person
 * @version 0.1
 * @date 2025-09-10
 * 
 * @copyright Copyright (c) 2025
 */

 #include <ros/ros.h>
 #include "learning_topic/Person.h" // 包含自定义消息的头文件

 void personCallback(const learning_topic::Person::ConstPtr& msg)
 {
     // 输出接收到的 Person 消息内容
    ROS_INFO("Received Person: name=%s, age=%d, sex=%d", 
                msg->name.c_str(), msg->age, msg->sex);
 }

 int main(int argc, char **argv)
 {
     ros::init(argc, argv, "person_subscriber"); // 初始化 ROS 节点，节点名称为 person_subscriber
     ros::NodeHandle nh; // 创建节点句柄

     // 创建订阅者，订阅 /person_info 话题，消息队列长度为 10，回调函数为 personCallback
     ros::Subscriber person_sub = nh.subscribe("/person_info", 10, personCallback);

     ros::spin(); // 进入循环，等待回调函数被调用

     return 0;
 }