#pragma once
#include "image.h"
class Read //Class to read the images
{
public:
	Image readImage(const char *filename);
	~Read();
};
