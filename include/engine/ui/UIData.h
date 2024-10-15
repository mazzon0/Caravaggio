#ifndef CRVG_UIDATA
#define CRVG_UIDATA

#include "widgets/Image.h"
#include "widgets/Text.h"
#include "WidgetManager.h"
#include "fonts/FontSystem.h"

namespace engine {

    class UIData {
    public:
        template<typename T>
        static WidgetID add(T& widget) {return getInstance().iAdd(widget);}

        static void updateData() {getInstance().iUpdateData();}

    private:
        std::tuple<WidgetManager<Image>, WidgetManager<Text>> m_managers;

        template<typename T>
        WidgetID iAdd(T& widget);
        void iUpdateData();

        WidgetID randomID();    /* TODO: check for duplicates? */

        UIData() = default;
        ~UIData() = default;

    private:
        static UIData& getInstance() {
            static UIData instance;  
            return instance;
        }

        UIData(const UIData&) = delete;
        UIData& operator=(const UIData&) = delete;
    };

    template<typename T>
    WidgetID UIData::iAdd(T& widget) {
        static_assert(std::is_base_of<Widget, T>::value, "ERROR: T must derive from Widget (UIData::add)");

        auto& manager = std::get<WidgetManager<T>>(m_managers);
        WidgetID id = randomID();
        manager.add(id, widget);

        return id;
    }

}

#endif
