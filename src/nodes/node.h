#pragma once

#include "../shared.h"


namespace OPTIC {

    class Window;

    class Node {
    public:

        // Memory management

        Node();                                                           // constructor for a top level node
        Node(Node* t_parent);                                             // constructor for a child node

        template <typename T>
        T* copy_as() {
            Node* result = this->copy();
            return static_cast<T*>(result);
        }

        Node*               copy();                                       // base class copy constructor
        virtual Node*       derived_copy() const = 0;                     // backend copy for derived classes

        virtual             ~Node();                                      // destructor

        // Family tree

        void                add_child(Node* child);                       // sets parent/child relationship from the parent node
        void                is_child_of(Node* t_parent);                  // sets parent/child relationship from the child node

        void                parent(Node* t_parent);                       // mutator
        Node*               parent();                                     // accessor

        const std::vector<Node*>& children() const { return children_; }

        // Events

        void                bind_event(void (*&event_func)(Node*), void (*action_func)(Node*));

        void                (*on_curser_enter)(Node* self) = nullptr;
        void                (*on_curser_leave)(Node* self) = nullptr;

        void                (*on_cursor_press)(Node* self) = nullptr;
        void                (*on_cursor_release)(Node* self) = nullptr;

        void                (*on_left_cursor_press)(Node* self) = nullptr;
        void                (*on_left_cursor_release)(Node* self) = nullptr;

        void                (*on_right_cursor_press)(Node* self) = nullptr;
        void                (*on_right_cursor_release)(Node* self) = nullptr;

        // Looping

        void                tick();                                       // entrypoint for parent
        virtual void        process();                          
        virtual void        render();

        // Visibility

        void                hide();
        void                show();

        // Positioning

        Node*               position(Normalized t_position);              // mutator
        Normalized          position();                                   // accessor

        void                position_px(Pixel t_position_px);             // mutator
        Pixel               position_px();                                // accessor

        Node*               anchor(Normalized t_anchor);                  // mutator
        Normalized          anchor();                                     // accessor

        // Sizing

        Node*               size(Normalized t_size);                      // mutator
        Normalized          size();                                       // accessor

        void                size_px(Pixel t_size_px);                     // mutator
        Pixel               size_px();                                    // accessor

        // Windowing

        virtual Window*     check_for_window();                           // climbs family tree in search of a window
        void                rasterize_to_window(Window* window);          // pixel conversion of ndc attributes based on provided window
        virtual void        handle_display_change();                     

    private:
        Normalized          position_;                           // normalized coordinate position based on parent size
        Pixel               position_px_;                        // position as raw computed pixels

        Normalized          anchor_;                             // normalized coordinate of node position based on size
        
        Normalized          size_;                               // size is a normalized device coordinate (2.0 = entire dimention)
        Pixel               size_px_;                            // size as raw computed pixels

        Visibility          visibility_;                         // controlls whether the node will render

        bool                touching_cursor;

        Node*               parent_;                             // pointer to the parent node
        std::vector<Node*>  children_;                           // all children nodes
    };  
}
