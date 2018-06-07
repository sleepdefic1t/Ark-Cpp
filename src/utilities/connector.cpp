

#include "utilities/connector.h"

namespace ARK
{
namespace Utilities
{
namespace Network
{
/**************************************************
* ARK::Utilities::Network::Connector
*	Default: Empty Constructor
**************************************************/
Connector::Connector() : 
    // network(nullptr),
    // netType(ARK::NetworkType::INVALID),
    networkPeer(),
    networkPort(-1) {}
/*************************************************/

/**************************************************************************************************/

/**************************************************
* Connects this to the supplied ARK::Network
**************************************************/
Connector::Connector(
		const ARK::Network& network
)
{
  this->connect(network);
}
/*************************************************/

/**************************************************************************************************/

/**************************************************
* Connects this to the supplied ARK::NetworkType
**************************************************/
Connector::Connector(
		ARK::NetworkType networkType
)
{
	(networkType == DEV) ?
			(this->connect(ARK::Constants::Networks::Model::Devnet)) :
			(this->connect(ARK::Constants::Networks::Model::Mainnet));
}
/*************************************************/

/**************************************************************************************************/

/**************************************************
*
**************************************************/
Connector::Connector(
		const Connector& other
) :
		network(other.network),
		netType(other.netType),
		networkPort(other.networkPort)
{
  strncpy(networkPeer, other.networkPeer, 16);
} 
/*************************************************/

/**************************************************************************************************/

/**************************************************
*
**************************************************/
Connector& Connector::operator=(const Connector& other)
{
	if (this != &other)
	{
		network = other.network;
		netType = other.netType;
		strncpy(networkPeer, other.networkPeer, 16);
		networkPort = other.networkPort;
	}
	return *this;
}
/*************************************************/

/**************************************************************************************************/

/**************************************************
*
**************************************************/
Connector::Connector(Connector&& other) :
		network(other.network),
		netType(other.netType),
		networkPort(other.networkPort)
{
  strncpy(networkPeer, other.networkPeer, 16);
}
/*************************************************/

/**************************************************************************************************/

/**************************************************
*
**************************************************/
Connector& Connector::operator=(Connector&& other)
{
	if (this != &other)
	{
		network = other.network;
		netType = other.netType;
		strncpy(networkPeer, other.networkPeer, 16);
		networkPort = other.networkPort;
	}
	return *this;
}
/*************************************************/

/**************************************************************************************************/

/**************************************************
* Sets networktype, network, and peer
**************************************************/
void Connector::connect(
		const ARK::Network& network
)
{
	if (strcmp(network.nethash(), ARK::Constants::Networks::Devnet::nethash) == 0)
	{
		this->netType = ARK::NetworkType::DEV;
	}
	else if (strcmp(network.nethash(), ARK::Constants::Networks::Mainnet::nethash) == 0)
	{
		this->netType = ARK::NetworkType::MAIN;
	}
	else if (strcmp(network.nethash(), "") != 0)
	{
		this->netType = ARK::NetworkType::CUSTOM;
	}
	else
	{
		this->netType = ARK::NetworkType::INVALID;
	};
	this->network = &network;
	this->setNetworkPeer(ARK::Constants::Networks::randomPeer(this->netType));
}
/*************************************************/

/**************************************************************************************************/

/**************************************************
*
**************************************************/
void Connector::connectCustom(
		const ARK::Network& network,
		const char* peer,
		int port
)
{
	this->netType = ARK::NetworkType::CUSTOM;
	this->network = &network;
	strncpy(this->networkPeer, peer, sizeof(this->networkPeer) / sizeof(this->networkPeer[0]));
	this->networkPort = port;
}
/*************************************************/

/**************************************************************************************************/

/**************************************************
* Sets Random Peer based on this->NetworkType
*	returns error String if error
**************************************************/
const char* Connector::randomPeer() const
{
	if (
			this->netType == ARK::NetworkType::DEV ||
			this->netType == ARK::NetworkType::MAIN
	)
	{
		return ARK::Constants::Networks::randomPeer(this->netType);
	}
	return "Error: Nethash does not match ARK::Constants";
}
/*************************************************/

/**************************************************************************************************/

/**************************************************
* Checks this->NetworkType
* Assigns ip & port to this
**************************************************/
void Connector::setNetworkPeer(
		const char* peer
)
{
	if (this->netType == ARK::NetworkType::DEV)
	{
		this->networkPort = ARK::Constants::Networks::Devnet::port;
	}
	else if (this->netType == ARK::NetworkType::MAIN)
	{
		this->networkPort = ARK::Constants::Networks::Mainnet::port;
	}
	strncpy(networkPeer, peer, sizeof(networkPeer) / sizeof(networkPeer[0]));
}
/*************************************************/

/**************************************************************************************************/

/**************************************************
* Manages directing the callback from
*	the devices HTTPClient Library
**************************************************/
// TODO: add proper check for callback.
std::string Connector::callback(
		const char *const request
)
{
	std::string httpGet = this->http->get(this->networkPeer, this->networkPort, request);
	while (strlen(httpGet.data()) < 10)
	{
		this->setNetworkPeer(randomPeer());
		httpGet = this->http->get(this->networkPeer, this->networkPort, request);
	};
	return httpGet.data();
}
/*************************************************/

};
};
};
