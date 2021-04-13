#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
    ros::init(argc ,argv, "talker"); // initialize ROS node
    ros::NodeHandle n;// create node handle
    // initialize a publisher, public a topic named chatter, with message type std_msgs::String
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000); 
    ros::Rate loop_rate(10); // node rest for 100ms between two loops

    int count = 0;
    while (ros::ok())// ensure that the node is ok
    {
        // initialize std_msgs::Strng message
        std_msgs::String msg;
        std::stringstream ss;
        ss << "hello world" << count;
        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());
        chatter_pub.publish(msg);

        ros::spinOnce();
        // when a work cycle of a publisher is finished, let the node rest for a while
        loop_rate.sleep();
        ++count;
    }
    
    return 0;

}