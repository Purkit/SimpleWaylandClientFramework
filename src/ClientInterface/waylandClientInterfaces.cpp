#include <SWCF/ClientInterface/waylandClientInterfaces.hpp>
#include <SWCF/Core/waylandInterfaceManager.hpp>

namespace SWCF {

    namespace ClientInterface {

        Compositor* Compositor::m_Instance = nullptr;

        Compositor& Compositor::GetInstance() {
            if (!m_Instance)
                m_Instance = new Compositor();
            return *m_Instance;
        }

        bool Compositor::Initialize() {
            SWCF::Core::WaylandCompositorInterfaceManager& interfaceManager = SWCF::Core::WaylandCompositorInterfaceManager::getInstance();
            m_compositor = static_cast<wl_compositor*>(interfaceManager.Bind("wl_compositor", &wl_compositor_interface, 1));

        }
        
    }
    




}