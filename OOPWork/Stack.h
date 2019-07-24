#pragma once
#include "Image.h"

class Stack
{
public:
	//image stack public header. 
	Image *img1 = new Image(3264, 2448);
	Image *img2 = new Image(3264, 2448);
	Image *img3 = new Image(3264, 2448);
	Image *img4 = new Image(3264, 2448);
	Image *img5 = new Image(3264, 2448);
	Image *img6 = new Image(3264, 2448);
	Image *img7 = new Image(3264, 2448);
	Image *img8 = new Image(3264, 2448);
	Image *img9 = new Image(3264, 2448);
	Image *img10 = new Image(3264, 2448);
	Image *img11 = new Image(3264, 2448);
	Image *img12 = new Image(3264, 2448);
	Image *img13 = new Image(3264, 2448);
	Image *img14 = new Image(3264, 2448);
	Image *img15 = new Image(3264, 2448);
	Image *img16 = new Image(3264, 2448);

	Image *images[16] = { img1,img2,img3,img4,img5,img6,img7,img8,img9,img10,img11,img12,img13,img14,img15,img16 };

	//processes to calculate Mean, Median and Sigma for the Image stacking.
	void readStack();
	void process();
	void output();
	void assignPixel(Image &img, int i, float r, float g, float b);
	void bubblesort(float *a, int n);
	void Mean(int size, float *a, float &mean);
	void Median(int size, float *a, float &median);
	void Sigma(float* vals, float mean, float &sig);
	~Stack();


};
