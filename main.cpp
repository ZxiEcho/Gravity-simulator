
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

struct Planets{
    int id;
    float X;
    float Y;
    float Z;
    float size;
    float mass;
    float x_speed;
    float y_speed;
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
        float xspeed = 0;
        float yspeed = 0;

        std::cin >> x >> y >> z >> size >> mass;

        temp_planet.X = x;
        temp_planet.Y = y;
        temp_planet.Z = z;
        temp_planet.size = size; 
        temp_planet.mass = mass;
        temp_planet.x_speed = xspeed;
        temp_planet.y_speed = yspeed;

        planets.push_back(temp_planet);
        
    }
    if(number_planets != 0){
        return false;
    }
    return true;
}

bool init_test(vector<Planets>& planets){

}



vector<float> force_calculator(vector<Planets>& planets){
    vector<float> temp_vec = {};
    for(int i = 0; i < planets.size(); i++){
        for(int j = i + 1; j < planets.size(); j++){
            float xdis = planets[i].X - planets[j].X;
            float ydis = planets[i].Y - planets[j].Y;

            float gravity_x = (planets[i].mass * planets[j].mass) / xdis;
            float gravity_y = (planets[i].mass * planets[j].mass) / ydis;
            temp_vec.push_back(gravity_x);
            temp_vec.push_back(gravity_y);
        }
    }
    return temp_vec;
}

void apply_force(vector<Planets>& planets, vector<float>& forces){

    for (int i = 0; i < planets.size(); i++){
        for(int j = i + 1; j < planets.size(); j++){ 
            int force_index = i * planets.size() + j - 1;
            for(int k = force_index; k < force_index + 2; k++){
                 
            }

        }
    }
}

int main(int argc, char const *argv[]){
    vector<Planets> planets = {};
    bool zero = init(planets);

    if (zero){
        return 0;
    }

    while(1){
        vector<float> forces = force_calculator(planets);

        apply_force(planets, forces);
    }
    
    
    return 0;
}

