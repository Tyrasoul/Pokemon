#include <iostream>

const int CategoryCount = 10;

enum PokemonTypes  {GROUND, WATER, FIRE, ICE, BUG, TOTALTYPES};
enum Weathers {SANDSTORM, RAIN, HARSHSUN, SNOW, CLEAR, TOTALWEATHERS};
enum Pokeballs {NORMAL, GREAT, ULTRA, DUSK, NET, MASTER, TOTALBALLS} BallType;
enum TimeofDay {MORNING, NOON, AFTERNOON, EVENING, NIGHT, TOTALTIME};


struct Pokemon {
    PokemonTypes Type;
    float HP;
    int Category;
} pokemon;

struct environment {
    Weathers Weather;
    TimeofDay Time;
} env;

using std::cout;
using std::cin;
using std::endl;

float numTOpercentage(int , int);
float catch_calculator(float, int);
float modifiers(float, float, float);
float weather_modifier(Weathers, PokemonTypes);
float pokeball_modifiers(Pokeballs, TimeofDay, PokemonTypes);
void handle_input();

int main() {

    handle_input();

    float WeatherModifier = weather_modifier(env.Weather, pokemon.Type);
    float PokeballModifier = pokeball_modifiers(BallType, env.Time, pokemon.Type);

    float BaseChance = catch_calculator(pokemon.HP, pokemon.Category);
    float Chance = modifiers(WeatherModifier, PokeballModifier, BaseChance);

    if (BallType == MASTER){
        Chance = 1.0f;
    };

    if (Chance > 1.0f) {
        Chance = 1.0f;
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

float pokeball_modifiers(Pokeballs balltype, TimeofDay time, PokemonTypes PokemonType){
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

float weather_modifier(Weathers WeatherType, PokemonTypes PokemonType) {
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
    cin >> pokemon.HP;
    while (pokemon.HP > 100 or pokemon.HP < 0) {
        cout << "Please enter a valid value of Pokemon HP in percentage : ";
        cin >> pokemon.HP;
    };
    
    cout << endl << "Enter Pokemon's catch-weight category : ";
    cin >> pokemon.Category;
    while (pokemon.Category > 9 or pokemon.Category < 1) {
        cout << endl << "Please enter a valid value of Pokemon's catch-weight category : ";
        cin >> pokemon.Category;
    };

    cout << endl << "Enter BallType : ";
    cin >> input;
    while (input >= TOTALBALLS or input < 0) {
        cout << "Please enter a valid value of BallType : ";
        cin >> input;
    };
    BallType = static_cast<Pokeballs>(input);

    cout << endl << "Enter Weather Condition : ";
    cin >> input;
    while (input >= TOTALWEATHERS or input < 0) {
        cout << "Please enter a valid value of Weather : ";
        cin >> input;
    };
    env.Weather = static_cast<Weathers>(input);

    cout << endl << "Enter Pokemon's type : ";
    cin >> input;
    while (input >= TOTALTYPES or input < 0) {
        cout << "Please enter a valid value of Pokemon HP in percentage : ";
        cin >> input;
    };
    pokemon.Type = static_cast<PokemonTypes>(input);

    cout << endl << "Enter Time : ";
    cin >> input;
    while (input >= TOTALTIME or input < 0) {
        cout << "Please enter a valid value of Pokemon HP in percentage : ";
        cin >> input;
    };
    env.Time = static_cast<TimeofDay>(input);
}