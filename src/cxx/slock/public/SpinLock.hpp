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

#ifndef SLOCK_SPIN_LOCK_HPP
#define SLOCK_SPIN_LOCK_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// slock
#ifndef SLOCK_HPP
#include "slock.hpp"
#endif // !SLOCK_HPP

// slock::Mutex
#ifndef SLOCK_MUTEX_HPP
#include "Mutex.hpp"
#endif // !SLOCK_MUTEX_HPP

// ===========================================================
// TYPES
// ===========================================================

namespace slock
{

	// -----------------------------------------------------------

	/**
	 * @brief
	 * SpinLock - decorator for thread-lock.
	 * 
	 * @Features:
	 * - spin;
	 * - RAII, mutex atomatically unlocked;
	 *
	 * @version 0.1
	**/
	class SpinLock final
	{

	private:

		// -----------------------------------------------------------

		// ===========================================================
		// CONSTANTS & FIELDS
		// ===========================================================

		static constexpr const unsigned char SPIN_LIMIT = 2;

		/** Mutex. **/
		slock::Mutex* mMutex;

		// ===========================================================
		// DELETED
		// ===========================================================

		SpinLock(const SpinLock&) = delete;
		SpinLock& operator=(const SpinLock&) = delete;
		SpinLock(SpinLock&&) = delete;
		SpinLock& operator=(SpinLock&&) = delete;

		// -----------------------------------------------------------

	public:

		// -----------------------------------------------------------

		// ===========================================================
		// CONSTRUCTORS & DESTRUCTOR
		// ===========================================================

		/**
		 * @brief
		 * SpinLock default constructor.
		 * 
		 * @param pMutex - mutex.
		 * @param defferLock - 'true' for deffer-lock, 'false' to lock.
		 * @throws - no exceptions.
		**/
		explicit SpinLock( slock::Mutex* const pMutex = nullptr, const bool defferLock = false ) SLOCK_NOEXCEPT;

		/**
		 * @brief
		 * SpinLock destructor.
		 * 
		 * @throws - no exceptions.
		**/
		~SpinLock() SLOCK_NOEXCEPT;

		// ===========================================================
		// GETTERS & SETTERS
		// ===========================================================

		/**
		 * @brief
		 * Check if this lock is locked.
		 * 
		 * @thread_safety - atomic-flag used.
		 * @throws - no exceptions.
		**/
		bool isLocked() const SLOCK_NOEXCEPT;

		// ===========================================================
		// METHODS
		// ===========================================================

		/**
		 * @brief
		 * Try lock.
		 * 
		 * @param pMutex - mutex to use (switch to).
		 * @returns - 'true' if locked, 'false' if failed.
		 * @throws - can throw exception.
		**/
		bool try_lock(slock::Mutex* const pMutex = nullptr);

		/**
		 * @brief
		 * Lock.
		 * 
		 * @param pMutex - mutex to use (switch to).
		 * @throws - can throw exception.
		**/
		void lock(slock::Mutex* const pMutex = nullptr);

		/**
		 * @brief
		 * Unlock.
		 * 
		 * @throws - can throw exception.
		**/
		void unlock();

		// -----------------------------------------------------------

	}; /// slock::SpinLock

	// -----------------------------------------------------------

} /// slock

// -----------------------------------------------------------

#endif // !SLOCK_SPIN_LOCK_HPP