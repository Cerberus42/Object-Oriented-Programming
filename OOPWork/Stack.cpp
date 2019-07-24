#include "Stack.h"
#include "Image.h"
#include "Read.h"
#include "Write.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <array>
#include <vector>
#include <cmath>

void Stack::readStack()
{
	//Class that reads all images to be stacked.
	Read *imgread = new Read;
	std::cout << "Reading images ..." << std::endl;
	*img1 = imgread->readImage("Images/ImageStacker_set1/IMG_1.ppm");
	*img2 = imgread->readImage("Images/ImageStacker_set1/IMG_2.ppm");
	*img3 = imgread->readImage("Images/ImageStacker_set1/IMG_3.ppm");
	*img4 = imgread->readImage("Images/ImageStacker_set1/IMG_4.ppm");
	*img5 = imgread->readImage("Images/ImageStacker_set1/IMG_5.ppm");
	*img6 = imgread->readImage("Images/ImageStacker_set1/IMG_6.ppm");
	*img7 = imgread->readImage("Images/ImageStacker_set1/IMG_7.ppm");
	*img8 = imgread->readImage("Images/ImageStacker_set1/IMG_8.ppm");
	*img9 = imgread->readImage("Images/ImageStacker_set1/IMG_9.ppm");
	*img10 = imgread->readImage("Images/ImageStacker_set1/IMG_10.ppm");
	*img11 = imgread->readImage("Images/ImageStacker_set1/IMG_11.ppm");
	*img12 = imgread->readImage("Images/ImageStacker_set1/IMG_12.ppm");
	*img13 = imgread->readImage("Images/ImageStacker_set1/IMG_13.ppm");
	std::cout << "Images Read" << std::endl;
	delete imgread;
}

void Stack::process()
{
	//Class that process's all of the successfully read images.
	std::cout << "Processing Images" << std::endl;
	const int size = 13;
	float redMean, greenMean, blueMean, medianR, medianG, medianB, sigmaR, sigmaG, sigmaB;
	float red1[size] = {};
	float green1[size] = {}; //These are the declarations for each of the pizels
	float blue1[size] = {};
	for (int i = 0; i < (images[0]->w * images[0]->h); i++)
	{
		redMean = greenMean = blueMean = medianR = medianG = medianB = sigmaR = sigmaG = sigmaB = 0;
		for (int j = 0; j < size; j++)
		{
			red1[j] = (images[j]->pixels[i].r / 255.f);
			green1[j] = (images[j]->pixels[i].g / 255.f);
			blue1[j] = (images[j]->pixels[i].b / 255.f);
		}
		bubblesort(red1, size);
		bubblesort(green1, size);
		bubblesort(blue1, size);

		Mean(size, red1, redMean);
		Mean(size, green1, greenMean);
		Mean(size, blue1, blueMean);

		Median(size, red1, medianR);
		Median(size, green1, medianG);
		Median(size, blue1, medianB);

		Sigma(red1, redMean, sigmaR);
		Sigma(green1, greenMean, sigmaG);
		Sigma(blue1, blueMean, sigmaB);

		assignPixel(*img14, i, redMean, greenMean, blueMean);
		assignPixel(*img15, i, medianR, medianG, medianB);
		assignPixel(*img16, i, sigmaR, sigmaG, sigmaB);
	}
	std::cout << "Processing complete." << std::endl;
	//success upon processed images.
}

void Stack::output()
{
	//Outputs of the Mean, Median and SigmaMean.
	Write imgWrite;
	imgWrite.writePPM(*img14, "MeanPPM.ppm");
	imgWrite.writePPM(*img15, "MedianPPM.ppm");
	imgWrite.writePPM(*img16, "SigMeanPPM.ppm");

}

void Stack::assignPixel(Image &img, int i, float r, float g, float b) //Pixels being assigned
{
	img.pixels[i].r = r * 255;
	img.pixels[i].g = g * 255;
	img.pixels[i].b = b * 255;
}

void Stack::Mean(int size, float *a, float &mean) //This calculates the means
{
	for (int i = 0; i < size; i++)
	{
		mean += a[i];
	}
	mean = mean / size;
}

void Stack::Median(int size, float *a, float &median) //This calculates the Median
{
	float temp;
	median = 0;
	size = size + 1;
	if (size % 2 == 0)
	{
		size /= 2;
		median = a[size];
	}
	else
	{
		temp = size;
		temp /= 2;
		temp -= 0.5f;
		size = temp;
		median = ((a[size] + a[size + 1]) / 2);
	}
}

void Stack::bubblesort(float *a, int n) //Implements a bubblesort algorithm
{
	float temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void Stack::Sigma(float* vals, float mean, float &sig)  //Calculating the sigma
{
	const int Arr = 13;

	float difmean[Arr] = {};
	float Temp = 0;
	float sigma = 1;
	float size = 0;
	for (int i = 0; i < Arr; i++)
	{
		difmean[i] = (vals[i] - mean);
		difmean[i] = pow(difmean[i], 2);
	}
	Mean(Arr, difmean, Temp);
	Temp = sqrt(Temp);
	for (int i = 0; i < Arr; i++)
	{
		if (vals[i] >= (mean - (sigma*Temp)) && vals[i] <= (mean + (sigma*Temp)))
		{
			sig += vals[i];
			size += 1;
		}
	}
	sig = sig / size;
}

Stack::~Stack()
{
}