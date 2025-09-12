/**
 * @file turtle_spawn.cpp
 * @author your name (you@domain.com)
 * @brief 该例子将请求 /spawn 服务，在指定位置创建新的海龟，消息类型turtlesim::Spawn
 * @version 0.1
 * @date 2025-09-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
// -*- coding: utf-8 -*-

#include <ros/ros.h>
#include <turtlesim/Spawn.h>
int main(int argc, char **argv)
{

    // 初始化节点
    ros::init(argc,argv, "turtle_spawn");
    // 创建节点句柄
    ros::NodeHandle nh;

    // 先发现 /spawn这个服务，是一个阻塞的函数
    // ros::service::waitForService("/spawn");

    // 创建一个客户端对象，连接名为/spawn的服务
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
    // 阻塞等待服务端出现
    client.waitForExistence(); // 阻塞等待

    // 创建一个请求对象
    turtlesim::Spawn srv;
    srv.request.x = 2.0;
    srv.request.y = 2.0;
    srv.request.theta = 1.57;
    srv.request.name = "turtle2";

    // 请求调用服务
    ROS_INFO("call service to spwan turtle[x: %0.6f, y: %0.6f, name: %s]",
        srv.request.x, srv.request.y, srv.request.name.c_str());
    // 发送请求,是一个阻塞函数
    bool result = client.call(srv);
    if(result)
    {
        ROS_INFO("name: %s 新的海龟创建成功", srv.response.name.c_str());
    }
    return 0;
}