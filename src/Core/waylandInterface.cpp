#include <SWCF/Core/waylandInterface.hpp>
#include <iostream>

namespace SWCF {
    namespace Core {

        WaylandCompositorInterface* WaylandCompositorInterface::m_Instance = nullptr;

        wl_registry_listener WaylandCompositorInterface::registry_listeners = {
            NewInterfaceAddEventNotifyCallback,
            InterfaceRemoveEventNotifyCallback
        };

        WaylandCompositorInterface& WaylandCompositorInterface::getInstance() {
            if (!m_Instance)
                m_Instance = new WaylandCompositorInterface();
            
            return *m_Instance;                
        }

        void WaylandCompositorInterface::Setup(wl_display* compositor_connection_h) {
            wayland_compositor_interface_registry = wl_display_get_registry(compositor_connection_h);
            wl_registry_add_listener(wayland_compositor_interface_registry, &registry_listeners, nullptr);
            wl_display_roundtrip(compositor_connection_h);
        }

        void WaylandCompositorInterface::NewInterfaceAddEventNotifyCallback(void* data, wl_registry* registry, uint32_t id, const char* interface, uint32_t version) {
            std::cout << "New Interface Registered: " << interface << " id " << id << "\n";
        }

        void WaylandCompositorInterface::InterfaceRemoveEventNotifyCallback(void* data, wl_registry* registry, uint32_t id) {
            std::cout << "Interface removed from Registry. ID: " << id << "\n";
        }



    }
}