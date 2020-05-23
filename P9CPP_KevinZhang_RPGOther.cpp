
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h>
#include "P9CPP_KevinZhang_Header.h"
using namespace std;

// function to cause pause or delay between sequences
void wait_to_refresh(float time){
	time = time * 1000;
	Sleep(time);
	system("CLS");
}

// function that allows the usage of items from the inventory
void use_item(Player::Inventory item){
	for (int j = 0; j < 3; j++){
		if (item.item_usage == obj_usage[j]){
			switch(j){
				case 0: player.Head = equip_player(transfer_item_to_use(item)); break;
				case 1: player.Body = equip_player(transfer_item_to_use(item)); break;
				case 2: player.Legs = equip_player(transfer_item_to_use(item)); break;
			}
		}
		else{
			player.hp = player.hp + item.item_hp;
			if (player.hp > player.get_final_thp()){
				player.hp = player.get_final_thp();
			}
		}
	}
	item.empty = true;
}

// return bool base on user's answer
bool return_answer(string answer, bool def){
	if (def){
		if (answer == "yes"){
			return true;
		}
		else{
			wait_to_refresh(.2);
			return false;
		}
	}
	else{
		if (answer == "yes"){
			wait_to_refresh(.2);
			return false;
		}
		else{
			wait_to_refresh(.2);
			return true;
		}
	}
}

// declare array
Install_Attack BL_Installment[4];
// function that will help generate these information into array
Install_Attack Load_BL_ATT(int num){
	Install_Attack temp;
	temp.set_install_id(num);
	switch(num){
		case 0:
			temp.name_install_att("pound");
			temp.set_install_dmg(2); break;
		case 1:
			temp.name_install_att("bite");
			temp.set_install_dmg(5); break;
		case 2:
			temp.name_install_att("scratch");
			temp.set_install_dmg(3); break;
		case 3:
			temp.name_install_att("stomp");
			temp.set_install_dmg(5); break;
	}
	return temp;
}

// declare array
Attack Single[3];
// function that will help generate single attacks
Attack Load_S_ATT(int num){
	Attack temp;
	temp.set_attack_id(num);
	temp.set_attack_type("Single");
	for (int i = 0; i < 3; i++){
		if (i == num){
			temp.set_req_lvl(0);
			temp.set_req_class("None");
		}
	}
	switch(num){
		case 0:
			temp.name_attack("hit");
			temp.set_req_weapon1("Any");
			temp.set_attack_dmg(10); break;
		case 1:
			temp.name_attack("kick");
			temp.set_req_weapon1("Any");
			temp.set_attack_dmg(8); break;
		case 2:
			temp.name_attack("sharp wind");
			temp.set_req_weapon1("Book");
			temp.set_req_weapon2("Staff");
			temp.set_attack_dmg(14); break;
		case 3:
			temp.name_attack("stab");
			temp.set_req_weapon1("Sword");
			temp.set_req_weapon2("Knife");
			temp.set_attack_dmg(15); break;
	}
	return temp;
}

// declare array
Object Head[10];
// function that will help load head gear
Object Load_Head_Gear(int num){
	Object temp;
	temp.set_obj_id(num);
	temp.only_for("Head");
	for (int i = 0; i < 10; i++){
		if (i == num){
			temp.set_obj_lvl(0);
			temp.set_class("None");
		}
	}
	switch(num){
		case 0:
			temp.give_name("Straw Hat");
			temp.set_cost(0);
			temp.set_object_stats(0,0,0,0,0,0,0); break;
		case 1:
			temp.give_name("Leather Helmet");
			temp.set_cost(100);
			temp.set_object_stats(0,0,0,0,0,1,0); break;
		case 2:
			temp.give_name("Strong Leather Helmet");
			temp.set_cost(150);
			temp.set_object_stats(0,0,0,0,1,1,0); break;
		case 3:
			temp.give_name("Metal Helmet");
			temp.set_cost(350);
			temp.set_object_stats(0,0,0,0,0,2,0); break;
	}
	return temp;
}

// declare array
Object Chest[10];
// function that will help load chest gear
Object Load_Chest_Gear(int num){
	Object temp;
	temp.set_obj_id(num);
	temp.only_for("Body");
	for (int i = 0; i < 10; i++){
		if (i == num){
			temp.set_obj_lvl(0);
			temp.set_class("None");
		}
	}
	switch(num){
		case 0: 
			temp.give_name("Ripped Shabby Shirt");
			temp.set_cost(0);
			temp.set_object_stats(0,0,0,0,0,0,0); break;
		case 1:
			temp.give_name("Leather Shirt");
			temp.set_cost(100);
			temp.set_object_stats(0,0,0,0,0,1,1); break;
		case 2:
			temp.give_name("Strong Leather Shirt");
			temp.set_cost(200);
			temp.set_object_stats(5,0,0,0,1,1,0); break;
		case 3:
			temp.give_name("Metal Plate");
			temp.set_cost(500);
			temp.set_object_stats(0,0,0,0,0,3,0); break;
	}
	return temp;
}

// declare array
Object Legs[10];
// function that will help load leg gear
Object Load_Legs_Gear(int num){
	Object temp;
	temp.set_obj_id(num);
	temp.only_for("Legs");
	for (int i = 0; i < 10; i++){
		if (i == num){
			temp.set_obj_lvl(0);
			temp.set_class("None");
		}
	}
	switch(num){
		case 0: 
			temp.give_name("Short Shabby Pants");
			temp.set_cost(0);
			temp.set_object_stats(0,0,0,0,0,0,0); break;
		case 1:
			temp.give_name("Short Pants");
			temp.set_cost(120);
			temp.set_object_stats(0,0,0,0,0,1,1); break;
		case 2:
			temp.give_name("Enforced Short Pants");
			temp.set_cost(200);
			temp.set_object_stats(5,0,0,0,1,1,0); break;
		case 3:
			temp.give_name("Metal Pants");
			temp.set_cost(400);
			temp.set_object_stats(0,0,0,0,0,2,0); break;
	}
	return temp;
}

// declare array
Object Potions[5];
// function that will help load potions
Object Load_Potions_Item(int num){
	Object temp;
	temp.set_obj_id(num);
	temp.set_obj_lvl(0);
	switch(num){
		case 0:
			temp.give_name("Small Health Potion");
			temp.set_cost(200);
			temp.set_object_stats(0,50,0,0,0,0,0); break;
		case 1:
			temp.give_name("Medium Health Potion");
			temp.set_cost(400);
			temp.set_object_stats(0,100,0,0,0,0,0); break;
	}
	return temp;
}

// function that adds infomation to enemies to complete enemy setup
void complete_BE_setup(){
	for (int i = 0; i < 2; i++){
		Normal_Wolf[i].name = "Normal Wolf";
		Normal_Wolf[i].id = 0;
		Normal_Wolf[i].level = i;
		Normal_Wolf[i].enemy_basic_stats(20+i*2,20+i*2,0,0);
		Normal_Wolf[i].enemy_action_stats(1+i,0,0+i/2);
		Normal_Wolf[i].basic_attacks[0] = set_enemy_attack(BL_Installment[1]);
		Normal_Wolf[i].basic_attacks[1] = set_enemy_attack(BL_Installment[2]);
	}
	for (int i = 0; i < 2; i++){
		Normal_Bear[i].name = "Normal Bear";
		Normal_Bear[i].id = 1;
		Normal_Bear[i].level = i;
		Normal_Bear[i].enemy_basic_stats(30+i*3,30+i*3,0,0);
		Normal_Bear[i].enemy_action_stats(2+i/2,0+i/2,0);
		Normal_Bear[i].basic_attacks[0] = set_enemy_attack(BL_Installment[0]);
		Normal_Bear[i].basic_attacks[1] = set_enemy_attack(BL_Installment[3]);
	}
}

// function that generates everything
void mass_generator(){
	for (int i = 0; i < 4; i++){
		//generate equipment (type: head)
		Head[i] = Load_Head_Gear(i);
		// generate equipment (type: chest)
		Chest[i] = Load_Chest_Gear(i);
		// generate equipment (type: legs)
		Legs[i] = Load_Legs_Gear(i);
		//generate installments of basic attacks
		BL_Installment[i] = Load_BL_ATT(i);
	}
	for (int i = 0; i < 3; i++){
		// generate attacks (type: single)
		Single[i] = Load_S_ATT(i);
	}
	for (int i = 0; i < 2; i++){
		// generate potions
		Potions[i] = Load_Potions_Item(i);
	}
	complete_BE_setup();
}

// function to cause pause or delay between sequences (for battle)
void battle_wait_to_refresh(float time){
	time = time * 1000;
	Sleep(time);
	system("CLS");
}

// return bool base on user's answer (for battle)
bool battle_return_answer(string answer, bool def){
	if (def){
		if (answer == "yes"){
			return true;
		}
		else{
			battle_wait_to_refresh(.2);
			return false;
		}
	}
	else{
		if (answer == "yes"){
			battle_wait_to_refresh(.2);
			return false;
		}
		else{
			battle_wait_to_refresh(.2);
			return true;
		}
	}
}

// function for randomization
int randomization(int num){
	srand(time(0));
	int factor = rand() % 7;
	switch(factor){
		case 0: return 2*(num+player.get_final_str()); break;
		case 1: return num+player.get_final_str(); break;
		case 2: return 8+num+player.get_final_str(); break;
		case 3: return 5+num+player.get_final_str(); break;
		case 4: return num+player.get_final_str(); break;
		case 5: return 2*player.get_final_str()+num; break;
		case 6: return 2*num+player.get_final_str(); break;
	}
}

// declare vector for the amount of enemies that will appear in battle
vector <Enemy> spots(0);

// function that generates two different enemy typies
void two_diffenemy(int amount, int level, Enemy entity1[], Enemy entity2[]){
	srand(time(0));
	for (int i = 0; i < amount; i++){
		int selection = rand() % 2;
		if (level != 0){
			level--;
		}
		else{
			level = level + rand() % 2;
		}
		switch(selection){
			case 0: spots.push_back(entity1[level]); break;
			case 1: spots.push_back(entity2[level]); break;
		}
	}
}

// function that update the amount of enemies left to battle
int update_active_enemy(){
	int count;
	for(int i = 0; i < spots.size(); i++){
		if (spots[i].active){
			count++;
		}
	}
	return count;
}

// function that put player into battle
void battle_sys(int num_enemy){
	srand(time(0));
	int battle_health = player.hp;
	int target, att_choice, actual_dmg, amount_left;
	string response, user_input;
	two_diffenemy(num_enemy, player.level, Normal_Wolf, Normal_Bear);
	// display the enemies that the player encountered
	for (int i = 0; i < num_enemy; i++){
		spots[i].active = true;
		amount_left++;
		cout<<"You have encountered a Level "<<spots[i].level<<" "<<spots[i].name<<"!"<<endl<<endl;
	}
	cout<<"Let's Start!"<<endl<<endl;
	// battle continues while there are enemies that are alive
	while (amount_left != 0 && battle_health > 0){
		int basic_incorrect = 0;
		int actual_dmg = 0;
		cout<<"You have "<<battle_health<<" health points left!!!"<<endl<<endl;
		cout<<"Type the name of the attack that you want to execute: ";
		cin>>user_input;
		// player attacks
		for (int i = 0; i < 3; i++){
			if (user_input == player.basic_attacks[i].name){
				actual_dmg = randomization(player.basic_attacks[i].damage);
				target = rand() % num_enemy;
				while (spots[target].active == false){
					target = rand() % num_enemy;
				}
				i = 100;
			}
			else{
				basic_incorrect++;
			}
		}
		// if incorrect, then that would count as a miss attack
		if (basic_incorrect == 3){
			cout<<player.name<<" have missed your attack! (incorrect input)"<<endl<<endl;
		}
		else{
			spots[target].hp = spots[target].hp - actual_dmg;
			cout<<player.name<<" deal "<<actual_dmg<<" damage to a Level "<<spots[target].level<<" "<<spots[target].name<<"!"<<endl<<endl;
			if (spots[target].hp <= 0){
				spots[target].active = false;
				cout<<player.name<<" have killed a Level "<<spots[target].level<<" "<<spots[target].name<<"!"<<endl<<endl;
				cout<<player.name<<" obtained 50 gold!"<<endl<<endl;
				player.money = player.money + 50;
			}
			else{
				cout<<"Level "<<spots[target].level<<" "<<spots[target].name<<" has "<<spots[target].hp<<" health points remaining!"<<endl<<endl;
			}
		}
		// enemy attacks
		for (int i = 0; i < num_enemy; i++){
			if (spots[i].active){
				att_choice = rand() % 2;
				if (player.get_final_def() != 0){
					actual_dmg = randomization(spots[i].basic_attacks[att_choice].damage) / player.get_final_def();
				}
				else{
					actual_dmg = randomization(spots[i].basic_attacks[att_choice].damage);
				}
				battle_health = battle_health - actual_dmg;
				cout<<"Level "<<spots[i].level<<" "<<spots[i].name<<"( "<<spots[i].hp<<" )"<<" dealt "<<actual_dmg<<" damage using '"<<spots[i].basic_attacks[att_choice].name<<"'"<<endl<<endl;
			}
		}
		amount_left = update_active_enemy();
		battle_wait_to_refresh(6);
	}
	// if all enemies are killed
	if (update_active_enemy() == 0){
		cout<<"You have killed all of your enemies!!!"<<endl;
		for (int i = 0; i < num_enemy; i++){
			spots.pop_back();
		}
		player.hp = battle_health;
	}
	// if player dies in battle
	else if (battle_health <= 0){
		cout<<player.name<<" have fallen. Better luck next time!"<<endl;
		player.hp = 0;
	}
}

// declare necessary variables
int player_room, place;
bool battle, gold;

// function that generates 3 by 3 room
void generate_3x3(){
	for (int i = 0; i < 9; i++){
		if (i % 2 == 0){
			if (i != 4){
				switch(i){
					case 0: map_room[i] = generate_corner_room(1); break;
					case 2: map_room[i] = generate_corner_room(2); break;
					case 6: map_room[i] = generate_corner_room(3); break;
					case 8: map_room[i] = generate_corner_room(4); break;
				}
			}
			else{
				map_room[i] = generate_fourway_room();
			}
		}
		else{
			switch(i){
				case 1: map_room[i] = generate_threeway_room(2,1); break;
				case 3: map_room[i] = generate_threeway_room(1,1); break;
				case 5: map_room[i] = generate_threeway_room(1,2); break;
				case 7: map_room[i] = generate_threeway_room(2,2); break;
			}
		}
	}
}

// function that builds the room
void set_room(int num){
	for (int i = 0; i < map_room[num].area_size; i++){
		map_room[num].build_space[i] = map_room[num].room_layout(i);
	}
	if (map_room[num].open_n){
		map_room[num].build_space[2] = ' ';
	}
	if (map_room[num].open_e){
		map_room[num].build_space[14] = ' ';
	}
	if (map_room[num].open_s){
		map_room[num].build_space[22] = ' ';
	}
	if (map_room[num].open_w){
		map_room[num].build_space[10] = ' ';
	}
}

// function that displays the room
void display_room(int num){
	for (int i = 0; i < map_room[num].area_size; i++){
		if (i % 5 == 4){
			cout<<map_room[num].build_space[i];
		}
		else{
			cout<<map_room[num].build_space[i]<<" ";
		}
		if (i % 5 == 4){
			cout<<endl;
		}
	}
	cout<<endl<<endl;
}

// function that will place player randomly in a certain room
void place_player(int id){
	int landing = rand() % 9;
	map_room[id].build_space[placement_area[landing]] = map_room[id].entity.player;
}

// function that will place player randomly in one of the dungeon rooms
void set_starting_room(int num){
	switch(num){
		case 0: place_player(0); break;
		case 1: place_player(2); break;
		case 2: place_player(6); break;
		case 3: place_player(8); break;
	}
}

// function that will randomize the apperance of enemies in the dungeon
void randomize_entity(int num){
	srand(time(0));
	for (int i = 0; i < num; i++){
		int placement = rand() % 9;
		for (int j = 0; j < 9; j++){
			int space = rand() % 9;
			if (map_room[placement].build_space[placement_area[space]] == ' '){
				map_room[placement].build_space[placement_area[space]] = map_room[placement].entity.enemy;
				j = 10;
			}
		}
	}
}

// function that will randomize the apperance of gold in the dungeon
void randomize_gold(){
	srand(time(0));
	for (int i = 0; i < 8; i++){
		int placement = rand() % 9;
		for (int j = 0; j < 9; j++){
			int space = rand() % 9;
			if (map_room[placement].build_space[placement_area[space]] == ' '){
				map_room[placement].build_space[placement_area[space]] = map_room[placement].objects.gold;
				j = 10;
			}
		}
	}
}

// function that will check if there's something blocking the player's movement
bool check_open(int id, int place, int num){
	char temp;
	temp = map_room[id].build_space[place+num];
	if (temp == '=' || temp == '|'){
		return false;
	}
	else{
		return true;
	}
}

// function that will reset the bool array
void reset_possible_directions(){
	for (int i = 0; i < 4; i++){
		directions_possible[i] = false;
	}
}

// function that will move player and see if the player encounters something
bool check_valid_direction(string temp){
	srand(time(0));
	char holder;
	for (int i = 0; i < 4; i++){
		if (temp == map_directions[i]){
			if (directions_possible[i]){
				map_room[player_room].build_space[place] = ' ';
				switch(i){
					case 0:
						holder = map_room[player_room].build_space[place-5];
						if(holder == map_room[player_room].entity.enemy){
							battle = true;
						}
						else if(holder == map_room[player_room].objects.gold){
							gold = true;
						}
						map_room[player_room].build_space[place-5] = map_room[player_room].entity.player; break;
					case 1: 
						holder = map_room[player_room].build_space[place+5];
						if(holder == map_room[player_room].entity.enemy){
							battle = true;
						}
						else if(holder == map_room[player_room].objects.gold){
							gold = true;
						}
						map_room[player_room].build_space[place+5] = map_room[player_room].entity.player; break;
					case 2: 
						holder = map_room[player_room].build_space[place+1];
						if(holder == map_room[player_room].entity.enemy){
							battle = true;
						}
						else if(holder == map_room[player_room].objects.gold){
							gold = true;
						}
						map_room[player_room].build_space[place+1] = map_room[player_room].entity.player; break;
					case 3:
						holder = map_room[player_room].build_space[place-1];
						if(holder == map_room[player_room].entity.enemy){
							battle = true;
						}
						else if(holder == map_room[player_room].objects.gold){
							gold = true;
						}
						map_room[player_room].build_space[place-1] = map_room[player_room].entity.player; break;
				}
				return true;
			}
		}
	}
	return false;
}

// function that will check if the user input is valid
int check_valid_input(string temp){
	if (temp == "market"){
		return 1;
	}
	else if (temp == "inventory"){
		return 2;
	}
	else{
		return 0;
	}
}

// function that will transfer the player into a new room due to movement inputted by the user
void transfer_room(){
	int place;
	// locate player in the room
	for (int i = 0; i < map_room[player_room].area_size; i++){
		if (map_room[player_room].build_space[i] == map_room[player_room].entity.player){
			place = i;
		}
	}
	// remove player from room
	map_room[player_room].build_space[place] = ' ';
	// move the player according to room and the direction they exited from
	switch(player_room){
		case 0:
			switch(place){
				case 14: player_room = 1; place = 11; break;
				case 22: player_room = 3; place = 7; break;
			} break;
		case 1:
			switch(place){
				case 10: player_room = 0; place = 13; break;
				case 14: player_room = 2; place = 11; break;
				case 22: player_room = 4; place = 7; break;
			} break;
		case 2:
			switch(place){
				case 10: player_room = 1; place = 13; break;
				case 22: player_room = 5; place = 7; break;
			} break;
		case 3:
			switch(place){
				case 2: player_room = 0; place = 17; break;
				case 14: player_room = 4; place = 11; break;
				case 22: player_room = 6; place = 7; break;
			} break;
		case 4:
			switch(place){
				case 2: player_room = 1; place = 17; break;
				case 10: player_room = 3; place = 13; break;
				case 14: player_room = 5; place = 11; break;
				case 22: player_room = 7; place = 7; break;
			} break;
		case 5:
			switch(place){
				case 2: player_room = 2; place = 17; break;
				case 10: player_room = 4; place = 13; break;
				case 22: player_room = 8; place = 7; break;
			} break;
		case 6:
			switch(place){
				case 2: player_room = 3; place = 17; break;
				case 14: player_room = 7; place = 11; break;
			} break;
		case 7:
			switch(place){
				case 2: player_room = 4; place = 17; break;
				case 10: player_room = 6; place = 13; break;
				case 14: player_room = 8; place = 11; break;
			} break;
		case 8:
			switch(place){
				case 2: player_room = 5; place = 17; break;
				case 10: player_room = 7; place = 13; break;
			} break;
	}
	// place player icon on the new updated room and the direction they entered the room from
	map_room[player_room].build_space[place] = map_room[player_room].entity.player;
}
