# Lunexa Release Checklist

## Pre-Release Checks

### Version Numbers
- [ ] Update Core RPC version (current: v1.0)
  - Location: `src/rpc/core_rpc_server_commands_defs.h`
  - Increment major version for breaking changes
  - Increment minor version for backwards-compatible changes

- [ ] Update Wallet RPC version (current: v1.0)
  - Location: `src/wallet/wallet_rpc_server_commands_defs.h`
  - Increment major version for breaking changes
  - Increment minor version for backwards-compatible changes

- [ ] Update Daemon ZMQ RPC version (current: v1.0)
  - Location: `src/rpc/daemon_rpc_version.h`
  - Increment major version for breaking changes
  - Increment minor version for backwards-compatible changes

### Code Quality
- [ ] Run all unit tests
- [ ] Run integration tests
- [ ] Check for memory leaks
- [ ] Verify build success on all supported platforms:
  - [ ] Linux
  - [ ] Windows
  - [ ] macOS

### Documentation
- [ ] Update API documentation
- [ ] Update user guides if needed
- [ ] Update installation instructions if needed
- [ ] Update release notes with changes
- [ ] Update any version numbers in documentation

### Security
- [ ] Run security audit tools
- [ ] Check for known vulnerabilities in dependencies
- [ ] Review access controls and permissions
- [ ] Verify cryptographic implementations

### Checkpoint Procedures
- [ ] Generate new checkpoints
  - [ ] Export blockchain data:
    ```bash
    ./lunexa-blockchain-export --output-file checkpoints.dat --block-stop <recent_block_height> --blocksdat
    ```
  - [ ] Calculate SHA256 hash of checkpoints.dat
  - [ ] Update `src/checkpoints/checkpoints.cpp` with recent hardcoded checkpoint
  - [ ] Update `src/blocks/checkpoints.dat` with new export
  - [ ] Update `expected_block_hashes_hash` in `src/cryptonote_core/blockchain.cpp` with new SHA256 hash

- [ ] Test checkpoint data
  - [ ] Verify checkpoint data on testnet
  - [ ] Verify checkpoint data on stagenet
  - [ ] Test blockchain sync with new checkpoints
  - [ ] Verify checkpoint validation logic

- [ ] Update DNS checkpoint records
  - [ ] Update TXT records for checkpoint servers:
    - [ ] checkpoints.lunexa.co
    - [ ] checkpoints.lunexapoint.co
    - [ ] checkpoints.lunexalabs.co
  - [ ] Set appropriate TTL values for DNS records
  - [ ] Verify DNS propagation
  - [ ] Test checkpoint fetching from multiple geographic locations

- [ ] Checkpoint Documentation
  - [ ] Document new checkpoint height and hash
  - [ ] Update checkpoint verification instructions
  - [ ] Archive old checkpoint data
  - [ ] Document checkpoint update procedure
  - [ ] Update checkpoint-related API documentation

## Release Process

### Build Verification
- [ ] Create release builds for all platforms
- [ ] Verify builds are reproducible
- [ ] CLI reproducible builds validated
- [ ] Test installation packages
- [ ] Verify all binaries are properly signed

### CLI Release Steps
- [ ] CLI released
  - [ ] https://www.lunexa.co/downloads/ updated
  - [ ] Update hashes.txt on website
  - [ ] Update auto-update DNS records
  - [ ] Update redirects on downloads box
  - [ ] Update seed nodes

### Testing
- [ ] Test wallet functionality:
  - [ ] Create new wallet
  - [ ] Restore from seed
  - [ ] Send transactions
  - [ ] Receive transactions
  - [ ] Check balance
  - [ ] Verify sync status

- [ ] Test daemon functionality:
  - [ ] Blockchain sync
  - [ ] Network connections
  - [ ] RPC functionality
  - [ ] Mining functionality

### Release Preparation
- [ ] Update version numbers in release files
- [ ] Generate checksums for all release files
- [ ] Prepare release notes with:
  - [ ] New features
  - [ ] Bug fixes
  - [ ] Breaking changes
  - [ ] Upgrade instructions
  - [ ] Known issues

### Distribution
- [ ] Upload release files to designated hosting
- [ ] Update download links
- [ ] Verify download integrity
- [ ] Update seed nodes if needed
- [ ] Update checkpoint data if needed

## Post-Release

### Verification
- [ ] Verify downloads work correctly
- [ ] Confirm update mechanisms work
- [ ] Check auto-update systems if applicable
- [ ] Verify release notes are accurate and complete

### Communication
- [ ] Announce release on official channels
- [ ] Update social media
- [ ] Notify key stakeholders
- [ ] Update any relevant documentation sites

### Monitoring
- [ ] Monitor for critical issues
- [ ] Track user feedback
- [ ] Monitor network stability
- [ ] Track adoption metrics

### Documentation
- [ ] Archive release artifacts
- [ ] Document any issues encountered
- [ ] Update version history
- [ ] Document lessons learned


## Final Checklist

- [ ] All tests passed
- [ ] All documentation updated
- [ ] All builds verified
- [ ] All checksums confirmed
- [ ] All signatures verified
- [ ] Release notes complete
- [ ] Announcement drafted and reviewed

---

**Note:** This checklist should be reviewed and updated for each release cycle. Add or modify items based on specific release requirements and lessons learned from previous releases. 