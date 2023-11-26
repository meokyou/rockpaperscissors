#pragma once

#include <array>
#include <unordered_set>
#include <cstdint>
#include <iostream>

template <class _Kty>
class OrderStatisticTree {
public:
    OrderStatisticTree(std::initializer_list<_Kty> _Ilist)
    {
        tree = _Ilist;
    }
    void Insert(const _Kty key) const
    {
        tree.insert(key);
    }
    const _Kty Select(const int i) const
    {
        auto it = tree.begin();
        std::advance(it, i);
        return *it;
    }
    std::int64_t Rank(const _Kty key) const
    {
        return std::distance(tree.begin(), tree.find(key));
    }
    const bool Contains(const _Kty key) const {
        return tree.find(key) != tree.end();
    }

private:
    std::unordered_set<_Kty> tree;
};

