#pragma once

#include <tuple>

class GPhysics { private: struct _internal; struct _internal* _; public: ~GPhysics();
        GPhysics(unsigned int max_bodies = 65536, int tickrate = 128);

        typedef void BodyID;

        BodyID* AddBox(float size_x, float size_y, float size_z, bool stationary);
        BodyID* AddSphere(float radius, bool stationary);
        BodyID* AddCylinder(float height, float top_radius, float bottom_radius, bool stationary);

        std::tuple<float, float, float> GetPosition(BodyID* body_id);
        void SetPosition(BodyID* body_id, float x, float y, float z);

        std::tuple<float, float, float> GetRotation(BodyID* body_id);
        void SetRotation(BodyID* body_id, float x, float y, float z);

        void ApplyForce(BodyID* body_id, float x, float y, float z); void ApplyAngularForce(BodyID* body_id, float x, float y, float z);
        void ApplyImpulse(BodyID* body_id, float x, float y, float z); void ApplyAngularImpulse(BodyID* body_id, float x, float y, float z);

        void LockXTranslation(BodyID* body_id); void LockYTranslation(BodyID* body_id); void LockZTranslation(BodyID* body_id);
        void LockXRotation(BodyID* body_id); void LockYRotation(BodyID* body_id); void LockZRotation(BodyID* body_id);

        void Remove(BodyID* body_id);

        void Tick();
};