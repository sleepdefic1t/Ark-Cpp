#include "utilities/platform.h"
#include <memory>
#include <vector>

#if (defined ESP32 || defined ESP8266)

#include "utilities/http.h"

#ifdef ESP8266

#include <ESP8266HTTPClient.h>

#else

#include <HTTPClient.h>

#endif

namespace ARK
{
namespace Utilities
{
namespace Network
{
namespace
{

/*************************************************
*
**************************************************/
class HTTP :
		public HTTPInterface
{
	public:
		/*************************************************
		*
		**************************************************/
		HTTP() = default;
		/*************************************************/

		/*************************************************
		*
		**************************************************/
		void printConnection(
				const char *const peer,
				int port,
				const char *const request
		)
		{
			Serial.print("\nOpening HTTP connection to:\n");
			Serial.print(peer); Serial.print(":");
			Serial.print(port);
			Serial.println(request);
		};
		/*************************************************/

		/*************************************************
		*
		**************************************************/
		int tryConnection(
				HTTPClient &client,
				const char *const peer,
				int port,
				const char *const request
		)
		{
			printConnection(peer, port, request);

			if (!client.begin(peer, port, request)) {
				// error
				Serial.println("\nbad HTTP begin");
			}
			auto code = client.GET();
			int count = 0;
			while (code != HTTP_CODE_OK) {
				//error
				if (count >=2)
				{
					Serial.println("\nbad connection. trying another peer");
					return -1;
				};
				Serial.println("\nbad HTTP GET");
				client.end();
				delay(1000);
				Serial.println("\nretrying connection..");
				client.begin(peer, port, request);
				code = client.GET();
				count++;
	
			};
			return code;
		};
		/*************************************************/

		/*************************************************
		*
		**************************************************/
		std::string get(
				const char *const peer,
				int port,
				const char *const request
		)
		{
			HTTPClient http;
			http.setReuse(true);
			http.setTimeout(2000);

			if (tryConnection(http, peer, port, request) != 200) {
				// error
				return std::string("");
			}

			const auto content_length = http.getSize();
			// get tcp stream
			auto stream = http.getStreamPtr();
			auto bytes_read = 0;
			std::string payload(content_length, '\0');
			
			// read all data from server
			while (http.connected() && (content_length > 0 || content_length == -1) && bytes_read < content_length) {
				// get available data size
				auto size = stream->available();
				if (size) {
					// read up to 128 byte
					bytes_read += stream->readBytes(&payload[0], size);			
				}
				delay(1);
			};
			return payload;
		}
		/*************************************************/
};

}

/*************************************************
*		HTTP object factory
**************************************************/
std::unique_ptr<HTTPInterface> make_http() {
	return std::unique_ptr<HTTPInterface>(new HTTP());
}
/*************************************************/

}
}
}

#endif
