
#include <vector>
#include <iostream>
using namespace std;

struct Planets{
    int id;
    float X;
    float Y;
    float Z;
    float size;
    float mass;
    float speed;
};



bool init(vector<Planets>& planets){
    int number_planets = 0;
    std::cout << "Enter number of planets" << std::endl;
    std::cin >> number_planets;
    for(int i = 0; i < number_planets; i++){
        Planets temp_planet;
        temp_planet.id = i;
        float x = 0; 
        float y = 0;
        float z = 0; 
        float size = 0;
        float mass = 0;
        float speed = 0;

        std::cin >> x >> y >> z >> size >> mass;

        temp_planet.X = x;
        temp_planet.Y = y;
        temp_planet.Z = z;
        temp_planet.size = size; 
        temp_planet.mass = mass;
        temp_planet.speed = speed;

        planets.push_back(temp_planet);
        
    }
    if(number_planets != 0){
        return false;
    }
    return true;
}

bool init_test(vector<Planets>& planets){

}

int main(int argc, char const *argv[]){
    vector<Planets> planets = {};
    bool zero = init(planets);

    if (zero){
        return 0;
    }

    for(int i = 0; i < planets.size(); i++){
        for(int j = i + 1; j < planets.size(); j++){
            float xdis = planets[i].X - planets[j].X;
            float ydis = planets[i].Y - planets[j].Y;
            float distance = sqrt((xdis * xdis) + (ydis * ydis));

            float gravity = (planets[i].mass * planets[j].mass) / distance;
        }
    }
    
    return 0;
}

