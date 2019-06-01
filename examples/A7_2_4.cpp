#include <cstdint>

enum class Enum1 : std::uint32_t {
    One,
    Two = 2,
    Three
};

enum class Enum2 : std::uint32_t {
    One,
    Two,
    Three
};

enum class Enum3 : std::uint32_t {
    One = 1,
    Two,
    Three
};

enum class Enum4 : std::uint32_t {
    One = 1,
    Two = 2,
    Three = 3
};

