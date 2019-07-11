#include "cspm_robot.h"


void cspm_robot::process(const sensor_msgs::ImageConstPtr& cam_image){
	cv_bridge::CvImagePtr cv_ptr;


	try
	{
	  cv_ptr = cv_bridge::toCvCopy(cam_image,sensor_msgs::image_encodings::BGR8);
	} catch (cv_bridge::Exception& e){
	  ROS_ERROR("cv_bridge exception:%s",e.what());

	  return;
	}
	current_image = cv_ptr->image;


	idx++;
	resize(current_image,current_image,Size(640,360));
	if(detect_flag){

		if(init_period){
			/**
			 * 首次进入循环时的准备阶段，初始化颜色等信息
			 */
			init_period = false;
			face_period = true;
			Mat color(2, 2, CV_8UC3, Scalar(0, 0, 255));
			cvtColor(color, color, CV_BGR2HSV);
			hsv = Scalar(color.at<unsigned char[3]>(0,0)[0], color.at<unsigned char[3]>(0,0)[1], color.at<unsigned char[3]>(0,0)[2]);

		}
		if(face_period){
			/**
			 * 人脸识别阶段
			 * 旋转寻找人脸，找到后停止运转并记录此时的颜色值，进入颜色阶段
			 */
			move(0,0,0,0,0,0.1);
			detectAndDraw(current_image,cascade,nestedCascade,2,0,pix_sum,ctr);
			if(abs(dst(ctr.x,current_image.cols/2)) < 0.7 && abs(dst(ctr.x,current_image.cols/2)) != 0){
				face_period = false;
				color_period = true;
			}

			/**
			 * 考虑到捕捉人脸时间较长，演示时直接进入识别人体阶段
			 */
			face_period = false;
			color_period = true;

		}
		if(color_period){
			/**
			 * 颜色识别阶段，根据颜色质心方向跟随主人
			 */
			Mat mask;
			detect_color_and_draw(hsv, current_image, mask, ctr);
			cmd_vel = fresh_vel;
			double erry = dst(ctr.x,current_image.cols);
			double errx = dst(ctr.y,current_image.rows * 0.8);
			cmd_vel.linear.y = -pid(erry,Kpy);
			cmd_vel.linear.x = pid(errx,Kpx);
			vel_pub.publish(cmd_vel);
			ctr.x = current_image.cols/2;
			ctr.y = current_image.rows/2;

		}
	}
//	if(detect_flag){
//			detectAndDraw(current_image,cascade,nestedCascade,2,0,pix_sum,ctr);
//			if(idx % 15 == 1 || (ctr.x != 0 && idx % 8 ==1)){
//				cout << "ctr:" << ctr.x << " " << ctr.y << endl;
//				cmd_vel = fresh_vel;
//				cout << "rows" << current_image.rows;
//				cout << "cols" << current_image.cols;
//				double erry = dst(ctr.x,current_image.cols);
//				double errx = dst(ctr.y,current_image.rows);
//				cout << "erry:" << erry << endl;
//				cmd_vel.linear.y = -pid(erry,Kpy);
//				cmd_vel.linear.x = pid(errx,Kpx);
//				vel_pub.publish(cmd_vel);
//				ctr.x = current_image.cols/2;
//				ctr.y = current_image.rows/2;
//			}

//	}



	imshow(WINDOW,current_image);
	int k = waitKey(1);
	double temp = 0;
	if(k != -1)
		cout << k << endl;

	if(k == UP)//up for forward
		forward(SPEED);
	if(k == DOWN)//down for back
		back(SPEED);
	if(k == LEFT)//left for turn_left
		rotation_clock(ROTATION);
	if(k == RIGHT)//right for turn_right
		rotation_inclock(ROTATION);
	if(k == SPACE)
		detect_flag = !detect_flag;
	if(k == 'p')
		vel_pub.publish(fresh_vel);
	if(k == 'j'){
		move(0,-SPEED,0,0,0,0);
	}
	/**
	 * 切换摄像头
	 */
	if(k == 't'){
		move(0,0,0,1,0,0);
			}
	if(k == 'k'){
		move(0,SPEED,0,0,0,0);
			}
	if(k == 'q'){
		temp = fresh_angle.linear.x + 0.1;
		if(temp < 1 && temp > -1)
			fresh_angle.linear.x += 0.1;
		ROS_INFO("The angle of the crawl is %f",fresh_angle.linear.x);
		vel_pub.publish(fresh_angle);
	}
	if(k == 'a'){
				double temp = fresh_angle.linear.x - 0.1;
				if(temp < 1 && temp > -1)
					fresh_angle.linear.x -= 0.1;
				ROS_INFO("The angle of the crawl is %f",fresh_angle.linear.x);
				vel_pub.publish(fresh_angle);
			}
	if(k == 'w'){
		temp = fresh_angle.linear.y + 0.1;
		if(temp < 1 && temp > -1)
		fresh_angle.linear.y += 0.1;
		ROS_INFO("The angle of the base is %f",fresh_angle.linear.y * 180);
		vel_pub.publish(fresh_angle);
	}
	if(k == 's'){
				temp = fresh_angle.linear.y - 0.1;
				if(temp < 1 && temp > -1)
					fresh_angle.linear.y -= 0.1;
				ROS_INFO("The angle of the base is %f",fresh_angle.linear.y * 180);
				vel_pub.publish(fresh_angle);
			}
	if(k == 'e')
	{
				temp = fresh_angle.angular.y + 0.1;
				if(temp < 1 && temp > -1)
					fresh_angle.angular.y += 0.1;
				ROS_INFO("The angle of the right servo is %f",fresh_angle.angular.y * 180);
				vel_pub.publish(fresh_angle);
					}
	if(k == 'd')
			{
						temp = fresh_angle.angular.y - 0.1;
						if(temp < 1 && temp > -1)
						fresh_angle.angular.y -= 0.1;
						ROS_INFO("The angle of the right servo is %f",fresh_angle.angular.y * 180);
						vel_pub.publish(fresh_angle);
							}
	if(k == 'r')
			{
						temp = fresh_angle.angular.z + 0.1;
						if(temp < 1 && temp > -1)
						fresh_angle.angular.z += 0.1;
						ROS_INFO("The angle of the left servo is %f",fresh_angle.angular.z * 180);
						vel_pub.publish(fresh_angle);
							}
	if(k == 'f')
			{
						temp = fresh_angle.angular.z - 0.1;
						if(temp < 1 && temp > -1)
						fresh_angle.angular.z -= 0.1;
						ROS_INFO("The angle of the servo is %f",fresh_angle.angular.z * 180);
						vel_pub.publish(fresh_angle);
			}
	if(k == 'l'){
						char cmd[256];
						sprintf(cmd, "firefox http://www.google.cn/maps/@%f,%f,17z", fix.latitude, fix.longitude);
						system(cmd);
	}



	return;

	}
void cspm_robot::fix_cb(sensor_msgs::NavSatFixConstPtr fixptr){
	fix = *fixptr;
	cout << fix.altitude << endl;
	cout << fix.latitude << endl;
	cout << fix.longitude << endl;

	return;

}

cspm_robot::cspm_robot(char* topic_name){
	ros::NodeHandle n;
	image_transport::ImageTransport it(n);
	image_sub = it.subscribe(string("/camera/image"),1,&cspm_robot::process,this);
	fix_sub = n.subscribe("/android/fix",1,&cspm_robot::fix_cb,this);
	vel_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel",1);
	cascade.load("../cspm/face_xml/haarcascade_frontalface_alt.xml");
	nestedCascade.load("../cspm/face_xml/haarcascade_eye_tree_eyeglasses.xml");
	fresh_angle.linear.z = 1;
	Kpx = 2;
	Kpy = 1;
	Kdx = 0.25;
	Kdy = 0.25;
	Kix = 0;
	Kiy = 0;
	pix_sum_old = 1;
	pix_sum_0 = 1;
	idx = 0;
	detect_flag = false;
	init_period = true;
	face_period = false;
	color_period = false;
}
