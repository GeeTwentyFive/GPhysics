#pragma once

#include <tuple>

class GPhysics { private: struct _internal; struct _internal* _; public: ~GPhysics();
        GPhysics(unsigned int max_bodies = 65536, int tickrate = 128);

        void* AddBox(float size_x, float size_y, float size_z, bool stationary);
        void* AddSphere(float radius, bool stationary);
        void* AddCylinder(float height, float top_radius, float bottom_radius, bool stationary);

        std::tuple<float, float, float> GetPosition(void* body_id);
        void SetPosition(void* body_id, float x, float y, float z);

        std::tuple<float, float, float> GetRotation(void* body_id);
        void SetRotation(void* body_id, float x, float y, float z);

        void ApplyForce(void* body_id, float x, float y, float z);
        void ApplyImpulse(void* body_id, float x, float y, float z);

        void LockXTranslation(void* body_id); void LockYTranslation(void* body_id); void LockZTranslation(void* body_id);
        void LockXRotation(void* body_id); void LockYRotation(void* body_id); void LockZRotation(void* body_id);

        void Tick();
};