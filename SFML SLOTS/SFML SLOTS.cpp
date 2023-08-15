#include <SFML/Graphics.hpp>


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <memory>


#include "Symbol.h"
#include "Row.h"
#include "Button.h"
#include"User.h"

typedef std::vector<std::vector<int>> Matrix;

sf::RenderWindow window(sf::VideoMode(1024, 576), "Bandoleros Slot Machine");  // The main window


struct ActionBtn {
    double CurBet = 0;
    bool state = false;
};


void PaternLine(double& multiplier, std::shared_ptr< Row> row)
{
    SymbolType prev = row->get_row()[0].get_type();
    int i = 1;
    for (; i < row->get_row().size(); ++i)
    {
        SymbolType next = row->get_row()[i].get_type();

        if ((prev == next) && (i >= 2))
        {
            multiplier += 1;
        }
        else if ((prev != next))
        {
            break;
        }
       

    }

    if (multiplier == 0)
    {
        return;
    }

    switch (prev)
    {
    case SymbolType::BELL: multiplier *= (i * 0.5); break;
    case SymbolType::SEVEN: multiplier *= (i * 5); break;
    case SymbolType::WATERMELON: multiplier *= (i*3) ; break;
    case SymbolType::CHERRY: multiplier *=(i*0.6) ; break;
    default: multiplier = 0; break;
    }

}



void SpinRow(std::vector<std::shared_ptr<Row>> rows, Symbol& logo, std::vector<std::shared_ptr<Button>> buttons, Symbol& background,User& player, ActionBtn& action) {
    // Spin the row


    double multiplier = 0;

    for (const auto& row : rows)
    {
        PaternLine(multiplier, row);
    }

    if (multiplier == 0)
    {
        multiplier = action.CurBet * (-1);
    }
    player.update_balance(multiplier);

    player.draw(window);


    for (auto& row : rows) {
   

        // Move the symbols to simulate spinning
        for (int i = 0; i < 30; ++i) {
            for (auto& r : row->get_row()) {
                r.move_position(0, 10);

                // Check for symbol-button overlap
                for (const auto& btn : buttons) {
                    sf::FloatRect symbolBounds = r.get_sprite().getGlobalBounds();
                    sf::FloatRect buttonBounds = btn->_shape.getGlobalBounds();

                    if (symbolBounds.intersects(buttonBounds)) {
                        // Move symbol upwards if it overlaps with a button
                        r.move_position(0, -10);
                    }
                }
            }

            window.clear();

            window.draw(background.get_sprite()); // background first

            window.draw(logo.get_sprite()); // logo drawing

            

            player.draw(window);
            
            

            for (auto& btn : buttons)
            {
                btn->draw(window);
            }

            for (auto& r : row->get_row()) {
                window.draw(r.get_sprite());
            }

            window.display();

            row->populate();

            sf::sleep(sf::microseconds(700));
        }

        // Position the symbols to show the result
        float j = row->_x;
        float q = row->_y;
        for (auto& r : row->get_row()) {
            r.set_position(j, q);
            j += 100;
        }
    }
}



void RefreshResult(std::vector< std::shared_ptr<Row>>& rows,Symbol& logo, std::vector<std::shared_ptr<Button>>& buttons,Symbol& background,User& player) 
{

    window.draw(background.get_sprite()); // Background First!

    window.draw(logo.get_sprite());

    player.draw(window);

    for (auto& btn : buttons)
    {
        btn->draw(window);
    }

    for (auto& row : rows)
    {
        for (auto& r : row->get_row())
        {
            window.draw(r.get_sprite());
        }
       
    }
    window.display();
}





void StartGame(Matrix& WinSymbols)
{
    User player(sf::Vector2f(850,500), sf::Vector2f(110, 40), 100);

    Symbol background(BACKGROUND);
    background.set_position(0, 0);

    Symbol logo(LOGO);
    logo.set_position((float)290, (float)10);

   
   


    std::vector<std::shared_ptr<Button>> buttons;
    ActionBtn actions;

    {
        std::vector<std::string> bets { "1", "2", "4", "10"};
     
        float size_x = 110;
        float size_y = 50;

        buttons.emplace_back(std::make_shared<Button>(bets[0], sf::Vector2f(75, 510), sf::Vector2f(size_x, size_y))); // bet for  1 unit

        buttons.emplace_back(std::make_shared<Button>("  " + bets[1], sf::Vector2f(60+SHIFT + SHIFT/2, 510), sf::Vector2f(size_x, size_y))); // bet for 2 units

        buttons.emplace_back(std::make_shared<Button>("  " + bets[2], sf::Vector2f(57 + 3 * SHIFT, 510), sf::Vector2f(size_x, size_y))); // bet for  4 units 


        buttons.emplace_back(std::make_shared<Button>( bets[3], sf::Vector2f(75 + 4 * SHIFT + SHIFT / 3, 510), sf::Vector2f(size_x, size_y))); // bet fot 3 units




    }
    
  

    std::vector< std::shared_ptr<Row>> rows; // rows of the slot machine


    float x = 255; // the x possition on the screen 
    float y = 100;   // the y possition on the screen 
    for (int row = 0; row < 4; ++row)
    {
        rows.emplace_back(std::make_shared<Row>(x, y));
        y += SHIFT;
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
                
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {

                    // Handle button click event here
                    std::cout << "Space Clicked!" << std::endl;
                   // SpinRow(rows,logo, buttons,background,player);
                
               
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {

                for (const auto& btn : buttons)
                {
                    if (btn->isMouseOver(window))
                    {
                        actions.CurBet = btn->get_bet();
                        actions.state = true;
                    }
                }

                
            }
            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && actions.state)
            {
               
                {
                    if(player.valid_balance(actions.CurBet))
                        SpinRow(rows,logo, buttons,background,player, actions);
                        std::cout << "Button Clicked! and released "<<actions.CurBet << std::endl;
                    actions.state = false;
                }

            }
        }

        window.clear();

      

        RefreshResult(rows, logo,buttons,background,player);
    }
}

Matrix InitGame()
{
    Matrix WinSymbols{ {0,1,2,3,4},{}

    };
   

    return WinSymbols;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

   auto init = InitGame();

    StartGame(init);


    return 0;
}
