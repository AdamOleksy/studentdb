#include <iostream>
#include <cstdlib>

class Generator{

    PeselValidator peselGenerator;

public:
	Generator();
    int generateInt(int min, int quantity);
    std::string generatePairXX(int min, int quantity);
    std::string generatePESEL();
    std::string generateValidPESEL();
    std::string drawString(std::string fileLocation);
    std::string drawName();
    std::string drawLastName();
    std::string drawAddress();
};
