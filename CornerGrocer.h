#include <map>
#include <string>

class CornerGrocer { //Here I created the Corner Grocer class.
public: //This is the public section of my class.
    void readInputFile(); //I created the function to read from the input file.
    void writeToFrequencyDataFile(); //I created the function to write to the output file.
    void userMenu(); //I created a function to diplay the menu.
        

private://This is the private section of my class.
    std::map<std::string, int> itemFrequency; //I created a map to lookup items based on their frequencies.
    std::string inputFile = "CS210_Project_Three_Input_File.txt"; //I gave the input file a name.
    std::string frequencyDataFile = "frequency.dat"; //I gave the data file a name.
    void itemSearch(); //I created a function for menu option 1.
    void printItemFrequency();//I created a function for menu option 2.
    void printHistogram();//I created a function for menu option 3.
};

#endif /* CORNERGROCER_H */
