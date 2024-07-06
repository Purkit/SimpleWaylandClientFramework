#include <SWCF/Core/waylandInterface.hpp>
#include <SWCF/DebugUtil/Logger/logger.hpp>
#include <iostream>

namespace SWCF {
    namespace Core {

        WaylandCompositorInterface* WaylandCompositorInterface::m_Instance = nullptr;

        wl_registry_listener WaylandCompositorInterface::registry_listeners = {
            WaylandCompositorInterface::NewInterfaceAddEventNotifyCallback,
            WaylandCompositorInterface::InterfaceRemoveEventNotifyCallback
        };

        WaylandCompositorInterface& WaylandCompositorInterface::getInstance() {
            if (!m_Instance)
                m_Instance = new WaylandCompositorInterface();
            
            DEBUG("Creating singleton instance of class 'WaylandCompositorInterface'.");
            return *m_Instance;
        }

        void WaylandCompositorInterface::Setup(wl_display* compositor_connection_h) {
            DEBUG("Trying to get the interface registry.");
            wayland_compositor_interface_registry = wl_display_get_registry(compositor_connection_h);
            DEBUG("Got the interface registry.");
            DEBUG("Now trying to set the registry event listener functions.");
            wl_registry_add_listener(wayland_compositor_interface_registry, &registry_listeners, this);
            DEBUG("Success!");
            DEBUG("Calling 'wl_display_roundtrip'");
            wl_display_roundtrip(compositor_connection_h);
            DEBUG("WaylandCompositorInterface::Setup Successful");
        }

        void WaylandCompositorInterface::NewInterfaceAddEventNotifyCallback(void* data, wl_registry* registry, uint32_t id, const char* interface, uint32_t version) {
            WaylandCompositorInterface* self = static_cast<WaylandCompositorInterface*>(data);
            self->PushNewInterface(interface, id);
            //std::cout << "New Interface Registered: " << interface << " id " << id << "\n";
        }

        void WaylandCompositorInterface::InterfaceRemoveEventNotifyCallback(void* data, wl_registry* registry, uint32_t id) {
            WaylandCompositorInterface* self = static_cast<WaylandCompositorInterface*>(data);
            self->DeleteInterface(id);
            //std::cout << "Interface removed from Registry. ID: " << id << "\n";
        }


        void WaylandCompositorInterface::PushNewInterface(const char* interface_string, uint32_t id) {
            interface_map[interface_string] = id;
        }

        void WaylandCompositorInterface::DeleteInterface(uint32_t id) {
            for (auto it = interface_map.begin(); it != interface_map.end(); ++it) {
                if (it->second == id) {
                    interface_map.erase(it);
                    break;
                }
            }
        }

        bool WaylandCompositorInterface::HasInterface(const std::string& interface_name) const {
            return interface_map.find(interface_name) != interface_map.end();
        }

        void* WaylandCompositorInterface::Bind(const std::string& interface_name, const wl_interface* interface, uint32_t version) {

            auto it = interface_map.find(interface_name);
            if (it != interface_map.end()) {
                return wl_registry_bind(wayland_compositor_interface_registry, it->second, interface, version);
            } else {
                std::cerr << "Interface " << interface_name << " not found" << std::endl;
                return nullptr;
            }
        }


    }
}