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

        void                tick();
        virtual void        process();
        virtual void        render();

        void                hide();
        void                show();

        void                position(Normalized t_position);    // mutator
        Normalized          position();                         // accessor

        void                anchor(Normalized t_anchor);        // mutator
        Normalized          anchor();                           // accessor

        void                size(Normalized t_size);            // mutator
        Normalized          size();                             // accessor

        void                set_parent(OPTIC::Window*);
        OPTIC::Window*      get_parent();


        
    private:
        // Positioning
        Normalized          position_;
        Normalized          anchor_;
        Normalized          size_;

        bool                hidden;
        bool                shown;

        OPTIC::Window*      parent;
    };  
}
