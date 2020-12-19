#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // Request a service and pass the velocities to it to drive the robot
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

    if (!client.call(srv))
	ROS_ERROR("Failed DriveToTarget call!!!");

}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{
    int white_pixel = 255;
    bool isBallFound = false;
    int tresholdLeft = (img.step/3);
    int tresholdRight = (img.step/3)*2;
    
    for (int i=0; i < img.height * img.step; i += 3)
    {
	int pointR = img.data[i];
	int pointG = img.data[i+1];
	int pointB = img.data[i+2];	
	int pointColumn = i % img.step;
	int pointRow = i/3;	

        if ((pointR == 255) && (pointB == 255) && (pointG == 255))
        {
            if (pointColumn < tresholdLeft)
                drive_robot(0.0, 0.5);  //Turn LEFT
            else if (pointColumn > tresholdRight)
                drive_robot(0.0, -0.5); //Turn RIGHT
            else
                drive_robot(0.3, 0);    //Go FORWARD

            isBallFound = true;
            break;
         }
     }

     if (!isBallFound)
         drive_robot(0, 0); 
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}
