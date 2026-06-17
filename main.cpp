#include <ios>
#include <iostream>
#include <limits>

const float MAX_CATCHRATE = 255.0f;

enum pokemontypes  {GROUND, WATER, FIRE, ICE, BUG, TOTALTYPES};
enum weathers {SANDSTORM, RAIN, HARSHSUN, SNOW, CLEAR, TOTALWEATHERS};
enum pokeballs {NORMAL, GREAT, PREMIER, ULTRA, DUSK, NET, DIVE, MASTER, TOTALBALLS};
enum timeofday {MORNING, NOON, AFTERNOON, EVENING, NIGHT, TOTALTIME};
enum terrain {UNDERWATER, CAVE, TOTALTERRAIN};


struct Pokemon {
    pokemontypes Type;
    float HP;
    int CatchRate;
};

struct Environment {
    weathers Weather;
    timeofday Time;
    terrain Terrain;
};

using std::cout;
using std::cin;
using std::endl;

float catch_calculator(float, int);
float modifiers(float, float, float);
float weather_modifier(weathers, pokemontypes);
float pokeball_modifiers(pokeballs, timeofday, pokemontypes, terrain);
void handle_input(pokeballs&, Pokemon&, Environment&);

int main() {
    Pokemon pokemon;
    Environment env;
    pokeballs BallType;

    handle_input(BallType, pokemon, env);

    float WeatherModifier = weather_modifier(env.Weather, pokemon.Type);
    float PokeballModifier = pokeball_modifiers(BallType, env.Time, pokemon.Type, env.Terrain);

    float BaseChance = catch_calculator(pokemon.HP, pokemon.CatchRate);
    float Chance = modifiers(WeatherModifier, PokeballModifier, BaseChance);

    if (BallType == MASTER){
        Chance = 1.0f;
    };

    if (Chance > 1.0f) {
        Chance = 1.0f;
    };

    cout << endl << "You have a " << 100.0f*Chance << " % chance of catching the pokemon";
    

return 0; }

float catch_calculator(float PokemonHP, int CatchRate) {

    float chance = ((100.0f - PokemonHP)/100.0f)*(CatchRate/MAX_CATCHRATE);
    return chance;
}

float modifiers(float WeatherModifier, float PokeballModifier, float BaseChance){

    return BaseChance*WeatherModifier*PokeballModifier;
}

float pokeball_modifiers(pokeballs balltype, timeofday Time, pokemontypes PokemonType, terrain Terrain ){
    switch(balltype){
        case NORMAL:
            return 1.0f;
        case GREAT:
            return 1.5f;
        case PREMIER:
            return 1.5f;
        case ULTRA:
            return 2.0f;
        case DUSK:
            if (Time == NIGHT || Terrain == CAVE){
                return 3.5f;
            };
        case NET:
            if (PokemonType == WATER || PokemonType == BUG){
                return 3.5f;
            };
        case DIVE:
            if (Terrain == UNDERWATER){
                return 3.5f;
            }
        case MASTER:
            return 1.0f;   //Don't worry - it is handled in main ;)
    };
    return 1.0f;
}

float weather_modifier(weathers WeatherType, pokemontypes PokemonType) {
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

void handle_input(pokeballs& BallType, Pokemon& pokemon, Environment& env) {
    int input;

    cout << "Enter Pokemon HP in percentage : ";
    while (!(cin>>pokemon.HP) || pokemon.HP > 100 or pokemon.HP < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a valid value of Pokemon HP in percentage : ";
    };
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << endl << "Enter Pokemon's Catch Rate : ";
    while (!(cin>>pokemon.CatchRate) || pokemon.CatchRate > 255 or pokemon.CatchRate < 1) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << endl << "Please enter a valid value of Pokemon's Catch Rate (1-255): ";
    };
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << endl << "Enter BallType : ";
    while (!(cin>>input) || input >= TOTALBALLS or input < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a valid value of BallType : ";
    };
    BallType = static_cast<pokeballs>(input);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << endl << "Enter Weather Condition : ";
    while (!(cin>>input) || input >= TOTALWEATHERS or input < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a valid value of Weather : ";
    };
    env.Weather = static_cast<weathers>(input);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << endl << "Enter Pokemon's type : ";
    while (!(cin>>input) || input >= TOTALTYPES or input < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a valid value of Pokemon Type : ";
    };
    pokemon.Type = static_cast<pokemontypes>(input);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << endl << "Enter Time : ";
    while (!(cin>>input) || input >= TOTALTIME or input < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a valid value of Time : ";
    };
    env.Time = static_cast<timeofday>(input);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << endl << "Enter Terrain : ";
    while (!(cin>>input) || input >= TOTALTERRAIN or input < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a valid value of Terrain : ";
    };
    env.Terrain = static_cast<terrain>(input);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}