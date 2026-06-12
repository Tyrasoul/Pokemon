#include <iostream>

const int CategoryCount = 10;

float numTOpercentage(int , int);
float catch_calculator(float, int);
float modifiers(float, float, float);
float weather_modifier(int, int);
float pokeball_modifiers(int, int, int);
void handle_input();


enum PokemonTypes  {GROUND, WATER, FIRE, ICE, BUG} PokemonType;
enum Weathers {SANDSTORM, RAIN, HARSHSUN, SNOW, CLEAR} WeatherType;
enum Pokeballs {NORMAL, GREAT, ULTRA, DUSK, NET, MASTER} BallType;
enum TimeofDay {MORNING, NOON, AFTERNOON, EVENING, NIGHT} Time;

float PokemonHP;
int PokemonCategory;

using std::cout;
using std::cin;
using std::endl;

int main() {

    void handle_input();

    float WeatherModifier = weather_modifier(WeatherType, PokemonType);
    float PokeballModifier = pokeball_modifiers(BallType, Time, PokemonType);

    float BaseChance = catch_calculator(PokemonHP, PokemonCategory);
    float Chance = modifiers(WeatherModifier, PokeballModifier, BaseChance);

    if (BallType == MASTER){
        Chance = 1;
    };

    cout << endl << "You have a " << 100.0f * Chance << " % chance of catching the pokemon";
    

return 0; }

float catch_calculator(float PokemonHP , int PokemonCategory) {

    float chance = (100.0f - PokemonHP)* numTOpercentage(PokemonCategory, CategoryCount) / 10000.0f;
    return chance;
}

float modifiers(float WeatherModifier, float PokeballModifier, float BaseChance){

    return BaseChance*WeatherModifier*PokeballModifier;
}

float pokeball_modifiers(int balltype, int time, int PokemonType){
    switch(balltype){
        case NORMAL:
            return 1.0f;
        case GREAT:
            return 1.5f;
        case ULTRA:
            return 2.0f;
    };

    if (balltype == DUSK and time == NIGHT) {     //night and dusk ball
        return 3.0f;
    };

    if (balltype == NET and (PokemonType == WATER or PokemonType == BUG)){    //net ball and water/bug type
        return 3.0f;
    };
    return 1.0f;
}

float weather_modifier(int WeatherType, int PokemonType) {
    // i.e. Evasion
    // From this logic Weather and pokemon type could be matched for example as (0,sandstorm,ground), (1, rain, water)
    
    if (WeatherType == CLEAR) {
        return 1.0f;
    };
    if (WeatherType == PokemonType) {
        return 1.5f;
    };
    return 1.0f;
}

float numTOpercentage(int number, int max) {
    float p = number*100.0f / max;
    return p;
}

void handle_input() {
    int input;

    cout << "Enter Pokemon HP in percentage : ";
    cin >> PokemonHP;
    cout << endl << "Enter Pokemon's catch weight category : ";
    cin >> PokemonCategory;

    cout << endl << "Enter BallType : ";
    cin >> input;
    BallType = static_cast<Pokeballs>(input);

    cout << endl << "Enter Weather Condition (-1 for no weather) : ";
    cin >> input;
    WeatherType = static_cast<Weathers>(input);

    cout << endl << "Enter Pokemon's type : ";
    cin >> input;
    PokemonType = static_cast<PokemonTypes>(input);

    cout << endl << "Enter Time : ";
    cin >> input;
    Time = static_cast<TimeofDay>(input);
}