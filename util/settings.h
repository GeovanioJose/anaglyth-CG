#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/glut.h>

#define RED  1
#define CYAN_RED  2
#define DTOR            0.0174532925
#define RTOD            57.2957795
#define TWOPI           6.283185307179586476925287
#define PI              3.141592653589793238462643
#define PID2            1.570796326794896619231322
#define ESC 27
#define ABS(x) (x < 0 ? -(x) : (x))
#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)
#define SIGN(x) (x < 0 ? (-1) : 1)
#define MODULUS(p) (sqrt(p.x*p.x + p.y*p.y + p.z*p.z))
#define CROSSPROD(p1,p2,p3) \
   p3.x = p1.y*p2.z - p1.z*p2.y; \
   p3.y = p1.z*p2.x - p1.x*p2.z; \
   p3.z = p1.x*p2.y - p1.y*p2.x

typedef struct {
   double x,y,z;
} XYZ;

typedef struct {
   XYZ vp;                           
   XYZ vd;                          
   XYZ vu;                           
   XYZ pr;                           
   double focal_distance;           
   double camera_opening;           
   double eye_separation; 
   int screen_height, screen_width;
} CAMERA;



int current_boot = -1;                 
float rotation_speed = 0.5;     
double camera_rotation_angle = 1.0;    
CAMERA camera;                         
XYZ origin = {0.0,0.0,0.0};           
int lens_type= CYAN_RED;


