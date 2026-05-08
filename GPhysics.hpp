#pragma once

#include <fpm/fixed.hpp>
#include <fpm/math.hpp>
#include <fpmlinalg.hpp>
#include <GCollision.hpp>

#include <stdint.h>

class GPhysics { public: ~GPhysics();
        GPhysics(uint32_t max_bodies = 65536, uint16_t tickrate = 128);

        struct Box {
                GPhysics* physics_instance;
                uint64_t id;
                bool dynamic;
                bool lock_x, lock_y, lock_z;
                gcollision::AABB aabb;
                fpmlinalg::Vec3 velocity;
                fpm::fixed_16_16 gravity;
                fpm::fixed_16_16 friction;
                fpm::fixed_16_16 bounciness;
                fpmlinalg::Vec3 GetPosition() const;
                void SetPosition(fpmlinalg::Vec3 new_pos);
                void ApplyForce(fpmlinalg::Vec3 f);
                void ApplyImpulse(fpmlinalg::Vec3 i);
                void Remove();
        };
        Box* AddBox(fpmlinalg::Vec3 size, bool dynamic, bool lock_x = false, bool lock_y = false, bool lock_z = false);

        void Tick();
};
