

#ifndef NETWORKS_H
#define NETWORKS_H

#include "utilities/platform.h"
#include "models/network.h"
#include "types/types.h"

namespace ARK
{
namespace Constants
{
namespace Networks 
{
/*************************************************
 * Devnet
 * ARK::Network devnet = ARK::Constants::Networks::Devnet::model;
 * 
 * 578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23
 * DARK
 * DѦ
 * https://dexplorer.ark.io/
 * 30
 *************************************************/
namespace Devnet
{
#define NUMBER_OF_DEVNET_SEEDS 16
	extern const Hash nethash;
	extern const char* const seeds[NUMBER_OF_DEVNET_SEEDS];
	extern const int port;
	extern const ARK::NetworkType type;
};


/*************************************************
 * Mainne
 * ARK::Network mainnet = ARK::Constants::Networks::Mainnet::model;
 * ARK::API::Manager mngr(mainnet);
 * 
 * 6e84d08bd299ed97c212c886c98a57e36545c8f5d645ca7eeae63a8bd62d8988
 * ARK
 * Ѧ
 * https://explorer.ark.io/
 * 23
*************************************************/
namespace Mainnet
{
/**************************************************************************************************/
#define NUMBER_OF_MAINNET_SEEDS 46
	extern const Hash nethash;
	extern const char* const seeds[NUMBER_OF_MAINNET_SEEDS];
	extern const int port;
	extern const ARK::NetworkType type;
};
/************************************************/
const char *randomPeer(ARK::NetworkType netType);
int getPort(ARK::NetworkType netType);
/**************************************************************************************************/

/**************************************************************************************************/
namespace Model
{
	extern const ARK::Network Devnet;
	extern const ARK::Network Mainnet;
};
/************************************************/
namespace Network_ADV
{
	extern const ARK::Network_ADV::network_t devnet;
	extern const ARK::Network_ADV::network_t main;
	extern const ARK::Network_ADV::network_t testnet;
	extern const ARK::Network_ADV::network_t bitcoin;
};
/**************************************************************************************************/
};
};
};

#endif
