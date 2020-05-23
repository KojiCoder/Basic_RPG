// main header

#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// usage of objects
string obj_usage[3] = {"Head", "Body", "Legs"};
// inventory possible actions
string inventory_action[3] = {"use", "discard"};
// usage for map
string map_directions[4] = {"north", "south", "east", "west"};

// class for Attack
class Attack{
private:
	int damage;
	int req_level;
	int attack_id;
	string name, attack_type;
	string req_class, req_weapon1, req_weapon2, req_weapon3;
public:
	void set_attack_id(int num) {attack_id = num;}
	void name_attack(string phrase) {name = phrase;}
	void set_attack_type(string type) {attack_type = type;}
	void set_req_lvl(int num) {req_level = num;}
	void set_req_class(string game_class) {req_class = game_class;}
	void set_req_weapon1(string object) {req_weapon1 = object;}
	void set_req_weapon2(string object) {req_weapon2 = object;}
	void set_req_weapon3(string object) {req_weapon3 = object;}
	void set_attack_dmg(int num) {damage = num;}
	string tell_attack_name() {return name;}
	string tell_attack_type() {return attack_type;}
	string weapon1() {return req_weapon1;}
	string weapon2() {return req_weapon2;}
	string weapon3() {return req_weapon3;}
	int attack_dmg() {return damage;}
	void display_info(){
		cout<<"ATTACK INFORMATION"<<endl;
		cout<<"Attack Name: \t"<<name<<endl;
		cout<<"Req. Class: \t"<<req_class<<endl;
		cout<<"Req. Level: \t"<<req_level<<endl;
		if (req_weapon2 == ""){
			cout<<"Req. Weapon: \t"<<req_weapon1<<endl;
		}
		else if (req_weapon3 == ""){
			cout<<"Req. Weapon: \t"<<req_weapon1<<", "<<req_weapon2<<endl;
		}
		else{
			cout<<"Req. Weapon: \t"<<req_weapon1<<", "<<req_weapon2<<", "<<req_weapon3<<endl;
		}
		cout<<"Attack Type: \t"<<attack_type<<" "<<"Target"<<endl;
		cout<<"Damage: \t"<<damage<<endl;
	}
};

// class for Install_Attack
class Install_Attack{
private:
	int damage;
	int install_id;
	string name;
public:
	void set_install_dmg(int num) {damage = num;}
	void set_install_id(int num) {install_id = num;}
	void name_install_att(string phrase) {name = phrase;}
	
	string give_name() {return name;}
	int att_dmg() {return damage;}
};

// class for Object
class Object{
private:
	int o_thp, o_hp, o_tma, o_ma;
	int o_str, o_def, o_spd;
	int req_level;
	int obj_id;
	int cost;
	string name, usage, req_class;
public:
	void set_obj_id(int num) {obj_id = num;}
	void set_obj_lvl(int num) {req_level = num;}
	void set_cost(int num) {cost = num;}
	void give_name(string phrase) {name = phrase;}
	void only_for(string phrase) {usage = phrase;}
	void set_class(string role){req_class = role;}
	void set_object_stats(int thp, int hp, int tma, int ma, int str, int def, int spd){
		o_thp = thp;
		o_hp = hp;
		o_tma = tma;
		o_ma = ma;
		o_str = str;
		o_def = def;
		o_spd = spd;
	}
	int transfer_basic_stat(int num){
		switch(num){
			case 1: return o_thp; break;
			case 2: return o_hp; break;
			case 3: return o_tma; break;
			case 4: return o_ma; break;
		}
	}
	int transfer_action_stat(int num){
		switch(num){
			case 1: return o_str; break;
			case 2: return o_def; break;
			case 3: return o_spd; break;
		}
	}
	int obj_cost() {return cost;}
	string get_obj_name() {return name;}
	string get_obj_use() {return usage;}
	string get_obj_class() {return req_class;}
	void display_info(){
		cout<<"ITEM'S INFORMATION"<<endl;
		cout<<"Item Name: \t"<<name<<endl;
		cout<<"Req. Class: \t"<<req_class<<endl;
		cout<<"Req. Level: \t"<<req_level<<endl;
		cout<<"Usage: \t\t"<<usage<<endl<<endl;
		cout<<"EFFECTS"<<endl;
		cout<<"Total Health: \t+"<<o_thp<<endl;
		cout<<"Health: \t+"<<o_hp<<endl;
		cout<<"Total mana: \t+"<<o_tma<<endl;
		cout<<"Mana: \t\t+"<<o_ma<<endl;
		cout<<"Strength: \t+"<<o_str<<endl;
		cout<<"Defense: \t+"<<o_def<<endl;
		cout<<"Speed: \t\t+"<<o_spd<<endl;
	}
};

// class for Player
class Player{
private:
	// stats with the addition of armor stats
	int final_thp, final_tma; // basic stats
	int final_def, final_str, final_spd; // action stats
public:
	// stats withour the additon of armor stats
	int total_hp, hp, total_mana, mana; // basic stats
	int def, str, spd, skill_lvl; // action stats
	int exp, level; // growth stats
	int money; // money
	string name, game_class;
	bool show_tutorial = true;
	
	// class created for equipments
	class Equipment{
	public:
		int amp_thp, amp_tma; // buff basic stats
		int amp_str, amp_def, amp_spd; // buff action stats
		string name, placement, req_class; // other stats
		bool protection = false; // is it occupied or empty
	};
	
public:
	// available areas for player equipment
	Equipment Head, Body, Legs, Right_Hand, Left_Hand;
	
	// keywords
	void set_eq_place(){
		Head.placement = "Head";
		Body.placement = "Body";
		Legs.placement = "Legs";
	}
	
	// class created for attacks
	class Action{
	public:
		// lines 41-43 are for attacks
		int damage;
		string name, type;
		string req_weapon1, req_weapon2, req_weapon3;
	};
	
public:
	// store possible player attacks
	Action basic_attacks[3];
	
	// clas created for inventory
	class Inventory{
	public:
		// item info
		int item_thp, item_hp, item_tma, item_ma;
		int item_str, item_def, item_spd;
		string item_name, item_usage, item_class;
		bool empty = true; // occupied for not
	};

public:
	// store information about items in player inventory
	Inventory space[5];
	
	// display inventory
	void display_inventory(){
		cout<<name<<"'s Inventory"<<endl<<endl;
		for (int i = 0; i < 5; i++){
			if (space[i].empty){
				cout<<i+1<<")\t"<<endl;
			}
			else{
				cout<<i+1<<")\t["<<space[i].item_name<<"]"<<endl;
			}
		}
	}
	// setter functions
	void setCLS(string role) {game_class = role;}
	void player_basic_stats(int n_thp, int n_hp, int n_tma, int n_ma){
		total_hp = n_thp;
		hp = n_hp;
		total_mana = n_tma;
		mana = n_ma;
	}
	// getter functions
	int get_final_thp() {return final_thp;}
	int get_final_tma() {return final_tma;}
	int get_final_str() {return final_str;}
	int get_final_def() {return final_def;}
	int get_final_spd() {return final_spd;}
	// display possible player choice of attack
	void display_attacks(){
		cout<<endl<<"BASIC ATTACK:"<<endl<<endl;
		for (int i = 0; i < 3; i++){
			cout<<i+1<<")\t"<<basic_attacks[i].name<<endl;
		}
	}
	// display the equipments currently on the player
	void show_player_equipment(){
		cout<<"Head: ["<<Head.name<<"]"<<endl;
		cout<<"Body: ["<<Body.name<<"]"<<endl;
		cout<<"Legs: ["<<Legs.name<<"]"<<endl;
	}
	// display overall stats
	void overall_stats(){
		cout<<endl<<"BASIC STATS"<<endl;
		cout<<"Character Name: "<<name<<endl;
		cout<<"Health:\t\t"<<hp<<" / "<<total_hp<<endl;
		cout<<"Mana:\t\t"<<mana<<" / "<<total_mana<<endl;
		cout<<"Defense:\t"<<def<<endl;
		cout<<"Strength:\t"<<str<<endl;
		cout<<"Speed:\t\t"<<spd<<endl;
		cout<<"Skill Level:\t"<<skill_lvl<<endl;
		cout<<endl<<"OTHER STATS"<<endl;
		cout<<"Level:\t\t"<<level<<endl;
		cout<<"Experience:\t"<<exp<<endl;
		cout<<"Money:\t\t"<<money<<endl;
		cout<<"Class:\t\t"<<game_class<<endl;
		cout<<endl<<"EQUIPMENT BUFFS"<<endl;
		cout<<"HEAD: ["<<Head.name<<"]"<<endl;
		cout<<"\t+"<<Head.amp_thp<<" in total health"<<endl;
		cout<<"\t+"<<Head.amp_tma<<" in total mana"<<endl;
		cout<<"\t+"<<Head.amp_str<<" in strength"<<endl;
		cout<<"\t+"<<Head.amp_def<<" in defense"<<endl;
		cout<<"\t+"<<Head.amp_spd<<" in speed"<<endl<<endl;
		cout<<"BODY: ["<<Body.name<<"]"<<endl;
		cout<<"\t+"<<Body.amp_thp<<" in total health"<<endl;
		cout<<"\t+"<<Body.amp_tma<<" in total mana"<<endl;
		cout<<"\t+"<<Body.amp_str<<" in strength"<<endl;
		cout<<"\t+"<<Body.amp_def<<" in defense"<<endl;
		cout<<"\t+"<<Body.amp_spd<<" in speed"<<endl<<endl;
		cout<<"LEGS: ["<<Legs.name<<"]"<<endl;
		cout<<"\t+"<<Legs.amp_thp<<" in total health"<<endl;
		cout<<"\t+"<<Legs.amp_tma<<" in total mana"<<endl;
		cout<<"\t+"<<Legs.amp_str<<" in strength"<<endl;
		cout<<"\t+"<<Legs.amp_def<<" in defense"<<endl;
		cout<<"\t+"<<Legs.amp_spd<<" in speed"<<endl<<endl;
	}
	// include equipment stats with player stats
	void update_final_stats(int num){
		switch(num){
			case 0: final_thp = total_hp + Head.amp_thp + Body.amp_thp + Legs.amp_thp; break;
			case 1: final_tma = total_mana + Head.amp_tma + Body.amp_tma + Legs.amp_tma; break;
			case 2: final_str = str + Head.amp_str + Body.amp_str + Legs.amp_str; break;
			case 3: final_def = def + Head.amp_def + Body.amp_def + Legs.amp_def; break;
			case 4: final_spd = spd + Head.amp_spd + Body.amp_spd + Legs.amp_spd; break;
		}
	}
};

// declare player variable
Player player;

// equip gear directly to player from class Object
Player::Equipment equip_player(Object temp){
	Player::Equipment gear;
	gear.name = temp.get_obj_name();
	gear.placement = temp.get_obj_use();
	gear.req_class = temp.get_obj_class();
	gear.amp_thp = temp.transfer_basic_stat(1);
	gear.amp_tma = temp.transfer_basic_stat(3);
	gear.amp_str = temp.transfer_action_stat(1);
	gear.amp_def = temp.transfer_action_stat(2);
	gear.amp_spd = temp.transfer_action_stat(3);
	gear.protection = true;
	return gear;
}

// give player a certain attack
Player::Action gained_attack(Attack temp){
	Player::Action diff_temp;
	diff_temp.name = temp.tell_attack_name();
	diff_temp.type = temp.tell_attack_type();
	diff_temp.damage = temp.attack_dmg();
	diff_temp.req_weapon1 = temp.weapon1();
	diff_temp.req_weapon2 = temp.weapon2();
	diff_temp.req_weapon3 = temp.weapon3();
	return diff_temp;
}

// transfer object into inventory
Player::Inventory transfer_obj_item(Object temp){
	Player::Inventory item;
	item.item_name = temp.get_obj_name();
	item.item_thp = temp.transfer_basic_stat(1);
	item.item_hp = temp.transfer_basic_stat(2);
	item.item_tma = temp.transfer_basic_stat(3);
	item.item_ma = temp.transfer_basic_stat(4);
	item.item_str = temp.transfer_action_stat(1);
	item.item_def = temp.transfer_action_stat(2);
	item.item_spd = temp.transfer_action_stat(3);
	item.item_usage = temp.get_obj_use();
	item.item_class = temp.get_obj_class();
	return item;
}

// transfer inventory to objects for use
Object transfer_item_to_use(Player::Inventory item){
	Object temp;
	temp.give_name(item.item_name);
	temp.set_object_stats(item.item_thp, item.item_hp, item.item_tma, item.item_ma, item.item_str, item.item_def, item.item_spd);
	temp.only_for(item.item_usage);
	temp.set_class(item.item_class);
	return temp;
}

// transfer equipment to inventory
Player::Inventory unequip_eq(Player::Equipment temp){
	Player::Inventory item;
	item.item_name = temp.name;
	item.item_thp = temp.amp_thp;
	item.item_hp = 0;
	item.item_tma = temp.amp_tma;
	item.item_ma = 0;
	item.item_str = temp.amp_str;
	item.item_def = temp.amp_def;
	item.item_spd = temp.amp_spd;
	item.item_usage = temp.placement;
	item.item_class = temp.req_class;
	return item;
}

// remove inventory
Player::Inventory discard_item(Player::Inventory item){
	item.item_name = "";
	item.item_thp = 0;
	item.item_hp = 0;
	item.item_tma = 0;
	item.item_ma = 0;
	item.item_str = 0;
	item.item_def = 0;
	item.item_spd = 0;
	item.item_usage = "";
	item.item_class = "";
	item.empty = true;
	return item;
}

// class for Enemy
class Enemy{
public:
	int total_hp, hp, total_mana, mana;
	int def, str, spd;
	int level, id;
	bool active;
	string name;
	
	class Action{
	public:
		int damage;
		string name, type;
	};
	
public:
	Action basic_attacks[2];
	
	void enemy_basic_stats(int n_thp, int n_hp, int n_tma, int n_ma){
		total_hp = n_thp;
		hp = n_hp;
		total_mana = n_tma;
		mana = n_ma;
	}
	void enemy_action_stats(int n_str, int n_def, int n_spd){
		str = n_str;
		def = n_def;
		spd = n_spd;
	}
	void general_stats(){
		cout<<"ENEMY'S STAT"<<endl;
		cout<<"Health: "<<hp<<" / "<<total_hp<<endl;
		cout<<"Mana: "<<mana<<" / "<<total_mana<<endl;
		cout<<"Defense: "<<def<<endl;
		cout<<"Strength: "<<str<<endl;
		cout<<"Speed: "<<spd<<endl;
		cout<<"Level: "<<level<<endl;
	}
};

// declare enemy variables
Enemy Normal_Wolf[2], Normal_Bear[2];

// function that will set a type of atttack on a certain enemy
Enemy::Action set_enemy_attack(Install_Attack temp){
	Enemy::Action diff_temp;
	diff_temp.name = temp.give_name();
	diff_temp.damage = temp.att_dmg();
	return diff_temp;
}

// arrays used for maps
bool directions_possible[4] = {false, false, false, false};
int placement_area[9] = {6,7,8,11,12,13,16,17,18};

// class for Map
class Map{
private:
	char verwall = '|';
	char hozwall = '=';
public:
	int area_size = 25;
	bool open_n = false;
	bool open_e = false;
	bool open_s = false;
	bool open_w = false;
	char build_space[100];
	
	// class for Icon
	class Icon{
	public:
		char player = 'P';
		char enemy = 'E';
		char gold = 'G';
	};

public:
	Icon entity, objects;
	
	char room_layout(int num){
		if (num == 0 || num == 4 || num == 20 || num == 24){
			return 'X';
		}
		else if (num < 5 || num > 20){
			return hozwall;
		}
		else if (num != 4 && num != 20 && (num % 5 == 4 || num % 5 == 0)){
			return verwall;
		}
		else{
			return ' ';
		}
	}
	void display_map_key(){
		cout<<"Map Key----------------------"<<endl<<endl;
		cout<<"P: Character"<<endl;
		cout<<"E: Enemy"<<endl;
		cout<<"G: Gold"<<endl<<endl;
	}
};

// declare map array
Map map_room[10];

// function that will generate corner room
Map generate_corner_room(int num){
	Map temp;
	switch(num){
		case 1:
			temp.open_e = true;
			temp.open_s = true; break;
		case 2:
			temp.open_w = true;
			temp.open_s = true; break;
		case 3:
			temp.open_n = true;
			temp.open_e = true; break;
		case 4:
			temp.open_n = true;
			temp.open_w = true; break;
	}
	return temp;
}

// function that will generate threeway room
Map generate_threeway_room(int num, int alt){
	Map temp;
	switch(num){
		case 1:
			temp.open_n = true;
			temp.open_s = true; break;
		case 2:
			temp.open_w = true;
			temp.open_e = true; break;
	}
	if (temp.open_e && temp.open_w){
		switch(alt){
			case 1: temp.open_s = true; break;
			case 2: temp.open_n = true; break;
		}
	}
	else{
		switch(alt){
			case 1: temp.open_e = true; break;
			case 2: temp.open_w = true; break;
		}
	}
	return temp;
}

// function that will generate fourway room
Map generate_fourway_room(){
	Map temp;
	temp.open_n = true;
	temp.open_s = true;
	temp.open_w = true;
	temp.open_e = true;
	return temp;
}
