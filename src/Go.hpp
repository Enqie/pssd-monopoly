#pragma once

#include "Space.hpp"

class Go: public Space
{
public:
    Go(): Space("Go"){}

    std::string getType() override { return "Go"; }

    ImVec4 getColourVec() override { return ImVec4(0.4f, 0.8f, 0.4f, 1.0f); }
};
