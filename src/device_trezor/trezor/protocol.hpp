// Copyright (c) 2017-2023, The Monero Project
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#ifndef LUNEXA_PROTOCOL_H
#define LUNEXA_PROTOCOL_H

#include "trezor_defs.hpp"
#include "device/device_cold.hpp"
#include "messages_map.hpp"
#include "transport.hpp"
#include "wallet/wallet2.h"

namespace hw{
namespace trezor{
namespace protocol{

  std::string key_to_string(const ::crypto::ec_point & key);
  std::string key_to_string(const ::crypto::ec_scalar & key);
  std::string key_to_string(const ::crypto::hash & key);
  std::string key_to_string(const ::rct::key & key);

  void string_to_key(::crypto::ec_scalar & key, const std::string & str);
  void string_to_key(::crypto::ec_point & key, const std::string & str);
  void string_to_key(::rct::key & key, const std::string & str);

  template<class sub_t, class InputIterator>
  void assign_to_repeatable(::google::protobuf::RepeatedField<sub_t> * dst, const InputIterator begin, const InputIterator end){
    for (InputIterator it = begin; it != end; it++) {
      auto s = dst->Add();
      *s = *it;
    }
  }

  template<class sub_t, class InputIterator>
  void assign_from_repeatable(std::vector<sub_t> * dst, const InputIterator begin, const InputIterator end){
    for (InputIterator it = begin; it != end; it++) {
      dst->push_back(*it);
    }
  };

  template<typename T>
  bool cn_deserialize(const void * buff, size_t len, T & dst){
    binary_archive<false> ba{{reinterpret_cast<const std::uint8_t*>(buff), len}};
    bool r = ::serialization::serialize(ba, dst);
    return r;
  }

  template<typename T>
  bool cn_deserialize(const std::string & str, T & dst){
    return cn_deserialize(str.data(), str.size(), dst);
  }

  template<typename T>
  std::string cn_serialize(T & obj){
    std::ostringstream oss;
    binary_archive<true> oar(oss);
    bool success = ::serialization::serialize(oar, obj);
    if (!success){
      throw exc::EncodingException("Could not CN serialize given object");
    }
    return oss.str();
  }

// Crypto / encryption
namespace crypto {
namespace chacha {
  // Constants as defined in RFC 7539.
  const unsigned IV_SIZE = 12;
  const unsigned TAG_SIZE = 16;  // crypto_aead_chacha20poly1305_IETF_ABYTES;

  /**
   * Chacha20Poly1305 decryption with tag verification. RFC 7539.
   */
  void decrypt(const void* ciphertext, size_t length, const uint8_t* key, const uint8_t* iv, char* plaintext, size_t *plaintext_len=nullptr);

}
}


// Cold Key image sync
namespace ki {

  using LunexaTransferDetails = messages::lunexa::LunexaKeyImageSyncStepRequest_LunexaTransferDetails;
  using LunexaSubAddressIndicesList = messages::lunexa::LunexaKeyImageExportInitRequest_LunexaSubAddressIndicesList;
  using LunexaExportedKeyImage = messages::lunexa::LunexaKeyImageSyncStepAck_LunexaExportedKeyImage;
  using exported_key_image = hw::device_cold::exported_key_image;

  /**
   * Converts transfer details to the LunexaTransferDetails required for KI sync
   */
  bool key_image_data(wallet_shim * wallet,
                      const std::vector<tools::wallet2::transfer_details> & transfers,
                      std::vector<LunexaTransferDetails> & res);

  /**
   * Computes a hash over LunexaTransferDetails. Commitment used in the KI sync.
   */
  std::string compute_hash(const LunexaTransferDetails & rr);

  /**
   * Generates KI sync request with commitments computed.
   */
  void generate_commitment(std::vector<LunexaTransferDetails> & mtds,
                           const std::vector<tools::wallet2::transfer_details> & transfers,
                           std::shared_ptr<messages::lunexa::LunexaKeyImageExportInitRequest> & req);

  /**
   * Processes Live refresh step response, parses KI, checks the signature
   */
  void live_refresh_ack(const ::crypto::secret_key & view_key_priv,
                        const ::crypto::public_key& out_key,
                        const std::shared_ptr<messages::lunexa::LunexaLiveRefreshStepAck> & ack,
                        ::cryptonote::keypair& in_ephemeral,
                        ::crypto::key_image& ki);
}

// Cold transaction signing
namespace tx {
  using TsxData = messages::lunexa::LunexaTransactionInitRequest_LunexaTransactionData;
  using LunexaTransactionDestinationEntry = messages::lunexa::LunexaTransactionDestinationEntry;
  using LunexaAccountPublicAddress = messages::lunexa::LunexaTransactionDestinationEntry_LunexaAccountPublicAddress;
  using LunexaTransactionSourceEntry = messages::lunexa::LunexaTransactionSourceEntry;
  using LunexaMultisigKLRki = messages::lunexa::LunexaTransactionSourceEntry_LunexaMultisigKLRki;
  using LunexaOutputEntry = messages::lunexa::LunexaTransactionSourceEntry_LunexaOutputEntry;
  using LunexaRctKey = messages::lunexa::LunexaTransactionSourceEntry_LunexaOutputEntry_LunexaRctKeyPublic;
  using LunexaRsigData = messages::lunexa::LunexaTransactionRsigData;

  using tx_construction_data = tools::wallet2::tx_construction_data;
  using unsigned_tx_set = tools::wallet2::unsigned_tx_set;

  void translate_address(LunexaAccountPublicAddress * dst, const cryptonote::account_public_address * src);
  void translate_dst_entry(LunexaTransactionDestinationEntry * dst, const cryptonote::tx_destination_entry * src);
  void translate_klrki(LunexaMultisigKLRki * dst, const rct::multisig_kLRki * src);
  void translate_rct_key(LunexaRctKey * dst, const rct::ctkey * src);
  std::string hash_addr(const LunexaAccountPublicAddress * addr, boost::optional<uint64_t> amount = boost::none, boost::optional<bool> is_subaddr = boost::none);
  std::string hash_addr(const std::string & spend_key, const std::string & view_key, boost::optional<uint64_t> amount = boost::none, boost::optional<bool> is_subaddr = boost::none);
  std::string hash_addr(const ::crypto::public_key * spend_key, const ::crypto::public_key * view_key, boost::optional<uint64_t> amount = boost::none, boost::optional<bool> is_subaddr = boost::none);
  ::crypto::secret_key compute_enc_key(const ::crypto::secret_key & private_view_key, const std::string & aux, const std::string & salt);
  std::string compute_sealing_key(const std::string & master_key, size_t idx, bool is_iv=false);

  typedef boost::variant<rct::Bulletproof, rct::BulletproofPlus> rsig_v;

  /**
   * Transaction signer state holder.
   */
  class TData {
  public:
    TsxData tsx_data;
    tx_construction_data tx_data;
    cryptonote::transaction tx;
    unsigned rsig_type;
    int bp_version;
    std::vector<uint64_t> grouping_vct;
    std::shared_ptr<LunexaRsigData> rsig_param;
    size_t cur_input_idx;
    size_t cur_output_idx;
    size_t cur_batch_idx;
    size_t cur_output_in_batch_idx;

    std::vector<std::string> tx_in_hmacs;
    std::vector<std::string> tx_out_entr_hmacs;
    std::vector<std::string> tx_out_hmacs;
    std::vector<rsig_v> tx_out_rsigs;
    std::vector<rct::ctkey> tx_out_pk;
    std::vector<rct::ecdhTuple> tx_out_ecdh;
    std::vector<size_t> source_permutation;
    std::vector<std::string> alphas;
    std::vector<std::string> spend_encs;
    std::vector<std::string> pseudo_outs;
    std::vector<std::string> pseudo_outs_hmac;
    std::vector<std::string> couts;
    std::vector<std::string> couts_dec;
    std::vector<std::string> signatures;
    std::vector<rct::key> rsig_gamma;
    std::string tx_prefix_hash;
    std::string enc_salt1;
    std::string enc_salt2;
    std::string enc_keys;

    std::shared_ptr<rct::rctSig> rv;

    TData();
  };

  class Signer {
  private:
    TData m_ct;
    wallet_shim * m_wallet2;

    size_t m_tx_idx;
    const unsigned_tx_set * m_unsigned_tx;
    hw::tx_aux_data * m_aux_data;

    unsigned m_client_version;
    bool m_multisig;

    const tx_construction_data & cur_src_tx() const {
      CHECK_AND_ASSERT_THROW_MES(m_tx_idx < m_unsigned_tx->txes.size(), "Invalid transaction index");
      return m_unsigned_tx->txes[m_tx_idx];
    }

    const tx_construction_data & cur_tx() const {
      return m_ct.tx_data;
    }

    const tools::wallet2::transfer_details & get_transfer(size_t idx) const {
      CHECK_AND_ASSERT_THROW_MES(idx < std::get<2>(m_unsigned_tx->transfers).size() + std::get<0>(m_unsigned_tx->transfers) && idx >= std::get<0>(m_unsigned_tx->transfers), "Invalid transfer index");
      return std::get<2>(m_unsigned_tx->transfers)[idx - std::get<0>(m_unsigned_tx->transfers)];
    }

    const tools::wallet2::transfer_details & get_source_transfer(size_t idx) const {
      const auto & sel_transfers = cur_tx().selected_transfers;
      CHECK_AND_ASSERT_THROW_MES(idx < m_ct.source_permutation.size(), "Invalid source index - permutation");
      CHECK_AND_ASSERT_THROW_MES(m_ct.source_permutation[idx] < sel_transfers.size(), "Invalid source index");
      return get_transfer(sel_transfers.at(m_ct.source_permutation[idx]));
    }

    void extract_payment_id();
    void compute_integrated_indices(TsxData * tsx_data);
    bool should_compute_bp_now() const;
    void compute_bproof(messages::lunexa::LunexaTransactionRsigData & rsig_data);
    void process_bproof(rsig_v & bproof);
    void set_tx_input(LunexaTransactionSourceEntry * dst, size_t idx, bool need_ring_keys=false, bool need_ring_indices=false);

  public:
    Signer(wallet_shim * wallet2, const unsigned_tx_set * unsigned_tx, size_t tx_idx = 0, hw::tx_aux_data * aux_data = nullptr);

    std::shared_ptr<messages::lunexa::LunexaTransactionInitRequest> step_init();
    void step_init_ack(std::shared_ptr<const messages::lunexa::LunexaTransactionInitAck> ack);

    std::shared_ptr<messages::lunexa::LunexaTransactionSetInputRequest> step_set_input(size_t idx);
    void step_set_input_ack(std::shared_ptr<const messages::lunexa::LunexaTransactionSetInputAck> ack);

    void sort_ki();

    std::shared_ptr<messages::lunexa::LunexaTransactionInputViniRequest> step_set_vini_input(size_t idx);
    void step_set_vini_input_ack(std::shared_ptr<const messages::lunexa::LunexaTransactionInputViniAck> ack);

    std::shared_ptr<messages::lunexa::LunexaTransactionAllInputsSetRequest> step_all_inputs_set();
    void step_all_inputs_set_ack(std::shared_ptr<const messages::lunexa::LunexaTransactionAllInputsSetAck> ack);

    std::shared_ptr<messages::lunexa::LunexaTransactionSetOutputRequest> step_set_output(size_t idx);
    void step_set_output_ack(std::shared_ptr<const messages::lunexa::LunexaTransactionSetOutputAck> ack);

    std::shared_ptr<messages::lunexa::LunexaTransactionSetOutputRequest> step_rsig(size_t idx);
    void step_set_rsig_ack(std::shared_ptr<const messages::lunexa::LunexaTransactionSetOutputAck> ack);

    std::shared_ptr<messages::lunexa::LunexaTransactionAllOutSetRequest> step_all_outs_set();
    void step_all_outs_set_ack(std::shared_ptr<const messages::lunexa::LunexaTransactionAllOutSetAck> ack, hw::device &hwdev);

    std::shared_ptr<messages::lunexa::LunexaTransactionSignInputRequest> step_sign_input(size_t idx);
    void step_sign_input_ack(std::shared_ptr<const messages::lunexa::LunexaTransactionSignInputAck> ack);

    std::shared_ptr<messages::lunexa::LunexaTransactionFinalRequest> step_final();
    void step_final_ack(std::shared_ptr<const messages::lunexa::LunexaTransactionFinalAck> ack);

    std::string store_tx_aux_info();

    unsigned client_version() const {
      return m_client_version;
    }

    uint8_t get_rv_type() const {
      if (!m_ct.rv){
        throw std::invalid_argument("RV not initialized");
      }
      return m_ct.rv->type;
    }

    bool is_simple() const {
      auto tp = get_rv_type();
      return tp == rct::RCTTypeSimple;
    }

    bool is_req_bulletproof() const {
      return m_ct.tx_data.rct_config.range_proof_type != rct::RangeProofBorromean;
    }

    bool is_req_clsag() const {
      return is_req_bulletproof() && m_ct.tx_data.rct_config.bp_version >= 3;
    }

    bool is_req_bulletproof_plus() const {
      return is_req_bulletproof() && m_ct.tx_data.rct_config.bp_version == 4;  // rct::genRctSimple
    }

    bool is_bulletproof() const {
      auto tp = get_rv_type();
      return rct::is_rct_bulletproof(tp) || rct::is_rct_bulletproof_plus(tp);
    }

    bool is_bulletproof_plus() const {
      auto tp = get_rv_type();
      return rct::is_rct_bulletproof_plus(tp);
    }

    bool is_clsag() const {
      auto tp = get_rv_type();
      return rct::is_rct_clsag(tp);
    }

    bool is_offloading() const {
      return m_ct.rsig_param && m_ct.rsig_param->offload_type() != 0;
    }

    size_t num_outputs() const {
      return m_ct.tx_data.splitted_dsts.size();
    }

    size_t num_inputs() const {
      return m_ct.tx_data.sources.size();
    }

    const TData & tdata() const {
      return m_ct;
    }
  };

  // TX Key decryption
  void load_tx_key_data(hw::device_cold::tx_key_data_t & res, const std::string & data);

  std::shared_ptr<messages::lunexa::LunexaGetTxKeyRequest> get_tx_key(
      const hw::device_cold::tx_key_data_t & tx_data);

  void get_tx_key_ack(
      std::vector<::crypto::secret_key> & tx_keys,
      const std::string & tx_prefix_hash,
      const ::crypto::secret_key & view_key_priv,
      std::shared_ptr<const messages::lunexa::LunexaGetTxKeyAck> ack
  );
}

}
}
}


#endif //LUNEXA_PROTOCOL_H
