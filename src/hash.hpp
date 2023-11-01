#ifndef TEMPLATE_META_PROGRAMMING_HASH_HPP
#define TEMPLATE_META_PROGRAMMING_HASH_HPP

// Hash function based on
// https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function#FNV-1a_hash

#include <cstddef>
#include <string_view>

template<typename STR>
constexpr size_t hashString64(const STR &strToHash)
{
    static_assert(sizeof(size_t) == 8);
    size_t result = 0xcbf29ce484222325;

    for(char c : strToHash) {
        result ^= c;
        result *= 0x00000100000001B3;
    }

    return result;
}

template<size_t N>
constexpr size_t hashString64(const char(&strToHash)[N])
{
    return hashString(std::string_view(strToHash));
}

template<typename STR>
constexpr uint32_t hashString32(const STR &strToHash)
{
    static_assert(sizeof(uint32_t) == 4);
    uint32_t result = 0x811c9dc5;

    for(char c : strToHash) {
        result ^= c;
        result *= 0x01000193;
    }

    return result;
}

template<size_t N>
constexpr uint32_t hashString32(const char(&strToHash)[N])
{
    return hashString(std::string_view(strToHash));
}

#endif // TEMPLATE_META_PROGRAMMING_HASH_HPP