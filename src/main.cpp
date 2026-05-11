//
//  main.cpp
//  Numerics
//
//  Created by jan aguirre on 05/04/2026.
//

#include "LFO.h"

#include <iomanip>
#include <iostream>

int main(int argc, const char* argv[])
{
    // double sampleFreq{440.0};
    LFO box;
    box.setParameters(20.0, 0.5, 0, LFO::Shape::Sine);
    while (true)
    {
        std::cout << "\rLFO: " << std::fixed << std::setprecision(6)
        << std::setw(10) << box.getValue() << std::flush;
    }

    return 0;
}
