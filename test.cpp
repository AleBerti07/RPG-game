//
// Created by Alessandro Berti on 17/06/2024.
//
#include <random>
#include <iostream>

int global;

class player{
    public:
        std::string name;
        int health;
        int strength;
        int dexterity;
        int magic;
};

int dice(void){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6);
    global = dist6(rng);

}
int main(){
    player player1;
    player1.name = "Lorenzo";
    player1.health = 100;
    dice();
    player1.strength = global; //create a local global to store random attributes
    dice();
    player1.magic = global;
    dice();
    player1.dexterity = global;
    std::cout<<player1.name<<std::endl;
    std::cout<<"Health:"<<" ";
    std::cout<<player1.health<<std::endl;
    std::cout<<"Strength:"<<" ";
    std::cout << player1.strength << std::endl;
    std::cout<<"Magic:"<<" ";
    std::cout << player1.magic << std::endl;
    std::cout<<"Dexterity:"<<" ";
    std::cout << player1.dexterity << std::endl;

}