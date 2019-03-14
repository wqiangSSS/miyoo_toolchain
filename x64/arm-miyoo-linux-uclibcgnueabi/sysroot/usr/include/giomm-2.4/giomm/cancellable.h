// Generated by gmmproc 2.54.0 -- DO NOT MODIFY!
#ifndef _GIOMM_CANCELLABLE_H
#define _GIOMM_CANCELLABLE_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2007 The gtkmm Development Team
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


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GCancellable = struct _GCancellable;
using GCancellableClass = struct _GCancellableClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class Cancellable_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** Allows actions to be cancelled.
 * Cancellable is a thread-safe operation cancellation stack used throughout GIO to allow for cancellation of synchronous and asynchronous operations.
 *
 * @newin{2,16}
 */

class Cancellable : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Cancellable;
  using CppClassType = Cancellable_Class;
  using BaseObjectType = GCancellable;
  using BaseClassType = GCancellableClass;

  // noncopyable
  Cancellable(const Cancellable&) = delete;
  Cancellable& operator=(const Cancellable&) = delete;

private:  friend class Cancellable_Class;
  static CppClassType cancellable_class_;

protected:
  explicit Cancellable(const Glib::ConstructParams& construct_params);
  explicit Cancellable(GCancellable* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Cancellable(Cancellable&& src) noexcept;
  Cancellable& operator=(Cancellable&& src) noexcept;

  ~Cancellable() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GCancellable*       gobj()       { return reinterpret_cast<GCancellable*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GCancellable* gobj() const { return reinterpret_cast<GCancellable*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GCancellable* gobj_copy();

private:


protected:
  Cancellable();

public:
  using SlotCancelledCallback = sigc::slot<void>;

  
  static Glib::RefPtr<Cancellable> create();


  /** Checks if a cancellable job has been cancelled.
   * 
   * @return <tt>true</tt> if @a cancellable is cancelled,
   * <tt>false</tt> if called with <tt>nullptr</tt> or if item is not cancelled.
   */
  bool is_cancelled() const;

  
  //May return -1 if fds not supported, or on errors .
  
  /** Gets the file descriptor for a cancellable job. This can be used to
   * implement cancellable operations on Unix systems. The returned fd will
   * turn readable when @a cancellable is cancelled.
   * 
   * You are not supposed to read from the fd yourself, just check for
   * readable status. Reading to unset the readable status is done
   * with g_cancellable_reset().
   * 
   * After a successful return from this function, you should use 
   * g_cancellable_release_fd() to free up resources allocated for 
   * the returned file descriptor.
   * 
   * See also g_cancellable_make_pollfd().
   * 
   * @return A valid file descriptor. %-1 if the file descriptor 
   * is not supported, or on errors.
   */
  int get_fd() const;

  
  /** Creates a PollFD corresponding to @a cancellable; this can be passed
   * to Glib::poll() and used to poll for cancellation. This is useful both
   * for unix systems without a native poll and for portability to
   * windows.
   * 
   * When this function returns <tt>true</tt>, you should use 
   * g_cancellable_release_fd() to free up resources allocated for the 
   *  @a pollfd. After a <tt>false</tt> return, do not call g_cancellable_release_fd().
   * 
   * If this function returns <tt>false</tt>, either no @a cancellable was given or
   * resource limits prevent this function from allocating the necessary 
   * structures for polling. (On Linux, you will likely have reached 
   * the maximum number of file descriptors.) The suggested way to handle
   * these cases is to ignore the @a cancellable.
   * 
   * You are not supposed to read from the fd yourself, just check for
   * readable status. Reading to unset the readable status is done
   * with g_cancellable_reset().
   * 
   * @newin{2,22}
   * 
   * @param pollfd A pointer to a PollFD.
   * @return <tt>true</tt> if @a pollfd was successfully initialized, <tt>false</tt> on 
   * failure to prepare the cancellable.
   */
  bool make_pollfd(GPollFD* pollfd);
  
  /** Releases a resources previously allocated by g_cancellable_get_fd()
   * or g_cancellable_make_pollfd().
   * 
   * For compatibility reasons with older releases, calling this function 
   * is not strictly required, the resources will be automatically freed
   * when the @a cancellable is finalized. However, the @a cancellable will
   * block scarce file descriptors until it is finalized if this function
   * is not called. This can cause the application to run out of file 
   * descriptors when many Cancellables are used at the same time.
   * 
   * @newin{2,22}
   */
  void release_fd();

  //This is safe to call from another thread.
  
  /** Will set @a cancellable to cancelled, and will emit the
   * Cancellable::signal_cancelled() signal. (However, see the warning about
   * race conditions in the documentation for that signal if you are
   * planning to connect to it.)
   * 
   * This function is thread-safe. In other words, you can safely call
   * it from a thread other than the one running the operation that was
   * passed the @a cancellable.
   * 
   * If @a cancellable is <tt>nullptr</tt>, this function returns immediately for convenience.
   * 
   * The convention within GIO is that cancelling an asynchronous
   * operation causes it to complete asynchronously. That is, if you
   * cancel the operation from the same thread in which it is running,
   * then the operation's SlotAsyncReady will not be invoked until
   * the application returns to the main loop.
   */
  void cancel();

  
  /** Gets the top cancellable from the stack.
   * 
   * @return A Cancellable from the top
   * of the stack, or <tt>nullptr</tt> if the stack is empty.
   */
  static Glib::RefPtr<Cancellable> get_current();

  
  /** Pushes @a cancellable onto the cancellable stack. The current
   * cancellable can then be received using g_cancellable_get_current().
   * 
   * This is useful when implementing cancellable operations in
   * code that does not allow you to pass down the cancellable object.
   * 
   * This is typically called automatically by e.g. File operations,
   * so you rarely have to call this yourself.
   */
  void push_current();
  
  /** Pops @a cancellable off the cancellable stack (verifying that @a cancellable
   * is on the top of the stack).
   */
  void pop_current();
  
  /** Resets @a cancellable to its uncancelled state.
   * 
   * If cancellable is currently in use by any cancellable operation
   * then the behavior of this function is undefined.
   * 
   * Note that it is generally not a good idea to reuse an existing
   * cancellable for more operations after it has been cancelled once,
   * as this function might tempt you to do. The recommended practice
   * is to drop the reference to a cancellable after cancelling it,
   * and let it die with the outstanding async operations. You should
   * create a fresh cancellable for further async operations.
   */
  void reset();

  /** Convenience function to connect to the Cancellable::signal_cancelled()
   * signal. Also handles the race condition that may happen
   * if the cancellable is cancelled right before connecting.
   *
   * @a slot is called at most once, either directly at the
   * time of the connect if @a cancellable is already cancelled,
   * or when @a cancellable is cancelled in some thread.
   *
   * See Cancellable::signal_cancelled() for details on how to use this.
   *
   * @newin{2,22}
   *
   * @param slot The slot to connect.
   * @return The id of the signal handler or 0 if @a cancellable has already
   * been cancelled.
   */
  gulong connect(const SlotCancelledCallback& slot);
  

  /** Disconnects a handler from a cancellable instance similar to
   * Glib::signal_handler_disconnect().  Additionally, in the event that a
   * signal handler is currently running, this call will block until the
   * handler has finished.  Calling this function from a
   * Cancellable::signal_cancelled() signal handler will therefore result in a
   * deadlock.
   * 
   * This avoids a race condition where a thread cancels at the
   * same time as the cancellable operation is finished and the
   * signal handler is removed. See Cancellable::signal_cancelled() for
   * details on how to use this.
   * 
   * If @a cancellable is <tt>nullptr</tt> or @a handler_id is %0 this function does
   * nothing.
   * 
   * @newin{2,22}
   * 
   * @param handler_id Handler id of the handler to be disconnected, or %0.
   */
  void disconnect(gulong handler_id);

  
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%cancelled()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the operation has been cancelled.
   * 
   * Can be used by implementations of cancellable operations. If the
   * operation is cancelled from another thread, the signal will be
   * emitted in the thread that cancelled the operation, not the
   * thread that is running the operation.
   * 
   * Note that disconnecting from this signal (or any signal) in a
   * multi-threaded program is prone to race conditions. For instance
   * it is possible that a signal handler may be invoked even after
   * a call to Glib::signal_handler_disconnect() for that handler has
   * already returned.
   * 
   * There is also a problem when cancellation happens right before
   * connecting to the signal. If this happens the signal will
   * unexpectedly not be emitted, and checking before connecting to
   * the signal leaves a race condition where this is still happening.
   * 
   * In order to make it safe and easy to connect handlers there
   * are two helper functions: g_cancellable_connect() and
   * g_cancellable_disconnect() which protect against problems
   * like this.
   * 
   * An example of how to us this:
   * 
   * [C example ellipted]
   * 
   * Note that the cancelled signal is emitted in the thread that
   * the user cancelled from, which may be the main thread. So, the
   * cancellable signal should not do something that can block.
   */

  Glib::SignalProxy< void > signal_cancelled();


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_cancelled().
  virtual void on_cancelled();


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
   * @relates Gio::Cancellable
   */
  Glib::RefPtr<Gio::Cancellable> wrap(GCancellable* object, bool take_copy = false);
}


#endif /* _GIOMM_CANCELLABLE_H */

