

#include "api/peerable/peer_respondable.h"

namespace ARK
{
namespace API
{
namespace Peer
{
namespace Respondable
{
/*************************************************
* Peers
**************************************************/
Peers::Peers(size_t newCapacity) :
		peers_(new ARK::Delegate[newCapacity]) {}

const ARK::Peer &ARK::API::Peer::Respondable::Peers::operator[](size_t index) const { return this->peers_[index]; }
ARK::Delegate &ARK::API::Peer::Respondable::Peers::operator[](size_t index) { return this->peers_[index]; }

size_t ARK::API::Delegate::Respondable::Delegates::printTo(Print &p) const
{
	size_t size = 0;
	size += p.print("\n\0");
	for (int i = 0; i < 20; i++)
	{
		size += p.print("\npeer: ");
		size += p.print(i + 1);
		size += p.print(":\n");
		size += p.println(this->peers_[i].printTo(p));
	};
	return size;
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* Constructor
**************************************************/
Version::Version(
		const char* const newVersion,
		const char* const newBuild
)
{
	strncpy(this->version_, newVersion, sizeof(version_) / sizeof(version_[0]));
	strncpy(this->build_, newBuild, sizeof(build_) / sizeof(build_[0]));
};
/*************************************************/

/*************************************************
*
**************************************************/
size_t Version::printTo(Print& p) const
{
	size_t size = 0;
		size += p.print("version: ");
		size += p.print(this->version_);
		size += p.print("\nbuild: ");
		size += p.print(this->build_);
	return size;
};
/*************************************************/

};
};
};
};
