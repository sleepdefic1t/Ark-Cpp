

#ifndef PEERABLE_H
#define PEERABLE_H

#include "api/peerable/peer_respondable.h"
#include "models/peer.h"
#include "utilities/connector.h"
#include "api/paths.h"
#include "utilities/json.h"

#include <cstring>
#include <cstdio>
namespace ARK
{
namespace API
{
/*************************************************
*	PUBLIC: ARK::API::Peerable
*	public Peer::Gettable
*	virtual ARK::Utilities::Network::Connectable
*    
*	API's Peer Model
**************************************************/
class Peerable :
    virtual ARK::Utilities::Network::Connectable
{
  public:
		/*************************************************
		*	/api/peers/get?ip=167.114.29.55&port=4002
		*
		*	@method:	peer(const char* const ip, int port)
    *	@param:	const char* const ip
		*	@param:	int port
		*	@return:	ARK::Peer
		*
		*	@brief:	Gets Ark Network Peer from a Node via API.
		**************************************************/
    ARK::Peer peer(
				const char* const ip,
				int port
		);
    /*************************************************/

		/**************************************************************************************************/
		
    /*************************************************
		*	/api/peers?limit=20
		*
		*	@method:	peer(const char* const ip, int port)
    *	@param:	const char* const ip
		*	@param:	int port
		*	@return:	ARK::Peer
		*
		*	@brief:	Gets Ark Network Peers list, limited to 20 for MCU.
		**************************************************/
    ARK::Peer peers();
    /*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/peers/version
		*
		*	@method:	peerVersion()
		*	@return:	ARK::API::Peer::Respondable::Version
		*
		*	@brief:	Gets Ark Network Peer Version from a Node via API.
		**************************************************/
    ARK::API::Peer::Respondable::Version peerVersion();
    /*************************************************/

};
/*************************************************/

};
};

#endif
