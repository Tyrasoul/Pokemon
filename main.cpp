#include <ios>
#include <iostream>
#include <limits>

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

    switch (WeatherType) {
        case CLEAR:
            return 1.0f;
        case SANDSTORM:
            if (PokemonType == GROUND){
                return 1.5f;
            };
        case RAIN:
            if (PokemonType == WATER){
                return 1.5f;
            };
        case HARSHSUN:
            if (PokemonType == FIRE){
                return 1.5f;
            };
        case SNOW:
            if (PokemonType == ICE){
                return 1.5f;
            };
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
    while (!(cin>>pokemon.HP) || pokemon.HP > 100 or pokemon.HP < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a valid value of Pokemon HP in percentage : ";
    };
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << endl << "Enter Pokemon's catch-weight category : ";
    while (!(cin>>pokemon.Category) || pokemon.Category > 9 or pokemon.Category < 1) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << endl << "Please enter a valid value of Pokemon's catch-weight category : ";
    };
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << endl << "Enter BallType : ";
    while (!(cin>>input) || input >= TOTALBALLS or input < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a valid value of BallType : ";
    };
    BallType = static_cast<Pokeballs>(input);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << endl << "Enter Weather Condition : ";
    while (!(cin>>input) || input >= TOTALWEATHERS or input < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a valid value of Weather : ";
    };
    env.Weather = static_cast<Weathers>(input);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << endl << "Enter Pokemon's type : ";
    while (!(cin>>input) || input >= TOTALTYPES or input < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a valid value of Pokemon HP in percentage : ";
    };
    pokemon.Type = static_cast<PokemonTypes>(input);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << endl << "Enter Time : ";
    while (!(cin>>input) || input >= TOTALTIME or input < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a valid value of Pokemon HP in percentage : ";
    };
    env.Time = static_cast<TimeofDay>(input);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}