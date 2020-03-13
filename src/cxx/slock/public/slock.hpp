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

#ifndef SLOCK_HPP
#define SLOCK_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include C++ atomic
#include <atomic>

// Include C++ mutex
#include <mutex>

// ===========================================================
// MACRO ~>_<~
// ===========================================================

/** Hard to explain. This is old method to enable noexcept only for releases. **/
#ifdef DEBUG // DEBUG
#define SLOCK_NOEXCEPT noexcept
#else // !DEBUG
#define SLOCK_NOEXCEPT
#endif // DEBUG

// ===========================================================
// TYPES
// ===========================================================

// Atomic-flag.
using slock_aflag_t =  std::atomic_flag;

// Mutex
using slock_mutex_t = std::mutex;

// -----------------------------------------------------------

#endif // !SLOCK_HPP