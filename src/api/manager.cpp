

#include "api/manager.h"

namespace ARK
{
namespace API
{
/*************************************************
*	Default: Empty Constructor
**************************************************/
Manager::Manager() {}
/*************************************************/

/*************************************************
*	Constructor
**************************************************/
Manager::Manager(const ARK::Network& network){ this->connect(network); }
/*************************************************/

/*************************************************
*	ARK::API::Manager::connect
**************************************************/
void Manager::connect(const ARK::Network& network)
{
	this->netConnector = ARK::Utilities::Network::Connector(network);
}
/*************************************************/

};
};
