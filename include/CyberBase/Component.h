#pragma once

#include "CyberBase/pointer.h"

namespace cc{
    template<class T,class Id>
    class ComponentManager{
    public:
        T& create(Id id){
            if(id.value() >= m_data.size()){
                m_data.resize(id.value()+1);
            }

            m_data[id.value()] = T{};

            return m_data[id.value()].value();
        }

        void destroy(Id id){
            m_data[id.value()].reset();
        }

        cc::OptionalRef<T> get(Id id){
            if(id.value() >= m_data.size()){
                return {};
            }
            return m_data[id.value()];
        }

    private:
        std::vector<std::optional<T>> m_data;
    };
}
