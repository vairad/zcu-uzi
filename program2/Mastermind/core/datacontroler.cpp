#include <string>

#include "datacontroler.h"

#include "cli/cmdinterface.h"

void DataControler::printColors(std::vector<unsigned int> guess_colors){
    CMDInterface::printColors(guess_colors);
}

void DataControler::echoItsOnYou(){
    std::string s = "Vy jste zadával ohodnocení....";
    CMDInterface::print(s);
}
