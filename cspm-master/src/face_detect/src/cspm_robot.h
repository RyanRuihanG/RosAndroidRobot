#ifndef CSPM_ROBOT_H_
#define CSPM_ROBOT_H_

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/image_encodings.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv/cv.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include <iostream>
#include <geometry_msgs/Twist.h>
#include <vector>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/NavSatFix.h>
#include <stdlib.h>
#include <unistd.h>

#define SPACE 32
#define ENTER 13
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363
#define ESC 27
#define W 1048695
#define A 1048673
#define S 1048691
#define D 1048676

#define SPEED 0.7
#define ROTATION 0.2

static const char WINDOW[]="RGB Image";
static const std_msgs::Empty e;

using namespace std;
using namespace cv;

void detect_and_draw( IplImage *image);
void detectAndDraw( Mat& img, CascadeClassifier& cascade,
					CascadeClassifier& nestedCascade,
					double scale, bool tryflip ,int& pix_sum,Point& ctr);
void detect_color_and_draw(Scalar hsv, Mat& src, Mat &dst, Point& ctr);
class cspm_robot{

	ros::Publisher takeoff_pub;
	ros::Publisher land_pub;
	ros::Subscriber fix_sub;
	image_transport::Subscriber image_sub;

	geometry_msgs::Twist cmd_vel;
	geometry_msgs::Twist fresh_vel;
	geometry_msgs::Twist fresh_angle;

	sensor_msgs::NavSatFix fix;
	ros::Publisher vel_pub;
	Mat last_image;//上一张图片
	Mat current_image;//下一张图片
	Mat edges;
	CascadeClassifier cascade,nestedCascade;
	bool stop;
	Point ctr;
	int pix_sum;

	//pid
	int Kpx;
	int Kpy;
	int Kdx;
	int Kdy;
	int Kix;
	int Kiy;
	int pix_sum_old;
	int pix_sum_0;
	int idx;
	int err;

	bool init_period;
	bool face_period;
	bool color_period;

	bool detect_flag;

	bool flag;
	Scalar hsv;

	void forward(float i){
		cmd_vel = fresh_vel;
		cmd_vel.linear.x = i;
		vel_pub.publish(cmd_vel);
	}
	void back(float i){
		cmd_vel = fresh_vel;

		cmd_vel.linear.x = -i;
		vel_pub.publish(cmd_vel);

	}
	void rotation_clock(float i){
		cmd_vel = fresh_vel;

		cmd_vel.angular.z = i;
		vel_pub.publish(cmd_vel);

	}
	void rotation_inclock(float i){
		cmd_vel = fresh_vel;

		cmd_vel.angular.z = -i;
		vel_pub.publish(cmd_vel);

	}
	void move(float x, float y, float z, float rx, float ry, float rz){
		cmd_vel = fresh_vel;
		cmd_vel.linear.x = x;
		cmd_vel.linear.y = y;
		cmd_vel.linear.z = z;
		cmd_vel.angular.x = rx;
		cmd_vel.angular.y = ry;
		cmd_vel.angular.z = rz;
		vel_pub.publish(cmd_vel);
	}
	double pid(double err,double Kp){
		return Kp*err;
	}
	double dst(int ctr,int siz){
		siz = siz/2;
		return double((ctr - siz)) / double(siz);
	}
	void process(const sensor_msgs::ImageConstPtr& cam_image);
	void fix_cb(sensor_msgs::NavSatFixConstPtr fixptr);
public:
	/*
	 *init the subscribers and publishers
	 */
	cspm_robot(char* topic_name);
};

#endif
