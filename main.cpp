#include <iostream>

const int BallCount = 10;
const int CategoryCount = 10;

float numTOpercentage(int , int);
float catch_calculator(float, int, int);
float modifiers(float, float );
float weather_modifier(int, int);

using std::cout;
using std::cin;
using std::endl;

int main() {

    float PokemonHP;             // Percentage
    int BallType;                // 0-9
    int PokemonCategory;         // 0-9
    int Weather;                 // (-1,0-9)
    int Type;                    // int

    cout << "Enter Pokemon HP in percentage : ";
    cin >> PokemonHP;
    cout << endl << "Enter BallType : ";
    cin >> BallType;
    cout << endl << "Enter Pokemon's catch weight category : ";
    cin >> PokemonCategory;
    cout << endl << "Enter Weather Condition (-1 for no weather) : ";
    cin >> Weather;
    cout << endl << "Enter Pokemon's type : ";
    cin >> Type;

    float WeatherModifier = weather_modifier(Weather, Type);

    float BaseChance = catch_calculator(PokemonHP, BallType, PokemonCategory);
    float Chance = modifiers(WeatherModifier, BaseChance);

    cout << endl << "You have a " << 100.0f * Chance << " % chance of catching the pokemon";
    

return 0; };

float catch_calculator(float PokemonHP , int BallType, int PokemonCategory) {

    float chance = (100.0f - PokemonHP) * numTOpercentage(BallType, BallCount) * numTOpercentage(PokemonCategory, CategoryCount) / 1000000;
    return chance;
};

float modifiers(float WeatherModifier, float BaseChance){

    return BaseChance*WeatherModifier;
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
};

float numTOpercentage(int number, int max) {
    float p = number*100.0f / max;
    return p;
};