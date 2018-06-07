

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


		/**************************************************************************************************/

    /*************************************************/
    /*************************************************/
  	/*	BROKEN: fix for large callbacks  */
  	/*	Peers callback is ~11,000 bytes  */
    /*  /api/peers  */
    // ARK::API::PeerGettable::PeersResponse peers()
    // { return ARK::API::PeerGettable::peers(this->netConnector); };
    /*************************************************/
    /*************************************************/

		/**************************************************************************************************/

/**************************************************************************************************/
/*************************************************/
/*************************************************/
/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~11,000 bytes  */
/*  =============================  */
/*  ARK::API::PeerGettable::peers  */
/*  /api/peers  */
// ARK::API::PeerGettablePeersResponse ARK::API::PeerGettable::peers(ARK::Utilities::Network::Connector _netConnector) {
//   String uri = ARK::API::Paths::Peer::peers_s;
//   String callback = _netConnector.cb(uri);
//   return ARK::API::PeerGettable::peersfromJSON(callback);
// };
/*
{ 
  "success":true,
  "peers":[
    {
      "ip":"138.68.21.196",
      "port":4002,
      "version":"1.1.1",
      "errors":0,
      "os":"linux4.4.0-93-generic",
      "height":2315528,
      "status":"OK",
      "delay":154
    },
    ...
    {
      "ip":"45.33.86.168",
      "port":4002,
      "version":"1.1.1",
      "errors":0,
      "os":"linux4.9.68-x86_64-linode89",
      "height":2315543,
      "status":"OK",
      "delay":35
    }
  ],
  "count":"_count"
}
*/
// ARK::API::PeerGettablePeersResponse ARK::API::PeerGettable::peersfromJSON(String _jsonStr) {
//   ARK::Utilities::JSONString jString(_jsonStr);
//   int peersCount = 10; // limited to 10
//   ARK::Peer::PeersResponse peersResponse(peersCount);
//   // for (int i = 0; i < peersCount; i++) {
//   //   ARK::Peer peer = {
//   //     jString.subarrayValueIn("peers", i, "ip"),
//   //     jString.subarrayValueIn("peers", i, "port").toInt(),
//   //     jString.subarrayValueIn("peers", i, "version"),
//   //     jString.subarrayValueIn("peers", i, "errors").toInt(),
//   //     jString.subarrayValueIn("peers", i, "os"),
//   //     jString.subarrayValueIn("peers", i, "height"),
//   //     jString.subarrayValueIn("peers", i, "status"),
//   //     jString.subarrayValueIn("peers", i, "delay").toInt()
//   //   };
//   //   peersResponse.list[i] = peer;
//   // };
//   return peersResponse;
// }
/*************************************************/
/*************************************************/
/**************************************************************************************************/