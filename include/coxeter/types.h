#pragma once

#include <cstddef>
#include <cstdint>
#include <stdfloat>
#include <string>

#include <xtensor/xarray.hpp>

using u64 = uint64_t;
using u32 = uint32_t;
using u16 = uint16_t;
using u8 = uint8_t;

using i64 = int64_t;
using i32 = int32_t;
using i16 = int16_t;
using i8 = int8_t;

using f128 = std::float128_t;
using f64 = std::float64_t;
using f32 = std::float32_t;
using f16 = std::float16_t;

using usize = size_t;
using isize = ptrdiff_t;

using str = std::string;

constexpr u64 KiB = 1024;
constexpr u64 MiB = KiB * KiB;
constexpr u64 GiB = KiB * KiB * KiB;
constexpr u64 TiB = KiB * KiB * KiB * KiB;
constexpr u64 PiB = KiB * KiB * KiB * KiB * KiB;
constexpr u64 EiB = KiB * KiB * KiB * KiB * KiB * KiB;

constexpr auto operator"" _i8( unsigned long long int value ) noexcept -> i8
{
    return static_cast< i8 >( value );
}

constexpr auto operator"" _i16( unsigned long long int value ) noexcept -> i16
{
    return static_cast< i16 >( value );
}

constexpr auto operator"" _i32( unsigned long long int value ) noexcept -> i32
{
    return static_cast< i32 >( value );
}

constexpr auto operator"" _i64( unsigned long long int value ) noexcept -> i64
{
    return static_cast< i64 >( value );
}

constexpr auto operator"" _u8( unsigned long long int value ) noexcept -> u8
{
    return static_cast< u8 >( value );
}

constexpr auto operator"" _u16( unsigned long long int value ) noexcept -> u16
{
    return static_cast< u16 >( value );
}

constexpr auto operator"" _u32( unsigned long long int value ) noexcept -> u32
{
    return static_cast< u32 >( value );
}

constexpr auto operator"" _u64( unsigned long long int value ) noexcept -> u64
{
    return static_cast< u64 >( value );
}

constexpr auto operator"" _f16( long double value ) noexcept -> f16
{
    return static_cast< f16 >( value );
}

constexpr auto operator"" _f32( long double value ) noexcept -> f32
{
    return static_cast< f32 >( value );
}

constexpr auto operator"" _f64( long double value ) noexcept -> f64
{
    return static_cast< f64 >( value );
}

constexpr auto operator"" _f128( long double value ) noexcept -> f128
{
    return static_cast< f128 >( value );
}

namespace cx::types {

// ---------------------------------------------------------------------------
//
//  Templates
//
// ---------------------------------------------------------------------------

template< typename Scalar, usize N = 0 >
struct MatType
{
    using type = typename std::conditional< N == 0, xt::xarray< Scalar >,
        xt::xtensor_fixed< Scalar, xt::xshape< N, N > > >::type;
};

template< typename Scalar, usize N = 0 >
struct VecType
{
    using type = typename std::conditional< N == 0, xt::xarray< Scalar >,
        xt::xtensor_fixed< Scalar, xt::xshape< N > > >::type;
};

template< typename Scalar, usize N = 0 >
using MatType_t = typename MatType< Scalar, N >::type;

template< typename Scalar, usize N = 0 >
using VecType_t = typename VecType< Scalar, N >::type;

// ---------------------------------------------------------------------------
//
//  Types
//
// ---------------------------------------------------------------------------

using Sca = f64;

using Mat = MatType_t< Sca >;
using Vec = VecType_t< Sca >;

using Mat3 = MatType_t< Sca, 3 >;
using Mat4 = MatType_t< Sca, 4 >;

using Vec3 = VecType_t< Sca, 3 >;
using Vec4 = VecType_t< Sca, 4 >;

} // namespace types
