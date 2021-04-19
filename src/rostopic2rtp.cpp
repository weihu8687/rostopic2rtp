//
// Created by weihu on 2021/4/19.
//

#include <ros/ros.h>
#include <sensor_msgs/Image.h>

class TransRTP {
 public:
  TransRTP() { image_sub_ = nh_.subscribe("/pylon_sweepfront/image_raw", 100, &TransRTP::trans_rtp_callback, this); }

  void trans_rtp_callback(const sensor_msgs::Image::ConstPtr &msg) {}

  void Run() { ros::spin(); }

 private:
  ros::Subscriber image_sub_;
  ros::NodeHandle nh_;
};

int main(int argc, char **argv) {
  ros::init(argc, argv, "rostopic_2_rtp");
  TransRTP trans_rtp_node;
  trans_rtp_node.Run();
  return 0;
}