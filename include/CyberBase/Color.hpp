#pragma once

namespace cb 
{
    template<class T>
    class ColorRGB{
    public:
        T red, green, blue;
    };

    template<class T>
    class ColorRGBA{
    public:
        T red, green, blue, alpha;
    };

    using ColorRGBf = ColorRGB<float>;
    using ColorRGBu8 = ColorRGB<unsigned int>;

    using ColorRGBAf = ColorRGBA<float>;
    using ColorRGBAu8 = ColorRGBA<unsigned int>;

    using Color = ColorRGBAu8;

    constexpr Color BLACK{0,0,0,255};
    constexpr Color RED{255,0,0,255};
}
