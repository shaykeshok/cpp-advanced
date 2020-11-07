#include <iostream>
#include <complex>
#include "Editor.h"
using namespace std;

int main(int argc, char *argv[])
{
    if (argc > 0)
    {
        Editor ed("months.txt");
        ed.loop();
    }
    else
    {
        Editor ed;
        ed.loop();
    }

    
    return 0;
}