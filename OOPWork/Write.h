#pragma once
#include "Image.h"

class Write
{
public: 
	void writePPM(const Image &img, const char *filename);
	~Write();
};

