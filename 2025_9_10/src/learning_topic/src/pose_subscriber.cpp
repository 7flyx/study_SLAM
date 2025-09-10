/**
 * @file pose_subscriber.cpp
 * @author your name (you@domain.com)
 * @brief 该例子 将订阅  /turtle1/pose 话题，消息类型是 turtlesim/Pose
 * @version 0.1
 * @date 2025-09-10
 * 
 * @copyright Copyright (c) 2025
 */

 #include <ros/ros.h>
 #include <turtlesim/Pose.h> // 消息类型头文件

void poseCallback(const turtlesim::Pose::ConstPtr& msg)
{
    ROS_INFO("Turtle Pose: x=%.2f, y=%.2f, theta=%.2f", msg->x, msg->y, msg->theta);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "pose_subscriber"); // 初始化 ROS 节点，节点名称为 pose_subscriber
    ros::NodeHandle nh; // 创建节点句柄

    // 创建订阅者，订阅 /turtle1/pose 话题，消息队列长度为 10，回调函数为 poseCallback
    ros::Subscriber sub = nh.subscribe("/turtle1/pose", 10, poseCallback);

    ros::spin(); // 进入循环，等待回调函数被触发

    return 0;
}