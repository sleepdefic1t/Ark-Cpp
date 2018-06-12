

#include "api/peerable/peerable.h"

/*************************************************
* /api/peers/get?ip=167.114.29.55&port=4002
*
* EXAMPLE:
* { 
*	"success":true,
*	"peer":
*	{
*		"ip": "String",
*		"port": int,
*		"version":  "String",
*		"errors": int,
*		"os": "String",
*		"height": String,
*		"status": "String",
*		"delay":  int
*	}
* }
**************************************************/
ARK::Peer ARK::API::Peerable::peer(
		const char* const ip,
		int port
) {
	char uri[68 + 1] = { '\0' };
		strcpy(uri, ARK::API::Paths::Peer::get_s);
		strcat(uri, "?ip=");
		strcat(uri, ip);
		strcat(uri, "&port=");
	const auto len = strlen(uri);
		sprintf(uri + len, "%d", port);
	auto callback = netConnector.callback(uri);
	auto parser = ARK::Utilities::makeJSONString(callback);
	return {
		parser->valueIn("peer", "ip").c_str(),
		convert_to_int(parser->valueIn("peer", "port").c_str()),
		parser->valueIn("peer", "version").c_str(),
		convert_to_int(parser->valueIn("peer", "errors").c_str()),
		parser->valueIn("peer", "os").c_str(),
		parser->valueIn("peer", "height").c_str(),
		parser->valueIn("peer", "status").c_str(),
		convert_to_int(parser->valueIn("peer", "delay").c_str())
	};
};

/*************************************************
* /api/peers/version
*
* EXAMPLE:
* {
*	"success":true,
*	"version": "String",
*	"build": "String"
* }
**************************************************/
ARK::API::Peer::Respondable::Version ARK::API::Peerable::peerVersion()
{
	auto callback = netConnector.callback(ARK::API::Paths::Peer::version_s);
	auto parser = ARK::Utilities::makeJSONString(callback);
	return {
		parser->valueFor("version").c_str(),
		parser->valueFor("build").c_str()
	};
};
