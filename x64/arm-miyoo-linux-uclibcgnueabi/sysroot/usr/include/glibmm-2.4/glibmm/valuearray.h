// Generated by gmmproc 2.54.0 -- DO NOT MODIFY!
#ifndef _GLIBMM_VALUEARRAY_H
#define _GLIBMM_VALUEARRAY_H

#include <glibmmconfig.h>

#ifndef GLIBMM_DISABLE_DEPRECATED


/* Copyright (C) 2002-2009 The gtkmm Development Team
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


#include <glib-object.h>
#include <glibmm/value.h>
#include <sigc++/functors/slot.h>

 
 // This whole file is deprecated.

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GValueArray GValueArray; }
#endif

namespace Glib
{

/** A container structure to maintain an array of generic values.
 * The prime purpose of a ValueArray is for it to be used as an object property
 * that holds an array of values. A ValueArray wraps an array of ValueBase
 * elements.
 *
 * @newin{2,22}
 *
 * @deprecated Use std::vector<Glib::ValueBase*> or std::vector< Glib::Value<> >
 *             instead of Glib::ValueArray.
 */
class ValueArray
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = ValueArray;
  using BaseObjectType = GValueArray;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type() G_GNUC_CONST;


  explicit ValueArray(GValueArray* gobject, bool make_a_copy = true);

  ValueArray(const ValueArray& other);
  ValueArray& operator=(const ValueArray& other);

  ValueArray(ValueArray&& other) noexcept;
  ValueArray& operator=(ValueArray&& other) noexcept;

  ~ValueArray() noexcept;

  void swap(ValueArray& other) noexcept;

  ///Provides access to the underlying C instance.
  GValueArray*       gobj()       { return gobject_; }

  ///Provides access to the underlying C instance.
  const GValueArray* gobj() const { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  GValueArray* gobj_copy() const;

protected:
  GValueArray* gobject_;

private:

  
public:
  /** For example,
   *  int on_compare(const Glib::ValueBase& v1, const Glib::ValueBase& v2);.
   *  The compare function should return -1 if v1 < v2, 0 if v1 == v2, and 1 if
   *  v1 > v2.
   */
  using SlotCompare = sigc::slot<int, const Glib::ValueBase&, const Glib::ValueBase&>;

  /** Default constructor.  Constructs a new array with no pre-allocation.
   */
  ValueArray();

  /** Constructs a new array with pre-allocation.
   */
  ValueArray(guint n_preallocated);

  /** Return the value at @a index contained in the value array.
   * @param index Index of the value of interest.
   * @param value An uninitialized ValueBase in which to store the result.  If
   * the get is successful, @a value will be valid, otherwise it will remain
   * uninitialized.
   * @return whether the get was successful or not.
   */
  bool get_nth(guint index, Glib::ValueBase& value);
  

  /** Insert a copy of @a value as last element of @a value_array. If @a value is
   * <tt>nullptr</tt>, an uninitialized value is appended.
   * 
   * Deprecated: 2.32: Use Array and Glib::array_append_val() instead.
   * 
   * @param value Value to copy into ValueArray, or <tt>nullptr</tt>.
   * @return The ValueArray passed in as @a value_array.
   */

  Glib::ValueArray& append(const Glib::ValueBase& value);

  
  /** Insert a copy of @a value as first element of @a value_array. If @a value is
   * <tt>nullptr</tt>, an uninitialized value is prepended.
   * 
   * 
   * Deprecated: 2.32: Use Array and Glib::array_prepend_val() instead.
   * 
   * @param value Value to copy into ValueArray, or <tt>nullptr</tt>.
   * @return The ValueArray passed in as @a value_array.
   */

  Glib::ValueArray& prepend(const Glib::ValueBase& value);

  
  /** Insert a copy of @a value at specified position into @a value_array. If @a value
   * is <tt>nullptr</tt>, an uninitialized value is inserted.
   * 
   * Deprecated: 2.32: Use Array and Glib::array_insert_val() instead.
   * 
   * @param index Insertion position, must be <= value_array->;n_values.
   * @param value Value to copy into ValueArray, or <tt>nullptr</tt>.
   * @return The ValueArray passed in as @a value_array.
   */

  Glib::ValueArray& insert(guint index, const Glib::ValueBase& value);

  
  /** Remove the value at position @a index from @a value_array.
   * 
   * Deprecated: 2.32: Use Array and g_array_remove_index() instead.
   * 
   * @param index Position of value to remove, which must be less than
   *  @a value_array->n_values.
   * @return The ValueArray passed in as @a value_array.
   */

  Glib::ValueArray& remove(guint index);

  
  /** Sort @a value_array using @a compare_func to compare the elements according to
   * the semantics of CompareFunc.
   * 
   * The current implementation uses the same sorting algorithm as standard
   * C qsort() function.
   * 
   * Deprecated: 2.32: Use Array and g_array_sort().
   * 
   * @param compare_func Function to compare elements.
   * @return The ValueArray passed in as @a value_array.
   */

  Glib::ValueArray& sort(const SlotCompare& compare_func);
  

};

} //namespace Glib


namespace Glib
{

/** @relates Glib::ValueArray
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 */
inline void swap(ValueArray& lhs, ValueArray& rhs) noexcept
  { lhs.swap(rhs); }

} // namespace Glib

namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Glib::ValueArray
 */
Glib::ValueArray wrap(GValueArray* object, bool take_copy = false);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class Value<Glib::ValueArray> : public Glib::Value_Boxed<Glib::ValueArray>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif // GLIBMM_DISABLE_DEPRECATED


#endif /* _GLIBMM_VALUEARRAY_H */

