#include <SWCF/Core/waylandInterfaceManager.hpp>
#include <SWCF/DebugUtil/Logger/logger.hpp>
#include <iostream>

namespace SWCF {
    namespace Core {

        WaylandCompositorInterfaceManager* WaylandCompositorInterfaceManager::m_Instance = nullptr;

        wl_registry_listener WaylandCompositorInterfaceManager::registry_listeners = {
            WaylandCompositorInterfaceManager::NewInterfaceAddEventNotifyCallback,
            WaylandCompositorInterfaceManager::InterfaceRemoveEventNotifyCallback
        };

        WaylandCompositorInterfaceManager& WaylandCompositorInterfaceManager::getInstance() {
            if (!m_Instance)
                m_Instance = new WaylandCompositorInterfaceManager();
            
            DEBUG("Creating singleton instance of class 'WaylandCompositorInterface'.");
            return *m_Instance;
        }

        void WaylandCompositorInterfaceManager::Initialize(wl_display* compositor_connection_h) {
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

        void WaylandCompositorInterfaceManager::NewInterfaceAddEventNotifyCallback(void* data, wl_registry* registry, uint32_t id, const char* interface, uint32_t version) {
            WaylandCompositorInterfaceManager* self = static_cast<WaylandCompositorInterfaceManager*>(data);
            self->PushNewInterface(interface, id);
            //std::cout << "New Interface Registered: " << interface << " id " << id << "\n";
        }

        void WaylandCompositorInterfaceManager::InterfaceRemoveEventNotifyCallback(void* data, wl_registry* registry, uint32_t id) {
            WaylandCompositorInterfaceManager* self = static_cast<WaylandCompositorInterfaceManager*>(data);
            self->DeleteInterface(id);
            //std::cout << "Interface removed from Registry. ID: " << id << "\n";
        }


        void WaylandCompositorInterfaceManager::PushNewInterface(const char* interface_string, uint32_t id) {
            interface_map[interface_string] = id;
        }

        void WaylandCompositorInterfaceManager::DeleteInterface(uint32_t id) {
            for (auto it = interface_map.begin(); it != interface_map.end(); ++it) {
                if (it->second == id) {
                    interface_map.erase(it);
                    break;
                }
            }
        }

        bool WaylandCompositorInterfaceManager::HasInterface(const std::string& interface_name) const {
            return interface_map.find(interface_name) != interface_map.end();
        }

        void* WaylandCompositorInterfaceManager::Bind(const std::string& interface_name, const wl_interface* interface, uint32_t version) {

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