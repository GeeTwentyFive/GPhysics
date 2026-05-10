#include <GPhysics.hpp>

#include <iostream>

int main() {
        GPhysics gp{};

        GPhysics::Box* floor = gp.AddBox({10, 1, 10});

        GPhysics::Box* b1 = gp.AddBox({1, 1, 1});
        b1->dynamic = true;
        b1->aabb.SetCenterPos({0, 2, 0});

        GPhysics::Box* b2 = gp.AddBox({1, 1, 1});
        b2->dynamic = true;
        b2->aabb.SetCenterPos({0, 5, 0});

        for (int i = 0; i < (int)gp.tickrate; i++) {
                std::cout << std::endl;
                std::cout << "Tick: " << i << std::endl;
                std::cout << std::endl;

                fpmlinalg::Vec3 b1_pos = b1->aabb.GetCenterPos();
                std::cout << "Box 1 X: " << (float)b1_pos.x << std::endl;
                std::cout << "Box 1 Y: " << (float)b1_pos.y << std::endl;
                std::cout << "Box 1 Z: " << (float)b1_pos.z << std::endl;
                std::cout << std::endl;

                fpmlinalg::Vec3 b2_pos = b2->aabb.GetCenterPos();
                std::cout << "Box 2 X: " << (float)b2_pos.x << std::endl;
                std::cout << "Box 2 Y: " << (float)b2_pos.y << std::endl;
                std::cout << "Box 2 Z: " << (float)b2_pos.z << std::endl;
                std::cout << std::endl;

                gp.Tick();
        }

        return 0;
}