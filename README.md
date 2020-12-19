
![alt text](GoChaseIt.png)
# Go Chase It
The **Go Chase It** project is the second project that comes in **ROS Essentials** lesson in Robotics Software Engineer Nanodegree Program. This project is built upon the first project which has a custom built world. In addition to that, there is a custom built two wheeled robot with a lidar and a camera component whose data can be visualized by Rviz.
With additional service (called **process_images**) robot follows the sphere by analyzing the camera view.

### Directory Structure
```
    .GoChaseIt                         # Go Chase It Project
    ├── my_robot                       # my_robot package                   
    │   ├── launch                     # launch folder for launch files   
    │   │   ├── robot_description.launch
    │   │   ├── world.launch
    │   ├── meshes                     # meshes folder for sensors
    │   │   ├── hokuyo.dae
    │   ├── urdf                       # urdf folder for xarco files
    │   │   ├── my_robot.gazebo
    │   │   ├── my_robot.xacro
    │   ├── rviz                       # rviz folder for rviz configuration data
    │   │   ├── config_file.rviz
    │   ├── world                      # world folder for world files
    │   │   ├── MyFirstRosWorld.world
    │   ├── CMakeLists.txt             # compiler instructions
    │   ├── package.xml                # package info
    ├── ball_chaser                    # ball_chaser package                   
    │   ├── launch                     # launch folder for launch files   
    │   │   ├── ball_chaser.launch
    │   ├── src                        # source folder for C++ scripts
    │   │   ├── drive_bot.cpp
    │   │   ├── process_images.cpp
    │   ├── srv                        # service folder for ROS services
    │   │   ├── DriveToTarget.srv
    │   ├── CMakeLists.txt             # compiler instructions
    │   ├── package.xml                # package info                  
    └── GoChaseIt.png                 # screenshot from the project                          
```

### Steps to launch the simulation

#### Step 1 | Create a catkin workspace
```sh
$ mkdir -p catkin_ws/src
$ cd catkin_ws/src
$ catkin_init_workspace
$ cd ..
$ catkin_make
```

#### Step 2 | Clone the repository
```sh
$ cd catkin/src
$ git clone https://github.com/CetinFurkan/GoChaseIt.git  
$ cd ..
$ catkin_make
```

#### Step 3 | Source the workspace  
```sh
$ source devel/setup.bash
```

#### Step 4 | Launch the simulation environment
```sh
$ roslaunch my_robot world.launch 
$ roslaunch ball_chaser ball_chaser.launch
```
