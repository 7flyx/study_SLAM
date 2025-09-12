#!/usr/bin/env python3
# 该例子将调用 /spawn 服务，创建一个新的乌龟，服务消息类型turtlesim::Spawn



import rospy
from turtlesim.srv import Spawn
import sys


def turtle_spawn():

    rospy.init_node('turtle_spawn')
    # 1. 创建一个服务客户端对象
    client = rospy.ServiceProxy('/spawn', Spawn)
    # 2. 等待服务端出现
    client.wait_for_service()


    # 3. 发送请求
    resp = client.call(1.0, 1.0, 0.0, 'turtle2')
    # 4. 处理响应
    if resp.name:
        rospy.loginfo('乌龟创建成功，名称为：%s', resp.name)
    else:
        rospy.loginfo('乌龟创建失败')
        
if __name__ == '__main__':
    try:
        turtle_spawn()
    except rospy.ROSInterruptException:
        pass