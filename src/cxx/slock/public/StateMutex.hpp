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

#ifndef SLOCK_STATE_MUTEX_HPP
#define SLOCK_STATE_MUTEX_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// slock
#ifndef SLOCK_HPP
#include "slock.hpp"
#endif // !SLOCK_HPP

// ===========================================================
// TYPES
// ===========================================================

namespace slock
{
	/**
	 * @brief
	 * StateMutex - wrapper (decorator) for mutex.
	 * 
	 * @version 0.1
	 * @author Denis Z. (code4un@yandex.ru)
	**/
	class StateMutex final
	{

	private:

		// -----------------------------------------------------------

		// ===========================================================
		// CONSTANTS & FIELDS
		// ===========================================================

		/** THE, Mutex. **/
		slock_mutex_t mMutex;

		/** Atomic-flag. **/
		slock_aflag_t mLockedFlag;

		// -----------------------------------------------------------

	public:

		// -----------------------------------------------------------

		// ===========================================================
		// CONSTRUCTORS & DESTRUCTOR
		// ===========================================================

		/**
		 * @brief
		 * StateMutex default constructor.
		 * 
		 * @throws - no exceptions.
		**/
		explicit StateMutex( ) SLOCK_NOEXCEPT;

		/**
		 * @brief
		 * StateMutex destructor.
		 *
		 * (?) RAII, mutex automatically closed, without causing exceptions.
		 *
		 * @throws - no exceptions.
		**/
		~StateMutex( ) SLOCK_NOEXCEPT;

		// ===========================================================
		// GETTERS & SETTERS
		// ===========================================================

		// ===========================================================
		// METHODS
		// ===========================================================

		// ===========================================================
		// OPERATORS
		// ===========================================================

		// -----------------------------------------------------------

	}; /// slock::StateMutex

} /// slock

// -----------------------------------------------------------

#endif // !SLOCK_STATE_MUTEX_HPP