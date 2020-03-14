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
#ifndef SLOCK_SPIN_LOCK_HPP
#include "../public/SpinLock.hpp"
#endif // !SLOCK_SPIN_LOCK_HPP

// ===========================================================
// slock::SpinLock
// ===========================================================

namespace slock
{

	// -----------------------------------------------------------

	// ===========================================================
	// CONSTRUCTORS & DESTRUCTOR
	// ===========================================================

	SpinLock::SpinLock( slock::Mutex* const pMutex, const bool defferLock ) SLOCK_NOEXCEPT
		: mMutex( pMutex )
	{
		if( !defferLock && mMutex )
			this->lock();
	}

	SpinLock::~SpinLock() SLOCK_NOEXCEPT
	{
		this->unlock();
	}

	// ===========================================================
	// GETTERS & SETTERS
	// ===========================================================

	bool SpinLock::isLocked() const SLOCK_NOEXCEPT
	{ return mMutex ? mMutex->isLocked() : false; }

	// ===========================================================
	// METHODS
	// ===========================================================

	bool SpinLock::try_lock(slock::Mutex* const pMutex)
	{
#ifdef DEBUG // DEBUG
		assert( (mMutex || pMutex) && "SpinLock::try_lock - null mutex !" );
#endif // DEBUG

		if ( pMutex )
		{
			this->unlock();
			mMutex = pMutex;
		}

		for( unsigned char i = 0; i < SPIN_LIMIT; i++ )
		{
			if ( !mMutex->isLocked() )
			{ break; }
		}
		return mMutex->try_lock();
	}

	void SpinLock::lock(slock::Mutex* const pMutex)
	{
#ifdef DEBUG // DEBUG
		assert( (mMutex || pMutex) && "SpinLock::lock - null mutex !" );
#endif // DEBUG

		if (pMutex)
		{
			this->unlock();
			mMutex = pMutex;
		}

		for( unsigned char i = 0; i < SPIN_LIMIT; i++ )
		{
			if ( !mMutex->isLocked() )
			{ break; }
		}
		mMutex->lock();
	}

	void SpinLock::unlock()
	{
		if (mMutex && mMutex->isLocked())
			mMutex->unlock();
	}

	// -----------------------------------------------------------

} /// slock

// -----------------------------------------------------------