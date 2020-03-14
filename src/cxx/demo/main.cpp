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
#include "main.hpp"

// ===========================================================
// FIELDS
// ===========================================================

slock_mutex_t mutex_;

// ===========================================================
// METHODS
// ===========================================================

void foo()
{
	std::cout << "foo start" << std::endl;
	slock::SpinLock lock_( &mutex_, false );
	std::cout << "foo end" << std::endl;
}

void bar()
{
	std::cout << "bar start" << std::endl;
	slock::SpinLock lock_( &mutex_, false );
	std::cout << "bar end" << std::endl;
}

int main()
{
	std::cout << "Starting threads" << std::endl;

	std::thread first( foo );
	std::thread second( bar );

	std::cout << "Waiting threads" << std::endl;

	first.join();
	second.join();

	std::cout << "Test complete, press any key to exit." << std::endl;
	std::cin.get();

	// OK
	return 0;
}

// -----------------------------------------------------------