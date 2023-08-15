#pragma once

#ifndef DEFINES_H
#define DEFINES_H


#define __BELL__ ".\\bell.png"                 // bell image
#define __SEVEN__ ".\\seven.png"              // seven (7) image
#define __CHERRY__ ".\\cherry.png"           // cherry image
#define __WATERMELON__ ".\\watermelon.png"  // watermelon image

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