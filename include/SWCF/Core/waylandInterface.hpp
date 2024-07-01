#ifndef WAYLAND_COMPOSITOR_INTERFACE_HPP
#define WAYLAND_COMPOSITOR_INTERFACE_HPP

#include <wayland-client.h>

namespace SWCF {
    namespace Core {

        class WaylandCompositorInterface {

            public:

                static WaylandCompositorInterface& getInstance();

                void Setup(wl_display* compositor_connection_h);
            
            private:

                static WaylandCompositorInterface* m_Instance;


            private:
                wl_registry* wayland_compositor_interface_registry;
            
            private:
                static void NewInterfaceAddEventNotifyCallback(void* data, wl_registry* registry, uint32_t id, const char* interface, uint32_t version); // Handle new global interface registration
                static void InterfaceRemoveEventNotifyCallback(void* data, wl_registry* registry, uint32_t id); // Handle global interface removal

                static wl_registry_listener registry_listeners;
            
            private:
                WaylandCompositorInterface() {}
                ~WaylandCompositorInterface() {}

        };


    }
}

#endif // ! WAYLAND_COMPOSITOR_INTERFACE_HPP