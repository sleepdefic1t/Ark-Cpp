

#include "constants/networks.h"

namespace ARK
{
namespace Constants
{
namespace Networks
{
/**************************************************************************************************/
namespace Devnet
{
	const Hash nethash("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23");
	const char* const seeds[NUMBER_OF_DEVNET_SEEDS] = {
		"167.114.29.32", "167.114.29.33", "167.114.29.34", "167.114.29.35",
		"167.114.29.36", "167.114.29.37", "167.114.29.38", "167.114.29.39",
		"167.114.29.40", "167.114.29.41", "167.114.29.42", "167.114.29.51",
		"167.114.29.52", "167.114.29.53", "167.114.29.54", "167.114.29.55"
	};
	const int port = 4002;
	const ARK::NetworkType type = NetworkType::DEV;
};
/**************************************************************************************************/

// template<size_t SIZE>
// class Seeds
// {
// 	protected:
// 		uint8_t bytes_[SIZE][4];
// 	public:
// 		Seeds( uint8_t newSeeds[SIZE][4] )
// 		{
// 			for (int i = 0; i < SIZE - 1; i++)
// 			std::memcpy( this->bytes_, newSeeds, SIZE );
// 		};
// };

/**************************************************************************************************/
namespace Mainnet
{
	const Hash nethash("6e84d08bd299ed97c212c886c98a57e36545c8f5d645ca7eeae63a8bd62d8988");	
	const char* const seeds[NUMBER_OF_MAINNET_SEEDS] = {
		"5.39.9.240", "5.39.9.241",
		"5.39.9.242", "5.39.9.243",
		"5.39.9.244", "5.39.9.250",
		"5.39.9.251", "5.39.9.252",
		"5.39.9.253", "5.39.9.254",
		"5.39.9.255", "5.39.53.48",
		"5.39.53.49", "5.39.53.50",
		"5.39.53.51", "5.39.53.52",
		"5.39.53.53", "5.39.53.54",
		"5.39.53.55", "37.59.129.160",
		"37.59.129.161", "37.59.129.162",
		"37.59.129.163", "37.59.129.164",
		"37.59.129.165", "37.59.129.166",
		"37.59.129.167", "37.59.129.168",
		"37.59.129.169", "37.59.129.170",
		"37.59.129.171", "37.59.129.172",
		"37.59.129.173", "37.59.129.174",
		"37.59.129.175", "193.70.72.80",
		"193.70.72.81", "193.70.72.82",
		"193.70.72.83", "193.70.72.84",
		"193.70.72.85", "193.70.72.86",
		"193.70.72.87", "193.70.72.88",
		"193.70.72.89", "193.70.72.90"
	};
	const int port = 4001;
	const ARK::NetworkType type = NetworkType::MAIN;
};
/**************************************************************************************************/

const char *randomPeer(ARK::NetworkType netType)
{
	switch (netType) {
		case DEV: return Devnet::seeds[generate_random_number(0, NUMBER_OF_DEVNET_SEEDS)]; break;
		case MAIN: return Mainnet::seeds[generate_random_number(0, NUMBER_OF_MAINNET_SEEDS)]; break;
		case CUSTOM: return "Error: method yet not available for custom networks"; break;
		default: return "Error: Nethash Invalid"; break;
	}
}
/************************************************/
int getPort(ARK::NetworkType netType)
{
	switch (netType) {
		case DEV: return Devnet::port; break;
		case MAIN: return Mainnet::port; break;
		default: return -1; break;
	};
}
/**************************************************************************************************/

/**************************************************************************************************/

namespace Model
{
	const ARK::Network Devnet =
	{
		Devnet::nethash,
		"DARK",
		"DѦ",
		"https://dexplorer.ark.io/",
		30
	};
/************************************************/
	const ARK::Network Mainnet =
	{
		Mainnet::nethash,
		"ARK",
		"Ѧ",
		"https://explorer.ark.io/",
		23
	};
}
/**************************************************************************************************/

/**************************************************************************************************/
namespace Network_ADV
{
	const ARK::Network_ADV::network_t devnet
	{
		"\x18 Ark Devnet Signed message:\n",
		{
			0x43587CF, //<-hex dec: 70617039,
			0x4358394	//<-hex dec: 70615956
		},
		0x1E, //<-hex dec: 30,
		0xaa	//<-hex dec: 187
	};
/************************************************/
	const ARK::Network_ADV::network_t main
	{
		" \x18 Ark Signed Message: \n",
		{
			0x2bf4968, // base58 will have a prefix 'apub'
			0x2bf4530	// base58Priv will have a prefix 'apriv'
		},
		0x17, // Addresses will begin with 'A'
		// 0xaa works based on available test data but don't know if it is right
		// should it be 0xbb, or 0xef????
		0xaa	// Network prefix for wif generation
	};
/************************************************/
	const ARK::Network_ADV::network_t testnet
	{
		"\x18 Ark Testnet Signed Message:\n",
		{
			0x043587cf,
			0x04358394
		},
		0x52, // Addresses will begin with 'a'
		0xba	// Network prefix for wif generation
	};
/************************************************/
	const ARK::Network_ADV::network_t bitcoin
	{
		"\x18 Bitcoin Signed Message:\n",
		{
			0x0488b21e,
			0x0488ade4
		},
		0x00,
		0x80
	};
/**************************************************************************************************/
};
/**************************************************************************************************/
};
};
};



// // #define SEED_SIZE 4

// // class Seed
// // {
// // 	private:
// // 		uint8_t bytes_[SEED_SIZE];

// // 	public:

// // 		Seed(const uint8_t newSeeds[4])
// // 		{
// // 			for (int i = 0; i < SEED_SIZE; i++)
// // 			{
// // 				this->bytes_[i] = newSeeds[i];
// // 			};
// // 		};

// // 		const uint8_t *bytes() const
// // 		{
// // 			return this->bytes_;
// // 		};
// // 		const char* ip() const
// // 		{
// // 			std::vector<char> ipAddress(sizeof(this->bytes_));
// // 			for (int i = 0; i < SEED_SIZE; i++)
// // 			{
// // 				ipAddress.emplace_back(this->bytes_[i]); 
// // 				if (i < SEED_SIZE - 1) { ipAddress.emplace_back('.'); };
// // 			};
// // 			ipAddress.emplace_back('\0');
// // 			// std::make_shared<std::vector<char>>(ipAddress);
// // 			std::make_shared<char*>(ipAddress.data());
// // 			return ipAddress.data();
// // 		};

// // 		operator const char*() const
// // 		{
// // 			return this->ip();
// // 		};

// // };

 
// // template<size_t SEED_COUNT>
// // class Seeds
// // {
// // 	private:
// // 		uint8_t seeds_[SEED_COUNT][4];

// // 	public:

// // 		Seeds(const uint8_t newSeeds[SEED_COUNT][4])
// // 		{
// // 			for (int i = 0; i < SEED_COUNT; i++)
// // 			{
// // 				this->seeds[i] = newSeeds[i];
// // 			};
// // 		};

// // 		Seed at(unsigned int slot) const
// // 		{
// // 			return this->seeds_[slot];
// // 		};

// // 		Seed getRandom()
// // 		{
// // 			return this->seeds_[generate_random_number(0, SEED_COUNT)];
// // 		};

// // };
