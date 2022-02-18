#include "FindFile.hpp"

int main(int argc, char *argv[])
{
    
    if(argc == 2)
        goFind(argv[1]);
    else
        std::cout << "no input\n";


    return 0;
}