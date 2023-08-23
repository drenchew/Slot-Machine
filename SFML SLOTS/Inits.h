#pragma once
#ifndef INITS_H
#define INITS_H

#include "Symbol.h"
#include"Button.h"
#include<memory>
#include"Reel.h"

#include<string>


std::vector<std::shared_ptr<Button>>& get_buttons(std::vector<std::shared_ptr<Button>>& buttons); // return the buttons 

std::vector<std::shared_ptr<Reel>>& get_reels(std::vector<std::shared_ptr<Reel>>& reels); //return the reels

#endif // !INITS_H

