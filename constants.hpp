
//constants.hpp
#pragma once
#include<numbers>

namespace Constants {
    constexpr float P_2 = std::numbers::pi * 2.0f;
    constexpr float ToRad = P_2 / 360.f;
    constexpr float ToGradus = 360.f / P_2;
}