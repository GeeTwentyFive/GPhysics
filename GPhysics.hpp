#pragma once

class GPhysics { private: struct _internal; struct _internal* _; public: ~GPhysics();
        GPhysics(unsigned int max_bodies = 65536, int tickrate = 128);

        void* AddBox(float size_x, float size_y, float size_z, bool stationary); // TODO
        void* AddSphere(float radius, bool stationary); // TODO
        void* AddCylinder(float height, float top_radius, float bottom_radius, bool stationary); // TODO

        // TODO

        void Tick();
};