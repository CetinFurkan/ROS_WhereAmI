
![alt text](Localization.png)
# Where Am I
This project is the third project that comes in **Localization** lesson in Robotics Software Engineer Nanodegree Program. This project is built upon the second project which has a world and robot. In this project, the robot can be controlled by keyboard and AMCL package is used for localize the robot by analyzing lidar scan data.

### Directory Structure
```
    .WhereAmI                          
    ├── my_robot                       # main project file that includes launch files
    ├── ball_chaser                    # can be ignored for this project!
    ├── pgm_map_creator                # for creating 2d map view of world   
    ├── teleop_twist_keyboard          # for controlling from keyboard   
    ├── CMakeLists.txt                 # ball_chaser package   
    └── Localization.png               # screenshot from the project
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
$ git clone https://github.com/CetinFurkan/ROS_WhereAmI.git  
$ cd ..
$ catkin_make
```

#### Step 3 | Source the workspace  
```sh
$ source devel/setup.bash
```

#### Step 4 | Launch the simulation (each in seperated console)
```sh
$ roslaunch my_robot world.launch 
$ roslaunch my_robot amcl.launch
$ rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```
