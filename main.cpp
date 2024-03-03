#include <iostream>
#include "CornerGrocer.h"

int main() {
	CornerGrocer cornerGrocer; //Here I made an instance of the Corner Grocer class.
	cornerGrocer.readInputFile(); //Here I am using the instance and reading the from the input file. 
	cornerGrocer.writeToFrequencyDataFile(); //Here I am writing to the output file.
	cornerGrocer.userMenu(); //Here I am using the instance to display the menu.

	return 0;
}
