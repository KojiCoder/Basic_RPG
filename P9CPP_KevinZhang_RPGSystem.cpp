
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "P9CPP_KevinZhang_RPGOther.cpp"
using namespace std;

// function for setting up the player
void set_up_player(){
	player.set_eq_place();
	player.player_basic_stats(150, 150, 15, 15);
	player.str = 0;
	player.def = 0;
	player.spd = 0;
	player.skill_lvl = 0;
	int stat_points = 5;
	string input_keywords[5] = {"health", "mana", "strength", "defense", "speed"};
	// player stat buildup inside the while-loop
	while (stat_points != 0){
		bool correct_input = false;
		string input = "";
		cout<<"We are now going to configure your character stats:"<<endl;
		cout<<endl<<"Total Health:\t"<<player.total_hp<<endl;
		cout<<"Total Mana:\t"<<player.total_mana<<endl;
		cout<<"Strength:\t"<<player.str<<endl;
		cout<<"Defense:\t"<<player.def<<endl;
		cout<<"Speed:\t\t"<<player.spd<<endl<<endl;
		cout<<"Total Points Remaining: "<<stat_points<<endl<<endl;
		cout<<"1 point to health or mana adds 10 to the respective stat."<<endl;
		cout<<"1 point to everything else adds 1 to the respective stat."<<endl<<endl;
		for (int i = 0; i < 5; i++){
			if (i < 2){
				cout<<"Please enter "<<"'"<<input_keywords[i]<<"'"<<" for total "<<input_keywords[i]<<endl;
			}
			else{
				cout<<"Please enter "<<"'"<<input_keywords[i]<<"'"<<" for "<<input_keywords[i]<<endl;
			}
		}
		cout<<endl<<"Please enter the section you want to add points to: ";
		cin>>input;
		for (int i = 0; i < 5; i++){
			if (input == input_keywords[i]){
				int amount_points;
				cout<<"How many point(s) do you want to add in this section: ";
				cin>>amount_points;
				while (stat_points - amount_points < 0){
					cout<<"Unsuccessful! You don't have that much points! Please try again!"<<endl;
					cout<<"How many point(s) do you want to add in this section: ";
					cin>>amount_points;
				}
				switch(i){
					case 0: player.total_hp = player.total_hp + 10 * amount_points; break;
					case 1: player.total_mana = player.total_mana + 10 * amount_points; break;
					case 2: player.str = player.str + 1 * amount_points; break;
					case 3: player.def = player.def + 1 * amount_points; break;
					case 4: player.spd = player.spd + 1 * amount_points; break;
				}
				correct_input = true;
				stat_points = stat_points - amount_points;
			}
		}
		if (correct_input){
			cout<<"Successful! Your stats will be updated!"<<endl;
		}
		else{
			cout<<"Unsuccessful! Your input doesn't correspond to the given stats! Please try again!"<<endl;
		}
		wait_to_refresh(2.8);
	}
	// complete player setup
	player.game_class = "None";
	player.hp = player.total_hp;
	player.mana = player.total_mana;
	player.basic_attacks[0] = gained_attack(Single[0]);
	player.basic_attacks[1] = gained_attack(Single[1]);
	player.Head = equip_player(Head[0]);
	player.Head.protection = true;
	player.Body = equip_player(Chest[0]);
	player.Body.protection = true;
	player.Legs = equip_player(Legs[0]);
	player.Legs.protection = true;
}

// function to display market to user
void display_market(){
	int space = 0;
	bool exit_market = false;
	for (int i = 0; i < 5; i++){
		if (player.space[i].empty){
			space++;
		}
	}
	// while player is in market
	while (exit_market == false){
		bool exit_shop = false;
		int selection, temp_num;
		string response, buy;
		Object temp;
		cout<<"These are the following sections of the market:"<<endl<<endl;
		cout<<"\t1) Head Armor Shop\n\t2) Chest Armor Shop\n\t3) Leg Armor Shop\n\t4) Potion Shop"<<endl<<endl;
		cout<<"Which of the following do you want to enter (enter number): ";
		cin>>selection;
		while(selection < 1 || selection > 4){
			cout<<"Sorry, but the following section that you've entered is not available in the market. Please try again!"<<endl;
			wait_to_refresh(4);
			cout<<"These are the following sections of the market:"<<endl;
			cout<<"\t1) Head Armor Shop\n\t2) Chest Armor Shop\n\t3) Legs Armor Shop\n\t4) Potion Shop"<<endl;
			cout<<"Which of the following do you want to enter (enter number): ";
			cin>>selection;
		}
		wait_to_refresh(0.01);
		// while player is in one of the shop
		while (exit_shop == false){
			cout<<endl;
			switch(selection){
				case 1:
					for (int i = 1; i < 4; i++){
						cout<<i<<") "<<Head[i].get_obj_name()<<endl;
					} break;
				case 2:
					for (int i = 1; i < 4; i++){
						cout<<i<<") "<<Chest[i].get_obj_name()<<endl;
					} break;
				case 3:
					for (int i = 1; i < 4; i++){
						cout<<i<<") "<<Legs[i].get_obj_name()<<endl;
					} break;
				case 4:
					for (int i = 0; i < 2; i++){
						cout<<i+1<<") "<<Potions[i].get_obj_name()<<endl;
					} break;
			}
			cout<<endl<<endl<<"Enter the number that correspond to the object available in this section: ";
			cin>>temp_num;
			while(temp_num < 1){
				cout<<"You have entered an invaild number. Please try again!"<<endl;
				cout<<endl<<"Enter the number of any object in this section: ";
				cin>>temp_num;
			}
			wait_to_refresh(1.5);
			for (int i = 0; i < 50; i++){
				if (temp_num == i){
					switch(selection){
						case 1: temp = Head[temp_num]; break;
						case 2: temp = Chest[temp_num]; break;
						case 3: temp = Legs[temp_num]; break;
						case 4: temp = Potions[temp_num-1]; break;
					}
				}
			}
			temp.display_info();
			cout<<endl<<endl<<"Cost: "<<temp.obj_cost()<<" gold"<<endl;
			cout<<player.name<<"'s money: "<<player.money<<" gold"<<endl<<endl;
			cout<<"Do you want to buy this? (yes or no) ";
			cin>>buy;
			if (buy == "yes"){
				if (player.money - temp.obj_cost() < 0){
					cout<<"Unsuccessful! You don't have enough money to buy such item!"<<endl;
				}
				else if(space == 0){
					cout<<"Unsuccessful! You don't have enough space in your inventory to keep this item!"<<endl;
				}
				else{
					player.money = player.money - temp.obj_cost();
					cout<<"Successful! You have purchased '"<<temp.get_obj_name()<<"' from the shop and it will be placed in your inventory!"<<endl;
					for (int i = 0; i < 5; i++){
						if (player.space[i].empty){
							player.space[i] = transfer_obj_item(temp);
							player.space[i].empty = false;
							i = 100;
						}
					}
				}
			}
			cout<<"Exit shop? (yes or no) ";
			cin>>response;
			exit_shop = return_answer(response, true);
		}
		cout<<"Exit market? (yes or no) ";
		cin>>response;
		exit_market = return_answer(response, true);
	}
}

// function to display player's inventory
void player_inventory_interface(){
	Player::Equipment remove_request;
	bool go_to_inventory = true;
	// give inventory access to player within while-loop
	while(go_to_inventory){
		int num;
		string input, alt_input;
		player.display_inventory();
		cout<<endl<<"Select a item from above (enter num): ";
		cin>>num;
		num--;
		if (player.space[num].empty){
			cout<<"You have selected a space in your inventory that's empty."<<endl;
			cout<<endl<<"Exit inventory? (yes or no) ";
			cin>>input;
			go_to_inventory = return_answer(input, false);
		}
		else{
			cout<<endl<<"Enter 'use' to use the selected item or equip the gear"<<endl;
			cout<<"Enter 'discard' to remove selected item from inventory"<<endl<<endl;
			cout<<"What do you want to do with this selected object: ";
			cin>>input;
			if (input == inventory_action[0]){
				if (player.space[num].item_usage == obj_usage[0]){
					if (player.Head.protection){
						cout<<"Your character is currently equipped with '"<<player.Head.name<<"'."<<endl;
						cout<<"Are you sure you want to switch? (yes or no) ";
						cin>>input;
						if (input == "yes"){
							remove_request = player.Head;
						}
					}
					else{
						cout<<"Equip item? (yes or no) ";
						cin>>alt_input;
					}
				}
				else if (player.space[num].item_usage == obj_usage[1]){
					if (player.Body.protection){
						cout<<"Your character is currently equipped with '"<<player.Body.name<<"'."<<endl;
						cout<<"Are you sure you want to switch? (yes or no) ";
						cin>>input;
						if (input == "yes"){
							remove_request = player.Body;
						}
					}
					else{
						cout<<"Equip item? (yes or no) ";
						cin>>alt_input;
					}
				}
				else if (player.space[num].item_usage == obj_usage[2]){
					if (player.Legs.protection){
						cout<<"Your character is currently equipped with '"<<player.Legs.name<<"'."<<endl;
						cout<<"Are you sure you want to switch? (yes or no) ";
						cin>>input;
						if (input == "yes"){
							remove_request = player.Legs;
						}
					}
					else{
						cout<<"Equip item? (yes or no) ";
						cin>>alt_input;
					}
				}
				else{
					cout<<"Use item? (yes or no) ";
					cin>>alt_input;
				}
				if (input == "yes"){
					for (int i = 0; i < 5; i++){
						if (player.space[i].empty){
							player.space[i] = unequip_eq(remove_request);
							player.space[i].empty = false;
							i = 10;
						}
					}
				}
				if (input == "yes" || alt_input == "yes"){
					use_item(player.space[num]);
					player.space[num] = discard_item(player.space[num]);
					cout<<"Successful! You equipped/used the item from the inventory!"<<endl;
				}
			}
			else if (input == inventory_action[1]){
				player.space[num] = discard_item(player.space[num]);
				cout<<"Successful! You have discarded the selected item from the inventory!"<<endl;
			}
			wait_to_refresh(2.3);
			player.display_inventory();
			cout<<endl<<"Exit inventory? (yes or no) ";
			cin>>input;
			go_to_inventory = return_answer(input, false);
		}
	}
	// update final stat after equipment changes
	for (int i = 0; i < 5; i++){
		player.update_final_stats(i);
	}
}

// function that introduces the game to the user
void rpg_game_intro(){
	string player_name, answer;
	cout<<"Welcome to a RPG game!"<<endl;
	cout<<"To enjoy this game, please enter fullscreen for the best experience.";
	wait_to_refresh(4.5);
	// input character name
	cout<<"Please enter a name for your character: ";
	getline(cin, player_name);
	player.name = player_name;
	cout<<player_name<<", welcome to the game! We are happy that you are going to play this game!"<<endl;
	cout<<"The only rule that you have to follow is for all inputs from now on to be lowercase."<<endl;
	wait_to_refresh(4);
	// setup player
	set_up_player();
	cout<<"Below shows your character's stats:"<<endl;
	// display player stat
	player.overall_stats();
	wait_to_refresh(8); // time: 8
	cout<<"Below shows the available attacks your character can do: "<<endl;
	player.display_attacks();
	cout<<endl<<"To use an attack, you have to type the word of the attack."<<endl;
	cout<<"For example: If you want to use the attack 'hit', you will need to type the letters h, i, and t and press enter."<<endl;
	wait_to_refresh(7.5); // time: 7.5
	cout<<"Let's buy something from the market!!!"<<endl;
	cout<<"However, since you are new, you don't have any money on you."<<endl;
	cout<<"Thus, we shall grant you 200 gold for free. No need to pay it back."<<endl;
	player.money = 200;
	wait_to_refresh(8); // time: 8
	cout<<player.name<<" has obtained "<<player.money<<" gold!!!"<<endl;
	wait_to_refresh(4);
	cout<<"Now that you have the money, you shall buy something from the market."<<endl;
	cout<<"However, there are many parts to a market."<<endl;
	// display market to player
	display_market();
	wait_to_refresh(.5);
	cout<<"Once you buy an item from the market, it automatically goes into your inventory if it has space."<<endl;
	cout<<"If you don't have space, you would need to discard one item from your inventory in order to keep your recently bought item."<<endl;
	cout<<"Let's go to your inventory to see the item(s) you bought from the market!"<<endl<<endl;
	// display inventory to player
	player_inventory_interface();
	player.hp = player.get_final_thp();
	wait_to_refresh(.5);
	cout<<"These are the equipments you will be wearing for battle:"<<endl;
	player.show_player_equipment();
	cout<<endl<<"Any further changes to the character's equipment can be done later on."<<endl;
	wait_to_refresh(5);
	cout<<"Let's prepare you for battle!!!"<<endl;
	wait_to_refresh(2.5);
	// put user into battle against 5 enemies
	battle_sys(5);
}

// function that puts player into a dungeon situation
void enter_dungeon(){
	srand(time(0));
	wait_to_refresh(3);
	cout<<"After defeating your enemies, "<<player.name<<" became exhausted and collapsed."<<endl;
	wait_to_refresh(3.4);
	cout<<player.name<<" wake up a day later to found itself inside a dungeon."<<endl;
	cout<<"The sounds of enemies were everywhere."<<endl;
	wait_to_refresh(5);
	cout<<"Realizing the situation that he/she is currently in, "<<player.name<<" quickly woke up."<<endl;
	// setup and generate rooms
	generate_3x3();
	int room = rand() % 4, enemy_group = 4;
	bool player_is_here = true;
	for (int id = 0; id < 9; id++){
		set_room(id);
	}
	set_starting_room(room);
	randomize_entity(enemy_group);
	randomize_gold();
	for (int id = 0; id < 9; id++){
		for (int check = 0; check < map_room[id].area_size; check++){
			if (map_room[id].build_space[check] == 'P'){
				player_room = id;
			}
		}
	}
	wait_to_refresh(2.6);
	// show current room to player to show where he/she is at
	display_room(player_room);
	cout<<"This is the current room your character is in."<<endl;
	wait_to_refresh(3); // 6
	cout<<"Below shows the map key."<<endl<<endl;
	map_room[player_room].display_map_key();
	wait_to_refresh(3); // 5
	cout<<"Some important additional infomation:"<<endl;
	cout<<"\t-To access the market, type 'market' when asked for an input. (doesn't apply while in battle)"<<endl;
	cout<<"\t-To access character's inventory, type 'inventory' when asked for an input. (doesn't apply while in battle)"<<endl;
	wait_to_refresh(6); // 8
	cout<<"Your goal is to defeat all the enemy groups in the dungeon."<<endl;
	cout<<"Let's stop the waiting and let your character's journey begin!!!"<<endl;
	wait_to_refresh(2.5); // 4.2
	// while-loop runs until player dies or he completes the goal of defeating all the enemies in the dungeon
	while (player.hp > 0 && enemy_group > 0){
		string input;
		int remaining = 0;
		cout<<"There are "<<enemy_group<<" group(s) left in the dungeon."<<endl<<endl;
		// show room to player
		display_room(player_room);
		// map key
		map_room[player_room].display_map_key();
		for (int i = 0; i < map_room[player_room].area_size; i++){
			if (map_room[player_room].build_space[i] == map_room[player_room].entity.player){
				place = i;
			}
		}
		// determine possible directions for player to go
		directions_possible[0] = check_open(player_room, place, -5);
		directions_possible[2] = check_open(player_room, place, 1);
		directions_possible[1] = check_open(player_room, place, 5);
		directions_possible[3] = check_open(player_room, place, -1);
		for (int i = 0; i < 4; i++){
			if (directions_possible[i]){
				cout<<"Your character can go ";
				switch(i){
					case 0: cout<<"North"<<endl; break;
					case 1: cout<<"South"<<endl; break;
					case 2: cout<<"East"<<endl; break;
					case 3: cout<<"West"<<endl; break;
				}
			}
		}
		cout<<"Enter a direction that you want your character to move: ";
		cin>>input;
		while (check_valid_direction(input) == false && check_valid_input(input) == 0){
			cout<<"Unsuccessful! You have entered an incorrect direction! Please try again!"<<endl;
			cout<<"In what direction do you want to move the character: ";
			cin>>input;
		}
		// when player encounters an enemy
		if (battle){
			wait_to_refresh(0);
			// battle a roandomized amount of enemies
			battle_sys(rand() % 3 + 1);
			wait_to_refresh(3);
			battle = false;
		}
		// when player encounters gold
		if (gold){
			int found = rand() % 176 + 25;
			cout<<endl<<player.name<<" obtained "<<found<<" gold!"<<endl<<endl;
			player.money = player.money + found;
			wait_to_refresh(3);
			gold = false;
		}
		// determine the amount of enemy groups remaining
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				if (map_room[i].build_space[placement_area[j]] == map_room[i].entity.enemy){
					remaining++;
				}
			}
		}
		enemy_group = remaining;
		// when the input is 'market'
		if (check_valid_input(input) == 1){
			wait_to_refresh(0);
			display_market();
		}
		// when the input is 'inventory'
		if (check_valid_input(input) == 2){
			wait_to_refresh(0);
			player_inventory_interface();
		}
		// reset the bool array
		reset_possible_directions();
		int count = 0;
		for (int i = 0; i < 9; i++){
		if (map_room[player_room].build_space[placement_area[i]] != map_room[player_room].entity.player){
				count++;
			}
		}
		// if player exits, transfer room
		if (count == 9){
			transfer_room();
		}
		wait_to_refresh(0);
	}
	// player dies
	if (player.hp = 0){
		cout<<player.name<<" have fallen. Better luck next time!"<<endl;
	}
	// if player dies is a false statement
	else{
		cout<<"You have defeated all of the enemies in the dungeon!!!"<<endl;
		cout<<"Thanks for playing!!!"<<endl;
	}
}
