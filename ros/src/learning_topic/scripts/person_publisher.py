#!/usr/bin/env python3
# 该例子将发布 /person_info 话题，消息类型为 learning_topic/Person

import rospy
from learning_topic.msg import Person

def publish_person():
    # 1. 初始化ROS节点
    rospy.init_node('person_publisher', anonymous=True)

    # 2. 创建发布者对象
    person_pub = rospy.Publisher('/person_info', Person, queue_size=10)

    # 3. 设置循环的频率
    rate = rospy.Rate(10) # 10 Hz

    while not rospy.is_shutdown():
        # 4. 创建并填充自定义消息
        person_msg = Person()
        person_msg.name = "Alice"
        person_msg.age = 30
        person_msg.sex = Person.FEMALE

        # 5. 发布消息
        person_pub.publish(person_msg)
        rospy.loginfo("Published Person Info: Name=%s, Age=%d, sex=%d", 
                     person_msg.name, person_msg.age, person_msg.sex)

        # 6. 按照设定的频率延时
        rate.sleep()

if __name__ == '__main__':
    try:
        publish_person()
    except rospy.ROSInterruptException:
        pass