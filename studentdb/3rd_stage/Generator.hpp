#include <iostream>
#include <cstdlib>

class Generator{


public:
    int generateInt(int min, int quantity);
    std::string generatePairXX(int min, int quantity);
    std::string generatePESEL();
    std::string drawString(std::string fileLocation);
    std::string drawName();
    std::string drawLastName();
    std::string drawAddress();
};
