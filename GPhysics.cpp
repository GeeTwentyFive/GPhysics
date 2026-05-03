#include "GPhysics.hpp"


#include <Jolt/Jolt.h>
#include <Jolt/RegisterTypes.h>
#include <Jolt/Core/Factory.h>
#include <Jolt/Core/TempAllocator.h>
#include <Jolt/Core/JobSystemThreadPool.h>
#include <Jolt/Physics/PhysicsSettings.h>
#include <Jolt/Physics/PhysicsSystem.h>
#include <Jolt/Physics/Collision/Shape/BoxShape.h>
#include <Jolt/Physics/Collision/Shape/SphereShape.h>
#include <Jolt/Physics/Body/BodyCreationSettings.h>
JPH_SUPPRESS_WARNINGS


struct GPhysics::_internal {
        // TODO
};

GPhysics::GPhysics() { this->_ = new GPhysics::_internal; JPH::RegisterDefaultAllocator(); JPH::Factory::sInstance = new JPH::Factory(); JPH::RegisterTypes();
        // TODO
}