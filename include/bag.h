#ifndef BAG_H
#define BAG_H

#include <cstddef>
#include <vector>

/**
 * @tparam ItemType the type of item that can be placed in this Bag.
 * @pre ItemType has a default constructor.
 */
template < typename ItemType >
class Bag
{
public:
    /**
     * Destroys this object and frees memory allocated to the object.
     * (See C++ Interlude 2)
     */
    ~Bag( ) = default;

    /**
     * Gets the current number of entries in this bag.
     * @return The number of entries currently in this bag.
     */
    [[nodiscard]] virtual auto getCurrentSize( ) const -> std::size_t = 0;

    /**
     * Sees whether this bag is empty.
     * @return True if the bag is empty, or false if not.
     */
    [[nodiscard]] virtual auto isEmpty( ) const -> bool = 0;

    /**
     * Adds a new item to this bag.
     * @post  If successful, someItem is stored in the bag and the count of items in the bag has increased by 1.
     * @param someItem  The object to be added as a new entry.
     * @return True if addition was successful, or false if not.
     */
    virtual auto add( const ItemType &someItem ) -> bool = 0;

    /**
     * Removes one occurrence of a given entry from this bag, if possible.
     * @post  @post  If successful, someItem has been removed from the bag and the count of items in the bag has decreased by 1.
     * @param someItem  The entry to be removed.
     * @return True if removal was successful, or false if not.
     */
    virtual auto remove( const ItemType &someItem ) -> bool = 0;

    /**
     * Removes all entries from this bag.
     * @post  Bag contains no items, and the count of items is 0.
     */
    virtual void clear( ) = 0;

    /**
     * Counts the number of times a given entry appears in bag.
     * @param target  The entry to be counted.
     * @return  The number of times target appears in the bag.
     */
    virtual auto getFrequencyOf( const ItemType &target ) const -> std::size_t = 0;

    /**
     * Tests whether this bag contains a given item.
     * @param target  The entry to locate.
     * @return  True if bag contains target, or false otherwise.
     */
    virtual auto contains( const ItemType &target ) const -> bool = 0;

    /**
     * Creates a new vector with all entries that are in this bag.
     * @return  A vector containing all the entries in the bag.
     */
    virtual auto toVector( ) const -> std::vector< ItemType > = 0;
};

#endif
