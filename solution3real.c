#include <stdio.h>
#include <math.h>
#include <X11/Xlib.h>

#define DIM 512

/******************************************************************/
/* This structure contains the coordinates of a box drawn with    */
/* the left mouse button on the image window.                     */
/* roi.x , roi.y  - left upper corner's coordinates               */
/* roi.width , roi.height - width and height of the box           */
/******************************************************************/
extern XRectangle roi;


/******************************************************************/
/* Main processing routine. This is called upon pressing the      */
/* Process button of the interface.                               */
/* image  - the original greyscale image                          */
/* size   - the actual size of the image                          */
/* proc_image - the image representation resulting from the       */
/*              processing. This will be displayed upon return    */
/*              from this function.                               */
/******************************************************************/
void process_image(image, size, proc_img)
unsigned char image[DIM][DIM];
int size[2];
unsigned char proc_img[DIM][DIM];
{
int i=0;
int j = 0;
double topNeighbour = 0.0;
double leftNeighbour = 0.0;
double centerNeighbour = 0.0;
double threshold=10;
double diff1=0.0;
double diff2=0.0;
int k=0;

for(i = 1; i < (size[0]); i++)
{ 
for(j = 1; j < (size[1]); j++)
{
centerNeighbour = image[i][j];
leftNeighbour = image[i-1][j];
topNeighbour = image[i][j-1];

diff1= (centerNeighbour - leftNeighbour);
diff2 = (centerNeighbour - topNeighbour);

//blobLabel = (centerNeighbour - topNeighbour - leftNeighbour);
// four cases that could happen.
// case 1 equivalent to both neighbours
if(abs(diff2)<threshold && abs(diff1)<threshold)
{
printf("Case1");
proc_img[i][j-1] = diff2-leftNeighbour;
proc_img[i-1][j] = diff2-leftNeighbour;
proc_img[i][j]= proc_img[i-1][j];
}

// case 2 equivalent to top neighbour
else if(abs(diff2)<threshold)
{
printf("Case2");

proc_img[i][j]=proc_img[i][j-1];
}

// case 3 equilavent to left neighbour
else if (abs(diff1)<threshold)
{
printf("Case3");

proc_img[i][j]=proc_img[i-1][j];
}

//case 4 equivalent to none of the neighbours
else
{
printf("Case4");
diff2= abs(diff2-leftNeighbour)+8;
proc_img[i][j] = diff2;
}

}
}

}
