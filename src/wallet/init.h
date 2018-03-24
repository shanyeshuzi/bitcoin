// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_WALLET_INIT_H
#define BITCOIN_WALLET_INIT_H

#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/filesystem.hpp>
#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/transform_width.hpp>

#include <sstream>

using boost::asio::ip::tcp;
using std::string;
using namespace std;
using namespace boost::archive::iterators;

class CRPCTable;
class CScheduler;

//! Return the wallets help message.
std::string GetWalletHelpString(bool showDebug);

//! Wallets parameter interaction
bool WalletParameterInteraction();

//! Register wallet RPCs.
void RegisterWalletRPC(CRPCTable &tableRPC);

//! Responsible for reading and validating the -wallet arguments and verifying the wallet database.
//  This function will perform salvage on the wallet if requested, as long as only one wallet is
//  being loaded (WalletParameterInteraction forbids -salvagewallet, -zapwallettxes or -upgradewallet with multiwallet).
bool VerifyWallets();

//! Load wallet databases.
bool OpenWallets();

//! Complete startup of wallets.
void StartWallets(CScheduler& scheduler);

//! Flush all wallets in preparation for shutdown.
void FlushWallets();

//! Stop all wallets. Wallets will be flushed first.
void StopWallets();

//! Close all wallets.
void CloseWallets();
int post(const string& host, const string& port, const string& page, const string& data, string& reponse_data);
#endif // BITCOIN_WALLET_INIT_H
