#pragma once

#include <initializer_list>
#include <vector>

#include <xtensor/xadapt.hpp>

#include "types.h"

namespace cx {

struct Point
{
    using Sca = types::Sca;
    using Vec = types::Vec;

    Point() = delete;

    Point( std::initializer_list< Sca > const& cmps )
        : m_components( xt::adapt( std::vector< Sca >( cmps ) ) )
    {
    }

    auto size() -> usize
    {
        return m_components.size();
    }

private:
    Vec m_components;
};

}
