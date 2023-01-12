# Team-010-44 Bus Extension for Drone Simulation System

## Team Members: 
Dhondup Dolma (dolma012), Jenna Chuong (chuon007), Tenzin Tseten (tsete003)

## UML
[Hw 4 UML.pdf](https://github.umn.edu/umn-csci-3081-F22/Team-010-44-homework04/files/917/Hw4.1.pdf)
![image](https://media.github.umn.edu/user/25351/files/8bdd65b0-495b-407b-a42f-eb89869bf0dc)


## Docker
Link to Docker hub where this program can be run: https://hub.docker.com/repository/docker/chuon007/homework4

## PRESENTATION
Link to our presentation video: https://youtu.be/sMeqSC0YXVc

## What is this project about?
This project simulates the behavior of an Uber using entities such as drones and robots. This projects gives students a chance to practice using various design patterns to add additional functionality to the base project. 


## What does the simulation do?
The simulation will allow users to watch the interaction between the drone and passenger/robot via a 3D visualization. Users are able to set the pickup location and the final destination of the robot via a frontend scheduler webpage. After a robot is given a name, starting and ending location, and a movement strategy is selected, the drone will fly to pickup the robot and transport the robot to its final desitnation. With the use of various decorators, the robot and drone's behvaior can be modified (i.e. celebrating by spinning or jumping once the robot reaches its final destination). 


## How to run the simulation
This project must be run on a CSE Lab machine. This project can be run in 2 ways.
  1. Run the simulation directly on a CSE Lab machine
  2. SSH onto a CSE Lab machine and run it from the SSH client


## Option 1: Running on a CSE Lab machine

    ```bash
    # Go to the project directory
    cd /path/to/repo/project
    
    # Build the project
    make -j
    
    # Run the project (./build/web-app <port> <web folder>)
    ./build/bin/transit_service 8081 apps/transit_service/web/
    ```
    
Navigate to http://127.0.0.1:8081 and you should see a visualization.

Navigate to http://127.0.0.1:8081/schedule.html and you should see a page to schedule the trips.


## Option 2: Running the simulation via SSH onto a CSE Lab Machine
1. SSH into a CSE Lab Machine using **port forwarding** for the UI

   **Note:** If port `8081` is not available, choose a different port (e.g. 8082, 8083, etc...)

    ```bash
    ssh -L 8081:127.0.0.1:8081 x500@csel-xxxx.cselabs.umn.edu
    ```
    
    Example:
    ```bash
    ssh -L 8081:127.0.0.1:8081 chuon007@csel-kh1250-13.cselabs.umn.edu
    ```

2. Compile the project (within ssh session)

    ```bash
    # Go to the project directory
    cd /path/to/repo/project

    # Build the project
    make -j
    ```
    
 2. Run project (within ssh session)

    ```bash
    # Run the project (./build/web-app <port> <web folder>)
    ./build/bin/transit_service 8081 apps/transit_service/web/
    ```

3. Navigate to http://127.0.0.1:8081 and you should see a visualization.

4. Navigate to http://127.0.0.1:8081/schedule.html and you should see a page to schedule the trips.


# New Feature - Singleton Design Pattern
## What does it do?
Our extension will collect statistics of the drones in the simulation; we have specific columns labeling the data we collected for each drone. For example, we have time and distance traveled by the drone to drop off the robots during the simualation, and we also have the total time and total distance traveled by the drone for pickup and dropoff.  This data will then be outputed to a csv file. We will then use the csv file to analyze the data to determine the average distance traveled by a passenger. 

## Why is it significantly interesting?
The data collection extension is significantly interesting because before our extension, users are not able to extrapolate/collect data from the simulation. Now, users are not only able to colelct data, but also output it to a csv file, which can then be viewed and modified in an xcel sheet. This is interesting because it will allow us to analyze data points like total distance traveled, number of passengers delivered, and etc... which can be interesting to an bus driver/uber driver. The data collected can further be used to develop more insights regarding the drone system and can be used to generate data driven insights for further optimization. 

## How does it add to existing work?
The data collection extension using the Singleton adds to our project by allowing us to collect data on the simulation, output it to a csv file, and then we can use that file to analyze the data we collected. We can use the data we collected to calculate more data points like the average distance traveled between all passengers for example. 

## What design pattern did we use and why?
For data collection, we use the singleton design pattern. We use this because otherwise we would have have many instances of a data collection class for each drone, robot, bus, etc... in which our data is spread across many objects which is not desirable. By using the singleton design pattern, we can have one singular instance of our data collection class and so any changes to that class will be updated throughout all class/objects coupled to that single instance. Our data will be contained within one instance which is exactly what we want to happen in order to easily analyze the data we collected.


## Instructors to use Singleton Data Collection extension
1. Run the simulation using the above instructions.
2. When you want to ouput the collected data from the simulation, click the "Output to CSV" button on the simulation page.
3. View all the data that was collected by opening the "output.csv" file. 
4. Each time the "Output to CSV" button is clicked, a new data entry will be outputted to the csv file.

## Data Analysis
Based on the data we collected, we observed that the speed of the Drone has an inverse relationship between the Total Time and Trip Time. We noticed that Drones initiated with faster speeds reported shorter Total Times and Trip Times. Furthermore, we also observed another trend regarding pick up distance and drop of distances. The Total Distance the Drone travels will be the largest of the distance data points because it includes both the distance traveled to pickup a Robot and the distance traveled to drop off the Robot on a trip. On average, we found that the distance traveled by the drone to pickup a robot is less than the distance traveled by the drone dropping of the Robot to its destination. We believe this is due to the fact that when picking up, the Drone can fly in the air and use a straight Beeline to get to the Robot. This distance will be smaller than the distance used by one of the drop off strategies like AStar, DFS, and Dijkstra which need to follow a path generated using a graph of routes to take. 

# Spring Retrospective
## What went well?
Everyone was on task and did their part. We were able to finish all our tasks on the Jira board/backlog. We had adequate communication across our team. Each team member would update the group with what tasks they finished and were working on. 

## What didn't go well?
Initially, our idea was non-trivial, however, after attempting to code the logic, we found out that our implementation of our idea was too complicated to code. So, we had to shift gears and use a different design pattern to implement our extension. Another thing that didn't go as expected was that we ran into merge conflicts when trying to merge a branch to dev. We didn't review the merge request closely enough which caused our dev branch to break.

## Ideas for future sprint(s)
If we were to do this again, we would add a weekly or daily standup as a way to improve our communication within our team. In the standup we would want to talk about what tasks we finished, what we're working on, and what challenges we are facing. Furthermore, in the future we will be more careful about reviewing merge requests and making sure that everything works as it should before merging. We will also more carefully review conflicts, so that the right code is merged. 
