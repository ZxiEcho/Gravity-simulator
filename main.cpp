
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

#include <SFML/Graphics.hpp>

struct Planets{
    int id; 
    float X;
    float Y;
    float Z;
    float size; //radius of planet
    float mass; //weight 
    float x_speed; //speed along the x axis 
    float y_speed; //speed along the y axis
};



bool init(vector<Planets>& planets){ //entering all info about the planets 
    int number_planets = 0;
    std::cout << "Enter number of planets" << std::endl;
    std::cin >> number_planets;
    if(number_planets != 0){ //if we dont have any planets return
        return false;
    }
    for(int i = 0; i < number_planets; i++){ //enter all info for every planet
        Planets temp_planet;
        temp_planet.id = i;
        float x = 0; 
        float y = 0;
        float z = 0; 
        float size = 0;
        float mass = 0;
        float xspeed = 0;
        float yspeed = 0;

        std::cin >> x >> y >> size >> mass;

        temp_planet.X = x;
        temp_planet.Y = y;
        temp_planet.Z = z;
        temp_planet.size = size; 
        temp_planet.mass = mass;
        temp_planet.x_speed = xspeed;
        temp_planet.y_speed = yspeed;

        planets.push_back(temp_planet); //add the planet to our vector with planets
        
    }
    return true;
}

bool init_test(vector<Planets>& planets){//init with 2 planets for testing
    Planets temp_planet;
    temp_planet.id = 0;
    temp_planet.X = 50;
    temp_planet.Y = 50;
    temp_planet.Z = 0;
    temp_planet.size = 5;
    temp_planet.mass = 5;
    temp_planet.x_speed = 0;
    temp_planet.y_speed = 0.001;

    planets.push_back(temp_planet);

    temp_planet.id = 1;
    temp_planet.X = 200;
    temp_planet.Y = 200;
    temp_planet.Z = 0;
    temp_planet.size = 10;
    temp_planet.mass = 15;
    temp_planet.x_speed = 0;
    temp_planet.y_speed = 0;

    planets.push_back(temp_planet);

    return false;
}

void update_drawing(vector<Planets>& planets, sf::RenderWindow& window){ //render the window every loop itteration
    window.clear();
    for(int i = 0; i < planets.size(); i++){
        sf::CircleShape shape(planets[i].size); //create the circle 
        shape.setFillColor(sf::Color::Green);

        sf::Vector2f v(planets[i].X, planets[i].Y); 
        shape.setPosition(v); //set cirkle position

        window.draw(shape); //draw the circles
    }
    window.display();
}



vector<float> force_calculator(vector<Planets>& planets){ 
    vector<float> temp_vec = {};
    float power = 0.00000001; //need to scale the force with this constant so that they dont fly of screen in one loop itteration 
    float gravity_constant = 6.674 * power;
    for(int i = 0; i < planets.size(); i++){
        for(int j = i + 1; j < planets.size(); j++){
            float xdis = planets[i].X - planets[j].X;
            float ydis = planets[i].Y - planets[j].Y;

            float gravity_x = (planets[i].mass * planets[j].mass) / xdis;
            float gravity_y = (planets[i].mass * planets[j].mass) / ydis;

            gravity_x *= gravity_constant;
            gravity_y *= gravity_constant;

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

            if(planets[i].X < planets[j].X){
                planets[i].x_speed -= forces[force_index];  
                planets[j].x_speed += forces[force_index];
            }
            else{
                planets[i].x_speed += forces[force_index];  
                planets[j].x_speed -= forces[force_index];
            }

            if(planets[i].Y < planets[j].Y) {
                planets[i].y_speed -= forces[force_index + 1];
                planets[j].y_speed += forces[force_index + 1];
            }
            else{
                planets[i].y_speed += forces[force_index + 1];  
                planets[j].y_speed -= forces[force_index + 1];
            }
        }
    }
}

void update_position(vector<Planets>& planets){ //updates the position
    for(int i = 0; i < planets.size(); i++){
        planets[i].X += planets[i].x_speed;
        planets[i].Y += planets[i].y_speed;
    }
}

int main(int argc, char const *argv[]){
    vector<Planets> planets = {};
    bool zero = init_test(planets);
    
    if (zero){
        return 0;
    }
    
    sf::RenderWindow window(sf::VideoMode({1000,1000}), "SFML Works"); //creates the window we render to

    while(window.isOpen()){
        vector<float> forces = force_calculator(planets);
        apply_force(planets, forces);
        update_position(planets);
        update_drawing(planets, window);
    }
    
    return 0;
}

