#include <ros/ros.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <tf/transform_broadcaster.h>
#include <turtlesim/Pose.h>


std::string pose_name;



void poseCallback(const geometry_msgs::PoseWithCovarianceStampedPtr& msg){
  static tf::TransformBroadcaster br;
  tf::Transform transform;
  transform.setOrigin( tf::Vector3(msg->pose.pose.position.x, msg->pose.pose.position.y, msg->pose.pose.position.z) );
  tf::Quaternion q(msg->pose.pose.orientation.x , msg->pose.pose.orientation.y, msg->pose.pose.orientation.z , msg->pose.pose.orientation.w);



  transform.setRotation(q);
  br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", "robot"));
}

int main(int argc, char** argv){
  ros::init(argc, argv, "my_tf_broadcaster");
  if (argc != 2){ROS_ERROR("need pose name as argument"); return -1;};
  pose_name = argv[1];

  ros::NodeHandle node;
  ros::Subscriber sub = node.subscribe("vslam/pose", 10, &poseCallback);

  ros::spin();
  return 0;
};
