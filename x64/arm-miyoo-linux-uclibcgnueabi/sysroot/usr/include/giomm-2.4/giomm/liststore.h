// Generated by gmmproc 2.54.0 -- DO NOT MODIFY!
#ifndef _GIOMM_LISTSTORE_H
#define _GIOMM_LISTSTORE_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2016 The giomm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <glibmm/object.h>
#include <giomm/listmodel.h>
#include <vector>
#include <type_traits>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class ListStoreBase_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** A simple implementation of Gio::ListModel that stores all items in memory.
 *
 * The templated subclass ListStore<> provides better compile-time type safety.
 *
 * It provides insertions, deletions, and lookups in logarithmic time
 * with a fast path for the common case of iterating the list linearly.
 *
 * @newin{2,50}
 */

class ListStoreBase
: public Glib::Object,
  public ListModel
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ListStoreBase;
  using CppClassType = ListStoreBase_Class;
  using BaseObjectType = GListStore;
  using BaseClassType = GListStoreClass;

  // noncopyable
  ListStoreBase(const ListStoreBase&) = delete;
  ListStoreBase& operator=(const ListStoreBase&) = delete;

private:  friend class ListStoreBase_Class;
  static CppClassType liststorebase_class_;

protected:
  explicit ListStoreBase(const Glib::ConstructParams& construct_params);
  explicit ListStoreBase(GListStore* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ListStoreBase(ListStoreBase&& src) noexcept;
  ListStoreBase& operator=(ListStoreBase&& src) noexcept;

  ~ListStoreBase() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GListStore*       gobj()       { return reinterpret_cast<GListStore*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GListStore* gobj() const { return reinterpret_cast<GListStore*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GListStore* gobj_copy();

private:

  
protected:
    explicit ListStoreBase(GType item_type);


public:
  
  static Glib::RefPtr<ListStoreBase> create(GType item_type);


  /** Inserts @a item into @a store at @a position. @a item must be of type
   * ListStore::property_item_type() or derived from it. @a position must be smaller
   * than the length of the list, or equal to it to append.
   * 
   * This function takes a ref on @a item.
   * 
   * Use g_list_store_splice() to insert multiple items at the same time
   * efficiently.
   * 
   * @newin{2,50}
   * 
   * @param position The position at which to insert the new item.
   * @param item The new item.
   */
  void insert(guint position, const Glib::RefPtr<Glib::ObjectBase>& item);

  /** A slot that will be called to compare two items.
   * The slot should return a negative integer if the first item comes before the second,
   * 0 if they are equal, or a positive integer if the first value comes after the second.
   * For instance,
   * @code
   * int on_compare_item(const Glib::RefPtr<const Glib::ObjectBase>& item1, const Glib::RefPtr<const Glib::ObjectBase>& item2);
   * @endcode
   *
   * @newin{2,50}
   */
  using SlotCompare = sigc::slot<int, const Glib::RefPtr<const Glib::ObjectBase>&, const Glib::RefPtr<const Glib::ObjectBase>&>;

  
  /** Inserts @a item into @a store at a position to be determined by the
   *  @a slot.
   * 
   * The list must already be sorted before calling this function or the
   * result is undefined.  Usually you would approach this by only ever
   * inserting items by way of this function.
   * 
   * This function takes a ref on @a item.
   * 
   * @newin{2,50}
   * 
   * @param item The new item.
   * @param slot Pairwise comparison function for sorting.
   * @return The position at which @a item was inserted.
   */
  guint insert_sorted(const Glib::RefPtr<Glib::ObjectBase>& item, const SlotCompare& slot);

  
  /** Sort the items in @a store according to @a slot.
   * 
   * @newin{2,50}
   * 
   * @param slot Pairwise comparison function for sorting.
   */
  void sort(const SlotCompare& slot);

  
  /** Appends @a item to @a store. @a item must be of type ListStore::property_item_type().
   * 
   * This function takes a ref on @a item.
   * 
   * Use g_list_store_splice() to append multiple items at the same time
   * efficiently.
   * 
   * @newin{2,50}
   * 
   * @param item The new item.
   */
  void append(const Glib::RefPtr<Glib::ObjectBase>& item);
  
  /** Removes the item from @a store that is at @a position. @a position must be
   * smaller than the current length of the list.
   * 
   * Use g_list_store_splice() to remove multiple items at the same time
   * efficiently.
   * 
   * @newin{2,50}
   * 
   * @param position The position of the item that is to be removed.
   */
  void remove(guint position);
  
  /** Removes all items from @a store.
   * 
   * @newin{2,50}
   */
  void remove_all();

  /** Removes @a n_removals items and adds @a additions.size() items.
   * @a additions must contain items of type property_item_type() or derived from it.
   * Empty RefPtr is not permitted.
   *
   * This function is more efficient than insert() and remove(), because it only emits
   * ListModel::signal_items_changed() once for the change.
   *
   * The parameters @a position and @a n_removals must be correct (i.e.
   * @a position + @a n_removals must be less than or equal to the length of
   * the list at the time this function is called).
   *
   * @newin{2,50}
   *
   * @param position The position at which to make the change.
   * @param n_removals The number of items to remove.
   * @param additions The items to add.
   */
  void splice(guint position, guint n_removals,
    const std::vector<Glib::RefPtr<Glib::ObjectBase>>& additions);
  

  /** The type of items contained in this list store. Items must be
   * subclasses of Object.
   * 
   * @newin{2,50}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< GType > property_item_type() const;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


}; // end class ListStoreBase

/** A simple implementation of Gio::ListModel that stores all items in memory.
 *
 * It provides insertions, deletions, and lookups in logarithmic time
 * with a fast path for the common case of iterating the list linearly.
 *
 * @newin{2,50}
 *
 * @tparam T_item Base class of the items in the ListStore. All items must
 *                be of type T_item or a type derived from T_item.
 *                T_item must be Glib::Object or a type derived from Glib::Object.
 */
template <typename T_item>
class ListStore : public ListStoreBase
{
  static_assert(std::is_base_of<Glib::Object, T_item>::value,
    "T_item must be Glib::Object or derived from Glib::Object.");

protected:
  ListStore();

public:
  static Glib::RefPtr<ListStore> create();

  /** Get the item at @a position.
   * If @a position is greater than or equal to the number of
   * items in @a list, an empty Glib::RefPtr is returned.
   *
   * An empty Glib::RefPtr is never returned for an index that is less than the length
   * of the list.  See ListModel::get_n_items().
   *
   * @newin{2,50}
   *
   * @param position The position of the item to fetch.
   * @return The object at @a position.
   */
  Glib::RefPtr<T_item> get_item(guint position);

  /** Get the item at @a position.
   * If @a position is greater than or equal to the number of
   * items in @a list, an empty Glib::RefPtr is returned.
   *
   * An empty Glib::RefPtr is never returned for an index that is less than the length
   * of the list.  See ListModel::get_n_items().
   *
   * @newin{2,50}
   *
   * @param position The position of the item to fetch.
   * @return The object at @a position.
   */
  Glib::RefPtr<const T_item> get_item(guint position) const;

  /** Inserts @a item at @a position.
   * @a item must be of type ListStoreBase::property_item_type() or derived from it.
   * @a position must be smaller than the length of the list, or equal to it to append.
   *
   * Use splice() to insert multiple items at the same time efficiently.
   *
   * @newin{2,50}
   *
   * @param position The position at which to insert the new item.
   * @param item The new item.
   */
  void insert(guint position, const Glib::RefPtr<T_item>& item);

  /** A slot that will be called to compare two items.
   * The slot should return a negative integer if the first item comes before the second,
   * 0 if they are equal, or a positive integer if the first value comes after the second.
   * For instance,
   * @code
   * int on_compare_item(const Glib::RefPtr<const T_item>& item1, const Glib::RefPtr<const T_item>& item2);
   * @endcode
   *
   * @newin{2,50}
   */
  using SlotCompare = sigc::slot<int, const Glib::RefPtr<const T_item>&, const Glib::RefPtr<const T_item>&>;

  /** Inserts @a item at a position to be determined by the @a slot.
   *
   * The list must already be sorted before calling this function or the
   * result is undefined.  Usually you would approach this by only ever
   * inserting items by way of this function.
   *
   * @newin{2,50}
   *
   * @param item The new item.
   * @param slot Pairwise comparison function for sorting.
   * @return The position at which @a item was inserted.
   */
  guint insert_sorted(const Glib::RefPtr<T_item>& item, const SlotCompare& slot);

  /** Sorts the items according to @a slot.
   *
   * @newin{2,50}
   *
   * @param slot Pairwise comparison function for sorting.
   */
  void sort(const SlotCompare& slot);

  /** Appends @a item.
   * @a item must be of type ListStoreBase::property_item_type() or derived from it.
   *
   * Use splice() to append multiple items at the same time efficiently.
   *
   * @newin{2,50}
   *
   * @param item The new item.
   */
  void append(const Glib::RefPtr<T_item>& item);

  /** Removes @a n_removals items and adds @a additions.size() items.
   * @a additions must contain items of type ListStoreBase::property_item_type()
   * or derived from it. Empty RefPtr is not permitted.
   *
   * This function is more efficient than insert() and remove(), because it only emits
   * ListModel::signal_items_changed() once for the change.
   *
   * The parameters @a position and @a n_removals must be correct (i.e.
   * @a position + @a n_removals must be less than or equal to the length of
   * the list at the time this function is called).
   *
   * @newin{2,50}
   *
   * @param position The position at which to make the change.
   * @param n_removals The number of items to remove.
   * @param additions The items to add.
   */
  void splice(guint position, guint n_removals,
    const std::vector<Glib::RefPtr<T_item>>& additions);

private:
  static int compare_data_func(gconstpointer a, gconstpointer b, gpointer user_data);
}; // end class ListStore

#ifndef DOXYGEN_SHOULD_SKIP_THIS

template <typename T_item>
ListStore<T_item>::ListStore()
: ListStoreBase(T_item::get_base_type())
{ }

template <typename T_item>
Glib::RefPtr<ListStore<T_item>> ListStore<T_item>::create()
{
  return Glib::RefPtr<ListStore<T_item>>(new ListStore<T_item>());
}

template <typename T_item>
Glib::RefPtr<T_item> ListStore<T_item>::get_item(guint position)
{
  return Glib::RefPtr<T_item>::cast_dynamic(ListModel::get_object(position));
}

template <typename T_item>
Glib::RefPtr<const T_item> ListStore<T_item>::get_item(guint position) const
{
  return const_cast<ListStore<T_item>*>(this)->get_item(position);
}

template <typename T_item>
void ListStore<T_item>::insert(guint position, const Glib::RefPtr<T_item>& item)
{
  ListStoreBase::insert(position, item);
}

template <typename T_item>
guint ListStore<T_item>::insert_sorted(
  const Glib::RefPtr<T_item>& item, const SlotCompare& slot)
{
  // Use the original slot (not a copy).
  auto slot_copy = const_cast<SlotCompare*>(&slot);

  return g_list_store_insert_sorted(gobj(), item->gobj(), &compare_data_func, slot_copy);
}

template <typename T_item>
void ListStore<T_item>::sort(const SlotCompare& slot)
{
  // Use the original slot (not a copy).
  auto slot_copy = const_cast<SlotCompare*>(&slot);

  g_list_store_sort(gobj(), &compare_data_func, slot_copy);
}

template <typename T_item>
void ListStore<T_item>::append(const Glib::RefPtr<T_item>& item)
{
  ListStoreBase::append(item);
}

template <typename T_item>
void ListStore<T_item>::splice(guint position, guint n_removals,
  const std::vector<Glib::RefPtr<T_item>>& additions)
{
  const std::size_t n_additions = additions.size();
  std::unique_ptr<gpointer[]> g_additions{new gpointer[n_additions]};
  for (std::size_t i = 0; i < n_additions; i++)
  {
    g_additions[i] = additions[i]->gobj();
  }
  g_list_store_splice(gobj(), position, n_removals, g_additions.get(), n_additions);
}

template <typename T_item>
int ListStore<T_item>::compare_data_func(gconstpointer a, gconstpointer b, gpointer user_data)
{
  auto slot = static_cast<SlotCompare*>(user_data);

  // cast_dynamic is necessary if T_item is a user-derived class, such as
  // class MyObject : public Glib::Object
  const Glib::RefPtr<const T_item> item_a = Glib::RefPtr<T_item>::cast_dynamic(
    Glib::wrap(static_cast<typename T_item::BaseObjectType*>(const_cast<gpointer>(a)), true));
  const Glib::RefPtr<const T_item> item_b = Glib::RefPtr<T_item>::cast_dynamic(
    Glib::wrap(static_cast<typename T_item::BaseObjectType*>(const_cast<gpointer>(b)), true));

  return (*slot)(item_a, item_b);
}

#endif // DOXYGEN_SHOULD_SKIP_THIS

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::ListStoreBase
   */
  Glib::RefPtr<Gio::ListStoreBase> wrap(GListStore* object, bool take_copy = false);
}


#endif /* _GIOMM_LISTSTORE_H */

