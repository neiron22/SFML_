//FontManager.cpp
#include "FontManager.hpp"

#include"resource.h"
#include"Windows.h"

//IDR_RCDATA1

//вроде ничего менять не надо

sf::Font FontManager::font;

void FontManager::init() {
    HRSRC hResource = FindResource(NULL, MAKEINTRESOURCE(IDR_RCDATA1), RT_RCDATA);
    DWORD size = SizeofResource(NULL, hResource);
    void* data = LockResource(LoadResource(NULL, hResource));
    font.loadFromMemory(data, size);
}

sf::Font& FontManager::get() {
    return font;
}