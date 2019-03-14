// Generated by gmmproc 2.54.0 -- DO NOT MODIFY!
#ifndef _GIOMM_NETWORKADDRESS_H
#define _GIOMM_NETWORKADDRESS_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2007 The giomm Development Team
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
#include <giomm/socketconnectable.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GNetworkAddress = struct _GNetworkAddress;
using GNetworkAddressClass = struct _GNetworkAddressClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class NetworkAddress_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** A SocketConnectable for resolving hostnames
 *
 * NetworkAddress provides an easy way to resolve a hostname and then attempt to
 * connect to that host, handling the possibility of multiple IP addresses and
 * multiple address families.
 *
 * @newin{2,24}
 * @ingroup NetworkIO
 */

class NetworkAddress : public Glib::Object,
    public SocketConnectable
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = NetworkAddress;
  using CppClassType = NetworkAddress_Class;
  using BaseObjectType = GNetworkAddress;
  using BaseClassType = GNetworkAddressClass;

  // noncopyable
  NetworkAddress(const NetworkAddress&) = delete;
  NetworkAddress& operator=(const NetworkAddress&) = delete;

private:  friend class NetworkAddress_Class;
  static CppClassType networkaddress_class_;

protected:
  explicit NetworkAddress(const Glib::ConstructParams& construct_params);
  explicit NetworkAddress(GNetworkAddress* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  NetworkAddress(NetworkAddress&& src) noexcept;
  NetworkAddress& operator=(NetworkAddress&& src) noexcept;

  ~NetworkAddress() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GNetworkAddress*       gobj()       { return reinterpret_cast<GNetworkAddress*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GNetworkAddress* gobj() const { return reinterpret_cast<GNetworkAddress*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GNetworkAddress* gobj_copy();

private:

  
    explicit NetworkAddress(const std::string& hostname, guint16 port);


public:
  
  static Glib::RefPtr<NetworkAddress> create(const std::string& hostname, guint16 port);


  /** Gets @a addr's hostname. This might be either UTF-8 or ASCII-encoded,
   * depending on what @a addr was created with.
   * 
   * @newin{2,22}
   * 
   * @return  @a addr's hostname.
   */
  std::string get_hostname() const;
  
  /** Gets @a addr's port number
   * 
   * @newin{2,22}
   * 
   * @return  @a addr's port (which may be 0).
   */
  guint16 get_port() const;
  
  /** Gets @a addr's scheme
   * 
   * @newin{2,26}
   * 
   * @return  @a addr's scheme (<tt>nullptr</tt> if not built from URI).
   */
  std::string get_scheme() const;

  static Glib::RefPtr<NetworkAddress> parse(const std::string& host_and_port, guint16 default_port);

  /** Hostname to resolve.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< std::string > property_hostname() const;


  /** Network port.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< guint > property_port() const;


  /** URI Scheme.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< std::string > property_scheme() const;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::NetworkAddress
   */
  Glib::RefPtr<Gio::NetworkAddress> wrap(GNetworkAddress* object, bool take_copy = false);
}


#endif /* _GIOMM_NETWORKADDRESS_H */

