#include "models/transaction.h"

namespace ARK
{
/*************************************************
* Default: Empty Constructor
**************************************************/
ARK::Transaction::Transaction()	:
		id_(),
		blockID_(),
		height_(),
		type_(),
		timestamp_(),
		amount_(),
		fee_(),
		vendorField_(),
		senderId_(),
		recipientId_(),
		senderPublicKey_(),
		signature_(),
		confirmations_() {};
/*************************************************/

/*************************************************
* Constructor
**************************************************/
ARK::Transaction::Transaction(
		const char *const newID,
		const char *const newBlockID,
		const char *const newHeight,
		int newType,
		const char *const newTimestamp,
		const char *const newAmount,
		const char *const newFee,
		const char *const newVendorField,
		const char *const newSenderID,
		const char *const newRecipientID,
		const char *const newSenderPublickey,
		const char *const newSignature,
		const char *const newConfirmations
)	:	id_(newID),
		type_(newType),
		amount_(newAmount),
		fee_(newFee), 
		senderId_(newSenderID),
		recipientId_(newRecipientID),
		senderPublicKey_(newSenderPublickey),
		signature_(newSignature)
{
	strncpy(this->blockID_, newBlockID, sizeof(blockID_) / sizeof(blockID_[0]));
	strncpy(this->height_, newHeight, sizeof(height_) / sizeof(height_[0]));
	strncpy(this->timestamp_, newTimestamp, sizeof(timestamp_) / sizeof(timestamp_[0]));
	strncpy(this->vendorField_, newVendorField, sizeof(vendorField_) / sizeof(vendorField_[0]));
	strncpy(this->confirmations_, newConfirmations, sizeof(confirmations_) / sizeof(confirmations_[0]));

}
/*************************************************/

/*************************************************
*
**************************************************/
size_t ARK::Transaction::printTo(Print &p) const
{
	size_t size = 0;
		size += p.print("\nid: ");
		size += p.print(this->id_.c_str());

		size += p.print("\nblockID: ");
		size += p.print(this->blockID_);

		size += p.print("\nheight: ");
		size += p.print(this->height_);

		size += p.print("\ntype: ");
		size += p.print(this->type_);

		size += p.print("\ntimestamp: ");
		size += p.print(this->timestamp_);

		size += p.print("\namount: ");
		size += p.print(this->amount_.ark());

		size += p.print("\nfee: ");
		size += p.print(this->fee_.ark());

		size += p.print("\nvendorField: ");
		size += p.print(this->vendorField_);

		size += p.print("\nsenderId: ");
		size += p.print(this->senderId_.c_str());

		size += p.print("\nrecipientId: ");
		size += p.print(this->recipientId_.c_str());

		size += p.print("\nsenderPublicKey: ");
		size += p.print(this->senderPublicKey_.c_str());

		size += p.print("\nsignature: ");
		size += p.print(this->signature_.c_str());

		size += p.print("\nconfirmations: ");
		size += p.print(this->confirmations_);
	return size;
}
/*************************************************/

};
