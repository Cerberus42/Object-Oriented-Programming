#include "read.h"
#include "Image.h"
#include <iostream>
#include <fstream>
#include <sstream>

Image Read::readImage(const char *filename)
{
	//Remove this cout to prevent multiple outputs
	// prints line out
	std::ifstream ifs;								// creates input stream called ifs
	ifs.open(filename, std::ios::binary);			// opens the given file in binary
	Image src;
	try
	{
		if (ifs.fail())// checks to see if the data is okay
		{
			throw("Can't open the input file - is it named correctly/is it in the right directory?");
		}
		std::string header; //create a new string called header

		int w, h, b;  // create a new int called w, b and h
		ifs >> header; // parse ifs into string header
		if (strcmp(header.c_str(), "P6") != 0) // checks to see if p6 in the header
		{
			throw("Can't read the input file - is it in binary format (Has P6 in the header)?");  // if not then outputs error
		}
		ifs >> w >> h >> b;
		src.w = w;
		src.h = h;
		//std::cout << w << " " << h << std::endl;
		src.pixels = new Image::Rgb[w * h]; // this is throw an exception if bad_alloc 
		ifs.ignore(256, '\n'); // skip empty lines in necessary until we get to the binary data 
		unsigned char pix[3]; // read each pixel one by one and convert bytes to floats 
		for (int i = 0; i < w * h; ++i)
		{
			ifs.read(reinterpret_cast<char *>(pix), 3);
			src.pixels[i].r = pix[0] / 255.f;
			src.pixels[i].g = pix[1] / 255.f;
			src.pixels[i].b = pix[2] / 255.f;
		}

		ifs.close();
	}
	catch (const char *err) {
		fprintf(stderr, "%s\n", err);
		ifs.close();
	}

	return src;
}


Read::~Read()
{

}
