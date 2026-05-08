#pragma once

#include <fpm/fixed.hpp>
#include <fpm/math.hpp>
#include <fpmlinalg.hpp>
#include <GCollision.hpp>

#include <stdint.h>

class GPhysics { public: ~GPhysics();
        GPhysics(uint16_t max_boxes = 8192, uint16_t tickrate = 128);

        struct Box {
                GPhysics* physics_instance = nullptr;
                bool dynamic = false;
                bool lock_x = false, lock_y = false, lock_z = false;
                bool in_air = true;
                gcollision::AABB aabb = gcollision::AABB{fpmlinalg::Vec3{0, 0, 0}, fpmlinalg::Vec3{0, 0, 0}};
                fpmlinalg::Vec3 velocity = fpmlinalg::Vec3{0, 0, 0};
                fpm::fixed_16_16 gravity = fpm::fixed_16_16::from_custom_fraction<100>(9, 81);
                fpm::fixed_16_16 friction = fpm::fixed_16_16{1}/fpm::fixed_16_16{2};
                fpm::fixed_16_16 bounciness = fpm::fixed_16_16{1}/fpm::fixed_16_16{8};
                fpmlinalg::Vec3 GetPosition() const {fpmlinalg::Vec3 mm = aabb.min + aabb.max; return fpmlinalg::Vec3{mm.x/2, mm.y/2, mm.z/2};};
                void SetPosition(fpmlinalg::Vec3 new_pos) { fpmlinalg::Vec3 size = aabb.max - aabb.min;
                        fpmlinalg::Vec3 half_extent = fpmlinalg::Vec3{size.x/2, size.y/2, size.z/2};
                        this->aabb.min = new_pos - half_extent;
                        this->aabb.max = new_pos + half_extent;
                };
                void ApplyForce(fpmlinalg::Vec3 f);
                void Remove();
        };
        Box* AddBox(fpmlinalg::Vec3 size);

        void Tick();
};
