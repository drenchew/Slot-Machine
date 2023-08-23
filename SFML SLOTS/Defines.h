#pragma once

#ifndef DEFINES_H
#define DEFINES_H

//                                                  USED FOR LOADING THE IMAGES
constexpr auto __BELL__ = ".\\assets\\bell.png";
constexpr auto __SEVEN__ = ".\\assets\\seven.png";
constexpr auto __CHERRY__ = ".\\assets\\cherry.png";
constexpr auto __WATERMELON__ = ".\\assets\\watermelon.png";
constexpr auto __GRAPE__ = ".\\assets\\grape.png";

constexpr auto __LOGO__ = ".\\assets\\Bandoleros.png";
constexpr auto __BACKGROUND__ = ".\\assets\\back.png";


//                                      CONSTANTS FOR THE GAME LOGIC

const sf::Vector2f PlayerPosition(850, 500); // position of the playes balance
const sf::Vector2f PlayerSize(110, 40); // size of the balance
constexpr int InitialBalance = 100;     // starting balance
constexpr int ReelSpinDuration = 500; // spin duration in milliseconds
constexpr int MaxSpinDuration = 2501; // total sping duration of all reels



#define SHIFT 100 // shift symbols of each other

enum SymbolType
{
    CHERRY, // 0 
    BELL, // 1 
    WATERMELON, // 2 
    GRAPE, // 3 
    SEVEN,// 4
  
   
    LOGO = 100,
    BACKGROUND,


    ERROR = 404,

};

#endif // !DEFINES_H