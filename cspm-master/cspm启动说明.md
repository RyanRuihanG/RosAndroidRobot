1.启动roscore
roscore
2.需要将视频重发布为raw格式
rosrun image_transport republish compressed in:=/camera/image raw out:=/camera/image
3.需要将手柄重发布话题
rosrun topic_tools relay /virtual_joystick/cmd_vel /cmd_vel
4.不要忘记修改ip地址
5.显示图像
rosrun image_view image_view image:=/camera/image _image_transport:=compressed

