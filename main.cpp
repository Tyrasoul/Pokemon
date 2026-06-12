#include <iostream>

const int PokeBallCount = 10;
const int CategoryCount = 10;

float numTOpercentage(int , int);
float catch_calculator(float, int, int);
float modifiers(float, float, float);
float weather_modifier(int, int);
float pokeball_modifiers(int, int, int);

using std::cout;
using std::cin;
using std::endl;

int main() {

    float PokemonHP;             // Percentage
    int BallType;                // 1-9
    int PokemonCategory;         // 1-9
    int WeatherType;                 // (-1,0-9)
    int PokemonType;                    // int
    int Time;

    cout << "Enter Pokemon HP in percentage : ";
    cin >> PokemonHP;
    cout << endl << "Enter BallType : ";
    cin >> BallType;
    cout << endl << "Enter Pokemon's catch weight category : ";
    cin >> PokemonCategory;
    cout << endl << "Enter Weather Condition (-1 for no weather) : ";
    cin >> WeatherType;
    cout << endl << "Enter Pokemon's type : ";
    cin >> PokemonCategory;
    cout << endl << "Enter Time : ";
    cin >> Time;

    float WeatherModifier = weather_modifier(WeatherType, PokemonType);
    float PokeballModifier = pokeball_modifiers(BallType, Time, PokemonType);

    float BaseChance = catch_calculator(PokemonHP, BallType, PokemonCategory);
    float Chance = modifiers(WeatherModifier, PokeballModifier, BaseChance);

    if (PokeballModifier == -1){
        Chance = 1;
    };

    cout << endl << "You have a " << 100.0f * Chance << " % chance of catching the pokemon";
    

return 0; }

float catch_calculator(float PokemonHP , int BallType, int PokemonCategory) {

    float chance = (100.0f - PokemonHP)* numTOpercentage(PokemonCategory, CategoryCount) / 10000;
    return chance;
}

float modifiers(float WeatherModifier, float PokeballModifier, float BaseChance){

    return BaseChance*WeatherModifier*PokeballModifier;
}

float pokeball_modifiers(int balltype, int time, int PokemonType){
    switch(balltype){
        case 0:
            return 1;
        case 1:
            return 1.5;
        case 2:
            return 2;
        case 9:
            return -1;
    };

    if (balltype == 4 and time == 1) {     //night and dusk ball
        return 3;
    };

    if (balltype == 4 and (PokemonType == 3 or PokemonType == 4)){    //net ball and water/bug type
        return 3;
    };
    return 1;
}

float weather_modifier(int WeatherType, int PokemonType) {
    // i.e. Evasion
    // From this logic Weather and pokemon type could be matched for example as (0,sandstorm,ground), (1, rain, water)
    // Will update to taking a struct or an arr if the need be  - will have to change the input details in main/ fxn call
    
    if (WeatherType == -1) {
        return 1;
    };
    if (WeatherType == PokemonType) {
        return 1.5;
    };
    return 1;
}

float numTOpercentage(int number, int max) {
    float p = number*100.0f / max;
    return p;
}