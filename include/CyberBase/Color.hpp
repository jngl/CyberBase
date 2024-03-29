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

    typedef ColorRGB<float> ColorRGBf;//float(0, 1)
    typedef ColorRGB<unsigned int> ColorRGBu8;//float(0, 255)

    typedef ColorRGBA<float> ColorRGBAf;//float(0, 1)
    typedef ColorRGBA<unsigned int> ColorRGBAu8;//float(0, 255)

    using Color = ColorRGBAu8;

    constexpr Color BLACK{0,0,0,255};
    constexpr Color RED{255,0,0,255};
}
