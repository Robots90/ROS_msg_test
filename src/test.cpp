#include <ros/ros.h>
#include "test_proj/Test.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "test_pub");
  ros::NodeHandle nh;
  ROS_INFO("inital");
  ros::Publisher pub_ = nh.advertise<test_proj::Test>("test_topic",100);//1000
  ros::Rate loop_rate(100);
  while(ros::ok())
  {
      ROS_INFO("Loop");
      test_proj::Test test_;
      test_.vel = 0;
      test_.name = "Test";
      pub_.publish(test_);
      ros::spinOnce();
      loop_rate.sleep();
  }    
  return 0;
}
