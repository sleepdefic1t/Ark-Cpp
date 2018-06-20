
cmake_minimum_required(VERSION 3.2.2)

project(Ark-Cpp-lib)

hunter_add_package(nlohmann_json)

hunter_add_package(PocoCpp)

set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
 
include_directories(
	${PROJECT_SOURCE_DIR}
	${PROJECT_SOURCE_DIR}/../include/bcl
	${PROJECT_SOURCE_DIR}/../include/uECC
)
 
find_package(nlohmann_json CONFIG REQUIRED)
find_package(Poco CONFIG REQUIRED Foundation Net)

set(COMMON_SRC 
	${PROJECT_SOURCE_DIR}/api/accountable/accountable.cpp
	${PROJECT_SOURCE_DIR}/api/accountable/account_respondable.cpp
	${PROJECT_SOURCE_DIR}/api/blockable/blockable.cpp
	${PROJECT_SOURCE_DIR}/api/blockable/block_respondable.cpp
	${PROJECT_SOURCE_DIR}/api/delegatable/delegatable.cpp
	${PROJECT_SOURCE_DIR}/api/delegatable/delegate_respondable.cpp
	${PROJECT_SOURCE_DIR}/api/loadable/loadable.cpp
	${PROJECT_SOURCE_DIR}/api/loadable/loader_respondable.cpp
	${PROJECT_SOURCE_DIR}/api/multisignaturable/multisignaturable.cpp
	${PROJECT_SOURCE_DIR}/api/peerable/peerable.cpp
	${PROJECT_SOURCE_DIR}/api/peerable/peer_respondable.cpp
	${PROJECT_SOURCE_DIR}/api/signaturable/signaturable.cpp
	${PROJECT_SOURCE_DIR}/api/transactionable/transactionable.cpp
	${PROJECT_SOURCE_DIR}/api/transactionable/transaction_respondable.cpp
	${PROJECT_SOURCE_DIR}/api/manager.cpp
	${PROJECT_SOURCE_DIR}/crypto/ark_crypto.cpp
	${PROJECT_SOURCE_DIR}/crypto/bip39/bip39.cpp
	${PROJECT_SOURCE_DIR}/constants/networks.cpp
	${PROJECT_SOURCE_DIR}/models/account.cpp
	${PROJECT_SOURCE_DIR}/models/block.cpp
	${PROJECT_SOURCE_DIR}/models/currency.cpp
	${PROJECT_SOURCE_DIR}/models/delegate.cpp
	${PROJECT_SOURCE_DIR}/models/fees.cpp
	${PROJECT_SOURCE_DIR}/models/network.cpp
	${PROJECT_SOURCE_DIR}/models/peer.cpp
	${PROJECT_SOURCE_DIR}/models/transaction.cpp
	${PROJECT_SOURCE_DIR}/models/voter.cpp
	${PROJECT_SOURCE_DIR}/utilities/connector.cpp
	${PROJECT_SOURCE_DIR}/utilities/platform.cpp
)

set (BCL_SRC
	${PROJECT_SOURCE_DIR}/../include/bcl/Base58Check.cpp
	${PROJECT_SOURCE_DIR}/../include/bcl/CurvePoint.cpp
	${PROJECT_SOURCE_DIR}/../include/bcl/Ecdsa.cpp
	${PROJECT_SOURCE_DIR}/../include/bcl/FieldInt.cpp
	${PROJECT_SOURCE_DIR}/../include/bcl/Ripemd160.cpp
	${PROJECT_SOURCE_DIR}/../include/bcl/Sha256Hash.cpp
	${PROJECT_SOURCE_DIR}/../include/bcl/Sha256.cpp
	${PROJECT_SOURCE_DIR}/../include/bcl/Sha512.cpp
	${PROJECT_SOURCE_DIR}/../include/bcl/Uint256.cpp
	${PROJECT_SOURCE_DIR}/../include/bcl/Utils.cpp
)

set (uECC_SRC
	${PROJECT_SOURCE_DIR}/../include/uECC/uECC.c
)

set(PLATFORM_SRC 
	${PROJECT_SOURCE_DIR}/platform/os/json.cpp
	${PROJECT_SOURCE_DIR}/platform/os/http.cpp
)

add_library(Ark-Cpp-lib STATIC ${COMMON_SRC} ${PLATFORM_SRC} ${BCL_SRC} ${uECC_SRC})

target_link_libraries(Ark-Cpp-lib PUBLIC nlohmann_json)
target_link_libraries(Ark-Cpp-lib PUBLIC Poco::Net)

if (MSVC)
	target_link_libraries(Ark-Cpp-lib PUBLIC crypt32)
endif()
