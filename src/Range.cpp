//
// Created by jngl on 19/02/2021.
//

#include "CyberBase/Range.h"

namespace cb {
    const char *InvalidRange::what() const noexcept {
        return "Invalid Range";
    }
}
