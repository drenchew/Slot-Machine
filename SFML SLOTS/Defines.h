#pragma once

#ifndef DEFINES_H
#define DEFINES_H

constexpr auto __BELL__ = ".\\assets\\bell.png";
constexpr auto __SEVEN__ = ".\\assets\\seven.png";
constexpr auto __CHERRY__ = ".\\assets\\cherry.png";
constexpr auto __WATERMELON__ = ".\\assets\\watermelon.png";
constexpr auto __LOGO__ = ".\\assets\\Bandoleros.png";
constexpr auto __BACKGROUND__ = ".\\assets\\back.png";




#define SHIFT 100 // shift symbols of each other

enum SymbolType
{
    CHERRY,
    BELL,
    WATERMELON,
    SEVEN,
  
   
    LOGO = 100,
    BACKGROUND,


    ERROR = 404,

};

#endif // !DEFINES_H