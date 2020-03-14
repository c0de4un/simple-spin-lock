/**
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
* IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
* PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
**/

#ifndef SLOCK_MUTEX_HPP
#define SLOCK_MUTEX_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Windows
#if defined(WIN32) || defined(WIN64)
#include <Windows.h>
#else // UNIX
#include <cstdlib>
#include <pthread>
#endif

// Include slock
#ifndef SLOCK_HPP
#include "slock.hpp"
#endif // !SLOCK_HPP

// ===========================================================
// TYPES
// ===========================================================

namespace slock
{

	// -----------------------------------------------------------

	// ===========================================================
	// CONFIGS
	// ===========================================================

// Windows
#if defined(WIN32) || defined(WIN64)
using mutex_t = CRITICAL_SECTION;
#else // UNIX
using mutex_t = pthread_mutex_t;
#endif

	// ===========================================================
	// slock::Mutex
	// ===========================================================

	/**
	 * @brief
	 * Mutex - mutex adaptor.
	 * 
	 * @Features:
	 * - RAII;
	 * - safe unlock from destructor;
	 * - platform specific native handler;
	 *
	 * @version 0.1
	 * @authors - Denis Z. (code4un@yandex.ru)
	**/
	class Mutex final
	{

	private:

		// -----------------------------------------------------------

		// ===========================================================
		// FIELDS
		// ===========================================================

		/** Platform-specific mutex native-implementation. **/
		mutex_t mMutex;

		/** Lock-indicator. **/
		slock_abool_t mLocked;

		// ===========================================================
		// DELETED
		// ===========================================================

		Mutex(const Mutex&) = delete;
		Mutex& operator=(const Mutex&) = delete;
		Mutex(Mutex&&) = delete;
		Mutex& operator=(Mutex&&) = delete;

		// -----------------------------------------------------------

	public:

		// -----------------------------------------------------------

		// ===========================================================
		// CONSTRUCTOR & DESTRUCTOR
		// ===========================================================

		/**
		 * @brief
		 * Mutex constructor.
		 * 
		 * @throws - can throw exception.
		**/
		explicit Mutex();

		/**
		 * @brief
		 * Mutex destructor.
		 * 
		 * @throws - can throw exception.
		**/
		~Mutex();

		// ===========================================================
		// GETTERS & SETTERS
		// ===========================================================

		/**
		 * @brief
		 * Returns 'true' if locked.
		 * 
		 * @thread_safety - atomic-flag used.
		 * @throws - no exceptions.
		**/
		bool isLocked() const noexcept;

		/**
		 * @brief
		 * Returns native handle to a mutex.
		 * 
		 * @throws - no exceptions.
		**/
		void* native_handle() noexcept;

		// ===========================================================
		// METHODS
		// ===========================================================

		/**
		 * @brief
		 * Try lock mutex.
		 * Does nothing, if already locked.
		 *
		 * @thread_safety - thread-safe.
		 * @returns - 'true' if locked, false if failed.
		 * @throws - (!) no exceptions.
		**/
		bool try_lock();

		/**
		 * @brief
		 * Lock mutex.
		 *
		 * @thread_safety - thread-safe.
		 * @throws - (!) no exceptions.
		**/
		void lock();

		/**
		 * @brief
		 * Unlock mutex.
		 *
		 * @thread_safety - thread-safe.
		 * @throws - (!) no exceptions.
		**/
		void unlock();

		// -----------------------------------------------------------

	}; /// slock::Mutex

	// -----------------------------------------------------------

} /// slock
using slock_mutex_t = slock::Mutex;
#define SLOCK_MUTEX_DECL

// -----------------------------------------------------------

#endif // !SLOCK_MUTEX_HPP