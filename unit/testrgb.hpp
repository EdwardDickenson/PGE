#ifndef TESTRGB_HPP
#define TESTRGB_HPP

#pragma once

#include "unit.hpp"

bool test_rgb_constructors(string fname)
{
	ofstream output(fname.c_str(), ios::app);
	clock_t curr_time;
	bool result = true;

	rgbColor color;
	rgbColor black(0.0, 0.0, 0.0);
	rgbColor white(1.0, 1.0, 1.0);
	rgbColor blackHTML(0, 0, 0);
	rgbColor whiteHTML(255, 255, 255);
	rgbColor maxRed(1.0, 0.0, 0.0);
	rgbColor maxGreen(0.0, 1.0, 0.0);
	rgbColor maxBlue(0.0, 0.0, 1.0);
	rgbColor maxHTMLRed(255, 0, 0);
	rgbColor maxRedGreen(1.0, 1.0, 0.0);
	rgbColor maxRedBlue(1.0, 0.0, 1.0);
	rgbColor maxGreenBlue(0.0, 1.0, 1.0);
	rgbColor maxHTMLGreen(0, 255, 0);
	rgbColor maxHTMLBlue(0, 0, 255);
	rgbColor maxHTMLRedBlue(255, 0, 255);
	rgbColor maxHTMLRedGreen(255, 255, 0);
	rgbColor maxHTMLGreenBlue(0, 255, 255);
	rgbColor negative(-1.0, 0.0, 0.0);
	rgbColor negativeHTML(-255, 0, 0);
	rgbColor tooBig(2.0, 0.0, 0.0);
	rgbColor tooBigHTML(1024, 0, 0);

	++ntests;
	if(negative.getRed() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negative.getRed() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(negative.getGreen() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negative.getGreen() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(negative.getBlue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negative.getBlue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(negative.getHTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negative.getBlue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(negative.getHTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negative.getHTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(negative.getHTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negative.getHTMLBlue() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedBlue.getBlue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedBlue.getRed() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedBlue.getGreen() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedBlue.getRed() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedBlue.getBlue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedBlue.getRed() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedBlue.getHTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedBlue.getHTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedBlue.getHTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedBlue.getHTMLGreen() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedBlue.getHTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedBlue.getHTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedGreen.getRed() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedGreen.getRed() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedGreen.getGreen() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedGreen.getGreen() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedGreen.getBlue() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedGreen.getBlue() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedGreen.getHTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedGreen.getHTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedGreen.getHTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedGreen.getHTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedGreen.getHTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedGreen.getHTMLBlue() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreenBlue.getRed() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreenBlue.getRed() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreenBlue.getGreen() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreenBlue.getGreen() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreenBlue.getBlue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreenBlue.getBlue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreenBlue.getHTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreenBlue.getHTMLRed() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreenBlue.getHTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreenBlue.getHTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreenBlue.getHTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreenBlue.getHTMLBlue() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxGreenBlue.getRed() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreenBlue.getRed() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxGreenBlue.getGreen() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreenBlue.getGreen() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxGreenBlue.getBlue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreenBlue.getBlue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxGreenBlue.getHTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreenBlue.getHTMLRed() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxGreenBlue.getHTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreenBlue.getHTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxGreenBlue.getHTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreenBlue.getHTMLBlue() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxRedBlue.getRed() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedBlue.getRed() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxRedBlue.getGreen() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedBlue.getGreen() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxRedBlue.getBlue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedBlue.getBlue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxRedBlue.getHTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedBlue.getHTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxRedBlue.getHTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedBlue.getHTMLGreen() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxRedBlue.getHTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedBlue.getHTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxRedGreen.getRed() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedGreen.getRed() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxRedGreen.getGreen() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedGreen.green() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxRedGreen.getBlue() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedGreen.getBlue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxRedGreen.getHTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedGreen.getHTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxRedGreen.getHTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedGreen.getHTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxRedGreen.getHTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedGreen.getHTMLBlue() != 0" << endl;
		result = false;
	}

	++ntests;
	if(black.getRed() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "black.getRed() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(black.getGreen() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "black.getGreen() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(black.getBlue() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "black.getBlue() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(black.getHTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "black.getHTMLRed() != 0" << endl;
		result = false;
	}

	++ntests;
	if(black.getHTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "black.getHTMLGreen() != 0" << endl;
		result = false;
	}

	++ntests;
	if(black.getHTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "black.getHTMLBlue() != 0" << endl;
		result = false;
	}

	++ntests;
	if(white.getRed() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "white.getRed()" << endl;
		result = false;
	}

	++ntests;
	if(white.getGreen() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "white.getGreen() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(white.getBlue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "white.getBlue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(white.getHTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "white.getHTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(white.getHTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "white.getHTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(white.getHTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "white.getHTMLBlue() != 255" << endl;
		result = false;
	}

	++ntests;
	if(whiteHTML.getRed() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "whiteHTML.getRed() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(whiteHTML.getGreen() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "whiteHTML.getGreen() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(whiteHTML.getBlue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "whiteHTML.getBlue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(whiteHTML.getHTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "whiteHTML.getHTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(whiteHTML.getHTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "whiteHTML.getHTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(whiteHTML.getHTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "whiteHTML.getHTMLBlue() != 255" << endl;
		result = false;
	}

	++ntests;
	if(blackHTML.getRed() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "blackHTML.getRed() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(blackHTML.getGreen() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "blackHTML.getGreen() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(blackHTML.getBlue() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "blackHTML.getBlue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(blackHTML.getHTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "blackHTML.getHTMLRed() != 0" << endl;
		result = false;
	}

	++ntests;
	if(blackHTML.getHTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "blackHTML.getHTMLGreen() != 0" << endl;
		result = false;
	}

	++ntests;
	if(blackHTML.getHTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "blackHTML.getHTMLBlue() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRed.getRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRed.getRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRed.getGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRed.getGreen() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRed.getBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRed.getRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRed.getHTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRed.getHTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRed.getHTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRed.getHTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRed.getHTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRed.getHTMLBlue() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.getRed() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.getRed() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.getGreen() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.getGreen() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxRed.getRed() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRed.getRed() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxRed.getGreen() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRed.getGreen() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxRed.getBlue() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRed.getBlue() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxRed.getHTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRed.getHTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxRed.getHTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRed.getHTMLGreen() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxRed.getHTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRed.getHTMLBlue() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxGreen.getRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreen.getRed() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxGreen.getGreen() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreen.getGreen() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxGreen.getBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreen.getBlue() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxGreen.getHTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreen.getHTMLRed() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxGreen.getHTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreen.getHTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxGreen.getHTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreen.getHTMLBlue() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxBlue.getRed() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxBlue.getRed() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxBlue.getGreen() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxBlue.getGreen() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxBlue.getBlue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxBlue.getBlue != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxBlue.getHTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxBlue.getHTMLRed() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxBlue.getHTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxBlue.getHTMLGreen() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxBlue.getHTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxBlue.getHTMLBlue() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.getBlue() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.getBlue() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.getHTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.getHTMLRed() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.getHTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.getHTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.getHTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.getHTMLBlue() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLBlue.getRed() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLBlue.getRed() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLBlue.getGreen() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLBlue.getGreen() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLBlue.getBlue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLBlue.getBlue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLBlue.getHTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLBlue.getHTMLRed() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLBlue.getHTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLBlue.getHTMLGreen() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLBlue.getHTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLBlue.getHTMLBlue() != 255" << endl;
		result = false;
	}

	++ntests;
	if(color.getRed() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.getRed() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(color.getGreen() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.getGreen() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(color.getBlue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.getBlue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(color.getHTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.getHTMLRed() != 255)" << endl;
		result = false;
	}

	++ntests;
	if(color.getHTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.getHTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(color.getHTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.getHTMLBlue() != 255" << endl;
		result = false;
	}

	output.close();

	return result;
}

#endif // TESTRGB_HPP



//  TODO:
//
//
//
//
