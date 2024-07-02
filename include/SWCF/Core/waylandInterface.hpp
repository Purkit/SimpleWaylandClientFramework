#ifndef WAYLAND_COMPOSITOR_INTERFACE_HPP
#define WAYLAND_COMPOSITOR_INTERFACE_HPP

#include <wayland-client.h>

#include <string>
#include <unordered_map>

namespace SWCF {
    namespace Core {

        class WaylandCompositorInterface {

            public:

                static WaylandCompositorInterface& getInstance();

                void Setup(wl_display* compositor_connection_h);

                bool HasInterface(const std::string& interface_name) const;
            
            private:

                static WaylandCompositorInterface* m_Instance;


            private:
                wl_registry* wayland_compositor_interface_registry;

                std::unordered_map<std::string, uint32_t> interface_map;
            
            private:
                static void NewInterfaceAddEventNotifyCallback(void* data, wl_registry* registry, uint32_t id, const char* interface, uint32_t version); // Handle new global interface registration
                static void InterfaceRemoveEventNotifyCallback(void* data, wl_registry* registry, uint32_t id); // Handle global interface removal

                void PushNewInterface(const char* interface_string, uint32_t id);
                void DeleteInterface(uint32_t id);

                static wl_registry_listener registry_listeners;
            
            private:
                WaylandCompositorInterface() {}
                ~WaylandCompositorInterface() {}

        };


    }
}

#endif // ! WAYLAND_COMPOSITOR_INTERFACE_HPP