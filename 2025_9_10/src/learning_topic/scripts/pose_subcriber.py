#!/usr/bin/env python3
# -- coding: utf-8 -*-
# 该例子将订阅 turtle1/pose 话题，接收乌龟位姿信息，消息类型是 turtlesim/Pose
import rospy
from turtlesim.msg import Pose


def pose_callback(msg):
    rospy.loginfo("乌龟的位姿信息：x=%.2f, y=%.2f, theta=%.2f",
            msg.x, msg.y, msg.theta)

if __name__ == '__main__':
    rospy.init_node('pose_subscriber')  # 初始化节点
    rospy.Subscriber('turtle1/pose', Pose, pose_callback)
    rospy.spin()  # 循环等待回调函数

'''

+-------------------+         +---------------------+         +-------------------+
| velocity_publisher|         |   turtlesim_node    |         |  pose_subscriber  |
|  (发布速度指令)   |         | (乌龟仿真与话题管理) |         | (订阅位姿信息)    |
+-------------------+         +---------------------+         +-------------------+
           |                            |                              |
           |  发布 /turtle1/cmd_vel     |                              |
           +--------------------------->|                              |
           |                            |                              |
           |                            |  发布 /turtle1/pose          |
           |                            +----------------------------->|
           |                            |                              |


'''
