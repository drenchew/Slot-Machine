#pragma once
#ifndef PATERNS_H
#define PATERNS_H

//#include"Game.h"
class SlotMachineInterface;




class Paterns {
public:
	Paterns() = default;

	Paterns(SlotMachineInterface* slotMachine): slots_interface(slotMachine)
	{}


	void check_patern1(const std::vector<std::shared_ptr<Reel>>& reels, const double& CurBet)
	{
	

		 double total = 0;

		// std::cout <<"current bet "<< CurBet << std::endl;
		
		for (size_t i = 0; i < 4; i++)
		{
			double multiplier = 0;
			unsigned short int streak = 0;

			auto f = reels.begin();
			 const Symbol first = (*(*f))[i];
			// std::cout << "first: " << first << '\n';
			
			
			//reels[i]

			switch (first.get_type())
			{
			case CHERRY: multiplier =1.2;
				break;
			case BELL: multiplier = 1.65;
				break;
			case WATERMELON: multiplier = 3;
				break;
			case GRAPE: multiplier = 4;
				break;
			case SEVEN: multiplier = 5;
				break;
			}
			
			for (auto& reel : reels)
			{
				std::cout << "symbol: " << (*reel)[i] << '\n';
				if ((*reel)[i] == first) {
					streak++;
				//	std::cout << "streak: " << streak<<'\n';

					switch (streak)
					{
					case 3: multiplier += 0.25; break;
					case 4: multiplier += 0.30; break;
					case 5: total += (multiplier + 2) * CurBet; break;
					}
					
				}
				else if((*reel)[i] != first && streak > 2) {
					total += multiplier * CurBet;
					break;
				}
				else { break; }
			

				//std::cout << (*reel)[i] << " ";
			}
			std::cout << "total: " << total;
			std::cout << '\n';
		}
		
		




		if ( 0 == total )
		{
			//slots_interface->set_multiplier(CurBet * (-1));
			slots_interface->update_balance(CurBet * (-1));
		}
		else {
			//slots_interface->set_multiplier(CurBet * multiplier * combo);
			slots_interface->update_balance(total);
		}
	

		

	}
private:
	SlotMachineInterface* slots_interface;
	
};

#endif // !PATERNS_H
