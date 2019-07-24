#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "Scale.h"
#include "Read.h"
#include "Write.h"
						//This is to do the image scaling
void Scale::read()
{
	Read *imgread = new Read;
	std::cout << "Reading image ..." << std::endl;
	*toScale = imgread->readImage("Images/Zoom/zIMG_1.ppm");
	std::cout << "Image Read" << std::endl;
	imgread->~Read();
}

void Scale::process()  //Up scaling
{
	resize(*toScale, 2, toScale->w, toScale->h, 1500, 1500, *Scale2);
	resize(*toScale, 4, toScale->w, toScale->h, 3000, 3000, *Scale4);
}

void Scale::output() //Outputting the scaling into file format
{
	Write imgWrite;
	imgWrite.writePPM(*Scale2, "2XScale.ppm");
	imgWrite.writePPM(*Scale4, "4XScale.ppm");
	imgWrite.~Write();
}

void Scale::resize(Image img, int scale, int width, int height, int heightnew, int widthnew, Image &scaled) //Resizing the images
{

	float ratiox = ((float)width / (float)widthnew);
	float ratioy = ((float)height / (float)heightnew);
	float xpix, ypix;
	float output, input;
	for (int i = 0; i < heightnew; i++)
	{
		for (int j = 0; j < widthnew; j++)
		{
			xpix = floor(j * ratiox);
			ypix = floor(i * ratioy);
			input = ((i * widthnew) + j);
			output = ((ypix * width) + xpix);
			scaled[input] = img[output];
		}
	}
}

Scale::~Scale()
{
}
