#!/usr/bin/env python3
# 该例子将订阅 /person_info 话题，消息类型为 learning_topic/Person

import rospy
from learning_topic.msg import Person

# 回调函数，当接收到消息时调用
def person_callback(msg):
    # 打印接收到的消息
    rospy.loginfo("Received Person Info: Name=%s, Age=%d, sex=%d", 
                 msg.name, msg.age, msg.sex)

def person_subscriber():
    # 1. 初始化ROS节点
    rospy.init_node('person_subscriber', anonymous=True)

    # 2. 创建订阅者对象
    person_sub = rospy.Subscriber('/person_info', Person, person_callback, queue_size=10)

    # 3. 保持节点运行
    rospy.spin()

if __name__ == '__main__':
    try:
        person_subscriber()
    except rospy.ROSInterruptException:
        pass
