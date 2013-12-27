ClosestStarbucks
================

Find the nearest Starbucks location

Background info
---------------
Imagine that you need to find the closes Starbucks store to your current location. Google maps makes this very easy – Simply searching for your current address + “starbucks” will work (http://maps.google.com/maps?q=starbucks%2045056). This kind of problem is called the “nearest neighbor problem.” In the nearest neighbor problem we start with a large but seldom changing list of locations (that is, we get the x and y coordinates of all Starbucks locations), and build a data structure. This data structure’s goal is to make it very efficient to find the closest Starbucks to a given pair of x and y coordinates. 

Your data structure will support two operations:

1. `void build(Entry* c, int n)` – My skeleton code will read in a file that contains the locations of all US Starbucks locations. c is a pointer to an array of “Entry” objects, and n is the length of c. The entry class has four member variables: City (string), Address (string), x (the longitude, which is a float between -360 and +360) and y (the latitude, which is a float between -360 and +360). Your build function is expected to store the data and build whatever data structure you want using that data. The running time of build is not important, as long as it finishes in a reasonable period of time (say less than 10 minutes). Note: I may delete the array that c points to, so you should not depend on it existing after build() finishes! You need to copy the data into your own data structure!
2.	`Entry* getNearest(double x, double y)` – There is not a Starbucks location at position (x,y), so it is to find the nearest location to it, and return a pointer to the appropriate entry in your data structure. I have provided two functions for computing distance: They are declared in Starbucks.h, and implemented in Controller.cpp.

