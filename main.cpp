#include <iostream>

const int BallCount = 10;
const int CatagoryCount = 10;

float numTOpercentage(int , int);
float catch_calculator(float, int, int);

using std::cout;
using std::cin;
using std::endl;

int main() {

    float PokemonHP;
    int BallType;
    int PokemonCatagory;

    cout << "Enter Pokemon HP in percentage : ";
    cin >> PokemonHP;
    cout << endl << "Enter BallType : ";
    cin >> BallType;
    cout << endl << "Enter Pokemon's catagory : ";
    cin >> PokemonCatagory;

    float chance = catch_calculator(PokemonHP, BallType, PokemonCatagory);

    cout << endl << "You have a " << chance << " chance of catching the pokemon";
    

return 0; };

float catch_calculator(float PokemonHP , int BallType, int PokemonCatagory) {
    // PokemonHP is in percentage, BallType is 0-9, PokemonCatagory is 0-9
    float chance = PokemonHP * numTOpercentage(BallType, BallCount) * numTOpercentage(PokemonCatagory, CatagoryCount) / 1000000;
    return chance;
};

float numTOpercentage(int number, int max) {
    float p = number*100.0f / max;
    return p;
};