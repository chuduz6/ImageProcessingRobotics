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
double xval=0.0;
double yval=0.0;
double magnitude=0.0;;
int i,j,k;
int x = size[0];
int y = size[1];

for(i=1; i<x-1; i++)
{
	for(j=1; j<y-1; j++)
	{
		xval = image[i-1][j+1] + image[i][j+1] + image[i+1][j+1] - ( image[i-1][j-1] + image[i][j-1] + image[i+1][j-1] );	
		//yval = image[i-1][j-1] + image[i-1][j] + image[i-1][j+1] - ( image[i+1][j-1] + image[i+1][j] + image[i+1][j+1] );
		magnitude = sqrt(xval*xval + yval*yval);
		proc_img[i][j]=magnitude;
	}
}

}




