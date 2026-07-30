#pragma once

#include "../shared.h"


namespace OPTIC {

    class Window;

    class Node {
    public:
                            Node();                                       // constructor
        virtual             ~Node();                                      // destructor

        virtual void        handle_display_change();

        void                tick();                                       // entrypoint for parent
        virtual void        process();                          
        virtual void        render();

        void                hide();
        void                show();

        void                position(Normalized t_position);              // mutator
        Normalized          position();                                   // accessor

        void                anchor(Normalized t_anchor);                  // mutator
        Normalized          anchor();                                     // accessor

        void                size(Normalized t_size);                      // mutator
        Normalized          size();                                       // accessor

        void                size_px(Pixel t_size_px);                     // mutator
        Pixel               size_px();                                    // accessor

        void                position_px(Pixel t_position_px);             // mutator
        Pixel               position_px();                                // accessor

        void                add_child(Node* child);                       // adopts a pointer to a node

        void                parent(Node* t_parent);                       // mutator
        Node*               parent();                                     // accessor

        void                window(Window* t_window);                     // mutator
        Window*             window();                                     // accessor


    private:
        // Positioning
        Normalized          position_;                           // normalized coordinate position based on parent size
        Normalized          anchor_;                             // normalized coordinate of node position based on size
        Normalized          size_;                               // size is a normalized device coordinate (2.0 = entire dimention)

        Pixel               position_px_;                        // position as raw computed pixels
        Pixel               size_px_;                            // size as raw computed pixels

        Visibility          visibility_;                         // controlls whether the node will render

        Window*             window_;                             // pointer to the window that owns this node
        Node*               parent_;                             // pointer to the parent node
        
        std::vector<Node*>  children_;                           // all children nodes
    };  
}
