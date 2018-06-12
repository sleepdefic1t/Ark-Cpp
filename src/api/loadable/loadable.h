

#ifndef LOADABLE_H
#define LOADABLE_H

#include "api/loadable/loader_respondable.h"
#include "utilities/connector.h"
#include "api/paths.h"
#include "utilities/json.h"

namespace ARK
{
namespace API
{
/*************************************************
* PUBLIC: ARK::API::Loadable
* public Loader::Gettable
* virtual ARK::Utilities::Network::Connectable
*    
* API's Network Loader Model
**************************************************/
class Loadable :
		virtual ARK::Utilities::Network::Connectable
{
	public:
		/*************************************************
		* /api/loader/autoconfigure
		*
		* @return: ARK::Network
		*
		* @brief: Returns an auto-configured network from a Networks NetHash from a Node via API. 
		*
		* EXAMPLE:
		* {
		*	"success":true,
		*	"network":
		*	{
		*		"nethash":  "Hash",
		*		"token":  "const char*",
		*		"symbol": "const char*,
		*		"explorer": "const char*",
		*		"version":  int
		*	}
		* }
		**************************************************/
		ARK::Network loaderAutoconfigure();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/loader/status
		*
		* @return: ARK::API::Loader::Respondable::Status
		*
		* @brief: Gets Ark Network Status from a Node via API.
		*
		* EXAMPLE:
		* { 
		*	"success":true,
		*	"loaded": bool,
		*	"now":  int,
		*	"blocksCount":  const char*
		* }
		**************************************************/
		ARK::API::Loader::Respondable::Status loaderStatus();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/loader/status/sync
		*
		* @return: ARK::API::Loader::Respondable::Sync
		*
		* @brief:	Gets Ark Network Sync Status from a Node via API. 
		*
		* EXAMPLE:
		* { 
		*	"success": bool,
		*	"syncing":  bool,
		*	"blocks": int,
		*	"height": const char*,
		*	"id": "const char*"
		* }
		**************************************************/
		ARK::API::Loader::Respondable::Sync loaderSync();
		/*************************************************/
		
};
/*************************************************/

};
};

#endif
