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

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// HEADER
#ifndef SLOCK_MUTEX_HPP
#include "../public/Mutex.hpp"
#endif // !SLOCK_MUTEX_HPP

// ===========================================================
// slock::Mutex
// ===========================================================

namespace slock
{

	// -----------------------------------------------------------

	// ===========================================================
	// CONSTRUCTOR & DESTRUCTOR
	// ===========================================================

// Windows
#if defined(WIN32) || defined(WIN64)

	Mutex::Mutex()
		: mMutex(),
		mLocked(false)
	{
		InitializeCriticalSection(&mMutex);
	}

	Mutex::~Mutex()
	{
		DeleteCriticalSection(&mMutex);
	}

#else // UNIX

	Mutex::Mutex()
		: mMutex(),
		mLocked(false)
	{
		pthread_mutex_init(&mMutex, nullptr);
	}

	Mutex::~Mutex()
	{
		pthread_mutex_destroy(&mMutex);
	}

#endif // WINDOWS

	// ===========================================================
	// GETTERS & SETTERS
	// ===========================================================

	bool Mutex::isLocked() const noexcept
	{
		const bool locked_ = mLocked;
		return locked_;
	}

	void* Mutex::native_handle() noexcept
	{ return &mMutex; }

	// ===========================================================
	// METHODS
	// ===========================================================

	bool Mutex::try_lock()
	{
		if ( isLocked() )
			return false;

		lock();
	}

// Windows
#if defined(WIN32) || defined(WIN64)

	void Mutex::lock()
	{
		mLocked = true;
		EnterCriticalSection(&mMutex);
	}

	void Mutex::unlock()
	{
		mLocked = false;
		LeaveCriticalSection(&mMutex);
	}

#else // UNIX

	void Mutex::lock()
	{
		mLocked = true;
		pthread_mutex_lock(&mMutex);
	}

	void Mutex::unlock()
	{
		mLocked = false;
		pthread_mutex_unlock(&mMutex);
	}

#endif // WINDOWS

	// -----------------------------------------------------------

} /// slock

// -----------------------------------------------------------