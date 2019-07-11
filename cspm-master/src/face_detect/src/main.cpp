#include "cspm_robot.h"
int main(int argc, char **argv){
//	GtkWidget *window;
//
//	    Mat a;
//	    gtk_init(&argc, &argv);
//
//	    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//	    gtk_widget_show(window);
//
//	    gtk_main();
//
//	    return(0);

    ros::init(argc,argv,"facedetect");
    cv::namedWindow(WINDOW);
    cspm_robot cr("/image/camera");
    ros::spin();
    return 0;
    }
