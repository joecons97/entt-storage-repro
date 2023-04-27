#include <entt/entt.hpp>

struct Component1 {

};

struct Component2 {

};

int main()
{
	entt::meta<Component1>().type(entt::hashed_string{ "Component1" })
		.ctor()
		.func<&entt::registry::storage<Component1>, entt::as_ref_t>(entt::hashed_string{ "storage" });

	//My attempt at the static cast suggestion...
	entt::meta<Component2>().type(entt::hashed_string{ "Component2" })
		.ctor()
		.func<static_cast<entt::storage<Component2>& (entt::registry::*)(const entt::id_type)>(&entt::registry::storage<Component2>), entt::as_ref_t>(entt::hashed_string{ "storage" });
}
