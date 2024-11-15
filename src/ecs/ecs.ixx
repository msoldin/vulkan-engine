//
// Created by marvi on 15.11.2024.
//
module;

#include <memory>

export module vulkan_engine.ecs;
export import :entity;
export import :system;
export import :component;
export import :coordinator;
export import :system_manager;
export import :component_manager;

namespace vulkan_engine::ecs {
export std::unique_ptr<CoordinatorBuilder> create() { return std::make_unique<CoordinatorBuilder>(); }
}  // namespace vulkan_engine::ecs