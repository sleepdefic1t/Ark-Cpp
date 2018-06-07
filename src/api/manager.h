

#ifndef MANAGER_H
#define MANAGER_H

#include "accountable/accountable.h"
#include "blockable/blockable.h"
#include "delegatable/delegatable.h"
#include "loadable/loadable.h"
#include "multisignaturable/multisignaturable.h"
#include "peerable/peerable.h"
#include "signaturable/signaturable.h"
#include "transactionable/transactionable.h"
#include "utilities/connector.h"

namespace ARK
{
namespace API
{
/*************************************************
*	ARK::API::Manager
**************************************************/
class Manager :
		public Accountable,
		public Blockable,
		public Delegatable,
		public Loadable,
		public MultiSignaturable,
		public Peerable,
		public Signaturable,
		public Transactionable,
		virtual ARK::Utilities::Network::Connectable
{
	public:
		/*************************************************
		*	ARK::API::Manager
		**************************************************/
		Manager();
		/*************************************************/

		/*************************************************
		*	ARK::API::Manager
		*
		*	@param: const ARK::Network& network 
		* @brief: Creates API Manager instance using an Ark-based network.
		**************************************************/
		explicit Manager(const ARK::Network& network);
		/*************************************************/

	private:
		/*************************************************
		*	ARK::API::Manager::connect
		*
		*	@param: const ARK::Network& network 
		*	@brief:	Private internal method. Connects APIManager to an Ark-based network.
		**************************************************/
		void connect(const ARK::Network& network);
		/*************************************************/

};
/*************************************************/

};
};

#endif
