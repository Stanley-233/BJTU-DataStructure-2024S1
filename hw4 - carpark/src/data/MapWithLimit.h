//
// Created by stanl on 24-10-15.
//

#ifndef MAPWITHLIMIT_H
#define MAPWITHLIMIT_H

#include <QMap>
#include <QMutex>
#include <stdexcept>

template<typename K, typename V>
class MapWithLimit {
public:
    MapWithLimit(size_t maxSize) : maxSize(maxSize) {}

    void insert(const K& key, const V& value) {
        if (data.size() >= maxSize) {
            throw std::overflow_error("MAP_WITH_LIMIT::MAX_SIZE_EXCEEDED");
        }
        data.insert(key, value);
    }

    void erase(const K& key) {
        data.remove(key);
    }

    V get(const K& key) {
        return data.value(key);
    }

    [[nodiscard]] size_t size() const {
        return data.size();
    }

    bool empty() const {
        return data.isEmpty();
    }

    bool full() const {
        return data.size() == maxSize;
    }

    K firstKey() const {
        return data.firstKey();
    }

    QPair<K, V> first() const {
        if (data.isEmpty()) {
            throw std::runtime_error("MAP_WITH_LIMIT::EMPTY");
        }
        return QPair<K, V>(data.key(data.begin().value()), data.begin().value());
    }

private:
    QMap<K, V> data;
    size_t maxSize;
};

#endif //MAPWITHLIMIT_H
