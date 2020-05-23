//Name: Kevin Zhang
//Period 9

#include <iostream>
#include "P9CPP_KevinZhang_RPGSystem.cpp"
using namespace std;

/* features:
1. equipments for player
2. market where you can buy
3. player inventory
4. potions
5. multiple enemies
*/

// main function of the rpg game
int main(){
	mass_generator();
	rpg_game_intro();
	if (player.hp > 0){
		enter_dungeon();
	}
}
