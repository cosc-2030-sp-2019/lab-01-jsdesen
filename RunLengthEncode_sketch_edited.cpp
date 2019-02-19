// RunLengthEncode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// CPP program to implement run length encoding
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string line;
	string whitespace(" \t\f\v\n\r");
	vector<string> pix_list;
	int i, count, n;
	const char* flag="11111111 ";
	ifstream pixf_full;
	pixf_full.open("PixData.txt");
	ofstream pixf_cmpr;
	pixf_cmpr.open("PixCmprsFrank.txt");
	if (pixf_full.is_open()) cout << "Input pixf_full is open.";
	// Read into pix_list.
	i = 0;
	while (getline(pixf_full,line))
	{
		cout << line;
		// 2.  (Explain statement below.)
		// push_back is a string function that takes a given character input and concatenates it to the string.
		pix_list.push_back(line);
		i = i + 1;
	}
	n = pix_list.size();
	cout << "Length of pix_list is " << n << " ; i = " << i << "\n";
	// Go through list, testing whether next pixel is the same.
	for (i = 0; i < n; i++)
	{
		if (pix_list[i + 1] != pix_list[i])
		{
			pixf_cmpr << flag << pix_list[i] << "\n";
		}
		else
		{
			// Pixels same.
			// 1. Write flag character and repeated pixel.  Strip pesky newline at end.
			pixf_cmpr << "00000000 " << pix_list[i].substr(0, (pix_list[i].find_last_not_of(whitespace)+1));
			// 5. (Explain loop below.)
			// The loop below first checks to see if the pixels in i and i+1 are the same.
			// If they are the same it then increments the count of similar pixels in this set and increments the value of i.
			// This process repeats until either the end of the file is reached, i < n-1, or the pixels are different, i != i + 1.
			count = 1;
			while (i < n - 1 && pix_list[i] == pix_list[i + 1])
			{
				count++;
				i++;
			}
			// Different pixel or end of file encountered.
			// Write output to file.
			pixf_cmpr << " " << count << "\n";
		}
	}
	return 0;
}

