BaseTools/BinWrappers/PosixLike/GenerateCapsule --encode \
                                                --capflag PersistAcrossReset \
                                                --json-file sign.json \
                                                --output inner_coreboot.cap

BaseTools/BinWrappers/PosixLike/GenerateCapsule --encode \
                                                --capflag PersistAcrossReset \
                                                --json-file sign_top.json \
                                                --output coreboot.cap