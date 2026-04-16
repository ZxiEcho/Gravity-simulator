
#include <iostream>

int main(int argc, char const *argv[]){
    if (!init()){
        return 0;
    }
    return 0;
}

bool init(){
    int planets = 0;
    std::cout << "Enter number of planets" << std::endl;
    std::cin >> planets;
    std::cout << "Number of planets: " << planets;
}
