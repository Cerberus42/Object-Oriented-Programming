#pragma once
#include "Image.h"
class Scale
{
	//all public processes because they're being utalized throughout
public:
	Image *toScale = new Image(750, 750);
	Image *Scale2 = new Image((750 * 2), (750 * 2));
	Image *Scale4 = new Image((750 * 4), (750 * 4));
	void read();
	void process();
	void output();
	void resize(Image img, int scale, int width, int height, int heightnew, int widthnew, Image &scaled);
	~Scale();
};
