#pragma once

#include "../shared.h"

namespace OPTIC {
    class Window;

    class Node {
    public:
        Node();
        virtual ~Node();

        template <typename Derived>
        Derived* as() {
            return dynamic_cast<Derived*>(this);
        }

        virtual void        handle_display_change();
        virtual void        tick();

        void                hide();
        void                show();

        void                set_parent(OPTIC::Window*);
        OPTIC::Window*      get_parent();
        
    private:
        bool                hidden;
        bool                shown;

        OPTIC::Window*      parent;
    };  
}
