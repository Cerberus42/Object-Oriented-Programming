//Jez Horton, 16610629 19/12/2017
//CMP2090M
//Object-Oriented Programming
#include <iostream>
#include <fstream>
#include <sstream>
#include "Image.h"
#include "Stack.h"
#include "Scale.h"



int main()
{
	std::cout << "************************************" << std::endl;
	std::cout << "Image Stacker & Image Scaler" << std::endl;
	std::cout << "************************************" << std::endl;
	int input;
	bool exit = false;
	std::cout << "Do you wish to Stack or Scale the images?" << std::endl;
	std::cout << "1. Stack Images" << std::endl;
	std::cout << "2.Scale Image" << std::endl;
	do
	{
		std::cin >> input; //This is the simple switch statement to select how you want to either stack or scale the images
		switch (input)
		{
		case 1:
		{
			std::cout << "Stacking the Images" << std::endl;
			Stack Stacker;
			Stacker.readStack();
			Stacker.process();
			Stacker.output();
			exit = true;
		}
		break;
		case 2:
		{
			std::cout << "Scaling the Images" << std::endl;
			Scale Scaler;
			Scaler.read();
			Scaler.process();
			Scaler.output();
			exit = true;
		}
		break;
		default:
		{
			std::cout << "Invalid Input." << std::endl;
			exit = false;
		}
		break;
		}
	} while (!exit);

	return 0;
}
//Image colour ratio as constant variables to be updated.
const Image::Rgb Image::kBlack = Image::Rgb(0);
const Image::Rgb Image::kWhite = Image::Rgb(1);
const Image::Rgb Image::kRed = Image::Rgb(1, 0, 0);
const Image::Rgb Image::kGreen = Image::Rgb(0, 1, 0);
const Image::Rgb Image::kBlue = Image::Rgb(0, 0, 1);