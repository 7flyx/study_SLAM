#!/usr/bin/env python3
# 该例子将发布 turtle1/cmd_vel 话题，控制乌龟移动，消息类型是 geometry_msgs/Twist
import rospy
from geometry_msgs.msg import Twist


def velocity_publisher():
    # 1. 初始化 ROS 节点
    rospy.init_node('velocity_publisher', anonymous=True)

    # 2. 创建发布者对象，发布 turtle1/cmd_vel 话题，消息类型是 geometry_msgs/Twist，队列长度10
    pub = rospy.Publisher('turtle1/cmd_vel', Twist, queue_size=10)

    # 3. 设置循环频率,单位: Hz
    rate = rospy.Rate(10)  # 10hz

    while not rospy.is_shutdown():
        # 4. 创建并设置消息
        vel_msg = Twist()
        vel_msg.linear.x = 0.5  # 设置线速度，单位：m/s
        vel_msg.angular.z = 0.2  # 设置角速度，单位：rad/s

        # 5. 发布消息
        pub.publish(vel_msg)

        # 6. 输出日志信息
        rospy.loginfo("Published velocity command: linear.x = %.2f, angular.z = %.2f",
             vel_msg.linear.x, vel_msg.angular.z)

        # 7. 按照循环频率延时
        rate.sleep()

if __name__ == '__main__':
    try:
        velocity_publisher()
    except rospy.ROSInterruptException:
        pass