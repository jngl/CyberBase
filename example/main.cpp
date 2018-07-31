#include <CyberBase.hpp>

#include <iostream>

int main(){
    cb::Vector3 test{45,2,3};
    float x = 0.f;

    std::cout<<test.x()/x<<" "<<test.y()<<" "<<test.z()<<std::endl;
}